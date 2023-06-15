#include <bits/stdc++.h>

using namespace std;

int t;
string mapa;
bool red;
bool green;
bool blue;
bool completed;


int main(){
	cin >> t;
	while(t>0){

		completed = true;
		red = false;
		green = false;
		blue = false;

		cin >> mapa;
		for(int i = 0; i<6;i++){
			if(mapa[i] == 'R' ){
				if(red == false ){
					completed = false;
					i = 6;
				}
				//else{red = false;}
			}
			if(mapa[i] == 'G' ){
				if(green == false){
					completed = false;
					i = 6;
				}
				//else{green = false;}
			}
			if(mapa[i] == 'B'  ){
				if(blue == false){
					completed = false;
					i = 6;
				}
				//else{blue = false;}
			}
			if(mapa[i] == 'r'){
				red = true;
			}
			if(mapa[i] == 'g'){
				green = true;
			}
			if(mapa[i] == 'b'){
				blue = true;
			}
			//cout << mapa[i] ;
		}
		//cout << red << green << blue << endl;
		if(completed){
			cout <<"YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		t--;
	}
}

