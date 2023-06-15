#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll mdc(ll a, ll b){
	int res;
	while(b > 0){
		res = a%b;
		a = b;
		b =  res;
	}
	return a;
}

bool check(ll a, ll b, ll G){
	
	if(G == mdc(a,b)){
		return true;
	}
	return false;
}

void solve(ll G, ll M){
	double a,b;
	a = 1;
	while(a*a <= M*G){
		b = (M*G)/a;
		if(b == (int)b ){
			//cout << a << " " << b << endl;
			if(check(a ,b ,G)){
				cout << "G M: " << G << " "<< M << " a, b :" << a << " " << b << endl;
				return;
			}
		}
		a += 1;
	}
	cout << -1 << endl;
	return;
}

int main(){
	ll t,G,M;
	double quo, res;
	cin >> t;
	while(t > 0){
		cin >> G >> M;
		quo = M/G;
		res = M%G;
		if(quo == (int)quo && res == 0){
			cout << G << " " << M << endl;
		}
		else{
			cout << -1 << endl; 
		}
		//solve(G,M);
		t--;
	}
} 

