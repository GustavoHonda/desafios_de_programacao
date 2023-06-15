#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1100000;
ll n;
ll f[N];
ll q[N],l,r;
ll ans;


//estrutura do retangulo com x y extremos esquerdo superior e o valor ai
struct rect{
	ll x,y,val;
}a[N];


//compara retangulos a e b para ordenar em forma de escadinha da esquerda pra direita de cima pra baixo
bool cmp(rect a, rect b){
	return (a.x == b.x)?(a.y>b.y):(a.x< b.x);
}

// calcula 
double calc(ll x, ll y){
	return 1.0*(f[x]-f[y])/(a[x].x-a[y].x);
}

template <typename T>
void print_array(T arr[], int arr_sz){
	for (int i = 1; i <= arr_sz; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i<=n;++i){
		cin >> a[i].x >> a[i].y >> a[i].val;
	}

	//ordena os retangulos 1 até n em "escadinha"
	sort(a+1,a+1+n,cmp);

	// print_array(f,N);



	for(int i = 1; i<= n;++i){

		//coloca borda esquerda
		while(l<r && calc(q[l], q[l+1])> a[i].y)
			++l;
		
		ll qwq = q[l];

		//calcula o valor da area nos ai
		f[i] = f[qwq]+ a[i].y*(a[i].x - a[qwq].x)-a[i].val;
		

		//atualiza o valor maximo da area 
		ans = max(ans,f[i]);
		
		//realoca borda direita
		while(l<r && calc(q[r-1],q[r])< calc(q[r],i))
			--r;
		
		//
		q[++r] = i;
	}
	cout << ans << endl;
}
