#include <bits/stdc++.h>

using namespace std;

double dist(int x1,int y1, int x2,int y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
	int n, m;
	int x1,x2,y1,y2,x3,y3;
	cin >> n;
	int count = 0;

	while(n--){
		cin >>x1 >> y1>>x2 >> y2 >> x3 >> y3;
		int a,b,c, res;
		a = dist(x1,y1,x2,y2);
  		b = dist(x1,y1,x3,y3);
    	c = dist(x3,y3,x2,y2);
		res = max(a,b);
		res = max(res,c);
		res = res*2;
		if(res == a+b+c){
			count++;
		}
	}
	cout << count << endl;
}