#include <bits/stdc++.h>
#define ll long long 

const ll N = 100000;

using namespace std;




struct Node{
    // menor elemento e a frequencia que ele aparece
    ll menor;

    Node(){
        menor = 1;
        // menor = 2;
    }

    Node(ll x){
        menor = x;
    }

    Node operator + (const Node &o) const{
        if(o.menor > 0 && menor > 0) return o;
        if(o.menor > 0 && menor < 0) return *this;
        if(o.menor < 0 && menor > 0) return o;
        if(o.menor < 0 && menor < 0) {
            Node ans;
            ans.menor = 1;
            return ans;            
        }
        if(o.menor == 0 || menor == 0) {
            Node ans;
            ans.menor = 0;
            return ans;            
        }else{
            return *this;
        }
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

void update(int no, int ini, int fim, int k, int valor){
    if(ini == fim){
        node[no] = Node(valor);
        return;
    }
    int meio = (ini + fim) / 2;
    if(k <= meio) update(2 * no, ini, meio, k, valor);
    else update(2 * no + 1, meio + 1, fim, k, valor);
    node[no] = node[2 * no] + node[2 * no + 1];
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,q,a,b,j,val;
    char s;
    while(cin >> n >> q){
        j=1;
        while(j<=n){
            cin >> val;
            if(val > 0){
                score[j] = 1;    
            }
            else if(val < 0){
                score[j] = -1;
            }
            else{
                score[j] = 0;
            }
            j++;
        }
        build(1, 1, n);
        while(q--){
            cin >> s;
            if(s == 'P'){
                cin >> a >> b;
                auto ans = qq(1, 1, n, a, b);
               // cout << ans.menor ;   
                if(ans.menor < 0){
                    cout << '-';
                }else if(ans.menor > 0){
                    cout << '+';
                }
                else{
                    cout << '0';
                }
            }
            if(s == 'C'){
                cin >> a >> b;
                if(b > 0){
                    update(1, 1, n, a, 1);
                }
                else if(b < 0){
                    update(1, 1, n, a, -1);
                }
                else{
                    update(1, 1, n, a, 0);
                }
                
            }
            // cout << "score" << s << endl;
            // for (int i = 1; i <20; ++i)
            // {
            //     cout << node[i].menor;
            // }
            // cout << endl;
        }
        cout << endl;
    }
}