#include <bits/stdc++.h>
#define ll long long

using namespace std;


//int 2^31-1
//ll 2^63-1
void teste(ll M, ll N){
	
	ll i,j;
	i = 1; j = 1;
	ll impar, par;
	impar=0; par = 0;
	cout << M <<":" <<  N<< endl;
	while(i <= M){
		while(j<= N){
			if((i+j)%2 == 0){
				//cout << "É par: " ;
				par ++;
			}
			else {
				//cout << "É imp: ";
				impar ++;
			}
			//cout << i+j << "; M: " << i << "; N: " << j << endl;
			j++;
		}
		j = 1;
		i++;
	}
	cout << "impa :" << impar << endl;
	cout << "pare :" << par << endl;
}

ll mdc(ll M, ll N){
	ll r = 1;
	cout << r << " " << M  << " " << N << endl;
	while(r != 0){
		r = M % N;
		M = N;
		N = r;
	}
	return M;
}


void solve(ll M, ll N){
	ll result;
	ll i, j;
	//cout << M << ":" << N << ":" ;
	//if(M == 1 &&  N ==1)cout << 0 << "/" << 1 << endl; 
	// cout << M << N << endl;
	i = (M*N)/2;
	j = (M*N)-i;
	result = mdc(i,i+j);
	//cout << i << j << result;
	cout << i/result << "/" << (i+j)/result << endl;
}

int main(){
	ll M, N,T;
	cin >> T;
	while(T > 0){
		cin >> M >> N;
		solve(M, N);
		T--;
	}
}


//int em vez de ll
// Não esquecer de inicializar variáveis com 0 ou 1

// caso 1 1 1 dá Floating point exception (core dumped)
// caso cout << M << N  << endl; seja descomentado o código funciona no caso 1 1 1