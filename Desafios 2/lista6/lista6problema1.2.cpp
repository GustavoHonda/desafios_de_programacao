#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,x,y, result;
	

	while(cin >> n){
		// cout << "loop" << endl;
		if(n == 0){
			break;
		}
		
		vector<pair<int,int>> points;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			points.push_back({x,y});
		}
		int res = 1;
		for (int i = 0; i < points.size(); i++){
			map<pair<int,int>,int> lines;
			for(int j = i+1;j<points.size();j++){
				int x = points[j].first-points[i].first;
				int y = points[j].second-points[i].second;
				if(x == 0 && y ==0){
					continue;
				}
				if(y ==0){
					tie(y,x) = make_pair(0,-1);
				}
				else if(x == 0){
					tie(y,x) = make_pair(-1,0);
				}
				else{
					int g = __gcd(x, y);

            		y /= g;
            		x /= g;
				}
				lines[{y,x}]++;	
			}
			for(auto j: lines){
				res = max(res,j.second +1);
			}
		}
		cout << res << endl;
	}
}