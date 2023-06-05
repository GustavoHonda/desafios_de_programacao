#include <bits/stdc++.h>

using namespace std;

long long solve(long long k,long long n,long long a,long long b){
	if(k - b*n <= 0){
		return -1;
	}
	long long fim = n;
	long long inicio = 0;
	long long meio ;
	while(fim>inicio){
		meio = (fim + inicio) / 2;
		//cout << inicio << fim << meio<<endl;
		if(meio*a+(n-meio)*b == k){
			return meio -1;
		}
		if(meio*a + (n-meio)*b <k){
			inicio = meio + 1;
		}
		else{
			fim = meio -1;
		}
	}
	//cout <<inicio<< fim<<meio << endl;
	if(inicio*a+(n-inicio)*b < k){
		return inicio;
	}
	else{
		return inicio-1;
	}
}

int main(){
	long long q;
	long long k;
	long long n;
	long long a;
	long long b;
	long long resposta;
	cin >> q;
	while (q>0){
		cin >> k >> n >> a >> b;
		resposta = solve(k ,n ,a,b);
		cout << resposta << endl;
		q--;
	}
}