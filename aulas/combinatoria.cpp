// https://www.spoj.com/problems/ADATEAMS/
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 1000010
#define MOD 1000000007
 
long long fat[MAXN];
 
// Retorna b^e (mod MOD)
// O (log e)
long long fastxp(long long b, long long e){
    if(e == 0) return 1;
    long long resp = fastxp(b, e / 2);
    resp = resp * resp % MOD;
    
    if(e%2 == 1) resp = resp * b % MOD;
    return resp;
}
 
long long bin(long long n, long long k){
    if(k > n) return 0;
    long long resp = 1;
    resp = fat[n];
    resp = resp * fastxp(fat[k], MOD - 2) % MOD;
    resp = resp * fastxp(fat[n - k], MOD - 2) % MOD;
    
    return resp;
}
 
int main(){
    fat[0] = 1;
    for(int i = 1; i < MAXN; i++) 
        fat[i] = fat[i - 1] * i % MOD;
    
    long long n, a, b, d;
    
    while(cin >> n >> a >> b >> d){
        long long resp = bin(n, a);
        resp = resp * fastxp(bin(b, d), a) % MOD;
        cout << resp << endl;
    }
} 