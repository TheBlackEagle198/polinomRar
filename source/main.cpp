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

PolinomRar pol, pol2;
char input;

int main() {
    cout << "┌────────────────────────────────────────────────────────────────────────┐" << endl;
    cout << "│ __________      .__  .__                                               │" << endl;
    cout << "│  \\______   \\____ |  | |__| ____   ____   _____   ____________ _______  │" << endl;
    cout << "│   |     ___/  _ \\|  | |  |/    \\ /  _ \\ /     \\  \\_  __ \\__  \\\\_  __ \\ │" << endl;
    cout << "│   |    |  (  <_> |  |_|  |   |  (  <_> |  Y Y  \\  |  | \\// __ \\|  | \\/ │" << endl;
    cout << "│   |____|   \\____/|____|__|___|  /\\____/|__|_|  /  |__|  (____  |__|    │" << endl;
    cout << "│                               \\/             \\/              \\/        │" << endl;
    cout << "└────────────────────────────────────────────────────────────────────────┘" << endl << endl << endl;

    do {
        cout << "                    ┌─────────┰───────────────────────────┐" << endl;
        cout << "                    │ Optiune │        Operatie           │" << endl;
        cout << "                    │─────────╀───────────────────────────│" << endl;
        cout << "                    │    1    │ Citirea polinomului       │" << endl;
        cout << "                    │    2    │ Scrierea polinoumului     │" << endl;
        cout << "                    │    3    │ Valoarea in punctul x     │" << endl;
        cout << "                    │    4    │    Inmultirea cu scalar   │" << endl;
        cout << "                    │    5    │ Aduanarea a doua polinoame│" << endl;
        cout << "                    │    e    │        Iesire             │" << endl;
        cout << "                    └─────────┴───────────────────────────┘" << endl << endl;
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
            default:
                cout << "Invalid" << endl;
                break;
        }
    } while(input != 'e');
    std::cout << "out";
}