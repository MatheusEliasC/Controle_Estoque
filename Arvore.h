#include <iostream>

using namespace std;

template <typename T> class No {
public:
    T valor;
    No<T> *pai;
    No<T> *esq;
    No<T> *dir;
};

template <typename T> class IArvBinBusca {
public:
    virtual bool Insere(T valor) = 0;
    virtual bool Remove(T valor) = 0;
    virtual bool Remove(No<T> *ref) = 0;
    virtual No<T> *Busca(T valor) = 0;
    virtual ~IArvBinBusca() {}

private:
    /* data */
};

template <typename T> class ArvBin {
private:
    No<T>* raiz;
    int n;
    No<T>* sucessor(No<T>* x){
        x=x->dir;
        while(x && x->esq)
            x=x->esq;
        return x;
    };

public:
    ArvBin(){
        raiz = nullptr;
        n=0;
    };

    bool Insere(T valor) {
        No<T> *novo = new No<T>;

        novo->valor = valor;
        novo->esq = nullptr;
        novo->dir = nullptr;
        novo->pai = nullptr;

        No<T> *anterior = nullptr;
        No<T> *atual = raiz;

        while (atual) {
            anterior = atual;

            if (valor < atual->valor)
                atual = atual->esq;
            else
                atual = atual->dir;
        }

        novo->pai = anterior;

        if (anterior) {
            if (valor < anterior->valor)
                anterior->esq = novo;
            else
                anterior->dir = novo;
        } else
            raiz = novo;
        n++;
        return true;
    }
    bool Remove(T valor) {
        No<T>* anterior = nullptr;
        No<T>* atual = raiz;

        while(atual && atual->valor != valor){
            anterior = atual;

            if(valor < atual->valor)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        if(atual == nullptr)
            return false;
        int filhos = (atual->esq != nullptr) + (atual->dir != nullptr);
        if(filhos == 0){
            if(atual->pai){
                if(atual == atual->pai->esq)
                    atual->pai->esq = nullptr;
                else
                    atual->pai->dir = nullptr;
            }
            else
                raiz = nullptr;
            delete atual;
            n--;
        }
        else if(filhos == 1){
            No<T>* base = atual->esq;
            No<T>* pai = atual->pai;

            if(!base)
                base = atual->dir;
            base->pai = pai;

            if(pai){
                if(base->valor < pai->valor)
                    pai->esq = base;
                else
                    pai->dir=base;
            }
            else
                raiz=base;

            delete atual;
            n--;
        }
        else{
            T valorSucessor = sucessor(atual)->valor;
            this->Remove(valorSucessor);
            atual->valor = valorSucessor;
        }
    }
    bool Remove(No<T> *r) {}
    No<T> *Busca(T valor) {
        No<T>* anterior = nullptr;
        No<T>* atual = raiz;

        while(atual && atual->valor != valor){
            anterior = atual;
            if(valor < atual->valor)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        return atual;
    }

    ~ArvBin(){
        while(Remove(raiz->valor));
    };
};