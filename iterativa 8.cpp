#include <iostream>
using namespace std;

int maior_elemento(int vet[], int n) {
    int maior = vet[0];
    for(int i = n ; i>=1 ; i--){
        if (vet[i-1] > maior){
            maior = vet[i-1];
        }
    }
    return maior;
}

int main() {
    int vet[] = {10, 5, 99, 7, 3, 2, 17};
    int quantidade = sizeof(vet) / sizeof(vet[0]);

    cout << "Maior elemento: " << maior_elemento(vet, quantidade) << endl;

    return 0;
}