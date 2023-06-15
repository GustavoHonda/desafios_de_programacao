#include <bits/stdc++.h>

using namespace std;


int two_pointers(vector<int> v, int k){
    int l ,r;
    int sum = 0;
    l = 0;
    r = 0;
    while(l < v.size()){
        while(v[r] < v[l]+k){
            r++;
            //cout << v[l] << " "<< v[r] << endl; 
        }
        if(v[r]-v[l] == k){
            sum++;
        }
        l++;
    }
    return sum;
}

int main(){
    int n , k;
    cin >> n >> k;
    int sum = 0;
    vector<int> v;
    int var;
    while(n>0){
        cin >> var;
        v.push_back(var);
        n--;
    }
    sort(v.begin(),v.end());
    cout << two_pointers(v, k) << endl;
}
