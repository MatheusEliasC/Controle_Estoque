#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <locale>
#include "Produto.h"
#include "Estoque.h"

using namespace std;

void menuCrud() {
//    cout << "?????????????????????????????????????????????????????????????????????????" << std::endl;
//    cout << "?     INSERIR PRODUTO                                                   ?" << std::endl;
//    cout << "?     REMOVER PRODUTO                                                   ?" << std::endl;
//    cout << "?     LISTAR PRODUTOS                                                   ? " << std::endl;
//    cout << "?     BUSCAR PRODUTO                                                    ?" << std::endl;
//    cout << "?     SAIR                                                              ? " << std::endl;
//    cout << "?                                                                       ?" << std::endl;
//    cout << "?                                                                       ? " << std::endl;
//    cout << "?                                                                       ? " << std::endl;
//    cout << "?????????????????????????????????????????????????????????????????????????" << std::endl;
//TODO ARRUMAR S?MBOLOS DE CAIXA, ESTES EST?O COM ERRO NA IMPRESS?O!
    cout << "+.......................................................................+" << std::endl;
    cout << "|                         1- INSERIR PRODUTO                            |"<< endl;
    cout << "|                         2- REMOVER PRODUTO                            |"<< endl;
    cout << "|                         3- LISTAR PRODUTOS                            |"<< endl;
    cout << "|                         4- BUSCAR PRODUTO5                            |"<< endl;
    cout << "|                                                                       |"<< endl;
    cout << "|                               5- SAIR                                 |"<< endl;
    cout << "+.......................................................................+" << std::endl;
};

void menuListar(){\
    cout<< "\n/OP??ES DE LISTA:"<<endl;
    cout<< "\n1 - POR TAMANHO\n2 - POR PRECO\n3 - POR NOME\n4 - POR DATA\n5 - VOLTAR\n";
};

int main() {
    setlocale(LC_ALL,"Portuguese");
    cout <<   "================} Controle de Estoque {==============" << endl;
//    cout << "?????????????????????????????????????????????????????????????????????????" << endl;
//    cout << "?  INSERIR PRODUTO  - REMOVER PRODUTO  n3 - LISTAR PRODUTOSn4 - BUSCAR PRODUTO5 - SAIR"<< endl;                                                                     ?" << std::endl;
//    cout << "?                                                                       ? " << endl;
//    cout << "?????????????????????????????????????????????????????????????????????????" << endl;
    int opc = 0;
    Estoque e(100);


    do{
        bool tenteOpc = false;
        menuCrud();
        cout << "Digite uma opcao: "<<endl;
        cin >> opc;

        //Validando a entrada do usu?rio.
        while(true)
        {
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Entre com uma op??o v?lida: "<<endl;
                cin>>opc;
            }
            if(!cin.fail()){
                break;
            }
        }

        switch(opc){
            case 1://Inserir
                e.InserirProduto();
                break;

            case 2://Remover
                e.RemoverProduto();
                break;

            case 3://Listar
                menuListar();
                int opcLista;
                cin >> opcLista;
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
                        cout <<"Op??o n?o encontrada, tente novamente"<<endl;
                }
                break;

            case 4: //Buscar
                cout << "Digite o id do produto que est? buscando. Digite 0 para voltar." << endl;
                int buscar;
                cin >> buscar;
                if(buscar == 0){
                    cout<< "Voltando ao menu!" << endl;
                    break;
                }
                else{
                    e.BuscarProduto(buscar);
                }
                break;

            case 5: //Sair
                cout << "At? mais!" << endl;
                break;

            default:
                cout << "Op??o n?o encontrada, tente novamente!" << endl;
        }
    }while(opc != 5);

    return 0;
}