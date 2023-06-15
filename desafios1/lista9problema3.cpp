#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

vector<int> minim(N);
int n, m, ID[N], SZ[N], menor, maior;

int find(int a){
    if(ID[a] == a) return a;
    return ID[a] = find(ID[a]);
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    
    if(SZ[a] < SZ[b]) swap(a, b);
    ID[b] = a;
    minim[SZ[b]] -= SZ[b];
    minim[SZ[a]] -= SZ[a];
    SZ[a] += SZ[b];
    minim[SZ[a]] += SZ[a];
    


    maior = max(maior, SZ[a]);
    int val = minim[SZ[b]],i = 0;
    if(menor == SZ[b]){
        while(val == 0){
            i++;
            val = minim[SZ[b]+i];
        }
        menor = SZ[b]+i;
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        ID[i] = i;
        SZ[i] = 1;
    }
    maior = 1;
    menor = 1;
    minim[1] = n;
    int x,y;
    for(int i = 1; i <= m; i++){       
        cin >> x >> y;

        merge(x,y);
        cout << maior-menor << endl;
    }
}