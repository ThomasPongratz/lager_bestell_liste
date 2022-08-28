#include "komponente.h"

struct KomponentenElement {
    Komponente *k;
    KomponentenElement *before;
    KomponentenElement *next;
};