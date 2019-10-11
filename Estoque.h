//
// Created by unifmcruz on 07/10/2019.
//

#include "Produto.h"
#include "Fila.h"

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

    Fila<Produto> fila;

    void InserirProduto(){
        string nome;
        int quantidade, tamanho;
        double preco;
        //Criando as variáveis nome, quantidade, tamanho , preco(preço) podemos receber as informações através do usuário.

        bool tenteTamanho, tentePreco;
        //As variáveis 'tenteTamanho' e 'tentePreco' servem como pivôs para testes de condição.

        cout << "Digite o nome do(s) produto(s)" << endl;
        cin >> nome;
        //Recebe o nome.

        cout << "Digite a quantidade de produtos" << endl;
        cin >> quantidade;
        //Recebe a quantidade.

        do{
            tenteTamanho = false;
            cout << "Digite o tamanho do(s) produto(s) (1-Pequeno 2-Médio 3-Grande" << endl;
            cin >> tamanho;
            tamanho--;
            if (tamanho < 0 || tamanho > 2) {
                tenteTamanho = true;
                cout << "Tamanho inválido, tente novamente" << endl;
            }
        }while(tenteTamanho);
        //No escopo do 'do' acima, recebemos o tamanho do produto, caso este não seja válido um loop se inicia até que um novo valor seja válido.
        //Este novo valor é uma escolha do usuário como o primeiro.

        do{
            tentePreco = false;
            cout << "Digite o preço equivalente a um produto" << endl;
            cin >> preco;
            if (preco < 0.00 || preco >= 5000.00) {
                tentePreco = true;
                cout << "Preço inválido, tente novamente" << endl;
            }
        }while(tentePreco);
        //No escopo deste 'do', recebemos, desta vez, o preço referente a uma unidade do produto,
        // caso este não seja válido um loop se inicia até que um novo valor seja válido.
        //Este novo valor é uma escolha do usuário como o primeiro.

        Produto novo(quantidade,preco,tamanho);
//        fila.add(novo);
        //Por fim, é criado um objeto do tipo Produto com os parametros recebidos pelas variáveis anteriores.

        cout<<"Produto adicionado com sucesso."<<endl;
        cout<<"Id: "<<novo.getId()<<endl;//TODO testar ID
    };
    void RemoverProduto(int idx){

    };
    void BuscarProduto(int idx){

    };
    void ListarProduto(){

    };
};