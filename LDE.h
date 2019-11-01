//
// Created by renan on 01/11/2019.
//
#include <iostream>
#ifndef STOCKCONTROL_LDE_H
#define STOCKCONTROL_LDE_H
using namespace std;
template <typename T>
class NoLDE
{
//private:
//    T valor;
//    No<T>* prox;
//public:
//    template <typename>
//    friend class LDE;
//};
//
//template <typename T>
//class LDE
//{
//private:
//    NoLDE<T>* primeiro;
//    int n;
//    T sentinela;
//
//    void limpa()
//    {
//        while(this->Remove(0));
//    }
//
//    void copia(const LDE& other)
//    {}
//
//public:
//    LDE ()
//    {
//        primeiro = NULL;
//        n = 0;
//    }
//
//
//    bool Insere(T valor)
//    {
//        NoLDE<T>* novo = new NoLDE<T>;
//
//        novo->valor = valor;
//        novo->prox = nullptr;
//
//        NoLDE<T>* atual = primeiro;
//        NoLDE<T>* anterior = nullptr;
//
//        while(atual != nullptr && atual->valor < valor)
//        {
//            anterior = atual;
//            atual = atual->prox;
//        }
//
//        if(anterior == nullptr)
//        {
//            primeiro = novo;
//        }
//        else
//        {
//            anterior->prox = novo;
//        }
//
//        novo->prox = atual;
//
//        n++;
//    };
//
//    int Busca(T valor)
//    {
//        NoLDE<T>* atual = primeiro;
//        int i = 0;
//
//        while(atual)
//        {
//            if(atual->valor == valor)
//            {
//                return i;
//            }
//            atual = atual->prox;
//            i++;
//        }
//        return -1;
//    };
//
//    bool Remove(int idx)
//    {
//        No<T>* atual = primeiro;
//        No<T>* anterior = NULL;
//
//        if(idx < 0 || idx > n)
//            return false;
//
//        while(atual && idx--)
//        {
//            anterior = atual;
//            atual = atual->prox;
//        }
//
//        if(anterior)
//            anterior->prox = atual->prox;
//        else
//            primeiro = atual->prox;
//
//        delete atual;
//
//        n--;
//        return true;
//    };
//
//    const T& operator[](int idx)
//    {
//        NoLDE<T>* atual = primeiro;
//        int i = idx;
//
//        while(atual && idx--)
//        {
//            atual = atual->prox;
//        }
//
//        if(idx < 0 || idx > n)
//            return sentinela;
//
//        return atual->valor;
//    };
//
//    void Imprime()
//    {
//        NoLDE<T>* atual = primeiro;
//        while(atual)
//        {
//            cout << atual->valor << " - ";
//            atual = atual->prox;
//        }
//        cout << endl;
//    };
//
//    ~LDE ()
//    {
//        limpa();
//    };

};
#endif //STOCKCONTROL_LDE_H
