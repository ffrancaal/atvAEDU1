#include <iostream>
using namespace std;

struct Paciente{
    char nome[51];
    int idade;
    char diagnostico[101];
} paciente;

void exibirPacientes60(Paciente pacientes[], int quantidade){
    for (int i = 0; i < quantidade ; i++){
        if (pacientes[i].idade > 60){
            cout << "Nome: " << pacientes[i].nome << endl;
            cout << "Idade: " << pacientes[i].idade << endl;
            cout << "Diagnóstico: " << pacientes[i].diagnostico << "\n\n";
            cout << endl;
        };
    }
}

int main(){

    Paciente pacientes[]={
        {"João Silva", 65, "Hipertensão"},
        {"Maria Oliveira", 58, "Diabetes"},
        {"Carlos Souza", 72, "Artrite"},
        {"Ana Santos", 45, "Asma"},
        {"Pedro Lima", 80, "Doença cardíaca"}
    };

    int quantidade = sizeof(pacientes) / sizeof(pacientes[0]);
    exibirPacientes60(pacientes, quantidade);

    return 0;
}