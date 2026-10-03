#include <iostream>
#include <string>
using namespace std;

// Estrutura da Pilha (LIFO)
struct Pilha {
    int dado;
    Pilha* prox;
};

// Estrutura da Fila (FIFO) - vamos precisar de início e fim
struct Fila {
    int dado;
    Fila* prox;
};

// Operações da Pilha
Pilha* push(Pilha* topo, int valor) {
    Pilha* novo = new Pilha;
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

Pilha* pop(Pilha* topo, int& valor) {
    if (topo == NULL) return NULL;
    valor = topo->dado;
    Pilha* temp = topo;
    topo = topo->prox;
    delete temp;
    return topo;
}

bool isEmpty(Pilha* topo) {
    return topo == NULL;
}

// Operações da Fila
Fila* enqueue(Fila* fim, int valor, Fila*& inicio) {
    Fila* novo = new Fila;
    novo->dado = valor;
    novo->prox = NULL;
    
    if (fim != NULL) {
        fim->prox = novo;
    } else {
        inicio = novo;
    }
    return novo;
}

Fila* dequeue(Fila* inicio, int& valor, Fila*& fim) {
    if (inicio == NULL) return NULL;
    valor = inicio->dado;
    Fila* temp = inicio;
    inicio = inicio->prox;
    delete temp;
    
    if (inicio == NULL) {
        fim = NULL;
    }
    return inicio;
}

bool isEmpty(Fila* inicio) {
    return inicio == NULL;
}

// Função que inverte a fila usando pilha auxiliar
void inverterFila(Fila*& inicio, Fila*& fim) {
    Pilha* pilha = NULL;
    int valor;
    
    // Passo 1: Descarregar toda a fila na pilha
    while (inicio != NULL) {
        inicio = dequeue(inicio, valor, fim);
        pilha = push(pilha, valor);
    }
    
    // Passo 2: Descarregar a pilha de volta na fila (agora invertido)
    while (!isEmpty(pilha)) {
        pilha = pop(pilha, valor);
        fim = enqueue(fim, valor, inicio);
    }
}

// Função auxiliar para imprimir a fila
void imprimirFila(Fila* inicio) {
    if (inicio == NULL) {
        cout << "Fila vazia!" << endl;
        return;
    }
    
    Fila* atual = inicio;
    cout << "Fila: ";
    while (atual != NULL) {
        cout << atual->dado;
        if (atual->prox != NULL) cout << " <- ";
        atual = atual->prox;
    }
    cout << endl;
}

int main() {
    Fila* inicio = NULL;
    Fila* fim = NULL;
    
    // Inserindo elementos: 1, 2, 3, 4, 5
    fim = enqueue(fim, 1, inicio);
    fim = enqueue(fim, 2, inicio);
    fim = enqueue(fim, 3, inicio);
    fim = enqueue(fim, 4, inicio);
    fim = enqueue(fim, 5, inicio);
    
    cout << "Antes de inverter:" << endl;
    imprimirFila(inicio);
    
    inverterFila(inicio, fim);
    
    cout << "\nDepois de inverter:" << endl;
    imprimirFila(inicio);
    
    return 0;
}