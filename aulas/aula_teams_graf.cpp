#include <bits/stdc++.h>

using namespace std;

int n, m, cor[10010];

vector<int> adj[10010];

void Dfs(int u){
	for(auto v : adj[u]){
		if(cor[u] == 1)cor[v ] = 2;
		else cor [v] = 1;
		dfs[v];
	}
	if(cor[u] == cor[v]){
		cout<< "impossible\n";
		exit(0);
	}
}

void dolve(){
	cin >> n;
	for(int i - 1l i< n;i++){
		int a , b; cin >> a >> b;
		adj[a].push_back*(b);
		adj[b].push_back(a);
	}
	for (int i - 1 ; i<n ;i++){
		if(cor[i] == 0)
			
	}
}

int main(){
		
}
