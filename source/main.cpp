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
#include "../etc/interfaceText.hpp"

PolinomRar pol, pol2;
char input;

int main() {
    printLogo();
    do {
        printMenu();
        cout << "                                 OPTIUNE: ";
        cin >> input;
        cout << endl;
        switch(input) {
            case '1':
            // citirea polinomului
                cin >> pol;
                break;
            case '2':
            // scrierea polinomului
                cout << pol;
                break;
            case '3':
            // valoarea in punctul x
                int x, rez;
                cout << "Dati x: ";
                cin >> x;
                rez = pol.valIn(x);
                cout << "Valoarea in punctul " << x << " este: " << rez << endl;  
                break;
            case '4':
            // inmultirea cu un scalar
                cout << "Dati scalarul cu care inmultim polinomul: ";
                cin >> x;
                pol = pol * x;
                cout << "Valoarea polinomului inmultit cu " << x << " este: " << pol << endl;  
                break;
            case '5':
            // aduna doua polinoame rare
                cout << "Introduceti al doilea polinom: ";
                cin >> pol2;
                cout << "Suma celor doua polinoame este: " << endl;
                cout << pol + pol2 << endl;
                break;
            case 'e':
                cout << "Iesire!" << endl << endl;
                break;
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while(input != 'e');
}