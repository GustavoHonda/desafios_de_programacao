#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> points;


int main(){
	int n,x,y, result;
	map<pair<int,int>,int> lines;

	while(cin >> n){
		if(n == 0){
			break;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			points.push_back({x,y});
		}
		for (int i = 0; i < points.size(); i++){
			int same_points = 0, vertical_points = 0,  max_p = 0;
			for(int j = i+1;j<points.size();j++){
				if(points[i] == points[j]){
					same_points++;
				}
				else if(points[i].first == points[j].first){
					vertical_points++;
				}
				else{
					int x = points[j].first-points[i].first;
					int y = points[j].second-points[i].second;
					int g = __gcd(x, y);
 
                	y /= g;
                	x /= g;

					lines[{x,y}]++;	
					max_p = max(max_p, lines[{x,y}]);
				}
				max_p = max(max_p,vertical_points);
			}
			result = max(result, max_p + same_points + 1);
			lines.clear();
		}
		if(n<2){
			cout << n << endl;
		}else{
			cout << result << endl;
		}
	}
}