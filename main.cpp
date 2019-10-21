#include <iostream>
#include "Produto.h"
#include "Estoque.h"

std::string menuCrud(){
   return "\n1 - INSERIR PRODUTO\n2 - REMOVER PRODUTO\n3 - LISTAR PRODUTOS\n4 - BUSCAR PRODUTO\n5 - SAIR\n";
};

using namespace std;
int main() {
    std::cout << "================> Controle de Estoque <==============" << std::endl;
    int opc;
    Estoque e(100);

    while(opc != 5){
        cout << menuCrud();
        cout << "Digite uma opcao: ";
        cin >> opc;
        if(opc == 1){
            e.InserirProduto();
        }

        else if(opc == 2){
            /*int id;
            cout << "Digite o ID do produto: ";
            cin >> id;
            e.BuscarProduto(id);*/

        }

        else if(opc == 3){

        }

        else if(opc == 4){

        }
    }

    return 0;
}