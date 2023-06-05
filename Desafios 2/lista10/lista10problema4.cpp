#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 2e5+100;

vector<bool> check(MAXN);
vector<ll> adj[MAXN];
vector<ll> dis(MAXN);


ll x, y;

ll dfs(ll node, ll depth, ll father){
	ll res = 0;
	dis[node] = depth;
	for(auto element: adj[node]){
		if(element != father){
			res += dfs(element, depth + 1, node);
		}
	}
	if(node != x){
		if(res != 0 || check[node]){
			res += 2;
		}	
	}
	return res;	
}

int main(){
	int q;
	cin >> q;
	while(q--){
		ll n,m;
		cin >> n >> m >> x >> y;
		for (int i = 0; i < n+50; ++i)
		{
			check[i] = 0;
	 		adj[i].clear();
		}
		for (int i = 0; i < m; ++i)
		{
			int v;
			cin >> v;
			check[v] = 1;
		}
		check[y] = 1;
		ll a,b;
		for (int i = 0; i < n-1; ++i)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ans  = dfs(x,0,0);
		if(y!=x){
			ans = ans - dis[y];
		}
		cout << ans << endl;
	}
}