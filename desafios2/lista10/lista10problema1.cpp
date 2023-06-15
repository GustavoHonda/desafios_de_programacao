#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXN = 2*1e5 +5;

ll n;
vector<ll> adj[MAXN];
ll check[MAXN], sz[MAXN];

ll solve(ll node, ll ans){
	ll max_points = ans; 
	check[node] = 1;
	for(auto element : adj[node]){
		if(!check[element]){
			max_points = max(max_points,solve(element, ans + n - (2*sz[element])));
		}
	}
	return max_points;
}


ll dfs(ll node){
	ll ans = 0;

	check[node] = 1;
	sz[node] = 1;

	for(auto element: adj[node]){
		if(!check[element]){
			ans += dfs(element);
			sz[node]+= sz[element];
		}
	}
	return sz[node] + ans;
}


int main(){
	cin >> n;


	ll a,b;
	for (int i = 0; i < n -1; ++i)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < MAXN; ++i)
	{
		check[i] = 0;
	}

	ll target = dfs(1);

	for (int i = 0; i < MAXN; ++i)
	{
		check[i] = 0;
	}

	cout << solve(1, target) << endl;
}