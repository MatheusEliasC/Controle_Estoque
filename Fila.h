//
// Created by JPascual on 14/10/2019.
//
#include <iostream>
#ifndef STOCKCONTROL_FILA_H
#define STOCKCONTROL_FILA_H

using namespace std;

template <typename T>
class IFila{
public:
    virtual bool Enfileira(T valor) = 0;
    virtual T Desenfileira(bool* ok) = 0;
    virtual T* Imprime() = 0;
    virtual ~IFila(){};
};

template <typename T>
class Fila : public IFila<T>{
private:
    T* v;
    int i;
    int f;
    int max;
public:
    Fila(int maximo) {
        v = new T[maximo+1];
        i=f=0;
        max = maximo+1;
    }

    ~Fila(){
        delete[] v;
    }

    bool Enfileira(T valor){
        if( (f+1) % max == i)
            return false;

        v[f] = valor;
        f = (f + 1) % max;
        return true;
    }

    T Desenfileira(bool* ok = NULL){
        if( i == f) {
            if(ok){
                *ok = false;
            }
            return v[i];
        }

        T temp = v[i];
        i = (i + 1) % max;
        if(ok)
            *ok = true;
        return temp;

    }

    T* Imprime(){
        return v;
    }

};
#endif //STOCKCONTROL_FILA_H
