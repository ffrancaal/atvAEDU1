#include <iostream>
using namespace std;

struct Funcionario {
    char nome[51];
    char cargo[31];
    float salario;
} ;

void cadastrarFuncionarios(int qtdFuncionarios, Funcionario* funcionarios){

    for(int i=0 ; i<qtdFuncionarios; i++){
        cout << "Digite o nome do funcionário " << i+1 << ": ";
        cin >> ws; // Limpa o buffer do teclado
        cin.getline(funcionarios[i].nome, 51);

        cout << "Digite o cargo do funcionário " << i+1 << ": ";
        cin.getline(funcionarios[i].cargo, 31);

        cout << "Digite o salário do funcionário " << i+1 << ": ";
        cin >> funcionarios[i].salario;
    }
}

void ExibirFuncionarios(int qtdFuncionarios, Funcionario* funcionarios){
    for(int i=0; i<qtdFuncionarios; i++){
        cout << "\nFuncionário " << i+1 << ":\n";
        cout << "Nome: " << funcionarios[i].nome << "\n";
        cout << "Cargo: " << funcionarios[i].cargo << "\n";
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << "Salário: R$" << funcionarios[i].salario << "\n";
    }
}

int main(){
    int n;

    cout << "Digite a quantidade de funcionários: ";
    cin >> n;

    Funcionario* funcionarios = new Funcionario[n]; // Aloca memória dinamicamente para os funcionários

    cadastrarFuncionarios(n, funcionarios);
    ExibirFuncionarios(n, funcionarios);

    delete[] funcionarios; // Libera a memória alocada

    return 0;
}