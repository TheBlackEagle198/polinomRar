#include "polinomRar.hpp"

PolinomRar::m_Nod *buildNode(int coeficient, int rang, PolinomRar::m_Nod *nextNode) {
    PolinomRar::m_Nod *newNode;
    newNode = new PolinomRar::m_Nod;
    newNode->coeficient = coeficient;
    newNode->rang = rang;
    newNode->next_node = nextNode;
    return newNode;
}

// --------------------------------------------------------------------------------------------------------

void addToList(PolinomRar::m_Nod* firstNode, PolinomRar::m_Nod* insertedNode) {
    for (PolinomRar::m_Nod *i_ptr = firstNode; i_ptr != nullptr; i_ptr = i_ptr->next_node) {
        if (i_ptr->next_node == nullptr) {
            i_ptr->next_node = insertedNode;
            insertedNode->next_node = nullptr;
        }
    }
}

// --------------------------------------------------------------------------------------------------------

PolinomRar::PolinomRar(){
    m_grad = 0;
    m_termeni = 0;
}

// --------------------------------------------------------------------------------------------------------

PolinomRar::PolinomRar(const PolinomRar& myPol){
    m_grad = myPol.m_grad;
    m_termeni = myPol.m_termeni;
    PolinomRar::m_Nod *newNode, *lastNode;
    newNode = buildNode(myPol.m_firstNode->coeficient, myPol.m_firstNode->rang, nullptr);
    m_firstNode = newNode;
    lastNode = m_firstNode;

    for (PolinomRar::m_Nod *i_ptr = myPol.m_firstNode->next_node; i_ptr != nullptr; i_ptr = i_ptr->next_node) {
        newNode = buildNode(i_ptr->coeficient, i_ptr->rang, nullptr);
        lastNode->next_node = newNode;
        lastNode = newNode;
    }
}
// ************************* work here ***************************************
PolinomRar::~PolinomRar() {
    PolinomRar::m_Nod *currNode, *lastNode;
    lastNode = this->m_firstNode;
    for (currNode = this->m_firstNode->next_node; currNode != nullptr; currNode = currNode->next_node) {
        delete lastNode;
        lastNode = currNode;
    }
    delete currNode;
}
// ***************************************************************************

int PolinomRar::valIn(int X){
    int valoare;
    for (PolinomRar::m_Nod *i_ptr = this->m_firstNode; i_ptr != nullptr; i_ptr = i_ptr->next_node) {
        valoare = i_ptr->coeficient * pow(X,i_ptr->rang) + valoare;
    }
    return valoare;
}

// --------------------------------------------------------------------------------------------------------

PolinomRar &operator*(PolinomRar &a, int x) {
    for (PolinomRar::m_Nod *i_ptr = a.m_firstNode; i_ptr != nullptr; i_ptr = i_ptr->next_node) {
        i_ptr->coeficient = i_ptr->coeficient * x;
    }
    return a;
}

// ************************* work here ***************************************

PolinomRar &operator+(PolinomRar &a, PolinomRar &b) {
    PolinomRar::m_Nod *list1_ptr = a.m_firstNode, *list2_ptr = b.m_firstNode, *sum_ptr;
    PolinomRar sum;
    int list1_size = a.m_termeni, list2_size = b.m_termeni, i = 0, j = 0;

    if (list1_ptr->rang > list2_ptr->rang) {
        sum.m_firstNode = buildNode(list1_ptr->coeficient, list1_ptr->rang, nullptr);
        i++;
        list1_ptr = list1_ptr->next_node;
    } else if (list1_ptr->rang == list2_ptr->rang) {
        sum.m_firstNode = buildNode(list1_ptr->coeficient + list2_ptr->coeficient, list1_ptr->rang, nullptr);
        i++; j++;
        list1_ptr = list1_ptr->next_node;
        list2_ptr = list2_ptr->next_node;
    } else {
        sum.m_firstNode = buildNode(list2_ptr->coeficient, list2_ptr->rang, nullptr);
        j++;
        list2_ptr = list2_ptr->next_node;
    }

    while (i < list1_size && j < list2_size) {
        if (list1_ptr->rang > list2_ptr->rang) {
            addToList(sum.m_firstNode, buildNode(list1_ptr->coeficient, list1_ptr->rang, nullptr));
            i++;
            list1_ptr = list1_ptr->next_node;
        } else if (list1_ptr->rang == list2_ptr->rang) {
            addToList(sum.m_firstNode, buildNode(list1_ptr->coeficient + list2_ptr->coeficient, list1_ptr->rang, nullptr));
            i++; j++;
            list1_ptr = list1_ptr->next_node;
            list2_ptr = list2_ptr->next_node;
        } else {
            addToList(sum.m_firstNode, buildNode(list2_ptr->coeficient, list2_ptr->rang, nullptr));
            j++;
            list2_ptr = list2_ptr->next_node;
        }
    }

    while (i < list1_size) {
        addToList(sum.m_firstNode, buildNode(list1_ptr->coeficient, list1_ptr->rang, nullptr));
        i++;
        list1_ptr = list1_ptr->next_node;
    }
    while (j < list2_size) {
        addToList(sum.m_firstNode, buildNode(list2_ptr->coeficient, list2_ptr->rang, nullptr));
        j++;
        list2_ptr = list2_ptr->next_node;
    }
    b.~PolinomRar();
    b.m_firstNode = new PolinomRar::m_Nod;
    *b.m_firstNode = *sum.m_firstNode; 
    return b;
}
// ****************************************************************************************************

istream &operator>>(istream& in, PolinomRar& myPol) {
    in >> myPol.m_grad >> myPol.m_termeni;
    int coeficient, rang;
    PolinomRar::m_Nod *newNode;
    if (myPol.m_termeni > 0) {
        in >> coeficient >> rang;
        myPol.m_firstNode = buildNode(coeficient, rang, nullptr);
    }

    PolinomRar::m_Nod *i_ptr = myPol.m_firstNode;

    for (int i = 1; i < myPol.m_termeni; i++) {
        in >> coeficient >> rang;
        newNode = buildNode(coeficient, rang, nullptr);
        i_ptr->next_node = newNode;
        i_ptr = i_ptr->next_node;
    }
    cout << "Citire efectuata!" << endl;
    return in;
}

// --------------------------------------------------------------------------------------------------------

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