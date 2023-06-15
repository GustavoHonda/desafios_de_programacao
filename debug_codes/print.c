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

void print_map(){
	for (int i = 1; i <=n; ++i)
	{
		for(auto element : colors[i]){
			cout << "(" <<i << "," <<  element.first << ")" << endl;
		}
		cout << endl;
	}
}

void print_adj(){
	for (int i = 1; i <=n; ++i){
		for(auto element : adj[i]){
			cout << "(" << i << "," << element << ")";
		}
		cout << endl;
	}
}

template <typename T>
void print_array(T arr[], int arr_sz){
	for (int i = 1; i <= arr_sz; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

