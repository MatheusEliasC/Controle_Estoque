//
// Created by unifmcruz on 07/10/2019.
//

#include "Produto.h"

#ifndef STOCKCONTROL_ESTOQUE_H
#define STOCKCONTROL_ESTOQUE_H

#endif //STOCKCONTROL_ESTOQUE_H

using namespace std;

class Estoque{
private:
    void iniciaProduto(){
        Produto relogio(5, 15.00, 0);
        Produto oculos(3, 9.00, 0);
        Produto quadroGrande(10, 56.00, 2);
        Produto vasoMedio(4, 25.00, 1);
    }

public:
    Estoque(){
        iniciaProduto();
    }

    void InserirProduto(){
        string nome;
        int quantidade, tamanho;
        double preco;
        bool tenteTamanho, tentePreco;
        cout << "Digite o nome do(s) produto(s)" << endl;
        cin >> nome;
        cout << "Digite a quantidade de produtos" << endl;
        cin >> quantidade;
        do {
            tenteTamanho = false;
            cout << "Digite o tamanho do(s) produto(s)" << endl;
            cin >> tamanho;
            if (tamanho < 0 || tamanho > 2) {
                tenteTamanho = true;
                cout << "Tamanho inválido, tente novamente" << endl;
            }
        }while(tenteTamanho);
        do {
            tentePreco = false;
            cout << "Digite o preço equivalente a um produto" << endl;
            cin >> preco;
            if (preco < 0.00 || preco >= 5000.00) {
                tentePreco = true;
                cout << "Preço inválido, tente novamente" << endl;
            }
        }while(tentePreco);
        Produto novo(quantidade,preco,tamanho);
        cout<<"Produto adicionado com sucesso."<<endl;
        cout<<"Id: "<<novo.getId()<<endl;//TODO testar ID
    };
    void RemoverProduto(){

    };
    void BuscarProduto(){

    };
    void ListarProduto(){

    };
};