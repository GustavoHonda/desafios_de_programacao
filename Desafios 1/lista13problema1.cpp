#include <bits/stdc++.h>

using namespace std;

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
	string s = pat;
	s.push_back('$');
	
	for(char c : text) 
		s.push_back(c);
	
	vector<int> lps = build_lps(s);
	
	int ocorrencias = 0;
	
	for(int i = pat.size() + 1; i < s.size(); i++){
		if(lps[i] == pat.size())
			ocorrencias++;
	}
	
	return ocorrencias;
}

int main(){
	int teste = 0;
	string s, t;
	cin >> teste;
	int i = 0;
	while(i<teste){
		i++;
		cin >> s >> t;
		cout << "Case " << i << ": ";
		cout << kmp(t, s) << endl;	
	}
}
