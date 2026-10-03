#include <iostream>
using namespace std;

int soma_digitos(int n){
    if((n>-10) && (n<10)){
        return n;
    }
    return (n%10) + soma_digitos(n/10);

};

int main(){
    int n;

    cout << "Digite aqui o numero a ter seus digitos somados:";
    cin >> n;

    cout << "Aqui está a soma de todos os dígitos: " << soma_digitos(n) << endl;

    return 0;
}