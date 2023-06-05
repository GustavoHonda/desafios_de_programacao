// https://neps.academy/br/exercise/57
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int t, n, m, a[1010][1010], dist[1010][1010];
pair<int, int> ini, fim;

vector<pair<int, int>> points;

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
    int max = 0;
    while(t>0){
        vector<pair<int, int>> points;
        cin >> n >> m;
        for(int i = 0; i< m; i++){
            for(int j =0; j< n; j++){
                cin >> s;
                if(s == '#'){
                    adj[i][j] = 0;
                }
                else if(s == '.'){
                    points.push_back()
                    adj[i][j] = 1;
                }
            }
        }
        for(int i = 0;i<points.size();i++){
            for(int j =0; j<points.size();j++){
                ini = points[i];
                fim = points[j];
                memset(dist, -1, sizeof(dist));
                dist[ini.first][ini.second] = 1;
                dfs(ini.first, ini.second);
                if(max<dist[fim.first][fim.second]){
                    max = dist[fim.first][fim.second];
                }       
            }
        }
        t--;
    }
}

int main(){
    solve();
}