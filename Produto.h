//
// Created by unifrsilva on 07/10/2019.
//
#include <time.h>
#include <iostream>

#ifndef STOCKCONTROL_PRODUTO_H
#define STOCKCONTROL_PRODUTO_H

/**
 * 'Produto' is a class to represent the product of the store.
 */
class Produto{
private:
    int quantidade;
    double preco;
    int tamanho;
    int id;

    int gerarId(){
        int r;
        srand(time(NULL));
        r = (rand() % 10000) + 1;
        return r;
    }

    //getters and setters
public:
    Produto(){
        id = gerarId();
    }

    Produto(int quantidade,double preco, int tamanho){
        this->quantidade=quantidade;
        this->preco = preco;
        this->tamanho = tamanho;
        id = gerarId();
    }

    int getQuantidade() const {
        return quantidade;
    }

    void setQuantidade(int quantidade) {
        Produto::quantidade = quantidade;
    }

    double getPreco() const {
        return preco;
    }

    void setPreco(double preco) {
        Produto::preco = preco;
    }

    int getTamanho() const {
        return tamanho;
    }

    void setTamanho(int tamanho) {
        Produto::tamanho = tamanho;
    }

    int getId() const {
        return id;
    }

};

#endif //STOCKCONTROL_PRODUTO_H
