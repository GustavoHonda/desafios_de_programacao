#include <bits/stdc++.h>

using namespace std;

#define fi first 
#define se second 
#define mp make_pair
#define pii pair<int, int>
#define ll long long 

const int MAXN = 200010;
const int LOGN = 20;
const int MAXQ = 2*200010;

int nextNode = 0;
int root[MAXQ];
int seg[4*MAXN + LOGN*MAXQ];
int L[4*MAXN + LOGN*MAXQ];
int R[4*MAXN + LOGN*MAXQ];
int x[MAXN];

int build(int l, int r){
	int node = nextNode++;

	if(l == r){
		seg[node] = x[l];
		return node;
	}

	int m = (l+r)/2;

	L[node] = build(l,m);

	R[node] = build(m+1,r);

	seg[node] = seg[L[node]] + seg[R[node]];

	return node;
}

int upd(int refNode, int l, int r, int pos, int v){
	int node = nextNode++;

	if(l == r){
		seg[node] = v;
		return node;
	}

	int m = (l+r)/2;
	if(pos <= m){
		R[node] = R[refNode];
		L[node] = upd(L[refNode], l, m, pos, v);
	}else{
		L[node] = L[refNode];
		R[node] = upd(R[refNode], m+1, r, pos, v);
	}

	seg[node] = seg[L[node]] + seg[R[node]];

	return node;
}

int query(int node, int l, int r, int b, int e){

	// printf("node : %d l: %d r :%d b: %d e: %d \n",node,l,r,b,e);

	if(e < l || r < b) return 0;

	if(b <= l && r <= e) return seg[node];

	int m = (l+r)/2;

	return query(L[node],l,m,b,e) + query(R[node], m+1, r, b, e);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q;

	cin >> n >> q;

	root[0] = build(1,n);

	map <int, int> last;
	for(int i=1; i<=n; i++){
		cin >> x[i];

		int baseRoot = root[i-1];
		if(last.find(x[i]) != last.end()){
			baseRoot = upd(baseRoot, 1, n, last[x[i]], 0);
		}
		root[i] = upd(baseRoot, 1, n, i, 1);

		last[x[i]] = i;
	}


	for(int i = 0; i<q; i++){
		int a, b; cin >> a >> b;
		// cout << "loop" << endl;
		cout << query(root[b], 1, n, a, b) << "\n";
	}
}