#include <iostream>
#include <string>
using namespace std;

struct Produto{
    string nome;
    int codigo;
    float preco;
} produto;

void ExibirProduto(Produto produto) {
    cout << "Nome do produto: " << produto.nome << "\n";
    cout << "Código: " << produto.codigo << "\n";
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
    cout << "Preço: R$" << produto.preco << "\n";
}

int main() {

    cout << "Digite o nome do produto: ";
    getline(cin, produto.nome);
    while (produto.nome.length() > 30) {
        cout << "Nome inválido. Digite novamente: ";
        getline(cin, produto.nome);
    }

    cout << "Digite o código do produto: ";
    cin >> produto.codigo;
    cin.ignore(); // Limpa o buffer do teclado

    cout << "Digite o preço do produto: ";
    cin >> produto.preco;
    cin.ignore(); // Limpa o buffer do teclado

    ExibirProduto(produto);

    return 0;
}