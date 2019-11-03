//
// Created by unifmcruz on 07/10/2019.
//

#include "Produto.h"
#include "Fila.h"
#include "LES.h"
#include "Arvore.h"
#include "Pilha.h"
#include "LDE.h"
#include <sstream>
#include <cstdio>
#include <string>
#include <algorithm>

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

    static string getValor(double valor){
        ostringstream strs;
        strs << valor;
        string valorStr = strs.str();
        replace( valorStr.begin(), valorStr.end(), '.', ',');
        return valorStr;
    }

    static Produto* bubble_sortPreco (Produto* vet, int max) {
        int flag;

        do {
            flag = 0;
            for (int i = 0; i < (max - 1); i++) {

                /* Verfica se o vetor está em ordem, no caso ele coloca em ordem crescente, para decrescente trocar '>' por '<' */
                if (vet[i].getPreco() > vet[i + 1].getPreco()) {
                    /* Caso não esteja, ordena */
                    Produto aux = vet[i];
                    vet[i] = vet[i + 1];
                    vet[i + 1] = aux;
                    flag = 1;
                }
            }
            /* Repete enquanto algum valor estiver fora de ordem */
        } while (flag == 1);

        Produto *v = vet;
        return v;
    }

    static Produto* bubble_sortTamanho (Produto* vet, int max) {
        int flag;

        do {
            flag = 0;
            for (int i = 0; i < (max - 1); i++) {

                /* Verfica se o vetor está em ordem, no caso ele coloca em ordem crescente, para decrescente trocar '>' por '<' */
                if (vet[i].getTamanho() > vet[i + 1].getTamanho()) {
                    /* Caso não esteja, ordena */
                    Produto aux = vet[i];
                    vet[i] = vet[i + 1];
                    vet[i + 1] = aux;
                    flag = 1;
                }
            }
            /* Repete enquanto algum valor estiver fora de ordem */
        } while (flag == 1);

        Produto *v = vet;
        return v;
    }

    bool InserirProduto() {

        //char buffer[80];
        string nomeStr, quantidadeStr, tamanhoStr;
        int quantidade = 0, tamanho = 0;
        string precoString;
        double preco;
        //Criando as variáveis nome, quantidade, tamanho , preco(preço) podemos receber as informações através do usuário.

        bool tenteTamanho, tentePreco, tenteQuant;
        //As variáveis 'tenteTamanho' e 'tentePreco' servem como pivôs para testes de condição.

        cout << "Digite o nome do(s) produto(s): ";
        getline(cin >> ws, nomeStr);
        //Recebe o nome.

        do {
            tenteQuant = false;
            cout << "Digite a quantidade de produtos: ";
            cin >> quantidadeStr;
            stringstream(quantidadeStr) >> quantidade;
            if (quantidade <= 0 || quantidade > 500) {
                cout << "Quantidade inválida, tente novamente!" << endl;
                tenteQuant = true;
            }
        }while (tenteQuant);
        //Recebe a quantidade.


        do {
            tenteTamanho = false;
            cout << "Digite o tamanho do(s) produto(s) (1-Pequeno 2-Médio 3-Grande): ";
            cin >> tamanhoStr;
            stringstream(tamanhoStr) >> tamanho;
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
            cout << "Digite o preço equivalente a um produto: ";
            cin >> precoString;
            replace( precoString.begin(), precoString.end(), ',', '.');
            stringstream(precoString) >> preco;
            if (preco <= 0.00 || preco >= 2500.00) {
                tentePreco = true;
                cout << "Preço inválido, tente novamente." << endl;
            }
        } while (tentePreco);
        //No escopo deste 'do', recebemos, desta vez, o preço referente a uma unidade do produto,
        // caso este não seja válido um loop se inicia até que um novo valor seja válido.
        //Este novo valor é uma escolha do usuário como o primeiro.
        //Produto novo(nomeStr, quantidade, preco, tamanho);
        //l().Insere(novo) retorna false quando a lista estiver cheia ou seja quando o número de elementos da lista for igual a capacidade maxima que foi passado pelo construtor.

        quantidadeAtual += quantidade; //Incrementa a quantidade atual de acordo com a quantidade de produtos inserida.
        //O estoque estará cheio quando a quantidadeAtual for maior ou igual a capacidade máxima.
        if (quantidadeAtual >= capacidadeMax) {
            cout << "Estoque cheio!" << endl;
            return false;
        }

        Produto novo(nomeStr, quantidade, preco, tamanho);
        if (l.Insere(novo)){
            cout << endl << "Produto adicionado com sucesso!" << endl << endl;
            //Por fim, é criado um objeto do tipo Produto com os parametros recebidos pelas variáveis anteriores.
            cout << "Informações do produto inserido: " << endl
                 << "Nome : " << novo.getNome() << endl
                 << "Preco: R$ " << getValor(novo.getPreco()) << endl
                 << "Quantidade: " << novo.getQuantidade() << endl
                 << "Tamanho: " << novo.getTamanho() << endl
                 << "Id: " << novo.getId() << endl;
//            strftime(buffer, 80, "Data da inserção: %d/%m/%y", novo.getData());
           // puts(buffer);
            return true;
        }
        else {
            cout << "Erro ao inserir produto na LES!" << endl;
            return false;
        }

    };

    bool BuscarProduto(int id){

        ArvBin<int> arv;
        if(l.getN() == 0){
            cout << "Erro ao inserir produtos na árvore! Nenhum produto encontrado!" << endl;
            return false;
        }

        for(int i=0;i<l.getN();i++){
            arv.Insere(l.BuscaPorPos(i).getId());
        }

        if(arv.Busca(id)){
            cout << "O produto foi encontrado." << endl;
            cout << "Deseja ver as informações do produto encontrado? (Sim ou Não)" << endl;
            string opc;
            int tolower ( int c );
            cin >> opc;
            for_each(opc.begin(), opc.end(), [](char & c){
                c = ::tolower(c);
            });
            if (opc.rfind("si", 0) == 0) {
                cout << "ID do produto: " << l.BuscaPorID(id).getId() << endl
                     << "Nome do produto: " << l.BuscaPorID(id).getNome() << endl
                     << "Quantidade de produto: " << l.BuscaPorID(id).getQuantidade() << endl
                     << "Tamanho do produto: " << l.BuscaPorID(id).getTamanho() << endl
                     << "Preço do produto: " << l.BuscaPorID(id).getPreco()<< endl
                     /*<< "Data de entrada no sistema: " << l.BuscaPorID(id).getData()<< endl << endl*/
                     << "Voltando ao menu..." << endl;
            }
            else{
                cout << "Retornando ao menu!" << endl;
            }
            return true;
        } else{
            cout << "Produto não encontrado! Retornando ao menu" << endl;
            return false;
        }
    };

    void RemoverProduto(){
        if(l.getN() <= 0){
            cout << "Erro ao remover produto! Estoque vazio!" << endl;
            return;
        }
        int pos, quantRemover;
        cout << "Escolha o produto: "<<endl;
        l.ImprimeTudo();
        cout << "Digite a posição do produto. Ou '0' para cancelar."<<endl;
        cin>>pos;
        if(pos == 0){
            cout << "Operação cancelada pelo usuário. Voltando ao menu..." << endl;
            return;
        }
        cout << "Produto selecionado: " << l.BuscaPorPos(pos-1).getNome() << endl;
        int quantidade = l.BuscaPorPos(pos-1).getQuantidade();
        bool tenteQuant;
        do {

            tenteQuant = false;
            cout << "O produto na posição " << pos << " contém " << quantidade << " de produtos." << endl;
            cout << "Digite a quantidade desse tipo de produto que você deseja remover. Ou '0' para cancelar." << endl;
            cin >> quantRemover;
            if (quantRemover == 0) {
                cout << "Operação cancelada pelo usuário. Voltando ao menu..." << endl;
                return;
            } else if (quantRemover < quantidade) {
                Produto novo(l.BuscaPorPos(pos-1).getNome(),quantidade-quantRemover,l.BuscaPorPos(pos-1).getPreco(),l.BuscaPorPos(pos-1).getTamanho());
                if(l.ReInsere(novo,pos-1))
                cout << "Quantidade de produtos reajustada... Quantidade atual para o produto "
                     << l.BuscaPorPos(pos - 1).getNome()
                     << " é igual a: " << l.BuscaPorPos(pos - 1).getQuantidade() << endl;
            } else if (quantRemover == quantidade) {
                if (l.Remove(pos - 1))
                    cout << "Produto removido com sucesso! Voltando ao menu..." << endl;
                else
                    cout << "Erro ao remover o produto da LES!" << endl;
            } else if (quantRemover < quantidade) {
                cout << "A quantidade inserida é menor do que existe no estoque para este produto!" << endl
                     << "Tente novamente..." << endl;
                tenteQuant = true;
            }
        }while(tenteQuant);
    };

    void ListarTamanho(){
        if(l.getN()==0){
            cout << "Nenhum produto encontrado! Voltando ao menu!" << endl;
            return;
        }

        //string *nomes = new string[l.getN()];


        //LDE<string> ld;
        LDE<string> ld;
        for(int i = 0; i < l.getN(); i++)
            ld.Insere("Produto " + to_string(i+1)+": "  + l.BuscaPorPos(i).getNome()+" | Tamanho: " + l.verificaTamanho(l.BuscaPorPos(i).getTamanho()));


//        Produto *temp = nullptr;
//        for(int i = 0;i<l.getN();i++){
//            temp[i]= l.BuscaPorPos(i);
//        }
//        Produto* v = bubble_sortTamanho(temp,l.getN());
//        LDE<Produto> ld;
//        for(int i = 0; i< l.getN(); i++){
//            ld.Insere(v[i]);
//        }

        cout << "Listando produtos: " << endl;
//        for(int i = 0; i < l.getN(); i++)
//            cout << l.BuscaPorPos(i).getNome() << " " << ld[i]  << endl;
        ld.Imprime();
//        for(int i = 0; i< l.getN(); i++){
//            ld.Remove(i);
//        }



        //TODO revisar bug de crash do código
        cout << "Voltando ao menu!" << endl;

    };

    void ListarPreco(){
        if(l.getN()<=0){
            cout << "Nenhum produto encontrado! Voltando ao menu..."<<endl;
            return;
        }
        Produto *temp = nullptr;
        for(int i = 0;i<l.getN();i++){
            temp[i]= l.BuscaPorPos(i);
        }
        Produto* v = bubble_sortPreco(temp,l.getN());
        Fila<Produto> fila(l.getN());
        for(int i = 0;i<l.getN();i++){
            fila.Enfileira(v[i]);
        }
        Produto* vetor = fila.Imprime();
        for(int i=0;i<l.getN();i++){
            cout << "Preço do produto: " << vetor[i].getPreco()
                 << "Nome do produto: " << vetor[i].getNome()
                 << "Quantidade de produto: " << vetor[i].getQuantidade()
                 << "Tamanho do produto: " << vetor[i].getTamanho()
                 << "ID do produto: " << vetor [i].getId();
        }
        for(int i = 0;i<l.getN();i++){
            fila.Desenfileira();
        }
        //TODO revisar bug de crash do código
        cout << "Voltando ao menu!" << endl;
    };

    void ListarNome(){
        if(l.getN()<=0){
            cout << "Nenhum produto encontrado! Voltando ao menu..."<<endl;
            return;
        }
        l.ImprimeNome();
    };

    void ListarData(){
        if(l.getN()<=0){
            cout << "Nenhum produto encontrado! Voltando ao menu..."<<endl;
            return;
        }
        Pilha<string> p(l.getN());

        bool ok;

        cout << "Lista de produtos (por data): " << endl;
        for(int i = 0; i < l.getN(); i++){
            p.Empilha(l.BuscaPorPos(i).dataHoraAtual());
            cout <<"Produto "<< i+1 << ": "<<  l.BuscaPorPos(i).getNome() << " | Id: "<< l.BuscaPorPos(i).getId()<< " | Data: "<< p.Desempilha(&ok) << endl;
        }

        return;
    };
};


#endif //STOCKCONTROL_ESTOQUE_H

