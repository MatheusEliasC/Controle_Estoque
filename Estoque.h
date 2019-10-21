//
// Created by unifmcruz on 07/10/2019.
//

#include "Produto.h"
#include "Fila.h"
#include "LES.h"
#include "Arvore.h"
#include <sstream>
#include <cstdio>



#ifndef STOCKCONTROL_ESTOQUE_H
#define STOCKCONTROL_ESTOQUE_H

using namespace std;

class Estoque{
private:
    int capacidadeMax;
    //Fila <Produto> f(5);
    LES<Produto> l();
    //virtual ArvBin<int> a();
    int quantidadeAtual;


public:
    explicit Estoque(){ }
    explicit Estoque(int Max){
//        l().setTamanhoMax(Max);
        capacidadeMax = Max;
        quantidadeAtual = 0;
    }



    bool InserirProduto(){

        char buffer[80];
        string nomeStr;
        int quantidade = 0, tamanho = 0;
        double preco;
        //Criando as variáveis nome, quantidade, tamanho , preco(preço) podemos receber as informações através do usuário.

        bool tenteTamanho, tentePreco;
        //As variáveis 'tenteTamanho' e 'tentePreco' servem como pivôs para testes de condição.

        cout << "Digite o nome do(s) produto(s): ";
        //cin >> nome; //TODO Consertar erro de leitura da string nome.
        cin >> nomeStr;

        //Recebe o nome.
        cout << "Digite a quantidade de produtos: ";
        cin >> quantidade;
        //Recebe a quantidade.


        do{
            tenteTamanho = false;
            cout << "Digite o tamanho do(s) produto(s) (1-Pequeno 2-Médio 3-Grande): " << endl;
            cin >> tamanho;
            tamanho--;
            if (tamanho < 0 || tamanho > 2) {
                tenteTamanho = true;
                cout << "Tamanho inválido, tente novamente." << endl;
            }
        }while(tenteTamanho);
        //No escopo do 'do' acima, recebemos o tamanho do produto, caso este não seja válido um loop se inicia até que um novo valor seja válido.
        //Este novo valor é uma escolha do usuário como o primeiro.

        do{
            tentePreco = false;
            cout << "Digite o preço equivalente a um produto: " << endl;
            cin >> preco;
            if (preco < 0.00 || preco >= 5000.00) {
                tentePreco = true;
                cout << "Preço inválido, tente novamente." << endl;
            }
        }while(tentePreco);
        //No escopo deste 'do', recebemos, desta vez, o preço referente a uma unidade do produto,
        // caso este não seja válido um loop se inicia até que um novo valor seja válido.
        //Este novo valor é uma escolha do usuário como o primeiro.
        Produto novo(nomeStr, quantidade, preco, tamanho);
        //l().Insere(novo) retorna false quando a lista estiver cheia ou seja quando o número de elementos da lista for igual a capacidade maxima que foi passado pelo construtor.

        quantidadeAtual += quantidade; //Incrementa a quantidade atual de acordo com a quantidade de produtos inserida.
        //O estoque estará cheio quando a quantidadeAtual for maior ou igual a capacidade máxima.
        if(quantidadeAtual >= capacidadeMax){
            cout << "Estoque cheio!" << endl;
            return false;
        }

        //l().Insere(novo);
        //Por fim, é criado um objeto do tipo Produto com os parametros recebidos pelas variáveis anteriores.

        cout<<"Produto adicionado com sucesso!"<<endl;
        /*cout << "Nome do produto: "<< novo.getNome() << endl;
        cout << "Preco do produto: R$ "<< novo.getPreco() << endl;
        cout << "Quantidade: "<< novo.getQuantidade() << endl;
        cout << "Tamanho: "<< novo.getTamanho() << endl;*/
        cout << "Id: "<< novo.getId() << endl;
        strftime(buffer,80,"Data: %d/%m/%y", novo.getData());
        puts(buffer);
        return true;
    };

    Produto BuscarProduto(int id){
        /*for(int i=0;i<l().getN();i++){
            a().Insere(l().Busca(&i,0).getId());
        }
        return l().Busca(nullptr,a().Busca(id)->valor);*/
    };

    void RemoverProduto(){
       /* int idProduto;
        cout << "Digite o id do produto a ser removido" << endl;
        cin >> idProduto;
        Produto temp = BuscarProduto(idProduto);
        l().Remove(l().Busca(temp));
        cout << "Produto removido com sucesso" << endl;
        */
    };

    void ListarProduto(){
    };
};

//LES<Produto> Estoque::l() {
    //return LES<Produto>(0);
//}

#endif //STOCKCONTROL_ESTOQUE_H

