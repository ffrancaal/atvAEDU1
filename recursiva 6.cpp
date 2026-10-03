#include <iostream>
#include <string>
using namespace std;

int verificar(const string& texto, int inicio, int fim) {
    if (inicio >= fim) {
        return 1; // Chegou ao meio sem encontrar diferenças
    }

    if (texto[inicio] != texto[fim]) {
        return 0;
    }

    return verificar(texto, inicio + 1, fim - 1);
}

int palindromo(const string& texto) {
    return verificar(texto, 0, static_cast<int>(texto.size()) - 1);
}

int main() {
    cout << palindromo("arara") << endl; // 1
    cout << palindromo("casa") << endl;  // 0
}