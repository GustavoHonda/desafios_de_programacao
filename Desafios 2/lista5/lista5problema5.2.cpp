#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define N 500005

ll n,m,ans[N],sz[N],c[N],son[N],cnt[N],sum,mx,nw;
vector<ll> e[N];
void dfs(ll x, ll p){
	sz[x]=1;
	for(ll i: e[x])
		if(i!=p)
			dfs(i,x),son[x] =(sz[son[x]]<sz[i]? i:son[x]),sz[x]+=sz[i];
}

void cal(ll x, ll p, ll s){
	cnt [c[x]]+=s;
	if(cnt[c[x]]>mx)mx=cnt[c[x]],sum=c[x];
	else if(cnt[c[x]] == mx) sum +=c[x];
	for(ll i:e[x]) if(i!=p&& i!=nw) cal(i,x,s);
}

void dfs2(ll x,ll p,ll fc){
	for(ll i: e[x]) if(i!=p&& i!=son[x]) dfs2(i,x,0);
	if(son[x]) dfs2(son[x],x,1),nw = son[x];
	cal(x,p,1),nw=0,ans[x]=sum;
	if(!fc)cal(x,p,-1),sum=0,mx=0;
}

int main(){
	scanf("%lld",&n);
	for(ll i = 1;i<=n;i++) scanf("%lld",&c[i]);
	for(ll i = 1,u,v;i<n;i++) scanf("%lld%lld",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs(1,0),dfs2(1,0,0);
	for(ll i = 1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}

