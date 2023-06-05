#include <bits/stdc++.h>

using namespace std;

vector<int> sort_index;
string str;


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

bool ranked(vector<int> rank){
	vector<bool> check(rank.size(),false);
	for(int i = 0;i< rank.size();i++){
		if(check[rank[i]]){
			return false;
		}
		else{
			check[rank[i]] = true;
		}
	}
	return true;
}

template <typename T>
void print_vect(vector<T> vect){
	for(auto element : vect){
		cout << element << " ";
	}
	cout << endl;
}

void print_suffix_array_circular(string str, vector<int> rank){
	for(auto element : rank){
		for(int i = 0; i < str.size() ;i++){
			cout << str[(i+element) % str.size()] << " ";
		}
		cout << endl;
	}
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
T getMax(vector<T> arr,int start,int end)
{
    T mx = arr[start];
    for (int i = start + 1; i < end; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

int getMax_pair(vector<pair<int,int>> arr)
{
    int mx = arr[0].first;
    for (int i = 1; i < arr.size(); i++){
        if(arr[i].first > mx)
            mx = arr[i].first;
        if(arr[i].first > mx)
        	mx = arr[i].second;
    }
    return mx;
}

template <typename T>
vector<T> countSort(vector<T> arr,int start, int end, int exp, int base)
{
    vector<T> output(arr.size());
    vector<int> aux_sort_index(sort_index.size()); 
    int count[base] = { 0 };
    for (int i = start; i < end; i++)
        count[(arr[i] / exp) % base]++;
 
    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];
 
    for (int i = end - 1; i >= start; i--) {
       	int j =count[(arr[i] / exp) % base] - 1; 
        output[j] = arr[i];
        aux_sort_index[j] = sort_index[i];
        count[(arr[i] / exp) % base]--;
    }

    sort_index =  aux_sort_index;
    return output;
}

template <typename T>
vector<T> radixsort(vector<T>arr,int start,int end,int base = 10)
{
	vector<T> output = arr;
    int m = getMax(arr,start,end);
    for (int exp = 1; m / exp > 0; exp *= base){
        output = countSort(output,start,end,exp,base);
    }
    return output;
}

vector<pair<int,int>> countSort_pair(vector<pair<int,int>> arr,int pos,int exp, int base)
{
    vector<pair<int,int>> output(arr.size());
    vector<int> aux_sort_index(sort_index.size()); 
    int count[base] = { 0 };
    int val;
    for (int i = 0; i < arr.size(); i++){
        val =  pos==0?arr[i].first:arr[i].second;
        count[(val / exp) % base]++;
    }
 
    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];
 
    for (int i = arr.size() - 1; i >= 0; i--) {
    	val =  pos==0?arr[i].first:arr[i].second;
       	int j = count[(val / exp) % base] - 1; 
        output[j] = arr[i];
        aux_sort_index[j] = sort_index[i];
        count[(val / exp) % base]--;
    }
    sort_index =  aux_sort_index;
    return output;
}


vector<pair<int,int>> radixsort_pair(vector<pair<int,int>>arr,int base = 10)
{
	int m = getMax_pair(arr);
    for (int exp = 1; m / exp > 0; exp *= base){
    	arr = countSort_pair(arr,1,exp,base);
    }
    for (int exp = 1; m / exp > 0; exp *= base){
    	arr = countSort_pair(arr,0,exp,base);
    }
    return arr;
}



vector<int> order(vector<pair<int,int>> pairs){
	pair<int,int> val;
	vector<int> rank(pairs.size()), output(rank.size());

	vector<pair<int,int>> ordered_pairs = radixsort_pair(pairs,10);

	// ordered_pairs vai ter os pares em ordem crescente

	// for(auto element : ordered_pairs){
	// 	printf("(%d,%d) ",element.first,element.second);	
	// }
	// cout << endl;

	int classification = 0;
	val = ordered_pairs[0];
	for(int i = 0; i<ordered_pairs.size();i++){
		if(ordered_pairs[i]==val){
			rank[i] = classification;
		}
		else{
			classification++;
			val = ordered_pairs[i];
			rank[i] = classification;
		}
	}
	// cout << "rank" << endl;
	// print_vect(rank);
	

	// rank vai ter as classificações dos pares em ordem crescente
	// index vai ter o index de origem de cada par

	for(int i =0; i< output.size();i++){
		output[sort_index[i]] = rank[i];
	}

	// output vai ter as classificações em ordem do sufix string 

	return output;
}

void prefix_doubling(vector<int> rank, int k){
	while(!ranked(rank) && pow(2,k)< rank.size()) {
		// cout << endl;
		for(int i = 0; i< rank.size();i++){
			sort_index[i] = i;	
		}
		// print_suffix_array(str,sort_index);
		vector<pair<int,int>> pair;
		int pos;
		for(int i = 0; i < rank.size();i++){
			pos = rank[((int)(i+pow(2,k))) % rank.size()];
			pair.push_back({rank[i], pos});
		}

		//pair vai ter os pares de rank de k
		
		rank = order(pair);

		k++;
	}
	return;
}


int main(){
	// cin >> str ;
	
	while(getline(cin,str) ){
		if(str.size() == 0){break;}
		vector<char> letter_conversion;
		sort_index.clear();
		for(int i = 0; str[i];i++){
			sort_index.push_back(i);	
		}
		
		letter_conversion = alfabet(str, str[0]);
		letter_conversion = radixsort(letter_conversion,0,letter_conversion.size());

		vector<int> str_num = convert(letter_conversion, str);

		

		//str_num vai ter a classificação dos sufix strings em ordem de tamanho


		prefix_doubling(str_num,0);
		// print_suffix_array_circular(str,sort_index);
		int val;
		for (int i = 0; i < sort_index.size(); ++i)
		{
			val = sort_index[i]-1;
			if(val< 0){
				val = sort_index.size()-1;
			}
			cout << str[val] << "";
		}
		cout << endl;
	}
}