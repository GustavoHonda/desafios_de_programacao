#include <bits/stdc++.h>

const int MAXN = 110;

using namespace std;

int mr[] = {-1,-1,-1,0,0,1,1,1};
int mc[] = {-1,0,1,-1,1,-1,0,1};
	 
int processed[MAXN][MAXN];
int grid[MAXN][MAXN];
vector<pair<int,int>> adj[MAXN][MAXN];


int h,w;

int solve(int r, int c){
	int resp = 0;
	queue<pair<int,int>> fila;
	fila.push({r,c});
	while(fila.size() > 0){
		pair<int,int> p = fila.front();
		int r = p.first;
		int c = p.second;
		fila.pop();
		processed[r][c] = grid[r][c];
		resp = max(resp,processed[r][c]);
		for(pair<int,int> p : adj[r][c]){
			if(processed[p.first][p.second] == -1){
				fila.push(p);
			}
		}
	}
	return resp;
}

int main(){
	int cs = 1, resp = 0;
	char s;
	cin >> h >> w;
	while(h!=0 and w!=0){

		queue<pair<int,int>> fila;
		for(int i = 1;i<=h ;i++){
			for(int j = 1;j<=w;j++){
				cin >> s;
				processed[i][j] = -1;
				grid[i][j] = (int)s -64;
				if(grid[i][j] == 1){
					fila.push({i,j});
				}
			}
		}

		for(int i = 1;i<=h ;i++){
			for(int j = 1;j<=w;j++){
				for(int k =0; k < 8;k++){
					int ii = i + mr[k];
					int jj = j + mc[k];
					if(ii < 1 or ii > h or jj < 1 or jj > w) continue;
					if(grid[i][j] + 1 == grid[ii][jj]){
						adj[i][j].push_back({ii,jj});
					}
				}
			}
		}
		while(fila.size() > 0){
			pair<int,int> p = fila.front();
			fila.pop();
			
			resp = max(resp,solve(p.first,p.second));
		}
		// for(int i = 1;i<=h ;i++){
		// 	for(int j = 1;j<=w;j++){
		// 		cout << processed[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		cout << "Case " << cs << ": " << resp << endl;
		cin >> h >> w;
		cs ++ ;
	}
}