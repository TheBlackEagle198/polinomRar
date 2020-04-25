#include "polinomRar.hpp"

PolinomRar::PolinomRar(){
    m_grad=0;
    m_termeni=0;
    m_coeficient=0;
    m_valoare=0;
}
PolinomRar::PolinomRar(const PolinomRar& z){
    m_grad=z.m_grad;
    m_termeni=z.m_termeni;
    m_coeficient=z.m_coeficient;
}
PolinomRar operator+(PolinomRar &a, PolinomRar &b){
    PolinomRar sum;
    
}
int PolinomRar::valIn(int X){
    for (PolinomRar::m_Nod *i_ptr = this->m_firstNode; i_ptr != nullptr; i_ptr = i_ptr->next_node){
        m_valoare=i_ptr->coeficient*pow(X,i_ptr->rang)+m_valoare;
    }
    return m_valoare;
}
istream& operator>>(istream& in, PolinomRar&) {
    return in;
}
ostream& operator<<(ostream& out, PolinomRar& z){
    cout <<' '<< z.m_grad << ' ' << z.m_coeficient;
    return out;
}