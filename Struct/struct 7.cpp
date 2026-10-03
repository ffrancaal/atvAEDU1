#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTATOS = 100;

struct Agenda{
    string nome;
    string telefone;
};

void addContact(Agenda* agenda, int index){
    cout << "\n--- Adicionando Contato [" << index + 1 << "] ---\n";

    cout << "Digite o nome: ";
    getline(cin, agenda[index].nome);
    while (agenda[index].nome.length() > 50) {
        cout << "Nome inválido. Digite novamente: ";
        getline(cin, agenda[index].nome);
    }


    cout << "Digite o telefone: ";
    getline(cin, agenda[index].telefone);
    while (agenda[index].telefone.length() > 15) {
        cout << "Telefone inválido. Digite novamente: ";
        getline(cin, agenda[index].telefone);
    }
    cout << "Contato cadastrado com sucesso!\n";
}

void getContact(Agenda* agenda,int total, string nome){
   bool encontrado = false;

   for (int i = 0 ; i<total ; i++){
    if (agenda[i].nome == nome){
        cout << "\n--- Contato Encontrado ---\n";
        cout << "Nome: " << agenda[i].nome << "\n";
        cout << "Telefone: " << agenda[i].telefone << "\n";
        encontrado = true;
        break;
        };

   if (!encontrado) {
       cout << "\n--- Contato não encontrado ---\n";
        }
    }}

int main(){
    int totalCadastrados = 0;
    Agenda agenda[MAX_CONTATOS];
    int opcao = 0;
    
    do {
        cout << "\n===== MENU AGENDA =====" << endl;
        cout << "1. Adicionar contato" << endl;
        cout << "2. Buscar contato por nome" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Limpa o caractere '\n' deixado pelo cin antes de usar getline()
        cin.ignore();

        if (opcao == 1) {
            if (totalCadastrados < MAX_CONTATOS) {
                addContact(agenda, totalCadastrados);
                totalCadastrados++;
            } else {
                cout << "Agenda cheia! Nao e possivel adicionar mais contatos.\n";
            }
        } else if (opcao == 2) {
            if (totalCadastrados == 0) {
                cout << "Agenda vazia. Cadastre contatos primeiro!\n";
            } else {
                string busca;
                cout << "Informe o nome exato para busca: ";
                getline(cin, busca);
                getContact(agenda, totalCadastrados, busca);
            }
        } else if (opcao == 3) {
            cout << "Encerrando programa...\n";
        } else {
            cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (opcao != 3);

    return 0;
};