// https://cses.fi/problemset/task/1668/
#include<bits/stdc++.h>
using namespace std;
 
int n, m, cor[100010];
vector<int> adj[100100];
 
void DFS(int u){
    for(auto v : adj[u]){
        if(cor[v] == 0){
            if(cor[u] == 1) cor[v] = 2;
            else cor[v] = 1;
            DFS(v);
        }
        if(cor[u] == cor[v]){
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
    
}   
 
void solve(){
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        if(cor[i] == 0){
            cor[i] = 1;
            DFS(i);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << cor[i] << " ";
    
}
 
int main(){
    solve();
}