#include <iostream>
#include "conjunto.h"
using namespace std;

int main(){
    Conjunto conjuntos[3];
    bool start = true;
    int op, nConjunto, auxNConjuntos, y;


    string str = ("\n-------------------------------------------------------------------------\n\t\t:::CONJUTOS:::\n");
    str+= ">conjuntos: 0 1 2\n";
    str+=("1.insere(int y,Conjunto *a)\t\t | \t 11. diferenca(Conjunto *a, Conjunto *b, Conjunto *c)\n");
    str+=("2. print()\t\t\t\t | \t 12. diferencaSimetrica(Conjunto *a, Conjunto *b, Conjunto *c)\n");
    str+=("3. min(Conjunto *a)\n");
    str+=("4. max(Conjunto *a)\n");
    str+=("5. copia(Conjunto *a, Conjunto *b)\n");
    str+=("6. membro(int y, Conjunto *a)\n");
    str+=("7. igual(Conjunto *a, Conjunto *b)\n");
    str+=("8. remove(int y, Conjunto *a)\n");
    str+=("9. uniao(Conjunto *a, Conjunto *b, Conjunto *c)\n");
    str+=("10. interseccao(Conjunto *a, Conjunto *b, Conjunto *c)\n");
    str+=("0. Finalizar\n");



    while(start){
        cout << str;
        cout << "--------------\nDigite Uma operação:";
        cin >> op;
        system("clear");
        switch(op){
            case 0:
                start = false;
                cout << "<<<FIM DE PROGRAMA>>>"<<endl;
                break;
            case 1:
                cout << "\tinsere(int y,Conjunto *a)"<<endl;
                cout << "Qual conjunto? ";
                cin >> nConjunto;
                if(nConjunto >= 0 && nConjunto < 3){
                    cout << "valor para inserir: ";
                    cin >> y;
                    conjuntos[nConjunto].insere(y,&conjuntos[nConjunto]);
                }else cout << "<Número de conjunto inválido>";
                break;
            case 2:
                for(int i = 0; i < 3; i++){
                    conjuntos[i].print();
                }
                break;
            case 3:
                cout << "\tmin(conjunto *a)"<<endl;
                cout << "Qual conjunto? ";
                cin >> nConjunto;
                if(nConjunto >= 0 && nConjunto < 3){
                    cout << "Valor minimo do conjunto "<<nConjunto<< " = " <<conjuntos[nConjunto].min(&conjuntos[nConjunto])<<endl;
                }else cout << "<Número de conjunto inválido>";
                break;
            case 4:
                cout << "\tmax(conjunto *a)"<<endl;
                cout << "Qual conjunto? ";
                cin >> nConjunto;
                if(nConjunto >= 0 && nConjunto < 3){
                    cout << "Valor máximo do conjunto "<<nConjunto<< " = "<< conjuntos[nConjunto].max(&conjuntos[nConjunto])<<endl;
                }else cout << "<Número de conjunto inválido>";
                break;
            case 5:
                cout << "\tcopia(conjunto *a, conjunto *b)"<<endl;
                cout << "Conjunto a ser copiado: ";
                cin >> nConjunto;
                cout << "Conjunto para armazenar a cópia: ";
                cin >> auxNConjuntos;
                if((nConjunto >= 0 && nConjunto < 3)&&(auxNConjuntos >= 0 && auxNConjuntos < 3)){
                    conjuntos[nConjunto].copia(&conjuntos[nConjunto], &conjuntos[auxNConjuntos]);
                }else cout << "<Número de conjunto inválido>";
                break;
            case 6:
                cout << "\tmembro(int y, conjunto *a)"<<endl;
                cout << "Qual conjunto? ";
                cin >> nConjunto;
                if(nConjunto >= 0 && nConjunto < 3){
                    cout << "Valor a ser buscado: ";
                    cin >> y;
                    if(conjuntos[nConjunto].membro(y,&conjuntos[nConjunto]) == 1){
                        cout << "Valor está no conjunto"<<endl;
                    }else cout << "Valor não esta no conjunto"<<endl;
                }else cout << "<Número de conjunto inválido>";
                break;
            case 7:
                cout << "\tigual(conjunto *a, conjunto *b)"<<endl;
                cout << "Conjuntos a serem testados: ";
                cin >> nConjunto;
                cin >> auxNConjuntos;
                if((nConjunto >= 0 && nConjunto < 3)&&(auxNConjuntos >= 0 && auxNConjuntos < 3)){
                    if(conjuntos[nConjunto].igual(&conjuntos[nConjunto], &conjuntos[auxNConjuntos])){
                        cout << "Conjuntos iguais"<<endl;
                    }else cout << "Conjuntos não são iguais"<<endl;
                }else cout << "<Número de conjunto inválido>";
                break;
            case 8:
                cout << "\tremove(int y, conjunto *a)"<<endl;
                cout << "Qual conjunto? ";
                cin >> nConjunto;
                if(nConjunto >= 0 && nConjunto < 3){
                    cout << "Valor a ser removido: ";
                    cin >> y;
                    conjuntos[nConjunto].remove(y,&conjuntos[nConjunto]);
                }else cout << "<Número de conjunto inválido>";
                break;
            case 9:
                cout << "\tuniao(conjunto *a, conjunto *b, conjunto *c)"<<endl;
                cout << "A união B"<<endl;
                conjuntos[0].uniao(&conjuntos[0], &conjuntos[1], &conjuntos[2]);
                break;
            case 10:
                cout << "\tinterseccao(conjunto *a, conjunto *b, conjunto *c)"<<endl;
                cout << "A interseccao B"<<endl;
                conjuntos[0].interseccao(&conjuntos[0], &conjuntos[1], &conjuntos[2]);
                break;
            case 11:
                cout << "\tdiferenca(Conjunto *a, Conjunto *b, Conjunto *c)"<<endl;
                cout << "1. A-B\n2. B-A\nEscolha: ";
                cin >> nConjunto;
                switch(nConjunto){
                case 1:
                    conjuntos[0].diferenca(&conjuntos[0], &conjuntos[1], &conjuntos[2]);
                    break;
                case 2:
                    conjuntos[0].diferenca(&conjuntos[1], &conjuntos[0], &conjuntos[2]);
                    break;
                default:
                    cout << "Opção inválida"<<endl;
                    break;
                }
                break;
            case 12:
                cout << "\t12. diferencaSimetrica(Conjunto *a, Conjunto *b, Conjunto *c)"<<endl;
                cout << "A diferença simétrica B"<<endl;
                conjuntos[0].diferencaSimetrica(&conjuntos[0], &conjuntos[1], &conjuntos[2]);
                break;
            default:
                cout << "Valor de operação inválido"<<endl;
                break;
        }
    }
    return 0;
}