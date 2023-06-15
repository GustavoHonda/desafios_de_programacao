#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 10;

int n;
char grid[N];
bool state[N][N];
int c[N][N];

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int y, int k){
	for(int i = x; i<=n;i+=lowbit(i)){
		for(int j = y; j <=n; j+=lowbit(j)){
			c[i][j]+=k;
		}
	}
}

int sum(int x, int y){
	int sum = 0;
	for(int i = x; i;i-=lowbit(i)){
		for(int j=y;j;j-=lowbit(j)){
			sum +=c[i][j];
		}
	}
	return sum;
}


int main(){
	int q,i=0;
	cin >> n >> q;
	for(int i = 1;i<=n;i++){
		cin >> grid + 1;
		for(int j=1;j<=n;j++){
			state[i][j] = (grid[j]=='*');
			if(state[i][j]){
				add(i,j,1);
			}
		}
	}
	while(i<q){
		int op,x0,y0,x1,y1;
		cin >> op;
		if(op == 1){
			cin >> x0 >> y0;
			if(state[x0][y0]){
				state[x0][y0] = false;
				add(x0,y0,-1);
			}
			else{
				state[x0][y0] = true;
				add(x0,y0,1);
			}
		}
		else
		{
			cin >> x0 >> y0 >> x1 >> y1;
			cout << sum(x1,y1)-sum(x1,y0-1)-sum(x0-1,y1) + sum(x0-1,y0-1) << endl ;
		}
		i++;
	}
}