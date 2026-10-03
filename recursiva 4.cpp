#include <iostream>
using namespace std;

int produto(int n1, int n2){
    if(n1 == 0 || n2 == 0){
        return 0;
    }
    else if (n1 == 1){
        return n2;
    }
    else if (n2 == 1){
        return n1;
    }

    return n1 + produto(n1, n2 - 1);
}

int main() {
    int n1, n2;

    cout << "Digite N1: ";
    cin >> n1;

    cout << "Digite N2: ";
    cin >> n2;

    cout << "O produto entre " << n1 << " e " << n2 << " é: " << produto(n1,n2) << endl;

    return 0;
}