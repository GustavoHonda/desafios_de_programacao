#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;


priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> fila;
int ID[MAXN+1];
int SZ[MAXN+1];
int n,m;


int find(int a){
    if(ID[a] == a) return a;
    return ID[a] = find(ID[a]);
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    
    if(SZ[a] < SZ[b]) swap(a, b);
    ID[b] = a;
    SZ[a] += SZ[b];    
}

int solve(){
	int count = 0, cost = 0;
	while(count< n-1 and fila.size()> 0){
		pair<int,pair<int,int>>p = fila.top();
		int wei = p.first;
		int x = p.second.first;
		int y = p.second.second;
		fila.pop();
		if(find(x) != find(y)){
			count++;
			cost += wei;
			merge(x,y);
			
		}
	}
	return cost;
	
}

int main(){
	int x,y,w,ans;
	cin >> n >> m;
	for(int i = 1; i<=n;i++){
		ID[i] = i;
		SZ[i] = 1;
	}
	while(m--){
		cin >> x >> y >> w;
		fila.push({w,{x,y}});
	}

	ans = solve();
	cout << ans << endl;

}