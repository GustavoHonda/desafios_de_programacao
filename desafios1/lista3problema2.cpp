#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    map<int,int> m;
    vector<int> v;
    while(cin >>x){
        if(m.count(x) == 0){
            v.push_back(x);
        }
        m[x]+=1;
    }
    for(auto x : v){
        cout<< x  << ' ' << m[x] << endl; 
    }
    
}

