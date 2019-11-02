//
// Created by unifrsilva on 07/10/2019.
//
#include <time.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>

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
    struct tm data;

    void setPreco(double preco) {
        Produto::preco = preco;
    }

    void setTamanho(int tamanho) {
        Produto::tamanho = tamanho;
    }

    void setId(int id) {
        Produto::id = id;
    }

    void setNome(string nome){
        this->nome = nome;
    }

    int gerarId(){
        int r;
        srand(time(NULL));
        r = (rand() % 10000) + 1;
        return r;
    }

    friend class Estoque;
    //getters and setters
public:
    Produto(){/*id = gerarId();*/}

    Produto(string nome, int quantidade, double preco, int tamanho){
        this->nome = nome;
        this->quantidade = quantidade;
        this->preco = preco;
        this->tamanho = tamanho;
        //Id
        id = gerarId();
        //Data
        time_t agr = time(0);
        time(&agr);
        data = *localtime(&agr);

    }

    int getQuantidade() const {
        return quantidade;
    }

    double getPreco() const {
        return preco;
    }

    int getTamanho() const {
        return tamanho;
    }

    std::string getNome(){
        return nome;
    }

    struct tm getData(){
        return data;
    }

    int getId() const {
        return id;
    }

    void setQuantidade(int quantidade) {
        this->quantidade = quantidade;
    }
    const string dataHoraAtual() {
//        time_t     now = time(0);
//        struct tm  tstruct;
        char buf[80];
//        tstruct = *localtime(&now);
        // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
        // for more information about date/time format
        strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &data);
        return buf;
    }

};

#endif //STOCKCONTROL_PRODUTO_H
