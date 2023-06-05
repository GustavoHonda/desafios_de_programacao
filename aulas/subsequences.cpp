#include <bits/stdc++.h>
#define ll long long

using namespace std;

int memo [1010][1010];
string a,b;


int dp(int i, int j ){

	if(memo[i][j] != -1 )return memo[i][j];

	if(i == a.size()or j == b.size()) return 0;

	int ans = 0;

	if(a[i]== b[j])
		ans = max (and,dp(i+1,j+1)+1);

	ans = max(ans, dp(i+1, j ));

	ans = max(ans , dp (i,j+1));

	return memo[i][j] = ans;

}
int main (){
	memoset(memo,-1,sizeof(memo));
	cin >> a >> b;
	cout << dp(0,0) << endl;
}