#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int N= 2e5 +10;
ll node[N*60];
int a[N],his[N], cnt = 1, lef[N*60],rit[N*60],dem;

inline void cop(int x, int y){
	lef[x] = lef[y], rit[x] = rit[y], node[x] = node[y];
}

void build(int x, int lx, int rx){
	if(lx == rx){
		node[x] = a[lx];
		return;
	}
	int m = (lx + rx) >> 1;
	if(lef[x] == 0) lef[x] = ++dem;
	if(rit[x] == 0) rit[x] = ++dem;
	build(lef[x], lx, m);
	build(rit[x], m+1,rx);
	node[x] = node[lef[x]] + node[rit[x]];
}

void upd(int x, int lx, int rx, int pos, int val){
	if(lx == rx){
		node[x] = val;
		return;
	}
	int m = (lx+rx) >> 1;
	if(pos <= m) {
		cop(++dem,lef[x]);
		lef[x] = dem;
		upd(lef[x],lx,m,pos,val);
	}
	else{
		cop(++dem,rit[x]);
		rit[x] = dem;
		upd(rit[x], m+1,rx,pos,val);
	}
	node[x] = node[lef[x]] + node[rit[x]];
}

ll get (int x, int lx, int rx, int l, int r){
	if(lx > r || rx < l) return 0;
	if(l <= lx && rx <= r) return node[x];
	int m = (lx+rx) >> 1;
	ll t1 = get(lef[x],lx,m,l,r);
	ll t2 = get(rit[x],m+1,rx,l,r);
	return t1 +t2;
}

void solve(){
	int n,q;

	cin >> n >> q;

	for(int i = 1;i<=n ; i++){
		cin>> a[i];
	}
	build(his[1],1,n);
	while(q--){
		int type,k,a,b;
		cin >>type >> k;
		if(type == 1){
			cin >> a >> b;
			upd(his[k],1,n,a,b);
		}
		if(type == 2){
			cin >> a >> b;
			cout << get(his[k],1,n,a,b) << endl;
		}
		if(type == 3)  { 
			his[++cnt] = ++ dem;
			cop(dem,his[k]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen("cf.inp", "r")){
		freopen("cf.inp","r", stdin);
	}
	solve();
}