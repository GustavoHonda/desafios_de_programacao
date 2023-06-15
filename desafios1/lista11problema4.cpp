#include <bits/stdc++.h>
#define int long long

using namespace std;

using coord = long double;
const coord EPS = 1e-8;

int sign(coord x) { return (x > EPS) - (x < -EPS); }


struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point p){ return {x + p.x, y + p.y}; }
	inline point operator-(point p){ return {x - p.x, y - p.y}; }
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(tht), this -> p
	inline int ccw(point p){ return sign(*this ^ p); }

};

struct segment {
	point a, b; // a != b
	segment() {} segment(point _a, point _b): a(_a), b(_b) {}
	int ccw(point p){ return((b - a).ccw(p - a));}

};




signed main(){
	int x1,x2,y1,y2,x3,y3;
	cin >>x1 >> y1>>x2 >> y2 >> x3 >> y3;
	point p1 = point(x1,y1),p2 = point(x2,y2),p3 = point(x3,y3); 
	segment s = segment(p1,p2);
	int res = s.ccw(p3);
	if(res == 1){
		cout << "LEFT" << endl;
	}
	else if(res == -1){
		cout << "RIGHT" << endl;
	}
	else{
		cout << "TOWARDS" << endl;
	}
}