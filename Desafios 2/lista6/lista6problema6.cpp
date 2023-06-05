#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
// Rescue Nibel!
using namespace std;

ll n,k,start,stop;

vector<ll> factorial;

template <typename T>
void print_vect(vector<T> vect){
	for(auto element : vect){
		cout <<"("<< element.first << "," << element.second << ") ";
	}
	cout << endl;
}

ll calc_factorial(ll n){
 	int sz = factorial.size()-1;
 	if(sz < n){
 		while(sz < n){
 			factorial.push_back((factorial[sz]*(sz+1)) % mod);
 			sz++;
 		}
 	}
 	return factorial[n];
}

ll expo(ll a, ll  b) {
	ll res = 1; 
	while (b > 0) {
		if (b & 1)res = (res * a) % mod;
		a = (a * a) % mod;
		b = b >> 1;
	}
 	return res;
}

ll calc_comb(ll n, ll k){
 	ll numer = calc_factorial(n) % mod;
 	ll denom = ( calc_factorial(n-k)*calc_factorial(k)) % mod;
 	ll num = expo(denom,mod-2);
 	return (numer*num) % mod;
}

int main(){
	vector<pair<ll,ll>> v;
	factorial.push_back({1});
	cin >> n >> k;
	int i = 0;
	while(i<n){
		cin >> start >> stop;
		v.push_back({start,0});
		v.push_back({stop,1});
		i++;
	}
	sort(v.begin(),v.end());

	int lanters= 0;
	ll ans = 0;
	for (auto element : v){
		if(element.second == 0){
			lanters++;
		}
		else{
			if(lanters >= k){
				ans = ( ans + calc_comb(lanters-1,k-1)) % mod;
			}
			lanters--;
		}
	}
	cout << ans << endl;

}