#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

vector<ll> v (310,0);

ll fastpow(ll base, ll e){
	if(e == 0) return 1;
	ll resp = fastpow(base,e/2);
	resp = resp * resp % MOD;
	if(e%2 == 1) resp = resp * base % MOD;
	return resp;
}

ll bin(ll a, ll b){
	if(b>a) return 0;
	ll resp = 1;
	resp = v[a];
	resp = resp * fastpow(v[b],MOD-2) % MOD;
	resp = resp * fastpow(v[a-b],MOD-2) % MOD;
	return resp;
}

ll solve(int n, int w, int t, int r){
	ll resp;
	resp = bin(n,w);
	resp = resp * bin(n-w,t) % MOD;
	return resp;
}


int main(){
	int n, w, t, r;
	v[0] = 1;
	for (int i = 1; i <= 305; ++i){
		v[i] = (v[i-1]*i) % MOD;
	}
	cin >> n >> w >> t >> r;
	cout << solve(n,w,t,r) << endl;
}


//Colocar os MOD 
//Ver os limites dos valores