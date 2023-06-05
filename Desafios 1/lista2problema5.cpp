#include <bits/stdc++.h>


using namespace std;



int main(){
	int n;
	long long l;
	int bordergap;
	double result;
	cin >> n ;
	cin >> l;
	vector<long long> lista;
	vector<long long> sub;
	long long var;

	while(n>0){
		cin >> var;
		lista.push_back(var);
		n--;
	}
	sort(lista.begin(), lista.end());
	
	if(lista.size()<2){
		if(lista[0]>l-lista[0]){
			cout << lista[0];
		}
		else{
			cout << l-lista[0];	
		}
	}
	else{
		//for(int i = 0; i < lista.size();i++){
		//	cout << lista[i] << endl;
		//}
		//cout << endl
		for(int i = 0; i<lista.size()-1; i++){
			sub.push_back(lista[i+1]-lista[i]);
		}
		sort(sub.begin(), sub.end());

		//for(int i = 0; i < sub.size();i++){
		//	cout << sub[i] << endl;
		//}
		
		if(lista[0] < l-lista[lista.size()-1]){
			bordergap = l-lista[lista.size()-1];
		}
		else{
			bordergap = lista[0];
		}
		//cout << bordergap << endl;
		result = sub[sub.size()-1]/2.0;
		//cout << result << endl;
		if(bordergap > result){
			result = bordergap;
		}
		cout << setprecision(9) << fixed;
		cout << result << endl;
	}
}