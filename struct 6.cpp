#include <iostream>
using namespace std;

struct Livro {
    char titulo[51];
    char autor[51];
    int anoPublicacao;
};

void exibeLivros(const Livro livros[], int quantidade, int anoLimite){
    bool encontrou = false;
    for(int i = 0; i < quantidade; i++){
        if(livros[i].anoPublicacao > anoLimite){
            cout << "Título: " << livros[i].titulo << "\n";
            cout << "Autor: " << livros[i].autor << "\n";
            cout << "Ano de Publicação: " << livros[i].anoPublicacao << "\n\n";
            encontrou = true;
        }
    }
    if(!encontrou){
        cout << "Nenhum livro encontrado publicado após " << anoLimite << ".\n";
    }
}

int main() {
    const int MAX_LIVROS = 5;
    Livro livros[MAX_LIVROS];
    int quantidade, anoLimite;

    cout << "Digite a quantidade de livros (até " << MAX_LIVROS << "): ";
    cin >> quantidade;

    while(quantidade < 1 || quantidade > MAX_LIVROS){
        cout << "Quantidade inválida. Digite novamente: ";
        cin >> quantidade;
    }

    for (int i = 0; i < quantidade; i++){
        cout << "Livro " << i+1 << ":\n";
        
        cout << "Título: ";
        cin >> ws; // Limpa o buffer do teclado
        cin.getline(livros[i].titulo, 51);

        cout << "Autor: ";
        cin.getline(livros[i].autor, 51);

        cout << "Ano de Publicação: ";
        cin >> livros[i].anoPublicacao;
    }

    cout << "Digite o ano limite para exibir livros publicados após ele: ";
    cin >> anoLimite;
    exibeLivros(livros, quantidade, anoLimite);

    return 0;
}
