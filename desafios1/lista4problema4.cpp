#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll x){
	ll count = 0;
	ll i = 5;
	while ( x / i >= 1 ){
        count += x / i;
        i *= 5;
	}
	return count;
}

int main(){
	ll t, n;
	cin >> t ;
	while(t> 0){
		cin >> n;
		n = solve(n);
		cout << n << endl;
		t--;
	}
}