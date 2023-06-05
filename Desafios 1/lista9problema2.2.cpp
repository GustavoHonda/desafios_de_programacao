#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long

using namespace std;

unordered_map <int, int> id, sz, adj;

int find(int a){
	if(id[a] == a) return a;
    return id[a] = find(id[a]);
}

void merge(int a, int b){
	int aa = find(a);
	int bb = find(b);
	if(aa==bb) return;
	if(sz[aa]>sz[bb]){
		id[bb] = aa;
		sz[aa] += sz[bb];
	}
	else{
		id[aa] = bb;
		sz[bb] += sz[aa];
	}
}

int main(){
	int n, m,a,b;
	cin>>n>>m;
    int count = 0, count2 = 0;
	unordered_map <int, int>::iterator x;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		if(id.find(a) == id.end()){
			id[a] = a;
			sz[a] = 1;
			adj[a] = 0;
			count++;
		}
		if(id.find(b) == id.end()){
		    
			id[b] = b;
			sz[b] = 1;
			adj[b] = 0;
			count++;
		}
		merge(a, b);
	}
	for(x = id.begin(); x!=id.end(); x++){
        int a = x->first;
		if(id.find(a)==id.end())
			count2++;
		else{
			int c = find(a);
			if(adj[c]==0){
				count2++;
				adj[c] = 1;
			}
		}
	}
	cout<<count2+n-count;
}