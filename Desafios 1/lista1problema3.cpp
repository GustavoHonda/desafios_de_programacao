#include <bits/stdc++.h>

using namespace std;

int ntestes;
int nentradas;

int searchsum(int entradas[],int length){
	int max = 0;
	int sum ;
	for(int i = 1; i<=length;i++){
		for(int j = 0;j+i<=length;j++){
			sum = 0;
			for(int k = j; k-j<i;k++){
				sum = sum + entradas[k];
			}
			if(sum > max){
				max = sum;
			}
		}
	}
	return max;
}

int main(){
	cin >> ntestes;
	while(ntestes >0){
		cin >> nentradas;
		int entradas[nentradas];
		while(nentradas >0){
			cin >> entradas[nentradas-1]; 
			nentradas--;
		}
		int length = sizeof(entradas)/sizeof(int);
		cout << searchsum(entradas,length) << endl;
		ntestes--;
	}
}

