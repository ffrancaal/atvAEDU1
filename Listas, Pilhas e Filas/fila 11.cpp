#include <iostream>
#include <string>
using namespace std;

// Estrutura do cliente
struct Cliente {
    string nome;
    int senha;
};

// Estrutura do nó da fila
struct No {
    Cliente dado;
    No* prox;
};

// Estrutura da fila (com início e fim para eficiência)
struct Fila {
    No* inicio;
    No* fim;
    int tamanho;
};

// Inicializa a fila vazia
void iniciarFila(Fila& f) {
    f.inicio = nullptr;
    f.fim = nullptr;
    f.tamanho = 0;
}

// Verifica se a fila está vazia
bool isEmpty(Fila& f) {
    return f.tamanho == 0;
}

// Enqueue: adiciona cliente no final da fila
void enqueue(Fila& f, Cliente cliente) {
    No* novo = new No;
    novo->dado = cliente;
    novo->prox = nullptr;
    
    if (isEmpty(f)) {
        f.inicio = novo;
        f.fim = novo;
    } else {
        f.fim->prox = novo;
        f.fim = novo;
    }
    f.tamanho++;
    cout << "✓ Cliente " << cliente.nome << " (senha " << cliente.senha << ") entrou na fila!\n";
}

// Dequeue: remove e retorna o cliente do início da fila
Cliente dequeue(Fila& f) {
    if (isEmpty(f)) {
        cout << "⚠ Fila vazia! Ninguém para atender.\n";
        return {"", -1};
    }
    
    No* temp = f.inicio;
    Cliente cliente = temp->dado;
    f.inicio = f.inicio->prox;
    
    if (f.inicio == nullptr) {
        f.fim = nullptr;
    }
    
    delete temp;
    f.tamanho--;
    cout << "✓ Cliente " << cliente.nome << " (senha " << cliente.senha << ") foi atendido!\n";
    return cliente;
}

// Exibe a fila atual
void exibirFila(Fila& f) {
    if (isEmpty(f)) {
        cout << "📭 Fila vazia!\n";
        return;
    }
    
    cout << "📋 Fila atual:\n";
    No* atual = f.inicio;
    int pos = 1;
    while (atual != nullptr) {
        cout << "  " << pos << "º - " << atual->dado.nome 
             << " (senha " << atual->dado.senha << ")\n";
        atual = atual->prox;
        pos++;
    }
    cout << "Total: " << f.tamanho << " cliente(s)\n";
}

// Menu principal
int menu() {
    int opcao;
    cout << "\n=== BANCO SIMULADOR ===\n";
    cout << "1. Chegar cliente (entrar na fila)\n";
    cout << "2. Atender próximo cliente\n";
    cout << "3. Exibir fila\n";
    cout << "4. Sair\n";
    cout << "Opção: ";
    cin >> opcao;
    return opcao;
}

int main() {
    Fila banco;
    iniciarFila(banco);
    
    int opcao, senha = 1;
    string nome;
    
    do {
        opcao = menu();
        
        switch (opcao) {
            case 1:
                cout << "Nome do cliente: ";
                cin.ignore();
                getline(cin, nome);
                enqueue(banco, {nome, senha++});
                break;
                
            case 2:
                dequeue(banco);
                break;
                
            case 3:
                exibirFila(banco);
                break;
                
            case 4:
                cout << "Saindo...\n";
                break;
                
            default:
                cout << "⚠ Opção inválida!\n";
        }
    } while (opcao != 4);
    
    return 0;
}