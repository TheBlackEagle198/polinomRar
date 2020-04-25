#include "polinomRar.hpp"

PolinomRar::PolinomRar(){
    m_grad = 0;
}
PolinomRar::PolinomRar(const PolinomRar& z){
    m_grad=z.m_grad;
    m_coeficient=z.m_coeficient;
}

istream& operator>>(istream& in, PolinomRar&) {
    return in;
}