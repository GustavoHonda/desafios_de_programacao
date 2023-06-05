#include <bits/stdc++.h>

using namespace std;

vector<int> pos;

vector<int> build_lps(string s) {
	int i = 1;
	int len = 0;
	int tam = (int) s.size();
	
	vector<int> lps(tam, 0);
	
	while(i < s.size()){
		if(s[i] == s[len]) {
			lps[i] = len + 1;
			len++;
			i++;
		}
		else if(len != 0){
			len = lps[len - 1];
		}
		else {
			lps[i] = 0;
			i++;
		}
	}
	
	return lps;
}

int kmp(string pat, string text){
	pos.clear();
	string s = pat;
	s.push_back('$');
	
	for(char c : text) 
		s.push_back(c);
	
	vector<int> lps = build_lps(s);
	
	int ocorrencias = 0;
	//cout << s  << endl;
	for(int i = pat.size() + 1; i < s.size(); i++){

		//cout << lps[i] << i << endl;
		if(lps[i] == pat.size()){

			ocorrencias++;

			pos.push_back(i-(pat.size()+1+pat.size()-2));
		}
	}
	
	return ocorrencias;
}

int main(){

	int teste = 0,res;
	string s, t;
	cin >> teste;
	while(teste--){
		cin >> s >> t;
		cout << endl;	
		res = kmp(t, s);
		if(res == 0){
			cout << "Not Found" << endl;
		}else{
			cout << res << endl;
			for(auto x : pos){
				cout << x << " ";
			}	
			cout << endl;
		}
		// if(teste != 0){
			
		// }
	}
	cout << endl;
}
