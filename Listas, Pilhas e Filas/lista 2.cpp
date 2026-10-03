#include <iostream>
#include <string>
using namespace std;

struct lista{
    int valor;
    lista *proximo;
};

void inserir_inicio(lista*& i, int valor){
    lista * a = new lista; // a é o novo nó
    a->valor = valor;
    a-> proximo = i; // aponta para o antigo primeiro nó.
    i = a; // mudamos o head para esse novo nó adicionado.
}

void inserir_fim(lista*& i, int valor){
    lista * a = new lista; // cria o novo nó
    a->valor = valor; // preenche o valor
    a-> proximo = nullptr; // aponta PROXIMO para vazio

    if (i == nullptr) {
        i = a;             // lista vazia: a vira o primeiro nó
        return;
    }

    lista* p = i;
    while (p->proximo != nullptr) {
        p = p->proximo;
    }

    p->proximo = a;        // liga o antigo último nó ao novo
}

bool remover(lista*& i, int valor) {
    if (i == nullptr) {
        return false; // lista vazia
    }

    if (i->valor == valor) {
        lista* a = i;
        i = i->proximo;
        delete a;
        return true;
    }

    lista* p = i;

    // Para quando o PRÓXIMO nó contém o valor procurado
    while (p->proximo != nullptr && p->proximo->valor != valor) {
        p = p->proximo;
    }

    if (p->proximo == nullptr) {
        return false; // valor não encontrado
    }

    lista* a = p->proximo; // nó que será removido
    p->proximo = a->proximo;
    delete a;
    return true;
}

void exibir(lista* i) {
    lista* p = i;

    while (p != nullptr) {
        cout << p->valor << " -> ";
        p = p->proximo;
    }

    cout << "NULL\n";
}

void contar(lista* i){
    lista* p = i;
    int contador = 0;
    while(p!=nullptr){
        contador++;
        p = p->proximo; //avançar pro proximo
    }
    cout << contador << " itens na lista." << endl;
    return;
}

int main() {
    lista *i = nullptr, *a, *p;

    int opcao, valor;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1 - Inserir no inicio\n";
        cout << "2 - Inserir no final\n";
        cout << "3 - Remover um valor\n";
        cout << "4 - Exibir a lista\n";
        cout << "5 - Contar quantos elementos a lista possui\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                inserir_inicio(i, valor);
                break;

            case 2:
                cout << "Digite o valor: ";
                cin >> valor;
                inserir_fim(i, valor);
                break;

            case 3:
                cout << "Digite o valor a remover: ";
                cin >> valor;

                if (remover(i, valor)) {
                    cout << "Valor removido.\n";
                } else {
                    cout << "Valor nao encontrado.\n";
                }
                break;

            case 4:
                exibir(i);
                break;
            
            case 5:
                contar(i);
                break;
            case 0:
                cout << "Encerrando...\n";
                break;

            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    return 0;
}