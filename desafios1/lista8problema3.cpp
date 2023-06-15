#include <bits/stdc++.h>
const int MAXN = 100;

using namespace std;


bool processed[MAXN][MAXN];
int grid[MAXN][MAXN];
int h,w, resp;
int mr[] = {-1,-1,-1,0,0,1,1,1};
int mc[] = {1,0,-1,1,-1,1,0,-1};


void solve(int r, int c){
	int  var;
	queue<pair<int,int>> fila;
	fila.push({r,c});
	while(fila.size() > 0){
		pair<int,int> p = fila.front();
		r = p.first;
		c = p.second;
		processed[r][c] = true;
		fila.pop();
		for(int i = 0; i<8; i++){
			int rr = r + mr[i];
		 	int cc = c + mc[i];
			if(rr > 1 and cc > 1 and rr<=h and cc <=w){
				if(!processed[rr][cc]){
					var = grid[rr][cc]; 
					if(var == grid[r][c]+1){
						if(var > resp){
							resp = var;
						}
						fila.push({rr,cc});
					}
				}
			}
		}
	}
}

int main(){
	int  cs;
	char s;
	cin >> h >> w;
	cs = 1;
	while(h != 0 and w != 0){
		queue<pair<int,int>> fila;
		for(int i = 1; i <=h; i++){
			for(int j = 1; j<=w; j++){
				cin >> s;
				processed[i][j] = false;
				grid[i][j] = (int)s - 64;
				if(grid[i][j] == 1){
					fila.push({i,j});
				}
			}
		}
		// for(int i = 1; i <=h; i++){
		// 	for(int j = 1; j<=w; j++){
		// 		cout << grid[i][j] << " ";	
		// 	}
		// 	cout << endl;
		// }
		while(fila.size() > 0){
			pair<int, int> p = fila.front();
			fila.pop();
		 	solve(p.first,p.second);
		}
		cout << "Case " << cs << ": " << resp << endl;
		cin >> h >> w;
		cs ++ ;
	}
}