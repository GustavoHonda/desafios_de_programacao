#include <bits/stdc++.h>
#define ll long long 

const ll infinite = 1e12;
const ll N = 100000;

using namespace std;




struct Node{
    // menor elemento e a frequencia que ele aparece
    ll menor;

    Node(){
        menor = infinite;
    }

    Node(ll x){
        menor = x;
    }

    Node operator + (const Node &o) const{
        if(menor < o.menor) return *this;
        if(o.menor < menor) return o;

        Node ans;
        ans.menor = menor;
        return ans;
    }
};

Node node[4 * N];
ll score[N];

void build(ll no, ll ini, ll fim){
    // O(n)
    if(ini == fim){
        node[no] = Node(score[ini]);
        return;
    }
    ll meio = (ini + fim) / 2;
    build(2 * no, ini, meio);
    build(2 * no + 1, meio + 1, fim);
    node[no] = node[2 * no] + node[2 * no + 1];
}

Node qq(ll no, ll ini, ll fim, ll l, ll r){
    if(fim < l or r < ini) return Node();
    if(l <= ini and fim <= r) return node[no];
    ll meio = (ini + fim) / 2;
    return qq(2 * no, ini, meio, l, r) + qq(2 * no + 1, meio + 1, fim, l, r);
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll t, n,q,a,b,i,j;
	cin >>t;
	i = 1;
	while(i<=t){
		cout << "Scenario #" << i << ":" << endl;
		cin >> n >>q;
		j=1;
		while(j<=n){
			cin >> score[j];
			j++;
		}
		build(1, 1, n);
		while(q--){
			cin >> a >> b;
			auto ans = qq(1, 1, n, a, b);
			cout << ans.menor << endl;
		}
		i++;
	}
}