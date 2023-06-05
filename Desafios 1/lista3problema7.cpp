#include <bits/stdc++.h>
#define lol long long


using namespace std;

int sum_interval(vector<long long> v, int k){
	v.push_back(0);
	int l,r;
	l = 0;
	r = 0;
	int sum = 0;
	int sum2 = 0 ;
	int max = 0;
	while(r<v.size()-1){
		while(sum <= k and r <= v.size()){
			sum += v[r];
			sum2 += v[r] + v[r+1];
			// cout << sum <<  " " << sum2 << endl;
			r +=2;
		}
		// cout << "end w" << endl;
		sum2 -= (sum - k);
		if(max< sum2){
			max = sum2;
			// cout<< "max :" << max << endl;
		}

		sum -= v[l] ;
		sum2 = sum2 + sum -k - v[l] - v[l+1];
		l += 2;
	}
	// cout << "p i a";
	r = 0;
	l = 0;
	sum = 0;
	sum2 = 0;
	while(r<v.size()-1){
		while(sum <= k and r <= v.size()){
			sum += v[r+1];
			sum2 += v[r] + v[r+1];
			// cout << sum <<  " " << sum2 << endl;
			r +=2;
		}
		// cout << "end w" << endl;
		sum2 -= (sum - k);
		if(max< sum2){
			max = sum2;
			// cout<< "max :" << max << endl;
		}

		sum -= v[l+1] ;
		sum2 = sum2 + sum -k - v[l] - v[l+1];
		l += 2;
	}
	cout << max; 
	return 0;
}

void print_vector(vector<long long> v){
	int x;
	for(auto x: v){
		cout << x << " ";
	}
	cout << endl;

}

int main(){
	int  n, k;
	vector<char> v (n,' ');
	vector< long long > interval ;
	char value;
	long long  sum = 0.0;


	cin >> n >> k;
	int  i = 0;
	while(i<n){
		cin >> v[i];
		if(i==0){
			value = v[i];
			sum = 1.0;
		}
		else if(v[i] == value){
			sum += 1.0;
		}
		else{
			interval.push_back(sum);
			sum = 1.0;
			value = v[i];
		}
		i++;

	}
	interval.push_back(sum);

	sum_interval(interval,k);
	//print_vector(interval);
}