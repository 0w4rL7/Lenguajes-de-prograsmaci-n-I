#include <iostream>

 using namespace std;
 int main() {
    int edad;
    cout << "Coloca tu edad: ";
    cin >> edad;    if (edad >=18) {
        cout << "Usted ya es mayor de edad." << endl;
        } else {
                cout << "Usted aun es menor de edad." << endl;
        }
        return 0;
}