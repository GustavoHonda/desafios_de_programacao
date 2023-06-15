#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int B =450;

int ANS, freq[1000000],a[200005];

struct Query{
	int i,l,r,block;

	Query(){}
	Query(int index, int left, int right){
		i = index;
		l = left;
		r = right;
		block = 1/B;
	}

	bool operator < (const Query& other){
		if(block == other.block){
			if(block & 1){
				return r < other.r;
			}
			else{
				return r > other.r;
			}
		}
		return (block < other.block);
	}

	// bool operator < (Query other)  const{
	// 	return make_pair(l/B,r) < make_pair(other.l /B,other.r);
	// }
};

void add(int i){
	int& x = a[i];
	if(freq[x] == 0) {
		ANS++;
	}
	freq[x]++;
}

void remove(int i){
	int& x = a[i];
	freq[x]--;
	if(freq[x] == 0){
		ANS--;	
	} 
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n,q,i,l,r;
	ANS = 0;

	cin >> n >> q;
	

	set<int> st;	
	for(i = 0;i <n;++i){
		cin >> a[i];
	 	st.insert(a[i]);
	}



	map<int,int> mp;i = 0;
	for(int element: st ){
		mp[element] = i;
		i++;	
	} 
	for(i = 0; i< n;++i){
		a[i] = mp[a[i]];
	}

	vector<Query> queries(q);
	for(i = 0;i< q;++i){
		cin >> l >> r;
		queries[i] = Query(i,l-1,r-1);
	}

	sort(queries.begin(),queries.end());

	vector<int> answers(q);
	l =0;r = -1;
	for(auto element : queries){
		while(l >element.l){
			l--;
			add(l);
		}
		while(r <element.r){
			r++;
			add(r);	
		} 
		while(l <element.l){
			remove(l);
			l++;	
		} 
		while(r >element.r){
			 remove(r);
			 r--;	
		}
		answers[element.i] = ANS;
	}

	for(i = 0; i< q; ++i){
		cout << answers[i] << endl;
	}
}