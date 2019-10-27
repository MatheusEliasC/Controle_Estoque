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

    LES(){
        tamanhoMax = 10;
        n = 0;
        v = new T[tamanhoMax];
    }

    ~LES(){
        delete[] this->v;
    }

    void ImprimeNome(){
        for(int i=0;i<n;i++){
            cout << i+1<<"- " << v[i].getNome() << " "<<endl;
        }
    }

    void ImprimeTudo(){
        for(int i=0;i<n;i++){
            cout << i+1<<"- Produto: " << v[i].getNome()
                 <<" Quantidade: " <<v[i].getQuantidade()
                 <<" Preço: "<<v[i].getPreco()
                 <<" Tamanho: "<< v[i].getTamanho()
                 <<" Id: "<< v[i].getId()<<endl;
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

    bool ReInsere(T x,int pos){
        int i;
        if(pos > n-1){
            return false;//Impossível inserir, posição maior que limite
        }
        v[pos] = x;
        return true;
    }

    T BuscaPorPos(int pos){
        int i;
        for(i=0;i<n;i++) {
            if (i == pos){
                return v[i];
            }
        }
    }

    T BuscaPorID(int id){
        for(int i=0;i<n;i++) {
            if (v[i].getId() == id){
                return v[i];
            }
        }
    }

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

    void Substituir(T prod, int pos){
        v[pos] = prod;
    }

    const T&operator[](int idx){}

    void setTamanhoMax(int tamanhoMax) {
        LES::tamanhoMax = tamanhoMax;
    }

    int getN() const {
        return n;
    }

};