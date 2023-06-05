// https://www.spoj.com/problems/PT07Y/
#include<bits/stdc++.h>
using namespace std;
 
int n, m, jafoi[10010];
vector<int> adj[10010];
 
void DFS(int u){
    jafoi[u]++;
    for(auto v : adj[u]){
        if(jafoi[v] == 0){
            DFS(v);
        }   
    }
}   
 
void solve(){
    cin >> n >> m;
    if(m != n - 1){
        cout << "NO\n";
        return;
    }
    
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    DFS(1);
    for(int i = 1; i <= n; i++){
        if(jafoi[i] == 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main(){
    solve();
} 