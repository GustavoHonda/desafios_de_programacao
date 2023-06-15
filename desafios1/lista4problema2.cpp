#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define lim 10000000

using namespace std;

vector<int> v(lim,0);
ll pos = 0;

bool solve(ll x){
	ll i = 2;
	bool check = false;
	while(i*i <= x){
		if(x%i == 0){
			if(i*i != x){
				//cout << i <<" ao quadrado nao é igual a "<< x << endl;
				return false;
			}
			else{
				check = true;
			}
		}
		i++;
	}
	return check;
}

bool solve2(ll x){
	ll i ;
	//cout << "init solve2 pos :" << pos ;
	while(pos <= x-2){
		if(v[pos] <= 1){
			i =  (pos+2)*2   ;
			while(i <= lim-1){
				//cout << i << endl;
				v[i-2] +=1;
				i += (pos+2);
			}
		}
		pos ++ ;
	}
	//cout << "result : "<<  pos <<  " "<< v[x-2] << " ";
	return v[x-2] == 1;
}

bool solve3(ll x){
	double i = sqrt(x);
	ll j = 2;
	//cout << i;
	if( i== (int)i){
		while(j*j <= i){
			if((int)i%j == 0){
				return false;
			}
			j++;
		}
		return true;
	}
	return false;
}

int main(){
	ll n, x;
	cin >> n;
	bool result;
	while(n>0){
		cin >> x;
		if(x == 1){
			cout << "NO"<< endl;
		}
		else{
			result = solve3(x);
			//cout << x;
			if(result){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		n--;
	}
}