#include <bits/stdc++.h>

const int MAXN = 10;

using namespace std;

int mr[] = {1 ,-1, 2,-2, 2,-2, 1, -1};
int mc[] = {-2,-2,-1,-1, 1, 1, 2, 2};

int dist[MAXN][MAXN];
bool processed[MAXN][MAXN];
vector<pair<int,int>> adj[MAXN][MAXN];


int solve(int inir, int inic, int fimr, int fimc){
	for(int i =1; i<=MAXN; i++){
		for(int j=1 ; j<=MAXN;j++){
			dist[i][j] = -1;
			processed[i][j] = false;
		}
	}
	queue<pair<int, pair<int, int>>> fila;
	fila.push({0,{inir,inic}});
	while(fila.size() > 0){
		pair<int, pair<int, int>> p = fila.front();
		int d = p.first;
		int r = p.second.first;
		int c = p.second.second;
		fila.pop();
		processed[r][c] = true;
		dist[r][c] = d;
		if(r == fimr and c == fimc){
			return dist[r][c];
		}
		for(pair<int, int> x : adj[r][c]){
			int rr = x.first;
			int cc = x.second;
			if(!processed[rr][cc]){
				fila.push({d+1,{rr,cc}});
			}
		}
	} 
	return dist[fimr][fimc];
}

int main(){
	int t,a,b, resp;
	char p,q;
	cin >> t;
	for(int i = 1;i<=8;i ++){
		for(int j = 1;j<=8; j++){
			for(int k =0; k<8; k++){
				int ii = i+mr[k];
				int jj = j+mc[k];
				if(ii<1 or ii >8 or jj<1 or jj>8)continue;
				adj[i][j].push_back({ii,jj});
			}
		}
	}
	while(t--){
		cin >> p >> a;
		cin >> q >> b;
		resp = solve((int)p-96,a,(int)q-96,b);
		cout << resp << endl;
	}
	// for(int i = 1;i<=8;i ++){
	// 	for(int j = 1;j<=8; j++){
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}