#include <bits/stdc++.h>
#define ll long long

using namespace std;



ll bin(ll a, ll b){
    if(b > a / 2) b = a - b;
    ll ans = 1;
    for(ll i = 0; i < b; i++){
        ans = ans * (a - i) / (i + 1);
    }
    return ans;
}

ll solve (ll n, ll k){
	return bin(n-1,k-1);
}

int main(){
	ll t,n,k;
	cin >> t;
	while(t>0){
		cin >> n >> k;
		cout << solve(n,k) << endl;
		t--;
	}
}

//bin(n,k) = (n/k)* bin(n-1, k-1) <- usar essa propriedade para resolver o problema
//fazer funcao bin()
// k < n
// bin(n,k) = (n/k)*...*(n-k+2/2)* bin(n-k+1,1)

// caso 1000000 1000000 está dando errado overflow