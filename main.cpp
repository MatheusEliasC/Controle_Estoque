#include <iostream>
#include "Produto.h"

std::string menuCrud(){
   return "\n1 - INSERIR PRODUTO\n2 - REMOVER PRODUTO\n3 - LISTAR PRODUTOS\n4 - BUSCAR PRODUTO\n5 - SAIR\n";
};

using namespace std;
int main() {
    std::cout << "================> Controle de Estoque <==============" << std::endl;
    int opc;

    while(opc != 5){
        cout << menuCrud();
        cout << "Digite uma opcao: ";
        cin >> opc;
        if(opc == 1){

        }

        else if(opc == 2){

        }

        else if(opc == 3){

        }

        else if(opc == 4){

        }
    }

    return 0;
}