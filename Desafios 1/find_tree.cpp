#include <bits/stdc++.h>
#define ll long long 

const ll MAXN = 100000;
const ll logN = 20;
ll n, q;

using namespace std;

bool check[MAXN];
vector< pair<int,int>> filhos[MAXN];
vector<pair<int,int>> v [MAXN];

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



int main(){
	for(auto x : filhos){
		x.clear();
	}
	cin >> n ;
	for(int i = 1; i<=n;i++){
		int a,b,peso;
		cin >> a >> b >> peso;
		v[a].push_back({b,peso});
	}
	tree();
	for(int i = 1; i<=n;i++){
		cout << i << endl;
		for(auto x : filhos[i]){
			cout <<" " <<  x.first << " ";
		}
		cout << endl;
	}
}