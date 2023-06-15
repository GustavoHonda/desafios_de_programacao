#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353

using namespace std;

ll len;


ll mdc(ll a, ll b){
	ll r = 1;
	//cout << a << b << endl;
	while(r > 0){
		//cout << r << endl;
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

ll gcd(vector<ll> v){
	for(int i =0;i<len;i++){
		v[i] *= i;
	}
	for(int i = 1;i<len-1;i++){
		v[i+1] = mdc(v[i],v[i+1]);
	}
	return v[len-1];
}

vector<ll> exch(vector<ll> v, ll i, ll j){
	ll var = v[i];
	v[i] = v[j];
	v[j] = var;
	return v;
}

void print(vector<ll> v){
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] ;
	}
	cout << endl;
}

ll permute( vector<ll> v , int k)
{
   int count;
   count = 0;
   if (k == len) {
   		print(v);
   		if(gcd(v)!=1){
   			count ++;
   		}
   } else {
      for (int i = k; i < len; i++) {
         v = exch( v, k, i);
         permute( v, k + 1);
         v = exch( v, i, k);
      }
   }
   return count;
}


ll solve(ll n){
	vector<ll> v(n,0);
	len = n;
	for(int i=1; i< len;i++){
		v[i]=i;
	}
	return permute(v,0);	
}


int main(){
	ll t, n;
	cin >> t;
	while(t>0){
		cin >> n;
		cout << solve(n) << endl;
		t--; 
	}
}