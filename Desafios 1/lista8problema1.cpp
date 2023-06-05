#include <bits/stdc++.h>

const int MAXN = 110;

using namespace std;

int n,e,t,m,u,v,w, resp;
vector<pair<int,int>> adj[MAXN];
bool processados[MAXN];
int dist[MAXN];



int solve(int start){
	for(int i = 1; i<=n;i++ ){
		processados[i] = false;
		dist[i] = -1;
	}
	pair<int,int> p;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
	fila.push({0,start});
	while(fila.size()>0){
		p = fila.top();
		int v = p.second;
		int d = p.first;
		fila.pop();
		processados[v] = true;
		dist[v] = d;
		if(v == e){
			return dist[v];
		}
		for(pair<int,int> x : adj[v]){
			int viz = x.second;
			int wei = x.first;
			if(!processados[viz]){
				fila.push({dist[v] + wei, viz});
			}
		}
	}
	
	return dist[e];
}

int main(){
	cin >> n >> e >> t >> m;
	while(m--){
		cin >> u >> v >> w ;
		adj[u].push_back({w,v});
	}
	int count = 0;
	for(int i = 1;i<=n;i++){
		resp = solve(i);
		if(resp <= t and resp != -1)
			count ++;
	}
	cout << endl << count << endl;
}