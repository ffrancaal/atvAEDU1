#include <iostream>
using namespace std;

struct lista{
    int valor;
    lista *proximo;
};


void reverter(lista*& i) {
    lista* anterior = nullptr;
    lista* p = i;
    lista* a = nullptr;

    while (p != nullptr) {
        a = p->proximo;          // guarda o próximo nó
        p->proximo = anterior;   // inverte a ligação
        anterior = p;            // avança o anterior
        p = a;                   // avança o atual
    }

    i = anterior; // atualiza o início da lista
}