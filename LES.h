//
// Created by Matheus on 20/10/2019.
//

#ifndef STOCKCONTROL_LES_H
#define STOCKCONTROL_LES_H

#endif //STOCKCONTROL_LES_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

template <typename T>
class LES {
private:
    int tamanhoMax;
    int n;
    T *v;
public:
//    LES(int tamanhoMax){
//        this->tamanhoMax = tamanhoMax;
//        this->n = 0;
//        this->v = new T[tamanhoMax];
//    }
    LES(){
        tamanhoMax = 10;
        n = 0;
        v = new T[tamanhoMax];
    }
    ~LES(){
        delete[] this->v;
    }

    void Imprime(){
        for(int i=0;i<n;i++){
            cout << i+1<<"- " << v[i].getNome() << " "<<endl;
        }
    }

    bool Insere(T x){
        int i;
        if(n == tamanhoMax){
            return false;//Impossível inserir, lista cheia
        }
        for (i = 0; i < n && v[i].getNome().at(0) < x.getNome().at(0); ++i) {}
        for(int j = n;j>i;--j){
            v[j] = v[j-1];
        }
        //TODO criar loop para testar e corrigir ordem de nomes que tem a mesma inicial

        v[i] = x;
        n++;
    }

//    T Busca(int *pos, int id){
//        if(n == 0) {
//            return NULL;
//        }
//        if(pos != nullptr)
//            return v[*pos]; // tipo int
//        for(int i = 0; i<n ;i++) {
//            if (v[i].id == id)
//                return v[i];
//        }
//    }
//
//
//    int Busca(T x){
//        int inicio=0;
//        int fim=n-1;
//        int f=0;
//        int meio = 0;
//        int valor;
//
//        while(inicio<=fim && f==0)
//        {
//            meio=(inicio+fim)/2;
//            if(x>v[meio])
//            {
//                inicio=meio+1;
//                valor=v[meio];
//            }
//            else if(x<v[meio])
//            {
//                fim=meio-1;
//                valor=v[meio];
//            }
//            else {
//                f = 1;
//            }
//        }
//        if(f==1){
//            return meio;
//        }
//        else{
//            return -1;
//        }
//    }

//    bool Remove(int pos){
//        int i;
//        for(i=0;i<n; ++i){ }
//        if(i == n-1){
//            return false;
//        }
//        for(int j=i;j<n;j++){
//            if(j+1 >= n){
//                break;
//            }
//            v[j] = v[j+1];
//        }
//        n--;
//        return true;
//    }

    bool Remove(int pos){
        int i;
        bool temp = false;
        for(i=0;i<n;i++) {
            if (i == pos){
                v[i] = v[i+1];
                pos++;
                temp = true;
            }
        }
        if(temp == true)
            n--;
        return temp;
    }

    const T&operator[](int idx){}

    void setTamanhoMax(int tamanhoMax) {
        LES::tamanhoMax = tamanhoMax;
    }

    int getN() const {
        return n;
    }

};