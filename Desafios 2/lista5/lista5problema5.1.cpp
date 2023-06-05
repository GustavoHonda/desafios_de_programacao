#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define N 1000000

ll n,sum,max_freq,aux;
ll ans[N],sz[N],color[N],bigger_son[N],color_freq[N];
vector<ll> adj[N];

template <typename T>
void print_vect(vector<T> vect){
	for(auto element : vect){
		cout << element << " ";
	}
	cout << endl;
}

template <typename T>
void print_arr(T ar[]){
	for(int i = 0; i< n+1;i++){
		cout << ar[i] << " ";
	}
	cout << endl;
}

void change_tree(ll root, ll father, ll in_out){
	color_freq[color[root]]+= in_out;
	if(color_freq[color[root]]>max_freq){
		max_freq=color_freq[color[root]];
		sum=color[root];
	}
	else if(color_freq[color[root]] == max_freq){
		sum +=color[root];
	}
	for(auto element:adj[root]) {
		if(element!=father && element!=aux) {
			change_tree(element,root,in_out);
		}
	}
}

void dfs_sz(ll root, ll father){
	sz[root]=1;
	for(auto element: adj[root]){
		if(element!= father){
			dfs_sz(element,root);
			if(sz[bigger_son[root]]<sz[element]){
				bigger_son[root] = element;
			}
			sz[root]+=sz[element];
		}
	}
}

void dfs(ll root,ll father,ll keep){
	// cout << "loop"<< endl;
	for(auto element: adj[root]) {
		if(element!= father&& element!=bigger_son[root]){
			dfs(element,root,0);
		} 
	}
	if(bigger_son[root] != 0){
		dfs(bigger_son[root],root,1);
		aux = bigger_son[root];
	}

	change_tree(root,father,1); //include nodes
	aux=0;
	ans[root]=sum; // keep sum in answer
	// print_arr(ans);
	if(keep == 0){
		change_tree(root,father,-1); //discard nodes
		sum=0;
		max_freq=0;
	}
}

int main(){
	cin >> n;
	for(ll i = 1;i<=n;i++){
		cin >> color[i];
	}
	for(ll i = 1,u,v;i<n;i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	} 
	// for (int i = 0; i < n+1; ++i)
	// {
	// 	print_vect(adj[i]);
	// }
	
	dfs_sz(1,0);
	// print_arr(sz);
	dfs(1,0,0);
	for(ll i = 1;i<=n;i++) {
		cout << ans[i] << " ";
	}
}

