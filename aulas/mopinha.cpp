// https://neps.academy/br/exercise/354
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, peso[N], jafoi[N];
vector<int> adj[N];

void dfs(int x){
    jafoi[x]++;
    peso[x] = 1;
    int menor = 1e9, maior = 0;
    for(auto u : adj[x]){
        if(jafoi[u] == 1) continue;
        dfs(u);
        peso[x] += peso[u];
        menor = min(menor, peso[u]);
        maior = max(maior, peso[u]);
    }
    
    if(maior != 0 and maior != menor){
        cout << "mal\n";
        exit(0);
    }
}

void solve(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    cout << "bem\n";
}

int main(){
    solve();
}