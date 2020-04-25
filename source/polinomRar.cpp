#include "polinomRar.hpp"
PolinomRar::PolinomRar(){
    m_grad=0;
    m_termeni=0;
    m_coeficient=0;
}
PolinomRar::PolinomRar(const PolinomRar& z){
    m_grad=z.m_grad;
    m_termeni=z.m_termeni;
    m_coeficient=z.m_coeficient;
}

