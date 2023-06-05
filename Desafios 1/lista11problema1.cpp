#include <bits/stdc++.h>

using namespace std;


double dist(double x1,double y1, double x2,double y2){
	return hypot(x1-x2,y1-y2);
}

int main(){

	double x1,x2,x3,y1,y2,y3,perim = 0, area;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	perim+= dist(x1,y1,x2,y2);
	perim+= dist(x1,y1,x3,y3);
	perim+= dist(x2,y2,x3,y3);
	area = abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
	std::cout << std::setprecision(4) << std::fixed;
	cout << perim << " ";
	cout << area << endl;

}