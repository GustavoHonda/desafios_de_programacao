#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

//Wrong answer 12.0

// 1 sec = 5*10^8 operations


// teste
// 3 4
// 1 2 3
// 2 3 1
// 1 3 7
// 2 1 5

void print_adj(int m,vector<vector<pair<int,int>>> adj){
	int i = 1;
	while(i<=m){
		for(pair<int,int> p : adj[i]){
			cout << p.first << p.second << endl;
		}
		i++;
	}
}

void print_fila(priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> fila ){
	
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> keep_fila;
	pair<int,pair<int,int>> edge;
	while(fila.size() >0){
		edge =  fila.top();
		keep_fila.push(edge);
		cout << edge.first << edge.second.first << edge.second.second << endl;
		fila.pop();
	}
	cout << endl;
	while(keep_fila.size() >0){
		edge =  keep_fila.top();
		fila.push(edge);
		keep_fila.pop();
	}
}

vector<long long> min_route(int n , int m, int init_vertex, vector<vector<pair<int,int>>> &adj){
	pair<long long,int> edge;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> fila;
	vector<long long> cumulative_cost(n+1,INT_MAX);
	cumulative_cost[init_vertex] = 0;

	fila.push({0,init_vertex});
	while(fila.size() > 0){
		edge = fila.top();
		int cost = edge.first;
		int destiny = edge.second;
		fila.pop();

		if(cumulative_cost[destiny] != -cost){
			continue;
		}

		for(pair<int,int> p : adj[destiny]){
			long long cost_2 = p.second + cumulative_cost[destiny];
			if(cumulative_cost[p.first] > cost_2){
				cumulative_cost[p.first] = cost_2;
				fila.push({-cost_2,p.first});
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
	int origin,destiny,passage,cost;
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
