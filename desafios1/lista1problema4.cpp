#include <bits/stdc++.h>

using namespace std;

int a;
int b;
double y;
double x;
int result;

int main(){
	cin >> a;
	cin >> b;
	if(a >2*b ){
		cout << b << endl;
	}
	else if(b>2*a){
		cout << a << endl;
	}else{
		
		y = (double)(2*a-b)/3;
		x = (double)(2*b-a)/3;
		result = x+y;
		x = x+y;
		if(result > x){
			result = result-1;
		}
		cout << result<< endl;
	}	
}