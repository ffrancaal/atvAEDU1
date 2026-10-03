#include <iostream>
#include <string>
using namespace std;

struct Carro{
    char modelo[31];
    int ano;
    float preco;
};

int main(){
    Carro* carro = new Carro; // Aloca memória dinamicamente para o carro

    cout << "Digite o modelo do carro: ";
    cin.getline(carro->modelo, 31);

    cout << "Digite o ano do carro: ";
    cin >> carro->ano;

    cout << "Digite o preco do carro: ";
    cin >> carro->preco;

    cout << "\nDados do carro:\n";
    cout << "Modelo: " << carro->modelo << "\n";
    cout << "Ano: " << carro->ano << "\n";
    cout << "Preco: " << carro->preco << "\n";

    delete carro; // Libera a memória alocada para o carro

    return 0;
}

