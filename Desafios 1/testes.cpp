#include <bits/stdc++.h>

using namespace std;

int main(){
	for(int i = 1; i<= 8; i++){
		for(int j = 1;j<=8;j++){
			for(int k = 1; k<= 8; k++){
				for(int l = 1;l<=8;l++){
					char a = 96+i;
					char b = 96 +k;
					cout << a << j << " " << b << l << endl;
				}
			}
		}
	}	
}