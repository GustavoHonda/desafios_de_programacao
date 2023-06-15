#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

//Wrong answer 18.0

// 1 sec = 5*10^8 operations


// teste
// 3 4
// 1 2 3
// 2 3 1
// 1 3 7
// 2 1 5

vector<long long> min_route(int n , int m, int init_vertex, vector<vector<pair<int,int>>> &adj){
	pair<long long,int> edge;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> fila;
	vector<long long> cumulative_cost(n+1,INT64_MAX);
	cumulative_cost[init_vertex] = 0;

	fila.push({0,init_vertex});
	while(fila.size() > 0){
		edge = fila.top();
		long long cost = edge.first;
		int destiny = edge.second;
		fila.pop();

		if(cumulative_cost[destiny] != cost){
			continue;
		}

		for(pair<int,int> p : adj[destiny]){
			long long cost_2 = p.second + cumulative_cost[destiny];
			if(cumulative_cost[p.first] > cost_2){
				cumulative_cost[p.first] = cost_2;
				fila.push({cost_2,p.first});
			}	
		}
		// print_fila(fila);
	}
	return cumulative_cost;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,i,a,b,c;
	
	cin >> n >> m;

	vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>> (0,{0,0}));
	vector<vector<pair<int,int>>> adj_inv(n+1, vector<pair<int,int>> (0,{0,0}));
	i = 0;
	while(i < m){
		i++;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj_inv[b].push_back({a,c});
	}
	
	// print_adj(m,adj);

	
	vector<long long> trip_cost = min_route(n,m,1,adj);
	vector<long long> trip_inv_cost = min_route(n,m,n,adj_inv);

	long long min_cost = INT64_MAX;
	long long cost;
	int origin,destiny,passage;
	for(int i = 1; i<= n; i++){
		for(pair<int,int> p : adj[i]){
			origin = i; destiny = p.first; passage = p.second;
			
			if(trip_cost[origin] == INT64_MAX || trip_inv_cost[destiny] == INT64_MAX){
				continue;
			}
			cost = trip_cost[origin] + passage/2 + trip_inv_cost[destiny];
			if(min_cost > cost){
				min_cost = cost;
			}
		}
	}
	cout << min_cost << endl;
	// cout << biggest[n] << endl;
}
