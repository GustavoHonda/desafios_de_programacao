// https://www.spoj.com/problems/PT07Z/

#include<bits/stdc++.h>
using namespace std;
 
int n, m;
vector<int> adj[100100];
 
void DFS(int u, vector<int> &dist){
    for(auto v : adj[u]){
        if(dist[v] == -1){
            dist[v] = dist[u] + 1;
            DFS(v, dist);
        }
    }
    
}   
 
void solve(){
    cin >> n;
    
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> dist(n + 10, -1);
    dist[1] = 0;
    DFS(1, dist);
    
    int ponta = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] > dist[ponta]){
            ponta = i;
        } 
    }
    
    vector<int> dist1(n + 10, -1);
    dist1[ponta] = 0;
    DFS(ponta, dist1);
        
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dist1[i]);
    cout << ans << "\n";
}
 
int main(){
    solve();
} 