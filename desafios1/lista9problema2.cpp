#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000000;

vector<int> ID(MAXN,0);

int n,m;
int num;


int find(int a){
    if(ID[a] == a) return a;
    return ID[a] = find(ID[a]);
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    ID[b] = a;
    num--;
}

int main(){
	cout << "start" << endl;
	ios_base::sync_with_stdio(0);cin.tie(0);
	int x,y;
	cin >> n >> m;
	num = n;
	for(int i = 1; i<=n;i++){
		ID[i] = i;
	}
	while(m--){
		cin >> x >> y ;
		merge(x,y);

	}
	cout << num << endl;

}