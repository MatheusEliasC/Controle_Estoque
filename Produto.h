//
// Created by unifrsilva on 07/10/2019.
//
#include <time.h>
#include <iostream>
#include <string.h>

#ifndef STOCKCONTROL_PRODUTO_H
#define STOCKCONTROL_PRODUTO_H
using namespace std;
/**
 * 'Produto' is a class to represent the product of the store.
 */
class Produto{
private:
    string nome;
    int quantidade;
    double preco;
    int tamanho;
    int id;
    struct tm *data;

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

    Produto(string nome, int quantidade,double preco, int tamanho){
        this->nome = nome;
        this->quantidade = quantidade;
        this->preco = preco;
        this->tamanho = tamanho;
        id = gerarId();
        //Data
        time_t agr;
        time(&agr);
        data = localtime(&agr);

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

    std::string getNome(){
        return nome;
    }

    struct tm* getData(){
        return data;
    }

    int getId() const {
        return id;
    }

};

#endif //STOCKCONTROL_PRODUTO_H
