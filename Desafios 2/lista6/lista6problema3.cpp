#include <bits/stdc++.h>
#define ll long long

using namespace std;



int t,n,m;
ll r,l,p;

template <typename T>
void print_vect(vector<T> vect){
	for(auto element : vect){
		cout << element.first << " " << element.second << " ";
	}
	cout << endl;
}

int find_time(vector<pair<ll,ll>> v, ll p){
	ll l = 0, r = v.size() - 1, mid;
	while(l <= r){
		mid = (l+r)/2;
		if(v[mid].first==p){
			return mid;
		}
		else if(p < v[mid].first){
			r = mid - 1;
			
		}
		else{
			l = mid + 1;
		}
	}
	return l;
}

int main(){
	vector<pair<ll,ll>> v;
	cin >> t;
	// v.push_back({0,0});
	while(t--){
		v.clear();
		cin >> n >> m;
		while(n--){
			cin >> r >> l;
			v.push_back({r,l});
		}
		sort(v.begin(), v.end());
		// print_vect(v);
		while(m--){
			cin >> p;
			pair<ll,ll> pair = {p,0};
			// int id = find_time(v,p);
			int id = lower_bound(v.begin(),v.end(),pair)-v.begin() ;
			if (id == 0){
	            cout << v[0].first - p << "\n";
	        }
	        else {
	            int a = -1;
	            if (v[id-1].second>p){
	            	a = 0;
	           	}
	            else if(id < v.size()){
	                a = v[id].first - p;
	            }
	            cout << a << "\n";
	        }
		}
	}

}