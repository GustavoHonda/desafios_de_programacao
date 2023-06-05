#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, m;
	int x1,x2,y1,y2,x,y;
	cin >> t;
	int count = 1;
	while(t--){
		cout << "Case " << count << ":" << endl; 
		cin >>x1 >> y1>>x2 >> y2;
		cin >> m;
		while(m --){
			cin >> x >> y;
			if(x1<x and x<x2 and y1<y  and y<y2){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;	
			}
		}
		count ++;
	}
}