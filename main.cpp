#include <iostream>
#include "Fila.h"
#include "Produto.h"

std::string menuCrud(){
   return "\n1 - INSERIR PRODUTO\n2 - REMOVER PRODUTO\n3 - LISTAR PRODUTOS\n4 - SAIR\n";//TODO Colocar a função buscar produto
};

using namespace std;
int main() {
    std::cout << "================> Controle de Estoque <==============" << std::endl;
    int opc;

    while(opc != 4){
        cout << menuCrud();
        cout << "Digite uma opcao: ";
        cin >> opc;
        if(opc == 1){

        }

        if(opc == 2){

        }

        if(opc == 3){

        }
    }

    return 0;
}