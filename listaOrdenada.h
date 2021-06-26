#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED
#include <iostream>

using namespace std;

template <typename Tipo>

struct Node{
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>

struct ListaOrdenada{
    Node<Tipo> *h; //Head: cabeça da Lista

    //Estado Inicial
    ListaOrdenada(){
        h=NULL;
    }

    bool listaVazia(){
        return h==NULL;
    }

    void inserir(Tipo x){
        Node<Tipo> *aux2;
        Node<Tipo> *aux = new Node<Tipo>;
        aux->info=x;
        //Se lista vazia ou novo elemento seja menor que a cabeça da Lista
        if(h == NULL || x < h->info){
            aux->prox=h;
            h = aux;
        }
        else{
            aux2=h; //Aux recebe head
            //Poderia ser while(aux!=NULL && x>aux2->info), mas haveria conflito ao encontrar elemento maior que "x" atual
            while(aux2->prox!=NULL && x > aux2->prox->info){
                aux2 = aux2->prox; //Aux2 aponta para o próximo
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

    bool buscarElemento(Tipo x){
        Node<Tipo> *aux=h;

        while(aux != NULL){
            if(x == aux->info){
                return true;
            }
            aux = aux->prox;
        }
        return false;
    }

    int posicao(Tipo x){
         Node<Tipo> *aux = h;
         int pos = 1;

         while(aux != NULL){
            if(x == aux->info){
                return pos;
            }
            aux = aux->prox;
            pos++;
        }
    }

    bool remover(Tipo x){
        //Se Lista é vazia ou se Número a ser removido é menor ao Elemento que está na Cabeça da Lista
        if (h == NULL || x < h->info){
            return false;
        }
        else{
            //Se Número a ser removido é igual ao elemento da Cabeça da Lista
            if(x == h->info){
                Node<Tipo> *aux = h;
                h = h->prox; //O próximo Valor se torna a Cabeça da Lista
                delete aux;
                return true;
            }

            Node<Tipo> *aux = h;

            //Enquanto próximo Elemento não for NULL e Número for maior que ele
            while (aux->prox != NULL && x > aux->prox->info){
                aux = aux->prox;
            }

            //Se o próximo Elemento para o qual o aux atual está apontando é NULL ou se é diferente de Número a ser removido
            if (aux->prox == NULL || aux->prox->info != x){
                return false;
            }
            else{
                aux->prox = aux->prox->prox;
                return true;
            }
        }
    }
/*
    void remover(Tipo x){
        Node<Tipo> *aux;

        //Se Número é igual ao Elemento da Cabeça da Lista
        if(x == h->info){
            aux = h->prox;
            delete h;
            h = aux; //O próximo Valor se torna a Cabeça da Lista
        }
        else{
            aux = h; //Aux recebe a Cabeça da Lista
            Node<Tipo> *aux2;

            while(aux != NULL){
                //Se Número for igual ao info para qual aux->prox está apontando, ou seja, o próximo Valor
                if(x == aux->prox->info){
                    //cout<< "Aux->prox->info = " << aux->prox->info;
                    aux2 = aux->prox;
                    aux->prox = aux2->prox;
                    //cout<< "Aux->prox->info = " << aux->prox->info;
                    delete aux2;
                }
                aux = aux->prox;
            }
        }
}*/
};

#endif // LISTAORDENADA_H_INCLUDED
