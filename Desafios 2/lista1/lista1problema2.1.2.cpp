#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
// const int INT_MAX = 2147483647;


int cumulative_cost[N];
int biggest[N];
vector<pair<int,int>> adj[N];

//Wrong answer 14.0

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

int min_route(int n , int m){
	for(int i = 0;i<= n ; i++){
		cumulative_cost[i] = INT_MAX;
	}
	pair<int,pair<int,int>> edge;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> fila;
	
	cumulative_cost[1] = 0;
	biggest[1] = 0;

	fila.push({0,{1,1}});
	while(fila.size() > 0){
		edge = fila.top();
		int cost = edge.first;
		int origin = edge.second.first;
		int destiny = edge.second.second;
		fila.pop();
		if(destiny != n){
			for(pair<int,int> p : adj[destiny]){
				if( biggest[destiny] < p.second ){
					if(cumulative_cost[p.first]>cumulative_cost[destiny] - biggest[destiny]/2 + biggest[destiny] + p.second/2 ) {
						cumulative_cost[p.first]=cumulative_cost[destiny] - biggest[destiny]/2 + biggest[destiny] + p.second/2;
						biggest[p.first] = p.second;
						fila.push({p.second,{destiny,p.first}});
					}
				} 
				else{
					if(cumulative_cost[p.first]> cumulative_cost[destiny] + p.second) {
						cumulative_cost[p.first] = cumulative_cost[destiny] + p.second; 
						biggest[p.first] = biggest[destiny];
						fila.push({p.second,{destiny,p.first}});
					}
				}
					
			}

		}
		// print_fila(fila);
	}
	return cumulative_cost[n];
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
	int total_cost = min_route(n,m);
	cout << total_cost << endl;
	// cout << biggest[n] << endl;
}
