#include <bits/stdc++.h>
using namespace std;
class PolinomRar{
    private:
        int m_grad;
        int m_termeni;
        struct m_Nod {
            int coeficient, rang;
            m_Nod *next_node;
        }*m_firstNode;

    public:
        PolinomRar();
        PolinomRar(const PolinomRar &);
        ~PolinomRar();
        int grad(){return m_grad;}
        int valIn(int);
        friend m_Nod *buildNode(int ,int, m_Nod *);
        friend void addToList(m_Nod*, m_Nod*);
        friend PolinomRar &operator+(PolinomRar &, PolinomRar &);
        friend PolinomRar &operator*(PolinomRar &, int);
        friend istream &operator>>(istream&, PolinomRar&);
        friend ostream &operator<<(ostream&, PolinomRar&);
};
