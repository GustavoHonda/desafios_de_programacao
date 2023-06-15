#include <bits/stdc++.h>

using namespace std;

char mat[51][51];
int r, c, dis[51][51];
int mx[] = {-1,-1,-1,0,0,1,1,1};
int my[] = {-1,0,1,-1,1,-1,0,1};


bool in_range(int x, int y, int r, int c){
	return (x < r && y < c && x >= 0 && y >= 0);
}

void dfs(int i, int j, int dist){
	int x, y;
	dis[i][j] = dist+1;
	for(int k = 0;k<8;k++){
		x = i+mx[k];
		y = j+my[k];
		if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
			dfs(x, y, dis[i][j]);
		}
	}
}

int main(){
	
	int max, tc=1;
	
	while(true){
		cin >> r >> c;
		if(r == 0 and c == 0)
			break;

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> mat[i][j];
				dis[i][j] = 0;
			}
		}

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(mat[i][j] == 'A' && dis[i][j] == 0)
					dfs(i, j, 0);
			}
		}
		max = dis[0][0];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				if(max < dis[i][j])
					max = dis[i][j];
		}
		printf("Case %d: %d\n", tc, max);
		tc++;
	}
}