#include <bits/stdc++.h>
#define ll long long
#define lim 100

using namespace std;

vector<bool> v(lim,true);
vector<bool> v2(lim,false);


bool solve(ll n){
	for(int i = 4; i <= n-4; i++){
		if(v2[i] && v2[n-i]){
			return true;
		}
	}
	return false;
}

void primes(){
	v[0] = false;
	v[1] = false;
	for(int i =2;i*i <= lim; i ++){
		if(v[i]){
			for(int j = i*i; j <= lim; j+=i){
				v[j] = false;
			}
		}
	}
}

void find_semi_primes(){
	primes();
	for(int i = 2; i < lim; i++){
		for(int j = i;j <= lim;j++){
			if(v[j] && v[i]){
				if(i*j <=200 && i!= j ){
					v2[i*j] = true;
				}
			}
		}
	}
}

int main(){
	ll t, n;
	cin >> t;
	find_semi_primes();
	while(t>0){
		cin >> n;
		//cout << n << " :" ;
		if(solve(n)){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		t--;
	}
}