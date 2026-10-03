#include <iostream>
#include <string>
using namespace std;

struct No {
    char letra;
    No* prox;
};

// Insere no topo da pilha
No* push(No* topo, char letra) {
    No* novo = new No;
    novo->letra = letra;
    novo->prox = topo;
    return novo;
}

// Remove e retorna o topo da pilha
No* pop(No* topo, char &letra) {
    if (topo == NULL) {
        return NULL;
    }

    letra = topo->letra;
    No* temp = topo;
    topo = topo->prox;
    delete temp;

    return topo;
}

bool isEmpty(No* topo) {
    return topo == NULL;
}

int main() {
    string texto;
    No* pilha = NULL;
    string invertida = "";

    cout << "Digite uma palavra: ";
    cin >> texto;

    // 1) Empilha todas as letras
    for (int i = 0; i < texto.length(); i++) {
        pilha = push(pilha, texto[i]);
    }

    // 2) Desempilha e monta a string invertida
    char letra;
    while (!isEmpty(pilha)) {
        pilha = pop(pilha, letra);
        invertida += letra;
    }

    cout << "String invertida: " << invertida << endl;

    return 0;
}