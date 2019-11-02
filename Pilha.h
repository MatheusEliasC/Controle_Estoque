//
// Created by renan on 27/10/2019.
//
#include <iostream>
#ifndef STOCKCONTROL_PILHA_H
#define STOCKCONTROL_PILHA_H

using namespace std;

template<typename T>
class Pilha;

template <typename T>
class Pilha
{
private:
    T* v;
    int n;
    int Max;
public:

    Pilha(){
        n = 0;
        Max = 0;
        v = new T[Max];
    }

    Pilha(int Max)
    {
        this->Max = Max;
        n = 0;
        v = new T[Max];
    }

    ~Pilha()
    {
        delete[] v;
    }

    bool Empilha(T valor)
    {
        if(n == Max)
            return true;

        v[n] = valor;
        n++;
    }

    T Desempilha(bool *ok=NULL)
    {
        if(n==0)
        {
            *ok = false;
            return v[0];
        }

        n--;
        if(ok!=NULL)
            *ok = true;
        return v[n];
    }

    void Imprime()
    {
        for (int i = 0; i < n; ++i)
        {
            cout << v[i] << ((i+1 == n) ? "\n" : " | ");
        }
    }

    // sobrecarga de operator para empilhar
    Pilha& operator<< (T valor)
    {
        Empilha(valor);
        return *this;
    }

    // sobrecarga de operator para desempilhar
    Pilha& operator>> (T& valor)
    {
        valor = Desempilha();
        return *this;
    }

    // concatena duas pilhas
    Pilha& operator<< (Pilha p2)
    {
        Pilha retorno (this-> Max + p2.Max);

        for (int i = 0; i < this->n; i++)
        {
            retorno.Empilha(this->v[i]);
        }

        for (int i = 0; i < p2.n; i++)
        {
            retorno.Empilha(p2.v[i]);
        }

        return retorno;
    }

    Pilha(const Pilha& outra)
    {
        this->v = new T[outra.Max];

        for (int i = 0; i < outra.n ; i++)
        {
            this->v[i] = outra.v[i];
        }
        this->n = outra.n;
    }

    void setTamanhoMax(int Max){
        this->Max = Max;
    }

    int getMax(){
        return Max;
    }

    int getN(){
        return n;
    }
};


#endif //STOCKCONTROL_PILHA_H
