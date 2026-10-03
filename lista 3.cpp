#include <iostream>
using namespace std;

struct lista{
    int valor;
    lista *proximo;
};

void inserir_ordenado(lista*& i, int valor) {
    lista* a = new lista;
    a->valor = valor;
    a->proximo = nullptr;

    // Lista vazia ou valor menor que o primeiro
    if (i == nullptr || valor < i->valor) {
        a->proximo = i;
        i = a;
        return;
    }

    lista* p = i;

    // Avança enquanto o próximo valor for menor ou igual ao novo
    while (p->proximo != nullptr && p->proximo->valor <= valor) {
        p = p->proximo;
    }

    a->proximo = p->proximo;
    p->proximo = a;
}