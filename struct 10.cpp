#include <iostream>
using namespace std;

struct ContaBancaria {
    char titular[51];
    int num_conta;
    float saldo;
} conta_bancaria;

void depositar(){
    int valor;
    cout << "Digite o valor a ser depositado: ";
                    cin >> valor;
                    conta_bancaria.saldo += valor;
                    cout << "Depósito realizado com sucesso!\n";
}

void sacar(){
    int valor;
    cout << "Digite o valor de saque: ";
    cin >> valor;
    if (valor > conta_bancaria.saldo){
        cout << "Saldo insuficiente para saque!\n";
    } else {
        conta_bancaria.saldo -= valor;
        cout << "Saque realizado com sucesso!\n";
    }
}

void exibirSaldo(){
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "Saldo atual: R$" << conta_bancaria.saldo << "\n";
}

int main() {
    int opcao;
    cout << "Digite o nome do titular da conta: ";
    cin.getline(conta_bancaria.titular, 51);

    cout << "Digite o número da conta: ";
    cin >> conta_bancaria.num_conta;

    cout << "Digite o saldo inicial da conta: ";
    cin >> conta_bancaria.saldo;

    cout << "Criamos sua conta, " << conta_bancaria.titular << "!\n";
    
   do { cout << "---Menu de operações---\n";
        cout << "1. Depositar\n";
        cout << "2. Sacar\n";
        cout << "3. Exibir saldo\n";
        cout << "4. Sair\n";

        cout << "Escolha uma opção: ";
        cin >> opcao;
            switch (opcao){
                case 1:
                    depositar();
                case 2:
                    sacar();
                case 3:
                    exibirSaldo();

            }
        } while (opcao < 4 && opcao > 0);

        cout << "Obrigado por utilizar nosso sistema bancário, " << conta_bancaria.titular << "!\n";

 return 0;
}