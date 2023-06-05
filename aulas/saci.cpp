// https://neps.academy/br/exercise/57
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m, a[1010][1010], dist[1010][1010];
pair<int, int> ini, fim;

void dfs(int i, int j){
    for(int k = 0; k < 4; k++){
        int ii = i + dx[k], jj = j + dy[k];
        if(ii < 1 or ii > n or jj < 1 or jj > m) continue;
        if(a[ii][jj] == 0) continue;
        
        if(dist[ii][jj] == -1){
            dist[ii][jj] = dist[i][j] + 1;
            dfs(ii, jj);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2)
                ini = make_pair(i, j);
            if(a[i][j] == 3)
                fim = make_pair(i, j);
        }
    }
    memset(dist, -1, sizeof(dist));
    dist[ini.first][ini.second] = 1;
    dfs(ini.first, ini.second);
    cout << dist[fim.first][fim.second] << "\n";
}

int main(){
    solve();
}