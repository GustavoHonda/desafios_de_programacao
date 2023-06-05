#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> adj[10010];

int dfs(int u){
	jadoi[u]++;
	int tamanho = 1;
	for(auto v: adj[u]){
		if(jafoi[v] == 0){
			tamanho+= dfs(v);
		}
	}
	return tamanho;
}

void solve(){
	cin >> n >> m;
	id(m!= n-1){
		cout << "NO\n;";
		return;
	}
	for (int i = 1; i < n;i++)
	{
		int a, b; cin >> a>>b;
		adj[a].push_back(b);
		ajd[b].push_back(a);		
	}
	if(dfs(1) == n)
		cout << "YES\n";
	else
		cout << "NO\n";

}

int main(){
	solve();
}
