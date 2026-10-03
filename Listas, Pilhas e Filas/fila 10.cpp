#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;  // tamanho máximo da fila

struct FilaCircular {
    int dados[MAX];
    int inicio;  // índice do primeiro elemento
    int fim;     // índice da próxima posição livre
    int tamanho; // quantidade de elementos atualmente na fila
};

// Inicializa a fila
void inicializar(FilaCircular &f) {
    f.inicio = 0;
    f.fim = 0;
    f.tamanho = 0;
}

// Verifica se está vazia
bool isEmpty(const FilaCircular &f) {
    return f.tamanho == 0;
}

// Verifica se está cheia
bool isFull(const FilaCircular &f) {
    return f.tamanho == MAX;
}

// Insere no final (enqueue)
void enqueue(FilaCircular &f, int valor) {
    if (isFull(f)) {
        cout << "Fila cheia!\n";
        return;
    }
    f.dados[f.fim] = valor;
    f.fim = (f.fim + 1) % MAX;  // "volta" para 0 quando chegar no fim
    f.tamanho++;
}

// Remove do início (dequeue)
void dequeue(FilaCircular &f) {
    if (isEmpty(f)) {
        cout << "Fila vazia!\n";
        return;
    }
    cout << "Removido: " << f.dados[f.inicio] << "\n";
    f.inicio = (f.inicio + 1) % MAX;  // "volta" para 0 quando chegar no fim
    f.tamanho--;
}

// Mostra o primeiro elemento (front)
void front(const FilaCircular &f) {
    if (isEmpty(f)) {
        cout << "Fila vazia!\n";
        return;
    }
    cout << "Primeiro elemento: " << f.dados[f.inicio] << "\n";
}

// Imprime toda a fila (na ordem FIFO)
void imprimir(const FilaCircular &f) {
    if (isEmpty(f)) {
        cout << "Fila vazia!\n";
        return;
    }

    cout << "Fila: ";
    int i = f.inicio;
    for (int count = 0; count < f.tamanho; count++) {
        cout << f.dados[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << "\n";
}

int main() {
    FilaCircular f;
    inicializar(f);

    // Exemplo de uso
    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);
    imprimir(f);          // 10 20 30

    dequeue(f);           // remove 10
    imprimir(f);          // 20 30

    enqueue(f, 40);
    enqueue(f, 50);
    imprimir(f);          // 20 30 40 50

    dequeue(f);           // remove 20
    dequeue(f);           // remove 30
    imprimir(f);          // 40 50

    // Agora podemos inserir mais elementos reutilizando o espaço
    enqueue(f, 60);
    enqueue(f, 70);
    imprimir(f);          // 40 50 60 70

    front(f);             // mostra 40

    return 0;
}