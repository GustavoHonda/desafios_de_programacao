#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,m,k;
    cin >> n >> m >> k ;
    vector<long long> v (n);
    vector<long long> operands (n+1,0);
    vector<long long> l (m),r (m),d (m);
    vector<long long> operands2(m+1,0);
    vector<long long> x (k),y (k);
    long long stamp = 0;
    long long inicio,fim;
    long long i = 0;
    while(i<n){
        cin >> v[i];
        i++;
    }
    i = 0;
    while(i<m){
        cin >> l[i];
        cin >> r[i];
        cin >> d[i];
        i++;
    }
    i = 0;
    while(i<k){
        cin >> x[i];
        cin >> y[i];
        i++;
    }
    
    i=0;
    while(i<k){
        inicio = x[i]-1;
        fim = y[i];
        operands2[inicio] += 1;
        operands2[fim] -=1;
        i++;
    }

    i = 0;
    while(i<m){
        operands2[i] = operands2[i]+stamp;
        stamp = operands2[i];
        i++;
    }
    
    i=0;
    while(i<m){
        inicio = l[i]-1;
        fim = r[i];
        operands[inicio]+=d[i]*operands2[i];
        operands[fim]-=d[i]*operands2[i];
        i++;
    }

    i = 0;
    stamp = 0;
    while(i < n){
        operands[i] = operands[i]+stamp;
        stamp = operands[i];
        operands[i] += v[i];
        cout << operands[i] << " ";
        i++;
    }
}
