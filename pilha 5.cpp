#include <iostream>
#include <string>

using namespace std;

#define CAPACIDADE 5 // Tamanho maximo do vetor

struct Pilha {
    int itens[CAPACIDADE];
    int topo;
};

// Inicializa a pilha com topo em -1 (vazia)
void inicializar(Pilha &p) {
    p.topo = -1;
}

// Retorna true se a pilha estiver vazia, false caso contrario
bool isEmpty(Pilha &p) {
    return p.topo == -1;
}

// Verifica se a pilha atingiu a capacidade maxima (overflow)
bool isFull(Pilha &p) {
    return p.topo == CAPACIDADE - 1;
}

// Insere um elemento no topo da pilha
void push(Pilha &p, int valor) {
    if (isFull(p)) {
        cout << "Erro: Pilha cheia (Stack Overflow)!" << endl;
        return;
    }
    p.topo++;
    p.itens[p.topo] = valor;
    cout << "Elemento " << valor << " inserido com sucesso." << endl;
}

// Remove o elemento do topo da pilha
void pop(Pilha &p) {
    if (isEmpty(p)) {
        cout << "Erro: Pilha vazia (Stack Underflow)!" << endl;
        return;
    }
    cout << "Elemento " << p.itens[p.topo] << " removido do topo." << endl;
    p.topo--; // Apenas recua o indice do topo
}

// Exibe o elemento presente no topo da pilha sem remove-lo
void top(Pilha &p) {
    if (isEmpty(p)) {
        cout << "Pilha vazia! Nao ha elemento no topo." << endl;
        return;
    }
    cout << "Elemento no topo: " << p.itens[p.topo] << endl;
}

int main() {
    Pilha p;
    inicializar(p);

    cout << "--- Testando a Pilha com Vetor ---" << endl;
    cout << "A pilha esta vazia? " << (isEmpty(p) ? "Sim" : "Nao") << endl;

    // Inserindo elementos
    push(p, 10);
    push(p, 20);
    push(p, 30);

    // Consultando o topo
    top(p);

    // Removendo elementos
    pop(p);
    top(p);

    cout << "A pilha esta vazia? " << (isEmpty(p) ? "Sim" : "Nao") << endl;

    return 0;
}