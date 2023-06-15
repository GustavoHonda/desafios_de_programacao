#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arrays;

void print_array(){
	cout << "arrays size " << arrays.size() << endl;
	for(vector<int> v : arrays){
		for(int i: v){
			cout << i << " ";
		}
		cout << endl;
	}
}

int solve(int command, int k, int a, int b, int x){
	if(command == 1){
		arrays[k][x]= a;
	}
	if(command == 3){
		vector<int> v(arrays[k-1]);
		arrays.push_back(v);
	}
	print_array();
}

int main(){
	int n, q,t,i = 0,command, k, x, a, b;
	vector<int> v;
	cin >> n >> q;
	while(i<n){
		cin >> t;
		v.push_back(t);
		i++;
	}
	arrays.push_back(v);
	i=0;
	while(i< q){
		cin >> command;
		cin >> k;
		if(command == 1){
			cin >> a;
			cin >> x;
		}
		if(command == 2){
			cin >> a;
			cin >> b;
		}
		solve(command,k,a,b,x);
		i++;
	}
}