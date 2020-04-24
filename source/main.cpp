#include <iostream>
#include "polinomRar.hpp"

PolinomRar pol, pol2;
char input;

int main() {
    do {
        std::cin >> input;
        switch(input) {
            case '1':
            // valoarea in punctul x
                // pol.valIn(x);
                std::cout << "case 1";
                break;
            case '2':
            // inmultirea cu un scalar
                // pol.multBy(x);
                std::cout << "case 2";
                break;
            case '3':
            // aduna doua polinoame rare
                // pol.add(pol2);
                std::cout << "case 3";
                break;
            default:
                break;
        }
    } while(input != 'e');
    std::cout << "out";
}