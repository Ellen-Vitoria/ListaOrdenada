#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include "listaOrdenada.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    ListaOrdenada<int> lista;
    int opc, num;


    //Menu
    do{
        cout<< "\n\t  L I S T A   O R D E N A D A\n" <<endl;
        cout<< "\t  1 - Inserir um Novo Número" <<endl;
        cout<< "\t  2 - Buscar um Elemento" <<endl;
        cout<< "\t  3 - Remover um Elemento" <<endl;
        cout<< "\t  4 - Exibir a Lista" <<endl;
        cout<< "\t  5 - Fim" <<endl;
        cout<< "\n\t  Selecione: ";
        cin>> opc;

        system("cls");

        cout<< "\n\t  L I S T A   O R D E N A D A\n\n";

        switch(opc){
            //Inserir um Número na Lista
            case 1:
                cout<< "\t  Número: ";
                cin>> num;
                lista.inserir(num);
                break;

            //Buscar um Elemento
            case 2:
                if(lista.listaVazia()){
                    cout<< "\t  Lista Vazia................";
                }
                else{
                    cout<< "\t  Número: ";
                    cin>> num;

                    if(lista.buscarElemento(num)){
                        cout<< "\n\t  Número encontrado na " <<lista.posicao(num)<< "ª Posição!";
                    }
                    else{
                        cout<< "\n\t  Não encontrado! ";
                    }
                }
                break;

            //Remover um Elemento
            case 3:
                if(lista.listaVazia()){
                    cout<< "\t  Lista Vazia................";
                }
                else{
                    cout<< "\t  Número: ";
                    cin>> num;

                    if(lista.buscarElemento(num)){
                        if(lista.remover(num)){
                            cout<< "\n\t  Removido! ";
                        }
                    }
                    else{
                        cout<< "\n\t  Não encontrado! ";
                    }
                }
                break;

            //Exibir Lista
            case 4:
                if(lista.listaVazia()){
                    cout<< "\t  Lista Vazia................";
                }
                else{
                    Node<int> *aux=lista.h;
                    cout<< "\t  Lista: ";
                    while(aux != NULL){
                        cout<< aux->info << "  ";
                        aux = aux->prox;
                    }
                }
                break;

            //Fim
            case 5:
                cout<< "\t  Fim........................\n\n\t ";
                return 0;
                break;

            //Se for digitado outro Valor
            default:
                continue;
                break;
        }
        cout<< "\n\n\t  ";
        system("pause");
        system("cls");
    }
    while(opc != 5);
}
