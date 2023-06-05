#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using ll = long long;

const int B = 450;
int a[200005],freq[1000000];
int ANS;

struct Query{
	int i, l, r, block;

	Query(){}
	Query(int i, int l, int r):i(i),l(l),r(r){
		block = 1/B;
	}

	bool operator < (const Query& other){
		if(block == other.block) return ((block & 1) ? ( r < other.r) : (r > other.r));
		return (block < other.block);
	}
};

void reset(){
	ANS = 0;
}

void include(int i){
	int& x = a[i];
	if(freq[x] == 0) ++ANS;
	++freq[x];
}

void exclude(int i){
	int& x = a[i];
	--freq[x];
	if(freq[x] == 0) --ANS;
}

ll get_ans(){
	return ANS;
}

int main(){
	FAST;

	int n, q, i, l, r, qi ,ql, qr;
	cin >> n >> q;
	reset();

	set<int> st;
	for(i = 0; i < n; ++i){
		cin >> a[i];
	 	st.insert(a[i]);
	}
	
	map<int,int> mp;
	i = 0;
	for(int z : st ) mp[z] = i++;
	for(i = 0; i< n; ++i) a[i] = mp[a[i]];

	vector<Query> queries(q);
	for(i = 0; i < q; ++i){
		cin >> l >> r;
		--l; --r;
		queries[i] = Query(i,l,r);
	}
	sort(queries.begin(), queries.end());

	vector<int> ans(q);
	l = 0; r = -1;
	for(i = 0; i < q; ++i){
		Query query = queries[i];
		qi = query.i;
		ql = query.l;
		qr = query.r;

		while(l > ql) include(--l);
		while(r < qr) include(++r);
		while(l < ql) exclude(l++);
		while(r > qr) exclude(r--);

		ans[qi] = get_ans();
	}

	for(i = 0; i < q; ++i) cout << ans[i] << "\n";

	return 0;
}