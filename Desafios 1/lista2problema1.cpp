#include <bits/stdc++.h>

using namespace std;


int buscabi(int parte2, vector<int> lista){
    int sum1 ;
    int sum2 ;
    int inicio = 0;
    int fim = lista.size();
    int meio;
    int meio1;
    int meio2;
    while(fim - inicio-parte2>=0){
        meio =(fim+inicio) / 2;
        meio1 = meio - (parte2 / 2);
        meio2 = meio1 + parte2;
        //cout<< "meios" << meio1 << meio2 << endl;
        sum1 = 0;
        sum2 = 0;
        for(int i = 0; i < meio1;i++){
            sum1 = sum1 + lista[i];

        }
        for(int i = meio2;i<lista.size();i++){
            sum2 = sum2 + lista[i];
        }
        //cout << "sums" << sum1 <<' ' << sum2 << endl;
        if(sum1 == sum2){
            //cout<< "achei uma resposta !"<< endl; 
            return sum1;
        }
        else if(sum1 > sum2){
            fim = meio2 -1;
        }
        else{
            inicio = meio1 + 1;
        } 
        //cout<< "marcadores"<< inicio<< fim <<parte2 <<endl;
    }
    return 0;
}

int busca(vector<int> lista){
    int resposta = 0;
    int tamanho = lista.size();
    int parte2 = 0;
    int resultado = 0;
    while(parte2<tamanho){
        resultado = buscabi(parte2, lista);
        if(resultado > resposta){
            resposta = resultado;
        }
        parte2++;
    }
    return resposta;
}


int solve(){
    int var;
    int resposta = 0;
    std::vector<int> lista;
    int qtd = 3;
    cin >> qtd;
    while(qtd > 0){
        cin >> var;
        lista.push_back(var);
        qtd = qtd -1;
    }
    resposta = busca(lista);
    
    return resposta;
}


int main(){
    int resposta = solve();
    cout << resposta<< endl;
}


