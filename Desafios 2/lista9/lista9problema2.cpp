#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

#define int long long
#define endl '\n'

vector<int> adj[MAXN];
int viz[MAXN];
int low[MAXN];
vector<pair<int,int>> res;
int counter = 0;
int valid;
int n,m;


void dfs(int node, int father){
	low[node] = counter++;
	viz[node] = low[node];
	for(auto element : adj[node]){
		if(element != father){
			if(viz[element]){
				low[node] = min(low[node], viz[element]);
				if(viz[node] < viz[element]){
					res.push_back({element, node});	
				}
			}
			else{
				dfs(element,node);
				res.push_back({node,element});
				low[node] = min(low[node],low[element]);
				if(low[element] > viz[node]){
					valid = false;
					return;
				}
			}
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a,b; 
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	valid = true;
	dfs(1,0);
	if(!valid){
		cout << "IMPOSSIBLE" ;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		if(!viz[i]){
			cout << "IMPOSSIBLE" ;
			return 0;
		}
	}
	for(auto element : res){
		cout << element.first << " " << element.second << endl;
	}
}