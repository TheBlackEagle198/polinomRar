#include <bits/stdc++.h>
using namespace std;
class PolinomRar{
    private:
        int m_grad;
        int m_termeni;
        int m_coeficient;

    public:
        PolinomRar operator+(PolinomRar);
        PolinomRar operator*(PolinomRar);
        friend istream& operator>>(istream& in, PolinomRar&);
        friend ostream& operator<<(ostream& out, PolinomRar&);
        PolinomRar();
        PolinomRar(const PolinomRar &);
        PolinomRar(int , int, int);
        ~PolinomRar();
        int grad(){return m_grad;}
        int valIn(int X);
};

