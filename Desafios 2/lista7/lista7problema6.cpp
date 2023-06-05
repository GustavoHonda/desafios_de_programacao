#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base:: sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >>t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size(),ans = n, ans2 = 0;
		for(char i ='a';i<='z';i++){
			int cnt = 0, cnt2 = 0;
			for(int j = 0; j<n;j++){
				if(i == s[j]){
					cnt = max(cnt2,cnt);
					cnt2 = 0;
				}
				else{
					cnt2 ++;
				}
			}
			cnt = max(cnt2,cnt);
			ans = min(ans,cnt);
		}
		int c = 1;
		// int c = __builtin_clz(ans);
		while(ans > 1){
			ans = ans/2;
			c++;
		}
		if(ans == 0){
			cout << 0 << endl;
		}
		else{
			cout << c << endl;
		}
		// cout << (!ans?0:32-c) << endl;
	}
}