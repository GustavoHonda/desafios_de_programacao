#include <bits/stdc++.h>
using namespace std;
pair<int,int> rest[100010];



void solve(){
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        int l,r; cin >> l >> r;
        rest[i] = {l,r};
    }
    sort(rest,rest+n);

    for (int i=0;i<m;i++){
        int p; cin >> p;
        int id = lower_bound(rest,rest+n,make_pair(p,0)) - rest;
        if (id == 0){
            cout << rest[0].first - p << "\n";
        }
        else {
            int a = -1;
            if (rest[id-1].second>p) a = 0;
            else if(id < n){
                a = rest[id].first - p;
            }
            cout << a << "\n";
        }
    }
}

    
int main(){
    int t; cin >> t;
    while (t--) solve();
}