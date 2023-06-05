#include <bits/stdc++.h>
#define ll long long
const int MAXN = 500000;


using namespace std;

// if road is necessary its in dfs obrigatory

vector<int> adj[MAXN];
bool processados[MAXN];
int father[MAXN];
int depth[MAXN];
map<int,bool> colors[MAXN];
map<pair<int,int>,bool> edge;
vector<pair<int,int>> bridge;
ll n, m, a, b;

void print_map(){
	for (int i = 1; i <=n; ++i)
	{
		for(auto element : colors[i]){
			cout << "(" <<i << "," <<  element.first << ")" << endl;
		}
		cout << endl;
	}
}

void print_adj(){
	for (int i = 1; i <=n; ++i){
		for(auto element : adj[i]){
			cout << "(" << i << "," << element << ")";
		}
		cout << endl;
	}
}

template <typename T>
void print_array(T array[]){
	for (int i = 1; i <=n; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}


void change_color(int node, int ascendent){
	while(node != ascendent){
		colors[node][ascendent] = true;
		node = father[node];
	}
}

queue<int> dfs_recursive(int start, queue<int> q, int deep){
	for(auto element : adj[start]){
		
		depth[start] = deep;
		processados[start] = 1;
		if(processados[element] == 0){
			edge[{start,element}] = true;
			// cout << element << endl;
			father[element] = start;
			q = dfs(element,q, deep+1);
		}
		else if(not edge[{start,element}] && not edge[{element,start}]){
			if(depth[start] > depth[element]){
				change_color(start, element);
			}
			else{
				change_color(element,start);
			}
		}
		else{
			// cout << "[" << start << "," << element << "]" << endl; 
		}
	}
	q.push(start);
	return q;
}

queue<int> dfs_iterate(int start, queue<int> q){
	queue<int> fila;
	fila.push_back(start);
	int node;
	while(fila.size() > 0){
		node = fila.top();
		depth[node] = deep;
		processados[node] = 1;
		if(processados[element] == 0){
			edge[{start,element}] = true;
			// cout << element << endl;
			father[element] = start;
			q = dfs(element,q, deep+1);
		}
		else if(not edge[{start,element}] && not edge[{element,start}]){
			if(depth[start] > depth[element]){
				change_color(start, element);
			}
			else{
				change_color(element,start);
			}
		}


	}
}

bool check_colors(int x, int y){
	for(auto element : colors[x]){
		if(colors[y][element.first]){
			return false;
		}
	}
	return true;
}

int find(){
	int sum = 0;
	for(int i = 1;i <=n;i++){
		for(auto element : adj[i]){
			if(check_colors(element, i)){
				bridge.push_back({element, i});
				sum ++;
			}
		}
	}
	return sum;
}

int main(){
	
	cin >> n >> m;
	for (int i = 1; i <=n; ++i){
		processados[i] = 0;
		father[i] = -1;
		depth[i] = n+1;
		colors[i][i] = true;
	}
	for(int i = 0; i < m;i++){
		cin >> a >> b;
		edge[{a,b}] = false;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// print_adj();
	queue<int> q;
	q = dfs(1,q,0);
	// print_map();
	// print_array(depth);
	int num = find();
	cout << num << endl;
	for(auto element : bridge){
		cout << element.first << " " << element.second << endl;
	}
}