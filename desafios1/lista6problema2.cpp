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

ll solve(int n, int w, int t, int r){
	ll result;
	result = v[n];
	//cout << result;
	result = (result * fastpow(v[w], MOD-2)) % MOD;
	//cout << v[w];
	result = (result * fastpow(v[t], MOD -2)) % MOD;
	//cout << result;
	result = (result * fastpow(v[r], MOD-2)) % MOD;
	//cout << result;
	return result % MOD	;
}


int main(){
	int n, w, t, r;
	v[0] = 1;
	for (int i = 1; i < 299; ++i){
		v[i] = (v[i-1]*i) % MOD;
	}
	cin >> n >> w >> t >> r;
	cout << solve(n,w,t,r) << endl;
}