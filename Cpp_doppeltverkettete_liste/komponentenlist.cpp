#include "komponentenlist.h"

KomponentenElement* KomponentenList::getElement(int pos) const {
    KomponentenElement *pElement = nullptr;
    if (0 <= pos && pos < size()) {       
            pElement = first;
            for (int i = 0; i < pos && pElement != nullptr; ++i) {
                pElement = pElement->next;
            }
    }
    return pElement;
}

KomponentenList::~KomponentenList() {
    KomponentenElement *tmp = nullptr;
    while (first != end()) {
        tmp = first->next;
        delete first;
        first = tmp;
    }
    counter = 0;
}

const Komponente* KomponentenList::at(int pos) const {
    KomponentenElement *pElement = getElement(pos);
    return (pElement != nullptr) ? pElement->k : nullptr;
}

int KomponentenList::erase(int pos) {
    int returnPos = -1;
    if (first != nullptr) {
        returnPos = pos;
        KomponentenElement *pElement = getElement(pos);
        
    }
    return returnPos;
}

void KomponentenList::push_back(Komponente *k) {
    if (k != nullptr) {
        KomponentenElement* newElement = new KomponentenElement;
        newElement->next = nullptr;
        newElement->k = k;
        if (first == end()) {
            newElement->before = nullptr;
            first = newElement;
        } else {
            KomponentenElement *curr = getElement(size() - 1);
            newElement->before = curr;
            curr->next = newElement;
        }
        counter++;
    }
}