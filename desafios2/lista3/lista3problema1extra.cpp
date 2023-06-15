#include <bits/stdc++.h>
#define ll long long

using namespace std;



vector<vector<ll>> v_seg;
int n;


void build(int k) {
	for (int i = n - 1; i; i--) v_seg[k][i] = v_seg[k][2*i] + v_seg[k][2*i+1];
}

void query(int k,int a, int b) {
	ll ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret += v_seg[k][a];
		if (b % 2 == 0) ret += v_seg[k][b];
	}
	cout << ret << endl;
}

void update(int k,int p, ll x) {
	v_seg[k][p += n] = x;
	while (p /= 2) v_seg[k][p] = v_seg[k][2*p] + v_seg[k][2*p+1];
}

void add(int k){
	vector<ll> v(v_seg[k]);
	v_seg.push_back(v);
}

void solve(int command, int k, int a, int b, ll x){
	k = k-1;
	a = a-1;
	b = b-1;
	if(command == 1){
		update(k,a,x);
	}
	if(command == 2){
		query(k,a,b);
	}
	if(command == 3){
		add(k);
	}
}


int main(){
	int q,t,i = 0,command, k, a, b;
	ll x;
	cin >> n >> q;
	vector<ll> v(2*n,0);
	while(i<n){
		cin >> t;
		v[n+i] = t;
		i++;
	}
	v_seg.push_back(v);
	build(0);
	i=0;
	while(i< q){
		cin >> command;
		cin >> k;
		if(command == 1){
			cin >> a;
			cin >> x;
		}
		if(command == 2){
			cin >> a;
			cin >> b;
		}
		solve(command,k,a,b,x);
		i++;
	}
}