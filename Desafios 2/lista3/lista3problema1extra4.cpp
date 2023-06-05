#include<bits/stdc++.h>
using namespace std;

#define ll long long


// persistent segment tree

ll now = 1, n;
vector<ll> vect;
const ll  N = 2e5;

struct node {
    ll left, right, sum;
} seg[N*40];

void update(ll &root, ll index, ll val, ll low = 0, ll high = n-1) {
    ll mid;
    
    seg[now].left = seg[root].left;
    seg[now].right = seg[root].right;
    seg[now].sum = seg[root].sum + val;
    root = now; now++;

    if (low == high)
        return;


    mid = (low+high)/2;
    if (index <= mid)
        update(seg[root].left, index, val, low, mid);
    else
        update(seg[root].right, index, val, mid+1, high);
}

ll query(ll root, ll a, ll b, ll low = 0, ll high = n-1) {
    ll left_val, right_val, mid;
    if (a<=low && high<=b)
        return seg[root].sum;

    mid = (low+high)/2;
    
    if(a<=mid)
        left_val = query(seg[root].left, a, b, low, mid);
    else
        left_val = 0;
    
    if(mid<b) 
        right_val = query(seg[root].right, a, b, mid+1, high);
    else 
        right_val = 0;
    
    return right_val + left_val;
}

signed main(){
    ll q,x,i = 0,op,k,a,b;
    cin>>n>>q;
    vect.push_back(0);

    for (ll i = 0; i < n; i++) {
        cin>>x;
        update(vect[0], i, x);
    }

    while(i<q) {
        cin>>op;
        cin>>k;
        k--;
        if (op == 1) {
            cin>>a>>x;
            update(vect[k], a-1, x - query(vect[k], a-1, a-1));
        }
        else if (op == 2) {
            cin>>a>>b;
            cout<<query(vect[k], a-1, b-1)<<endl;
        }
        else {
            vect.push_back(vect[k]);
        }
        i++;
    }
}