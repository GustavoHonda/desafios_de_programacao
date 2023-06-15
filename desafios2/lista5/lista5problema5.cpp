#include <bits/stdc++.h>

using namespace std;
vector<int> memo;

template <typename T>
void print_vect(vector<T> vect){
	for(auto element : vect){
		cout << element << " ";
	}
	cout << endl;
}

template <typename T, typename F>
void print_map(map<T,F> map){
	for(auto element : map){
		cout << "(" << element.first << ":" << element.second << ") ";
	}
	cout << endl;
}



map<int,int> solve(vector<int> colors,vector<vector<int>>adj,int node,int father = 0){
	map<int,int> color_freq;
	color_freq[colors[node]] +=1;
	for(auto element : adj[node]){
		if(element == father){continue;}
		map<int,int> color_freq_son = solve(colors,adj,element,node);
		if(color_freq.size() > color_freq_son.size()){
			for(auto element2: color_freq_son){
				color_freq[element2.first] += element2.second;
			}
		}
		else{
			for(auto element2 : color_freq){
				color_freq_son[element2.first] += element2.second;
			}
			color_freq = color_freq_son;
		}
	}
	// print_map(color_freq);
	int max = 0;
	for(auto element : color_freq){
		if( element.second > max){
			max = element.second;
		}
	}
	for(auto element : color_freq){
		if( element.second == max){
			memo[node] += element.first;
		}
	}
	return color_freq;
}

int main(){
	int n, i=1,x,y;
	memo.push_back(0);
	cin >> n;
	vector<int> colors(n+1,0);
	vector<vector<int>> adj(n+1, vector<int>(0));
	while(i<n+1){
		cin >>colors[i];
		memo.push_back(0);
		i++;
	}
	i=0;
	while(i<n-1){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		i++;
	}

	// for(int i =0; i< adj.size();i++){
	// 	print_vect(adj[i]);
	// 	cout << endl;
	// }

	solve(colors, adj,1);
	for(int i = 1; memo[i];i++){
		cout << memo[i] << " ";
	}
	// cout << endl;
}