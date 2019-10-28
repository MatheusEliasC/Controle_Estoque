//
// Created by renan on 27/10/2019.
//
#include <iostream>
#ifndef STOCKCONTROL_PILHA_H
#define STOCKCONTROL_PILHA_H

using namespace std;

template<typename T>
class Pilha;

template<typename T>
class IPilha{
public:
    virtual bool Empilha(T valor) = 0;
    virtual T Desempilha(bool *ok) = 0;
    virtual void Imprime() = 0;
    virtual ~IPilha(){}
};

template<typename T>
class No{
private:
    //T* v;
    No* prox;
    No* ant;
    T valor;
    friend class Pilha<T>;

};

template <typename T>
class Pilha{
private:
    No<T>* topo;
    No<T>* base;
    int n;

public:
    Pilha(){
        cout << "Pilha instanciada";
        base->ant = NULL;
        base->prox = NULL;
    }

    ~Pilha(){}

    bool Empilha(T valor){
        cout << "\nEmpilha\n";
        No<T>* atual;
        No<T>* ant;
        atual = base;
        //Caso especial

        //Caso mais comum
        //No atual é igual ao No topo
        while(atual){ // Enquanto o atual for diferente de NULL
            ant = atual; //Anterior é igual a NULL.
            atual = atual->prox; //Percorre a pilha.
        }

        atual->valor = valor; // Insere o valor no último elemento da Pilha.
        return true;
    }

    T Desempilha(bool *ok=NULL){
        //Retorna o valor do ultimo elemento que entrou na Pilha, se o ok não for NULL.
        No<T> * atual = base;
        if(&ok)
            return topo->valor;

        delete topo;
    }

    void Imprime(){
        No<T>* atual;
        atual = topo;
        atual->valor = "string";
        while(atual){
            cout << atual->valor << " ";
            atual = atual->prox;
        }
        cout << endl;

    }

    Pilha& operator<<(T valor){
        // Empilha com o operador p << (3)
        Empilha(valor);
        return *this;
    }


    Pilha(const Pilha& outra){

    }//Copia pilha

    Pilha& operator>>(T& valor){
        //Desempilha com o operador p >>
        T x = Desempilha();
        cout << "- " << x << endl;
        return *this;
    }
};


#endif //STOCKCONTROL_PILHA_H
