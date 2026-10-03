#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    float nota;
};

int main(){
    Aluno alunos[5];
    float SomaNotas = 0.0;

    for (int i = 0 ; i < 5 ; i++){
        cout << "Aluno " << i + 1 << ":\n";

        cout << "Nome: ";
        getline(cin, alunos[i].nome);

        cout << "Matrícula: ";
        cin >> alunos[i].matricula;

        cout << "Nota: ";
        cin >> alunos[i].nota;

        SomaNotas += alunos[i].nota;
        cin.ignore(); // Limpa o buffer do teclado para a próxima entrada
    }
    
    float media = SomaNotas / 5.0;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "\nMédia das notas: " << media << "\n";

    return 0;
}