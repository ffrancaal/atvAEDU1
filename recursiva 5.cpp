#include <iostream>
using namespace std;

void contagem_regressiva(int num) {
    cout << num << endl;  // Imprime o número atual

    if (num == 0) {       // Caso base: para depois de imprimir o 0
        return;
    }

    contagem_regressiva(num - 1);}

int main() {
    int n;

    cout << "Digite aqui o numero: ";
    cin >> n;

    if (n < 0) {
        cout << "Digite um numero maior ou igual a 0." << endl;
        return 0;
    }

    contagem_regressiva(n);
    return 0;
}