#include <bits/stdc++.h>
#define int long long

using namespace std;



using coord = long double;
const long double pi = acos(-1);
const coord EPS = 1e-8;

// Retorna o sinal de x
// Retorna -1 se x < 0, 0 se x == 0 ou 1 se x > 0
int sign(coord x) { return (x > EPS) - (x < -EPS); }

coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point p){ return {x + p.x, y + p.y}; }
	inline point operator-(point p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point p){ x = p.x, y = p.y; }
		
	// Produto Escalar
	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(tht)
	
	// Produto Vetorial
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(tht), this -> p

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  1 left, 0 over, -1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){ return point(-y, x);}
	
	// Rotação por angulo "ang"
	inline point rot(long double ang){ 
		return point(cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y); 	}
		
	
	inline point project(point p){
		return p * (((*this) * p)/p.norm2()); 
	}
	
	inline bool operator<(point &p){ 
		return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; 
	} // lex_sort
	inline bool operator==(point p){ 
		return sign(x - p.x) == 0 and sign(y - p.y) == 0; 
	}

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};


void swap(point &a, point &b){ point aux = a; a = b; b = aux; }

struct line {
	point p; coord c; //(x, y) is in the line if p * (x,y) = c
	line() {} line(point _p, coord _c): p(_p), c(_c) {}
	
	// Construtor de uma reta que passa por "a" e "b"
	line(point a, point b) : p((b - a).rot90()), c(p * a) {}
	
	// Retorna a reta paralela que passa pelo ponto v
	line get_parall(point v){ return line(p, p * v); }
	
	// Retorna a reta perpendicular à reta
	line get_perp(){ return line(p.rot90(), c); }// perpendicular line

	bool contains(point v){ return sign(p * v - c) == 0; }

	
	bool intsec(line l){ return sign(p ^ l.p) != 0; } // false if is the same line

	coord dist(point v){ return abs(p * v - c) / p.norm(); }
	
	// parallel lines result in division by zero
	point get_intsec(line l){ 
		coord d = p^l.p; 
		return point((c*l.p.y - l.c*p.y)/d, (p.x*l.c - c*l.p.x)/d); 
	}
};

struct circle{
	point c; coord r;
	circle() {} circle(point _c, coord _r): c(_c), r(_r) {}
	
	bool intsec(circle b){ // circunference
		return ((sign((c - b.c).norm() - (r + b.r)) <= 0) and 
		(sign((c - b.c).norm() - fabs(r - b.r)) >= 0)); }

	bool contains(point p){
		return (sign((p - c).norm2() - r*r) <= 0);
	}
	
	vector<point> get_intsec(line l){ 
		coord d = l.dist(c);
		if (sign(d - r) > 0) return {};
		point proj = l.get_intsec((l.get_perp()).get_parall(c)); // prection of the center in the line 
		if (sign(d - r) == 0)return {proj};
		point aux = ((l.p).rot90()/(l.p.norm())) * sqrt(r * r - d * d);
		return {proj + aux, proj - aux};
	}	

	vector<point> get_intsec(circle o){
		if ((*this).intsec(o) == 0) return {};
		long double d2 = (c - o.c).norm2();
		long double tht = acos((r*r + d2 - o.r*o.r) / sqrt(4.0*r*r*d2));
		point vec = ((o.c - c)/(o.c - c).norm()) * r;
		return {c + vec.rot(tht),c + vec.rot(-tht)};
	}

	vector<point> get_tan(point p){ // tangent points
		long double d2 = (c - p).norm2();
		if (sign(d2 - r * r) < 0) return {};
		if (sign(d2 - r * r) == 0) return {p};
		long double tht = acos(sqrt((r*r)/d2));
		point vec = ((p - c)/(p - c).norm()) * r;
		return {c + vec.rot(tht),c + vec.rot(-tht)};
	}
};	



double dist(double x1,double y1, double x2,double y2){
	return hypot(x1-x2,y1-y2);
}

signed main(){
	int r, x,y,x1,y1,x2,y2;
	cin >>r >> x >>y >>x1 >>y1 >>x2 >>y2;
	point p = point(x,y);
	point p1 = point(x1,y1);
	point p2 = point(x2,y2);
	circle c = circle(p,r);
	line l = line(p1,p2);
	vector<point> v = c.get_intsec(l);
	if(v.size() == 0){
		cout << -1 << endl;
	}else if(v.size() == 1){
		cout << 0 << endl;
	}
	else{
		p1 = v[0];
		p2 = v[1];
		double res = dist(p1.x,p1.y,p2.x,p2.y);
		std::cout << std::setprecision(5) << std::fixed;
		cout << res << endl;
	}
	
	
}