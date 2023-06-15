#include <bits/stdc++.h>

using namespace std;

vector<int> sort_index;

bool not_same_rank(vector<int> rank){
	vector<bool> check(rank.size(),false);
	for(int element : rank){
		if(check[element]){
			return false;
		}
		else{
			check[element] = true;
		}
	}
	return true;
}

template <typename T>
void print_vect(vector<T> vect){
	cout << endl;
	for(auto element : vect){
		cout << element << " ";
	}
	cout << endl;
}

void print_suffix_array(string str, vector<int> rank){
	for(auto element : rank){
		for(int i = element; str[i];i++){
			cout << str[i] << " ";
		}
		cout << endl;
	}
}


template <typename T>
T getMax(vector<T> arr)
{
    T mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

template <typename T>
vector<T> countSort(vector<T> arr, int exp, int base)
{
    vector<T> output(arr.size()); 
    vector<int> aux_sort_index(sort_index.size()); 
    int count[base] = { 0 };
    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % base]++;
 
    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];
 
    for (int i = arr.size() - 1; i >= 0; i--) {
       	int j =count[(arr[i] / exp) % base] - 1; 
        output[j] = arr[i];
        aux_sort_index[j] = sort_index[i];
        count[(arr[i] / exp) % base]--;
    }
    sort_index =  aux_sort_index;
    return output;
}

template <typename T>
vector<T> radixsort(vector<T>arr,int base)
{
	vector<T> output = arr;
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= base){
        output = countSort(output, exp,base);
    }
    return output;
}


vector<int> prefix_doubling(vector<int> vect,int base){
	vector<int> P;

	int k = 0;
	// while(not_same_rank(rank)){
		for(int i =0; i< vect.size();i++){
			int pos = vect[i+1];
			if(i+1 >= vect.size()){
				pos = 0;
			}
			P.push_back(vect[i]*base+ pos);
			sort_index[i] = i;
		}
		vector<int> rank = radixsort(P,base);

		int val = rank[0];
		int classification=0;
		
		for(int i =0; i< rank.size();i++){
			if(rank[i]==val){
				rank[i] = classification;
			}
			else{
				classification ++;
				val = rank[i];
				rank[i] = classification;
			}
		}

		vector<int> aux_rank(rank.size());
		
		for(int i = 0; i< sort_index.size();i++){
			
			aux_rank[sort_index[i]] = rank[i];
		}
		rank = sort_index;	
	// }

	return rank;

}

int main(){
	string str;
	int pos;
	cin >> str >> pos;
	vector<char> letter_conversion;
	for(int i = 0;i<str.size();i++){
		sort_index.push_back(i);
		bool add = true;
		char letter = str[i];
		for(auto element : letter_conversion){
			if(letter == element){
				add = false;
				break;
			}
		}
		if(add){
			letter_conversion.push_back(letter);
		}
	}
	letter_conversion = radixsort(letter_conversion,letter_conversion.size());
	vector<int> str_num;
	for(int i = 0;i< str.size();i++){
		for(int j = 0; j<letter_conversion.size();j++){
			if(str[i] == letter_conversion[j]){
				str_num.push_back(j);
				break;
			}
		}
	}

	str_num = prefix_doubling(str_num,letter_conversion.size());
	// print_vect(str_num);
	print_suffix_array(str,str_num);
}