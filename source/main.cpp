#include <iostream>
#include "polinomRar.hpp"

PolinomRar pol, pol2;
char input;

int main() {
    do {
        cout << "┌───────────────────────────────────────────────┐";
        cin >> input;
        switch(input) {
            case '1':
            // valoarea in punctul x
                // pol.valIn(x);
                int x;
                cout << "Dati x: ";
                cin >> x;
                cout << "Valoarea in punctul " << x << " este: " << endl;  
                break;
            case '2':
            // inmultirea cu un scalar
                // pol.multBy(x);
                cout << "Dati scalarul cu care inmultim polinomul: ";
                cin >> x;
                cout << "Valoarea polinomului inmultit cu " << x << " este: " << endl;  
                break;
            case '3':
            // aduna doua polinoame rare
                // pol.add(pol2);
                cout << "Suma celor doua polinoame este: " << endl;
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while(input != 'e');
    std::cout << "out";
}