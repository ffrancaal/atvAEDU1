#include <iostream>
using namespace std;

void contagem(int n){
    for(int i = n ; i >= 0; i--){
        cout << i << endl;
    } return;
}

int main(){
    int n;

    cout << "Digite o numero que deseja a contagem: ";
    cin >> n;
    while(n<0){
        cout << "Digite um número igual ou maior do que 0.";
        cin >> n;}
    
    contagem(n);

    return 0;
}