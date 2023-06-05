#include <bits/stdc++.h>

using namespace std;

vector<int> sort_index;


template <typename T, typename F>
vector<F> alfabet(T str,F unit ){
	vector<F> letter_conversion;
	for(auto element : str){
		bool add = true;
		for(auto element2 : letter_conversion){
			if(element == element2){
				add = false;
				break;
			}
		}
		if(add){
			letter_conversion.push_back(element);
		}
	}
	return letter_conversion;
}

bool not_same_rank(vector<int> rank){
	vector<bool> check(rank.size(),false);
	for(int element : rank){
		if(check[element]){
			return true;
		}
		else{
			check[element] = true;
		}
	}
	return false;
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
vector<T> radixsort(vector<T>arr,int base = 10)
{
	vector<T> output = arr;
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= base){
        output = countSort(output, exp,base);
    }
    return output;
}


template < typename T, typename F>
vector<int> convert(T letter_conversion,F str ){
	vector<int> str_num;
	for(int i = 0;i< str.size();i++){
		for(int j = 0; j<letter_conversion.size();j++){
			if(str[i] == letter_conversion[j]){
				str_num.push_back(j);
				break;
			}
		}
	}
	return str_num;
}


vector<int> prefix_doubling(vector<int> vect){

	vector<int> P;
	vector<int> rank = vect;
	vector<int> aux_rank = rank;
	int pos, val, classification,k = 0,base;
	while(not_same_rank(aux_rank)){
		
		cout << "loop" << endl;
		base = getMax(rank);

		for(int i =0; i< vect.size();i++){
			pos = rank[i+1];
			if(i+1 >= rank.size()){
				pos = 0;
			}
			P.push_back(rank[i]*base+ pos);
			sort_index[i] = i;
		}

		P = convert(alfabet(P,P[0]), P);

		rank = radixsort(P, getMax(P));
		val = rank[0];
		classification=0;

		

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
		for(int i = 0; i< sort_index.size();i++){
			aux_rank[sort_index[i]] = rank[i];
		}

		rank = aux_rank;	
		k++;
		if(k==5)
			return rank;
	}
	
	return rank;
}




int main(){
	string str;
	int pos;
	cin >> str ;
	vector<char> letter_conversion;
	for(int i = 0; str[i];i++){
		sort_index.push_back(i);	
	}
	
	
	letter_conversion = alfabet(str, str[0]);
	letter_conversion = radixsort(letter_conversion,letter_conversion.size());

	vector<int> str_num = convert(letter_conversion, str);

	str_num = prefix_doubling(str_num);
	// print_vect(str_num);
	print_suffix_array(str,str_num);
}