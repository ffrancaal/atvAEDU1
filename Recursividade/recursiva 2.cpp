#include <iostream>
using namespace std;

int maior_elemento(int vet[], int n) {
    if (n == 1) {
        return vet[0];
    }

    int maior_anterior = maior_elemento(vet, n - 1);

    if (vet[n - 1] > maior_anterior) {
        return vet[n - 1];
    }

    return maior_anterior;
}

int main() {
    int vet[] = {10, 5, 99, 7, 3, 2, 17};
    int quantidade = sizeof(vet) / sizeof(vet[0]);

    cout << "Maior elemento: " << maior_elemento(vet, quantidade) << endl;

    return 0;
}