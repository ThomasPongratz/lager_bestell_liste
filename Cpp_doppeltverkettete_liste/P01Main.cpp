#include <iostream>
#include "komponente.h"
#include "bohrung.h"
#include "fraesung.h"
#include "komponentenlist.h"

//using std::cout;
//using std::endl;

int main() {
    Bohrung b1{1, 2, 8}, b2{2, 6, 4}, b3{10, 8, 7}, b4{7, 2, 5};
    Fraesung f1{2, 3, 5, 2*sqrt(2), 45}, f2{6, 7, 6, 3, 0}, f3{17, 6, 4, 4*sqrt(2), 45};

    KomponentenList *liste = new KomponentenList;
    liste->push_back(&b1);
    liste->push_back(&f1);
    liste->push_back(&b3);
    liste->push_back(&f2);
    liste->push_back(&b4);
    liste->push_back(&f3);
    liste->push_back(&b2);
/*
    std::cout << "Ausgabe der Liste" << std::endl;
    for (int i = 0; i < sizeof(liste) / sizeof(KomponentenList); ++i) {
        //liste->getElement(i)->k->output(std::cout);
    }
*/
    std::cout << "Ausgabe der Liste" << std::endl;
    int grenze = liste->size();
    for (int i = 0; i < grenze; ++i) {
        liste->at(i)->output(std::cout);
        std::cout << std::endl;
    }

    return 0;
}


