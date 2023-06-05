#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool prime(ll x){
	for(ll i = 3; i<x; i ++){
		if(x % i == 0 ){
			return false;
		}
	}
	return true;
}

void solve(ll m,ll n){
	
	if(m < 2){
		m = 2;
	}

	if(m == 2 ){
		cout << 2 << endl;
		m++;
	}
	if(m % 2 == 0){
		m++;
	}
	//cout <<  " aaaa" << endl;
	for(ll i = m; i<= n; i +=2){

		if(prime(i)){
			cout << i << endl;
		}
	}

}

int main(){
	ll t, m,n;
	cin >> t ;
	while(t>0){
		cin >> m >> n ;
		//cout << m << n << endl;
		solve (m,n);
	 	cout << endl;
		t--;
	}
}