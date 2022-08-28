#include "komponentenelement.h"

class KomponentenList {
    public:
        KomponentenList() : counter{0}, first{nullptr} {}
        ~KomponentenList();
        int size() const { return counter; }
        const Komponente *at(int pos);
        int erase(int pos);
        void push_back(Komponente *k);
        KomponentenElement *end() const { return nullptr; }
        KomponentenElement *begin() const { return first; }

    private:
        int counter;
        KomponentenElement *first;
        KomponentenElement *getElement(int pos) const;
};