//
// Created by unifmcruz on 07/10/2019.
//

#include "Produto.h"
#include "Fila.h"
#include "LES.h"
#include "Arvore.h"
#include <sstream>
#include <cstdio>
#include <string.h>



#ifndef STOCKCONTROL_ESTOQUE_H
#define STOCKCONTROL_ESTOQUE_H

using namespace std;

class Estoque{
private:
    int capacidadeMax;
    LES<Produto> l;
    int quantidadeAtual;


public:
    explicit Estoque(){ }
    explicit Estoque(int Max){
        l.setTamanhoMax(Max);
        capacidadeMax = Max;
        quantidadeAtual = 0;
    }



    bool InserirProduto() {

        char buffer[80];
        string nomeStr;
        int quantidade = 0, tamanho = 0;
        string precoString;
        double preco;
        //Criando as variáveis nome, quantidade, tamanho , preco(preço) podemos receber as informações através do usuário.

        bool tenteTamanho, tentePreco;
        //As variáveis 'tenteTamanho' e 'tentePreco' servem como pivôs para testes de condição.

        cout << "Digite o nome do(s) produto(s): ";
        cin >> nomeStr;

        //Recebe o nome.
        cout << "Digite a quantidade de produtos: ";
        cin >> quantidade;
        //Recebe a quantidade.


        do {
            tenteTamanho = false;
            cout << "Digite o tamanho do(s) produto(s) (1-Pequeno 2-Médio 3-Grande): " << endl;
            cin >> tamanho;
            tamanho--;
            if (tamanho < 0 || tamanho > 2) {
                tenteTamanho = true;
                cout << "Tamanho inválido, tente novamente." << endl;
            }
        } while (tenteTamanho);
        //No escopo do 'do' acima, recebemos o tamanho do produto, caso este não seja válido um loop se inicia até que um novo valor seja válido.
        //Este novo valor é uma escolha do usuário como o primeiro.

        do {
            tentePreco = false;
            cout << "Digite o preço equivalente a um produto: " << endl;
            cin >> precoString;
            stringstream(precoString)>>preco;
            if (preco < 0.00 || preco >= 5000.00) {
                tentePreco = true;
                cout << "Preço inválido, tente novamente." << endl;
            }
        } while (tentePreco);
        //No escopo deste 'do', recebemos, desta vez, o preço referente a uma unidade do produto,
        // caso este não seja válido um loop se inicia até que um novo valor seja válido.
        //Este novo valor é uma escolha do usuário como o primeiro.
        Produto novo(nomeStr, quantidade, preco, tamanho);
        //l().Insere(novo) retorna false quando a lista estiver cheia ou seja quando o número de elementos da lista for igual a capacidade maxima que foi passado pelo construtor.

        quantidadeAtual += quantidade; //Incrementa a quantidade atual de acordo com a quantidade de produtos inserida.
        //O estoque estará cheio quando a quantidadeAtual for maior ou igual a capacidade máxima.
        if (quantidadeAtual >= capacidadeMax) {
            cout << "Estoque cheio!" << endl;
            return false;
        }

        if (l.Insere(novo)){
            cout << endl << "Produto adicionado com sucesso!" << endl;
            //Por fim, é criado um objeto do tipo Produto com os parametros recebidos pelas variáveis anteriores.
            cout << "Informações do produto inserido: " << endl << endl
                 << "Nome: " << novo.getNome() << endl
                 << "Preco: R$ " << novo.getPreco() << endl
                 << "Quantidade: " << novo.getQuantidade() << endl
                 << "Tamanho: " << novo.getTamanho() << endl
                 << "Id: " << novo.getId() << endl;
            strftime(buffer, 80, "Data da inserção: %d/%m/%y", novo.getData());
            puts(buffer);
            return true;
        }
        else {
            cout << "Erro ao inserir produto na LES!" << endl;
            return false;
        }

    };

    Produto BuscarProduto(int id){
        //TODO Implementar Buscar com Árvore
    };

    void RemoverProduto(){
        int pos, quantRemover;
        cout << "Escolha o produto: "<<endl;
        l.ImprimeTudo();
        cout << "Digite a posição do produto. Ou '0' para cancelar."<<endl;
        cin>>pos;
        if(pos == 0){
            cout << "Operação cancelada pelo usuário. Voltando ao menu..." << endl;
            return;
        }
        cout << l.BuscaPos(pos-1).getNome()<< endl;
        int quantidade = l.BuscaPos(pos-1).getQuantidade();
        cout << "O produto na posição "<< pos << " contém "<< quantidade << " de produtos." << endl;
        cout << "Digite a quantidade desse tipo de produto que você deseja remover. Ou '0' para cancelar." << endl;
        cin  >> quantRemover;
        if(quantRemover == 0){
            cout << "Operação cancelada pelo usuário. Voltando ao menu..." << endl;
            return;
        }
        else if(quantRemover < quantidade){
            l.BuscaPos(pos-1).setQuantidade(quantidade-quantRemover);
            cout << "Quantidade de produtos reajustada... Quantidade atual para o produto " << l.BuscaPos(pos-1).getNome()
                 << " é igual a: " << l.BuscaPos(pos-1).getQuantidade() << endl;
        }
        else if(quantRemover = quantidade){
            if(l.Remove(pos-1))
                cout << "Produto removido com sucesso! Voltando ao menu..."<<endl;
            else
                cout << "Erro ao remover o produto da LES!" << endl;
        }
        else if(quantRemover < quantidade){
            cout << "A quantidade inserida é menor do que existe no estoque para este produto!" << endl;
            cout << "Voltando ao menu..." << endl;//TODO OLHA AQUI, seria interessante fazer um loop para o usuário tentar novamente?
        }
        //TODO ARRUMAR SISTEMA DE REMOVER QUANTIDADE, ELE APARECE QUE REMOVE MAS NÃO REMOVE
    };

    void ListarTamanho(){
        //TODO Aplicar LDE
        cout << "Falta LDE!" << endl;
    };

    void ListarPreco(){
        //TODO Aplicar FILA
        cout << "Falta FILA!" << endl;
    };

    void ListarNome(){
        //TODO ORDEM ALFABÉTICA
        if(l.getN()<=0){
            cout << "Nenhum produto encontrado! Voltando ao menu..."<<endl;
            return;
        }

        l.ImprimeNome();
    };

    void ListarData(){
        //TODO Aplicar Pilha
        cout << "Falta Pilha!" << endl;
    };
};


#endif //STOCKCONTROL_ESTOQUE_H

