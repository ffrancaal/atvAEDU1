#include <iostream>
using namespace std;

int contar_digitos(int n) {
    if (n > -10 && n < 10) {
        return 1; // Caso base: números de -9 a 9 têm um dígito
    }

    return 1 + contar_digitos(n / 10);
}

int main() {
    int n;

    cout << "Digite um numero inteiro: ";
    cin >> n;

    cout << "Quantidade de digitos: " << contar_digitos(n) << endl;

    return 0;
}