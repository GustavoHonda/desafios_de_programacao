#include <bits/stdc++.h>

typedef long long ll ;

using namespace std;


const ll ll_max = 2e5 + 10;
const ll N = 1e5;

// Wrong answer 17.0

// 1 sec = 5*10^8 operations


// teste
// 3 4
// 1 2 3
// 2 3 1
// 1 3 7
// 2 1 5


vector<ll> min_route(ll n , ll m, ll init_vertex, vector<vector<pair<ll,ll>>> &adj){
	pair<ll,ll> edge;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> fila;
	vector<ll> cumulative_cost(n+1,ll_max);

	cumulative_cost[init_vertex] = 0;
	fila.push({0,init_vertex});
	
	while(fila.size() > 0){
		edge = fila.top();
		ll cost = edge.first;
		ll destiny = edge.second;

		fila.pop();
		if(cost != cumulative_cost[destiny]){
			continue;
		}

		for(pair<ll,ll> p : adj[destiny]){
			ll cost_2 = p.second + cumulative_cost[destiny];
			
			if(cumulative_cost[p.first] > cost_2){
				cumulative_cost[p.first] = cost_2;
				fila.push({cost_2,p.first});
			}	
		}
	}
	return cumulative_cost;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,m,i,a,b,c;
	ll min_cost = ll_max;
	ll origin,destiny,passage,cost;


	i = 0;
	
	cin >> n >> m;

	vector<vector<pair<ll,ll>>> adj(n+1, vector<pair<ll,ll>> (0,{0,0}));
	vector<vector<pair<ll,ll>>> adj_inv(n+1, vector<pair<ll,ll>> (0,{0,0}));
	
	while(i < m){
		i++;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj_inv[b].push_back({a,c});
	}
	
	vector<ll> trip_cost = min_route(n,m,1,adj);
	vector<ll> trip_inv_cost = min_route(n,m,n,adj_inv);
	
	for(ll i = 1; i<= n; i++){
		for(pair<ll,ll> p : adj[i]){
			origin = i; destiny = p.first; passage = p.second;
			
			if(trip_cost[origin] == ll_max || trip_inv_cost[destiny] == ll_max){
				continue;
			}

			cost = trip_cost[origin] + (passage/2) + trip_inv_cost[destiny];
			if(min_cost > cost){
				min_cost = cost;
			}
		}
	}
	cout << min_cost << endl;
	// cout << biggest[n] << endl;
}
