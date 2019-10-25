#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "Produto.h"
#include "Estoque.h"


std::string menuCrud(){\
   return "\n1 - INSERIR PRODUTO\n2 - REMOVER PRODUTO\n3 - LISTAR PRODUTOS\n4 - BUSCAR PRODUTO\n5 - SAIR\n";
};

void menuListar(){\
    cout<< "\n/OPÇÕES DE LISTA:"<<endl;
    cout<< "\n1 - POR TAMANHO\n2 - POR PRECO\n3 - POR NOME\n4 - POR DATA\n5 - VOLTAR\n";
};

using namespace std;
int main() {
    cout << "================> Controle de Estoque <==============" << endl;
    cout << "╔═══════════════════════════════════════════════════════════════════════╗" << std::endl;
    cout << "║                                                                       ║" << std::endl;
    cout << "║                                                                       ║ " << std::endl;
    cout << "╚═══════════════════════════════════════════════════════════════════════╝" << std::endl;
    int opc;
    Estoque e(100);

    do{
        cout << menuCrud();
        cout << "Digite uma opcao: "<<endl;
        cin >> opc;
        cout << "╔═══════════════════════════════════════════════════════════════════════╗" << std::endl;
        cout << "║                                                                       ║" << std::endl;
        cout << "║                                                                       ║ " << std::endl;
        cout << "╚═══════════════════════════════════════════════════════════════════════╝" << std::endl;
        if(opc == 1){
            e.InserirProduto();
        }

        else if(opc == 2){
            e.RemoverProduto();
        }

        else if(opc == 3){
            menuListar();
            int opcLista;
            cin>>opcLista;
            switch(opcLista){
                case 1:
                    e.ListarTamanho();
                    break;
                case 2:
                    e.ListarPreco();
                    break;
                case 3:
                    e.ListarNome();
                    break;
                case 4:
                    e.ListarData();
                    break;
                case 5:
                    cout<< "Voltando ao menu!" << endl;
                    break;
                default:
                    cout <<"Opção não encontrada, tente novamente"<<endl;
            }
        }

        else if(opc == 4){
            //TODO IMPLEMENTEAR BUSCAR PRODUTO NA CLASSE ESTOQUE
        }

    }while(opc != 5);

    return 0;
}