//
// Created by unifrsilva on 07/10/2019.
//
#include <cstdlib>

#include <iostream>
#ifndef STOCKCONTROL_PRODUTO_H
#define STOCKCONTROL_PRODUTO_H

#endif //STOCKCONTROL_PRODUTO_H
/**
 * 'Produto' is a class to represent the product of the store.
 */
class Produto{
public:
    Produto(int quantidade,double preco, int tamanho){
        this->quantidade=quantidade;
        this->preco = preco;
        this->tamanho = tamanho;
        id = gerarId();
    }
    //Produto(){}

private:
    int quantidade;
    double preco;
    int tamanho;
    int id;

    int gerarId(){
        return quantidade++;//(rand() % 100000) + 1;//TODO trocar função de randomização
    }

    //getters and setters
public:
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

    void setId(int id) {
        Produto::id = id;
    }
};