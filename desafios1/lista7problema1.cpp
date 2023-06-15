
#include<bits/stdc++.h>
using namespace std;

int t, m,n, adj[1010][1010], aux[1010][1010];
bool marked[1010][1010];
char s;
int count, max;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve(){
    
}

void comp(int adj[][], int a, int b, int aux[][]){
    for(int i = 0;i<4;i++){
        int ii = a + dx[k], jj = b + dy[k];
        if(ii < 0 or ii >= n or jj < 0 or jj >= m) continue;
        if(adj[ii][jj] == 0 and aux [][]) continue;
        count++;
        if(max < count){
            max = count;
        }
        comp(adj, ii,jj);
        count--;
    }
}

int main(){
    max = 0;
    count = 0;
    cin >> t;
    while(t>0){
        cin >> m >> n ;
        for(int i = 0; i< m; i++){
            for(int j =0; j< n; j++){
                marked[i][j] = false;
                cin >> s;
                if(s == '#'){
                    adj[i][j] = 0;
                }
                else if(s == '.'){
                    adj[i][j] = 1;
                }
            }
        }
        for(int i = 0; i< m; i++){
            for(int j =0; j< n; j++){
                if(marked[i][j] == false && adj[i][j] == 1){
                    marked[i][j] = true;
                    comp(adj,i,j);
                }
            }
        }


    }
}