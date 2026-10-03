#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    int idade;
    float altura;
};

int main(){
    Pessoa pessoa;

    cout << "Digite o nome da pessoa: (até 50 caracteres)";
    getline(cin, pessoa.nome);

    while (pessoa.nome.length() > 50) {
        cout << "Nome inválido. Digite novamente: ";
        getline(cin, pessoa.nome);
    }

    cout << "Idade: ";
    cin >> pessoa.idade;

    cout << "Altura (em metros, e use ponto decimal):";
    cin >> pessoa.altura;

    cout << "\nDados da pessoa:\n";
    cout << "Nome: " << pessoa.nome << "\n";
    cout << "Idade: " << pessoa.idade << "anos\n";
    cout << "Altura: " << pessoa.altura << "m\n";

    return 0;
}