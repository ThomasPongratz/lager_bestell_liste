#include <stdio.h>
#include <stdlib.h>

#include "lagfunc.h"

int main() {
    struct artlst_t *root = NULL;
    char *ldatei = LAGERDATEINAME;
    if((root = makeOrderList(ldatei)) == NULL) {
        printf("Fehler beim Oeffnen der Lagerdatei!!\n");
    } else {
        printf("Bestellliste: \n");
        prtOrderList(root);
        remOrderList(root);
    }
    return 0;
}