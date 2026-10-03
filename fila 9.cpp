#include <iostream>
#include <string>
using namespace std;

#define MAX 100  // Tamanho máximo da fila

struct Fila {
    int dados[MAX];
    int frente;  // índice do primeiro elemento
    int tras;    // índice do próximo espaço disponível
    int tamanho; // quantidade de elementos na fila
};

// Inicializa a fila
void iniciarFila(Fila &f) {
    f.frente = 0;
    f.tras = 0;
    f.tamanho = 0;
}

// Verifica se a fila está vazia
bool isEmpty(Fila &f) {
    return f.tamanho == 0;
}

// Verifica se a fila está cheia
bool isFull(Fila &f) {
    return f.tamanho == MAX;
}

// enqueue: inserir elemento no final da fila
void enqueue(Fila &f, int valor) {
    if (isFull(f)) {
        cout << "Fila cheia!" << endl;
        return;
    }
    f.dados[f.tras] = valor;
    f.tras = (f.tras + 1) % MAX;  // volta ao início se chegar no fim (circular)
    f.tamanho++;
}

// dequeue: remover elemento do início da fila
void dequeue(Fila &f) {
    if (isEmpty(f)) {
        cout << "Fila vazia!" << endl;
        return;
    }
    f.frente = (f.frente + 1) % MAX;  // avança o início
    f.tamanho--;
}

// front: exibir o primeiro elemento (sem remover)
int front(Fila &f) {
    if (isEmpty(f)) {
        cout << "Fila vazia!" << endl;
        return -1;  // valor especial indicando erro
    }
    return f.dados[f.frente];
}

// Exibir todos os elementos da fila (extra, para teste)
void imprimirFila(Fila &f) {
    if (isEmpty(f)) {
        cout << "Fila vazia!" << endl;
        return;
    }
    cout << "Fila: ";
    int i = f.frente;
    for (int count = 0; count < f.tamanho; count++) {
        cout << f.dados[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    Fila minhaFila;
    iniciarFila(minhaFila);
    
    cout << "=== Testando Fila com Vetor ===" << endl << endl;
    
    // Testando isEmpty
    cout << "Fila vazia? " << (isEmpty(minhaFila) ? "Sim" : "Nao") << endl;
    
    // Testando enqueue
    cout << "\nInserindo elementos: 10, 20, 30" << endl;
    enqueue(minhaFila, 10);
    enqueue(minhaFila, 20);
    enqueue(minhaFila, 30);
    imprimirFila(minhaFila);
    
    // Testando front
    cout << "\nPrimeiro elemento (front): " << front(minhaFila) << endl;
    
    // Testando dequeue
    cout << "\nRemovendo primeiro elemento..." << endl;
    dequeue(minhaFila);
    imprimirFila(minhaFila);
    cout << "Novo primeiro elemento: " << front(minhaFila) << endl;
    
    // Testando isEmpty novamente
    cout << "\nFila vazia? " << (isEmpty(minhaFila) ? "Sim" : "Nao") << endl;
    
    return 0;
}