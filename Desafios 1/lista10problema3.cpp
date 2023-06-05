#include <bits/stdc++.h>
#define ll long long 

const ll MAXN = 100000;
const ll logN = 20;

using namespace std;

ll profundidade[MAXN], dist[MAXN][logN], memo[MAXN][logN];
vector< pair<int, int> > filhos[MAXN];
bool check[MAXN];
vector<pair<int,int>> v [MAXN];

int n, q;

void tree (){
	for(int i = 1; i<=n; i++){
		check[i] = false;
	}
	priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> fila;	
	fila.push({0,{0,1}});
	while(fila.size()>0){
		pair<int,pair<int,int>> p = fila.top();
		int wei = p.first;
		int pai = p.second.first;
		int filho = p.second.second;
		fila.pop();
		if(!check[filho]){
			filhos[pai].push_back({filho,wei});
			filhos[filho].push_back({pai,wei});
			for(auto x : v[filho]){

				fila.push({x.second,{filho,x.first}});
			}
		}
		check[filho] = true;
	}
}

void dfs(ll x, ll pai){
	for(auto it : filhos[x]){
		int u = it.first, peso = it.second;
		if(u == pai) continue;
		dist[u][0] = peso;
		memo[u][0] = x;
		profundidade[u] = profundidade[x]+1;
		dfs(u,x);
	}
}

pair<int,int> subir(int x, int k){
	int distancia =0 ;
	for(int bit = 0; bit<logN;bit++){
		if((1<<bit) & k){
			distancia += dist[x][bit];
			x = memo[x][bit];
		}
	}
	return {x,distancia};
}

int LCA(int a, int b){
	if(profundidade[a] > profundidade[b]){
		a = subir(a,profundidade[a]-profundidade[b]).first;
	}
	else{
		b = subir(b,profundidade[b] - profundidade[a]).first;
	}

	if(a == b){
		return a;
	}
	for(int i = 19;i >= 0;i--){
		if(memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	}
	return memo[a][0];
}


int main(){
	ll t ,a,b,peso ,x,y;
	cin >> t;
	while(t--){
		for(auto x : filhos){
			x.clear();
		}
		cin >> n >> q;
		for(int i = 1; i<=n;i++){
			cin >> a >> b >> peso;
			v[a].push_back({b,peso});
		}
		tree();
		for(auto x : v){
			x.clear();
		}
		dfs(1,-1);
		
		for(int i = 1;i<20;i++){
			for(int u = 1; u<=n;u++){
				int v = memo[u][i-1];
				dist[u][i] = dist[u][i-1] + dist[v][i-1];
				memo[u][i] = memo[v][i-1];
			}
		}

		while(q--){
			// cout << "runned" << endl;
			cin >> x >> y;
			int ancestral = LCA(x,y);
			// cout << ancestral << profundidade[ancestral] <<  endl;
			// cout << x <<  profundidade[x]  << endl;
			// cout << y <<  profundidade[y]  << endl;
			int distancia  = subir(x,profundidade[x]-profundidade[ancestral]).second;
			distancia +=  subir(y,profundidade[y]-profundidade[ancestral]).second;
			cout << distancia << endl;
		}
	}
		
}