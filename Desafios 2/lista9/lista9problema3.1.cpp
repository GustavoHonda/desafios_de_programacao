#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int n;
vector<int> adj[MAXN];
vector<bool> processed(MAXN);
vector<int> fix(MAXN);
vector<int> low(MAXN);
vector<pair<int,int>> bridge;
int counter;

void dfs(int node, int father = -1){
	processed[node] = true;
	fix[node] = low[node] = counter ++;
	for(int element : adj[node]){
		if(element == father){
			continue;
		}
		if(processed[element]){
			low[node] = min(low[node],fix[element]);
		} else{
			dfs(element,node);
			low[node] = min(low[node], low[element]);
			if(low[element] > fix[node]){
				bridge.push_back({min(node,element), max(node,element)});
			}
		}
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << bridge.size() << endl;
	for(auto e : bridge){
		cout << e.first << " " << e.second << endl;
	}
	return 0;
}