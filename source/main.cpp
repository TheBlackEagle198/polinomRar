/* 
__________      .__  .__                                             
\______   \____ |  | |__| ____   ____   _____   ____________ _______ 
 |     ___/  _ \|  | |  |/    \ /  _ \ /     \  \_  __ \__  \\_  __ \
 |    |  (  <_> |  |_|  |   |  (  <_> |  Y Y  \  |  | \// __ \|  | \/
 |____|   \____/|____|__|___|  /\____/|__|_|  /  |__|  (____  |__|   
                             \/             \/              \/       
*/

#include <iostream>
#include "polinomRar.hpp"
#include "../etc/interfaceText.h"

PolinomRar pol, pol2;
char input;

int main() {
    printLogo();

    do {
        printMenu();
        cout << "                                    OPTIUNE: ";
        cin >> input;
        cout << endl;
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
            case 'e':
                cout << "Iesire!" << endl << endl;
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while(input != 'e');
    std::cout << "out";
}