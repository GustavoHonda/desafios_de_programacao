#include <bits/stdc++.h>

using namespace std;

vector<int> sort_index;
vector<int> order;
int classification;

	string str;
	int pos;


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

bool ranked(vector<int> rank,int start,int end){
	vector<bool> check(rank.size(),false);
	for(int i = start;i< end;i++){
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
	cout << "vect_size:" << vect.size() <<endl << "vect:";
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
T getMax(vector<T> arr,int start,int end)
{
    T mx = arr[start];
    for (int i = start + 1; i < end; i++)
        if (arr[i] > mx)
            mx = arr[i];
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


void prefix_doubling(vector<int> rank,int start, int end, int k){
	vector<int> P;
	int pos, val,base;
	
	printf("\nloop %d start %d end %d\n\n",k,start,end);
	print_suffix_array(str,sort_index);
	base = getMax(rank,start,end);
	
	for(int i = start; i < end;i++){
		pos = rank[i+2^k];
		if(i+1 >= rank.size()){
			pos = 0;
		}
		P.push_back(rank[i]*base+ pos);
	}


	rank = radixsort(P,start,end, base);
	// if(k==1)exit(0);
	val = rank[start];


	for(int i = start; i<end;i++){
		if(rank[i]==val){
			rank[i] = classification;
		}
		else{
			classification++;
			
			val = rank[i];
			rank[i] = classification;
		}
	}

	
	// print_vect(rank);
	val = rank[start];
	for(int i = start; i<end;i++){
		if(rank[i] != val){
			if(i-start != 1){
				prefix_doubling(rank,start,i,k+1);		
			}
			start = i;
			val = rank[i];
		}
	}
	


	return;

	// P = convert(alfabet(P,P[0]), P);

	// for(int i = 0; i< sort_index.size();i++){
	// 		aux_rank[sort_index[i]] = rank[i];
	// }

}




int main(){
	cin >> str ;
	vector<char> letter_conversion;
	
	classification = 0;
	for(int i = 0; str[i];i++){
		sort_index.push_back(i);	
	}
	
	letter_conversion = alfabet(str, str[0]);
	letter_conversion = radixsort(letter_conversion,0,letter_conversion.size());

	vector<int> str_num = convert(letter_conversion, str);

	for(int i = 0; str[i];i++){
		sort_index[i] = i;	
	}
	prefix_doubling(str_num,0,str_num.size(),0);
	// print_suffix_array(str,sort_index);
}