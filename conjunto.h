#ifndef CONJUNTO_H
#define CONJUNTO_H

class Conjunto{
    private:
        int *conj = nullptr;                                                //conjunto
        int size;                                                           //tamanho do conjunto
    public:
        Conjunto();                                                         //construtor - cria um conjunto vazio e retorna o conjunto criado.
        ~Conjunto();                                                        //destrutor
        void uniao(Conjunto *a, Conjunto *b, Conjunto *c);                  //recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A ∪ B.
        void interseccao(Conjunto *a, Conjunto *b, Conjunto *c);            //recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A ∩ B.
        void diferenca(Conjunto *a, Conjunto *b, Conjunto *c);              //recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A - B.
        void diferencaSimetrica(Conjunto *a, Conjunto *b, Conjunto *c);     //recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A B.
        int membro(int y, Conjunto *a);                                     //recebe o conjunto A e um elemento y e retorna um 1 se y ∈ A e 0 caso contrário.
        void insere(int y,Conjunto *a);                                     //recebe o conjunto A e um elemento y e adiciona y ao conjunto A, isto é, A = A ∪ y.
        void remove(int y, Conjunto *a);                                    //recebe o conjunto A e um elemento y e remove y do conjunto A, isto é, A = A - y.
        void copia(Conjunto *a, Conjunto *b);                               //faz uma cópia do conjunto A em B.
        int min(Conjunto *a);                                               //retorna o valor mı́nimo do conjunto A.
        int max(Conjunto *a);                                               //retorna o valor máximo do conjunto A.
        bool igual(Conjunto *a, Conjunto *b);                               //retorna true se os conjuntos A e B são iguais e false caso contrário.
        //EXTRA
        void print();                                                       //imprime os valores do conjunto
};
#endif