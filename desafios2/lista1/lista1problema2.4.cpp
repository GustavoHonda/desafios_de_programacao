#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int processed[N];
int cumulative_cost[N];
vector<pair<int,int>> adj[N];

//Not tested

// 1 sec = 5*10^8 operations


// teste
// 3 4
// 1 2 3
// 2 3 1
// 1 3 7
// 2 1 5

void print_adj(int m){
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

int min_route(int n , int m, int init_vertex, int final_vertex){
	for(int i = 0;i<= n ; i++){
		processed[i] = 0;
	}
	pair<int,pair<int,int>> edge;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> fila;
	
	cumulative_cost[init_vertex] = 0;
	

	fila.push({0,{init_vertex,init_vertex}});
	while(fila.size() > 0){
		edge = fila.top();
		int cost = edge.first;
		int origin = edge.second.first;
		int destiny = edge.second.second;
		fila.pop();
		if(processed[destiny] == 0){
			cumulative_cost[destiny] = cost + cumulative_cost[origin];
			if(destiny == final_vertex){
				return cumulative_cost[destiny];
			}
			for(pair<int,int> p : adj[destiny]){
				if(processed[p.first] == 0){
					fila.push({p.second,{destiny,p.first}});
				}
			}
		}
		processed[origin] = 1;
		// print_fila(fila);
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,i,a,b,c;
	i = 0;
	cin >> n >> m;
	while(i < m){
		i++;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	
	// print_adj(m);
	
	int min_cost = min_route(n,m,1,n);
	int keep = 0;
	int passage_discounted = 0;
	for(int i = 0; i<= n; i++){
		for(int j = 0; j< adj[i].size();j++){
			if(passage_discounted < adj[i].at(j).second){
				int cost = min_route(n,m,1,i) + adj[i].at(j).second/2 + min_route(n,m,adj[i].at(j).first,n);
				if(min_cost > cost){
					min_cost = cost;
					passage_discounted = adj[i].at(j).second; 
				}
			}	
			
		}
	}
	cout << min_cost << endl;
	// cout << biggest[n] << endl;
}
