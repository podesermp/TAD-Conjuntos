#include <iostream>
#include "conjunto.h"
#include <climits>
using namespace std;

//Construtor
Conjunto::Conjunto(){
    size = 0;
    conj = new int[size];
}

//Destrutor
Conjunto::~Conjunto(){
    delete[] conj;
    cout << "conjunto destruido"<<endl;
}

//recebe o conjunto A e um elemento y e adiciona y ao conjunto A, isto é, A = A ∪ y.
void Conjunto::insere(int y,Conjunto *a){
    if(membro(y,a) == 0){
        a->conj[size] = y;
        size++;
    }
}

//retorna o valor mı́nimo do conjunto A.
int Conjunto::min(Conjunto *a){
    int minimo;
    minimo = a->conj[0];
    for(int i = 1; i < a->size; i++){
        if(a->conj[i] <= minimo){
            minimo = a->conj[i];
        }
    }
    return minimo;
}

//retorna o valor máximo do conjunto A
int Conjunto::max(Conjunto *a){
    int maximo;
    maximo = a->conj[0];
    for(int i = 1; i < a->size;i++){
        if(a->conj[i] >= maximo){
            maximo = a->conj[i];
        }
    }
    return maximo;
}

//faz uma cópia do conjunto A em B.
void Conjunto::copia(Conjunto *a, Conjunto *b){
    for(int i = 0; i < a->size; i++){
        b->insere(a->conj[i], b);
    }
}

//recebe o conjunto A e um elemento y e retorna um 1 se y ∈ A e 0 caso contrário.
int Conjunto::membro(int y, Conjunto *a){
    for(int i = 0; i < a->size; i++){
        if(a->conj[i] == y){
            return 1;
        }
    }
    return 0;
}

//retorna true se os conjuntos A e B são iguais e false caso contrário.
bool Conjunto::igual(Conjunto *a, Conjunto *b){
    if(a->size == b->size){
        for(int i = 0; i < a->size; i++){
            for(int j = 0; j < b->size; j++){
                if(a->membro(b->conj[j], a) == 0){
                    return false;
                }
            }
        }
        return true;
    }else{
        return false;
    }   
}

//recebe o conjunto A e um elemento y e remove y do conjunto A, isto é, A = A - y
void Conjunto::remove(int y, Conjunto *a){
    if(a->membro(y,a) == 1){
        int indice = INT_MAX;
        for(int i = 0; i < a->size; i++){
            if(a->conj[i] == y){
                indice = i;
            }
            if(i >= indice){
                a->conj[i] = a->conj[i+1];
            }
        }
        a->size--;
    }else{
        cout << "elemento não está no conjunto" << endl;
    }
}

//recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A ∪ B.
void Conjunto::uniao(Conjunto *a, Conjunto *b, Conjunto *c){
    c->copia(a, c);
    c->copia(b, c);
}

//recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A ∩ B.
void Conjunto::interseccao(Conjunto *a, Conjunto *b, Conjunto *c){
    for(int i = 0; i < a->size;i++){
        if(a->membro(a->conj[i], b) == 1){
            c->insere(a->conj[i], c);
        }
    }
}

//recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A - B
void Conjunto::diferenca(Conjunto *a, Conjunto *b, Conjunto *c){
    for(int i = 0; i < a->size;i++){
        if(a->membro(a->conj[i], b) == 0){
            c->insere(a->conj[i],c);
        }
    }
}

//recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A B.
void Conjunto::diferencaSimetrica(Conjunto *a, Conjunto *b, Conjunto *c){
   a->diferenca(a,b,c);
   b->diferenca(b,a,c);
}

//Auxiliares
//Printa os elemetos do conjunto
void Conjunto::print(){
    cout << "{ " ;
    for(int i = 0; i < size; i++){
        cout << conj[i] << "  ";
    }
    cout << "}" << endl;
}