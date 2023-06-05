#include <bits/stdc++.h>
#define ll long long

using namespace std;


int i ,S,n,p[2010],v[2010], memo[2010][2010];


int dp(int i , int peso_atual){
		if(memo[i][peso_atual]!= -1)return memo[i][peso_atual];
		if(i==n+1)return 0;
		int ans = 0;
		if(peso_atual +p[i] <= S){
			ans = max(ans,dp(i+1, peso_atual+p[i])+v[i]);
		}
		ans = max(ans,dp(i+1,peso_atual));
		return memo[i][peso_atual] = ans;
}

int main (){
	cin>> n >> S;
	i =0;
	memset(memo,-1,sizeof(memo));
	while(n> 0){
		cin >> p[i] >> v[i];
		i++;
		n--;
	}
	cout << dp(1,0) << endl;
}