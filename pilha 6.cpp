#include <iostream>
#include <string>
using namespace std;

bool parentesesBalanceados(string expressao) {
    string pilha; // Usaremos o fim da string como topo da pilha

    for (char caractere : expressao) {
        if (caractere == '(') {
            pilha.push_back(caractere); // Empilha
        } else if (caractere == ')') {
            if (pilha.empty()) {
                return false; // Encontrou ')' sem um '(' antes
            }
            pilha.pop_back(); // Desempilha um '('
        }
    }

    return pilha.empty(); // Sobrou algum '('?
}

int main() {
    string expressao;
    cout << "Digite a expressao: ";
    getline(cin, expressao);

    if (parentesesBalanceados(expressao)) {
        cout << "Valido" << endl;
    } else {
        cout << "Invalido" << endl;
    }

    return 0;
}