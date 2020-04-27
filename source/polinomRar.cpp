#include "polinomRar.hpp"

PolinomRar::PolinomRar(){
    m_grad=0;
    m_termeni=0;
    m_valoare=0;
}

PolinomRar::PolinomRar(const PolinomRar& myPol){
    m_grad = myPol.m_grad;
    m_termeni = myPol.m_termeni;
    PolinomRar::m_Nod *newNode, *lastNode;
    newNode = new PolinomRar::m_Nod;
    newNode->rang = myPol.m_firstNode->rang;
    newNode->coeficient = myPol.m_firstNode->coeficient;
    newNode-> next_node = nullptr;
    m_firstNode = newNode;
    lastNode = m_firstNode;

    for (PolinomRar::m_Nod *i_ptr = myPol.m_firstNode->next_node; i_ptr != nullptr; i_ptr = i_ptr->next_node) {
        newNode = new PolinomRar::m_Nod;
        newNode->rang = i_ptr->rang;
        newNode->coeficient = i_ptr->coeficient;
        newNode-> next_node = nullptr;
        lastNode->next_node = newNode;
        lastNode = newNode;
    }
}

PolinomRar::~PolinomRar() {
    cout << "Destruction complete!";
}

int PolinomRar::valIn(int X){
    for (PolinomRar::m_Nod *i_ptr = this->m_firstNode; i_ptr != nullptr; i_ptr = i_ptr->next_node) {
        m_valoare=i_ptr->coeficient*pow(X,i_ptr->rang)+m_valoare;
    }
    return m_valoare;
}

PolinomRar &operator*(PolinomRar &a, int x) {
    for (PolinomRar::m_Nod *i_ptr = a.m_firstNode; i_ptr != nullptr; i_ptr = i_ptr->next_node) {
        i_ptr->coeficient = i_ptr->coeficient * x;
    }
    return a;
}

PolinomRar &operator+(PolinomRar &a, PolinomRar &b) {
    PolinomRar::m_Nod *i_ptrBiggerList, *i_ptrSmallerList;

    i_ptrBiggerList = a.m_termeni > b.m_termeni ? a.m_firstNode : b.m_firstNode;
    i_ptrSmallerList = a.m_termeni < b.m_termeni ? a.m_firstNode : b.m_firstNode;

    for (; i_ptrBiggerList != nullptr; i_ptrBiggerList = i_ptrBiggerList->next_node) {
        if (i_ptrBiggerList->coeficient > i_ptrSmallerList->coeficient) {

        } else if (i_ptrBiggerList->coeficient == i_ptrSmallerList->coeficient) {

        } else {

        }
    }
    return b;
}

istream &operator>>(istream& in, PolinomRar& myPol) {
    in >> myPol.m_grad >> myPol.m_termeni;
    int coeficient, rang;
    PolinomRar::m_Nod *newNode;
    cout << "read grad, termeni";
    if (myPol.m_termeni > 0) {
        cout << "create first node....";
        in >> coeficient >> rang;
        myPol.m_firstNode = new PolinomRar::m_Nod;
        myPol.m_firstNode->coeficient = coeficient;
        myPol.m_firstNode->rang = rang;
        myPol.m_firstNode->next_node = nullptr;
        cout << "done!" << endl;
    }

    PolinomRar::m_Nod *i_ptr = myPol.m_firstNode;

    for (int i = 1; i < myPol.m_termeni; i++) {
        newNode = new PolinomRar::m_Nod;
        i_ptr->next_node = newNode;

        in >> coeficient >> rang;
        newNode->coeficient = coeficient;
        newNode->rang = rang;
        newNode->next_node = nullptr;
        i_ptr = i_ptr->next_node;
    }
    return in;
}

ostream &operator<<(ostream& out, PolinomRar& z) {
    for (PolinomRar::m_Nod *i_ptr = z.m_firstNode; i_ptr != nullptr; i_ptr = i_ptr->next_node) {
        out << i_ptr->coeficient;
        if (i_ptr->rang != 0) {
            out << "*X^" << i_ptr->rang;
        }
        if (i_ptr->next_node != nullptr) {
            out << " + ";
        }
    }
    out << endl << endl;
    return out;
}