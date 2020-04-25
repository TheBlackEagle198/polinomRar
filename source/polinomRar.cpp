#include "polinomRar.hpp"

PolinomRar::PolinomRar(){
    m_grad=0;
    m_indice=0;
}
PolinomRar::PolinomRar(const PolinomRar& z){
    m_grad=z.m_grad;
    m_indice=z.m_indice;
}
