#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 1e9 +7;

int memo[1010][1010];
string s[1010];
int dp(int i , int peso_atual){
	if(memo[][] != -1) return memo[][]
	if(i == n or j == n)return 0;
	if(s[i][j] == '*') return 0;
	if(i == n-1 and j == n-1) return 1;
	int ans = 0;
	ans = ans + dp(i,j+1 + dp(i+1,j));
	return memo [i][j] = ans % mod;	
}

int main (){
	memset(memo,-1,sizeof(memo));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cout << dp(0,0) << endl;
}