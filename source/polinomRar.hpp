#include <bits/stdc++.h>
using namespace std;
class PolinomRar{
    private:
        int m_grad;
        int m_termeni;
        int m_coeficient;
        struct m_Nod {
            int coeficient, rang;
            m_Nod *next_node;
        }*m_firstNode;

    public:
        PolinomRar();
        PolinomRar(const PolinomRar &myPol);
        ~PolinomRar();
        int grad(){return m_grad;}
        int valIn(int X);

        PolinomRar operator+(PolinomRar);
        PolinomRar operator*(PolinomRar);
        friend istream& operator>>(istream& in, PolinomRar& myPol);
        friend ostream& operator<<(ostream& out, PolinomRar& myPol);
};
//verificare
//nr 2
