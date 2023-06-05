#include <bits/stdc++.h>

using namespace std;


void solve(long long n){
	long long resultado;
	resultado = (sqrt(8*n+1)-1)/2;
	cout << resultado<<endl;
}

int main(){
	int t;
	long long n;
	cin >> t;
	while(t>0){
		cin >>n;
		solve(n);
		t--;
	}	
}