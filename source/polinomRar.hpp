#include <bits/stdc++.h>
using namespace std;
class PolinomRar{
    private:
        int m_grad;
        int m_termeni;
        int m_coeficient;
        int m_valoare;
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
        friend PolinomRar operator+(PolinomRar &, PolinomRar &);
        friend PolinomRar operator*(PolinomRar &, PolinomRar &);
        friend istream& operator>>(istream& in, PolinomRar& myPol);
        friend ostream& operator<<(ostream& out, PolinomRar& myPol);
};
