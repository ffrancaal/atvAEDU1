#include <iostream>
using namespace std;

struct Retangulo {
    float base;
    float altura;
} retangulo;

float calcularArea(Retangulo retangulo) {
    return retangulo.base * retangulo.altura;
}

float calcularPerimetro(Retangulo retangulo) {
    return 2 * (retangulo.base + retangulo.altura);
}

main(){

    cout<< "Digite a base do retângulo: ";
    cin >> retangulo.base;

    cout << "Digite a altura do retângulo: ";
    cin >> retangulo.altura;

    cout << "Área do retângulo: " << calcularArea(retangulo) << "\n";
    cout << "Perímetro do retângulo: " << calcularPerimetro(retangulo) << "\n"; 

    return 0;
}