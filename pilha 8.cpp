#include <iostream>
#include <string>
using namespace std;

// Estrutura da pilha
struct Pilha {
    int dados[100];
    int topo = -1;
};

// Operações básicas
void push(Pilha& p, int valor) {
    p.topo++;
    p.dados[p.topo] = valor;
}

int pop(Pilha& p) {
    int valor = p.dados[p.topo];
    p.topo--;
    return valor;
}

bool isEmpty(Pilha& p) {
    return p.topo == -1;
}

// Função principal de conversão
string decimalParaBinario(int decimal) {
    Pilha pilha;
    
    // Caso especial: 0
    if (decimal == 0) {
        return "0";
    }
    
    // Divisões sucessivas e empilhamento dos restos
    while (decimal > 0) {
        int resto = decimal % 2;
        push(pilha, resto);
        decimal = decimal / 2;
    }
    
    // Desempilha e monta a string binária
    string binario = "";
    while (!isEmpty(pilha)) {
        binario += to_string(pop(pilha));
    }
    
    return binario;
}

int main() {
    int numero;
    
    cout << "Digite um número decimal: ";
    cin >> numero;
    
    string resultado = decimalParaBinario(numero);
    
    cout << "Binário: " << resultado << endl;
    
    return 0;
}