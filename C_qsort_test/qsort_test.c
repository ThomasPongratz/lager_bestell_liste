#include <stdio.h>
#include <stdlib.h>

#define MAXANZ 10

int lesenDoubleWerte(double *, int);
void ausDoubleWerte(double *, int);
int vglDouble(const void *, const void *);

int main(void) {
    int anz;
    double darr[MAXANZ];
    anz = lesenDoubleWerte(darr, MAXANZ);
    qsort(darr, anz, sizeof(double), vglDouble);
    ausDoubleWerte(darr, anz);
    return 0;
}

int vglDouble(const void *d1, const void *d2) {
    int iRet = 0;
    if (*(double*)d1 < *(double*)d2) {
        iRet = 1;
    }
    return iRet;
}

int lesenDoubleWerte(double *dfeld, int iAnz) {
    unsigned int i = 0;
    int ende = 0;
    printf("Eingabe von double-Werten (maximal %d) :\n", iAnz);
    while (i<iAnz && !ende) {
        printf("Wert %2d : ", i);
        fflush(stdout);
        if (scanf ("%lf", dfeld++) <= 0) {
            ende = 1;
        } else {
            ++i;
        }
    }
    return i;
}

void ausDoubleWerte(double *dfeld, int iAnz) {
    unsigned int i;
    printf("\nAusgabe der sortierten Werte:\n");
    for (i = 0; i<iAnz; ++i) {
        printf("Wert %2d : %7.3lf\n", i, *(dfeld++));
    }
}