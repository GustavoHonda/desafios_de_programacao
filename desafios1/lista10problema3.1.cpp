#include <bits/stdc++.h>
#define ll long long 

const ll MAXN = 100000;
const ll logN = 20;

using namespace std;

ll profundidade[MAXN], dist[MAXN][logN], memo[MAXN][logN];
vector< pair<int, int>> filhos[MAXN];

int n, q;

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
			if(filhos[a].size() == 0 || filhos[b].size() == 0){
				filhos[a].push_back({b,peso});
				filhos[b].push_back({a,peso});	
			}else{
				for(int j=0;j< filhos[b].size();j++){
					pair<int, int> p = filhos[b][j];
					if(p.first == a){
						if(p.second > peso){
							filhos[b][j] = {a,peso};
							for(int k=0;k<filhos[a].size();k++){
								if(filhos[a][k].first == b){
									filhos[a][k] = {b,peso};
									break;
								}
							}
						}
						break;
					}
				}
			}
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
			cin >> x >> y;
			int ancestral = LCA(x,y);
			int distancia  = subir(x,profundidade[x]-profundidade[ancestral]).second;
			distancia +=  subir(y,profundidade[y]-profundidade[ancestral]).second;
			cout << distancia << endl;
		}
	}
		
}