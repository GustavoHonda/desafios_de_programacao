#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    int q;
    int x1;
    int x2;
    int sum;
    int var;
    vector<int> list;
    cin >> n;
    while(n>0){
        cin >> var;
        list.push_back(var);
        n--;
    }
    cin >> q;
    while(q>0){
        sum = 0;
        cin >> x1;
        cin >> x2;
        while(x1 <=x2){
            sum += list[x1];
            x1 += 1;
        }
        cout << sum << endl;
        q--;
    }
}

