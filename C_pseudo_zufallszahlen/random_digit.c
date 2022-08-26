#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANZ_ZZ 10000000L

int main() {
    int zz;
    int mzz;
    int mdis;
    unsigned int sd;
    long *ip;
    int i;
    long l;

    printf("\nErzeugung von %ld Pseude-Zufallszahlen:\n", MAX_ANZ_ZZ);
    printf("\nZufallszahlenbereich: 0 .. ? ");
    scanf("%d", &mzz);
    printf("\nInitialisierungswert der Folge? ");
    scanf("%u", &sd);
    printf("\nAnzahl der auszugebenden Zahlen? ");
    scanf("%d", &mdis);

    ip = calloc(mzz + 1, sizeof(long));
    /* ODER
    ip = malloc((mzz + 1) * sizeof(long));
    memset(ip, '\0', (mzz + 1) * sizeof(long));
    */

    putchar('\n');
    srand(sd);
    for (l = 0; l < MAX_ANZ_ZZ; ++l) {
        zz = rand() % (mzz + 1);
        if (l < mdis) {
            printf("%d  ", zz);
        }
        ++ip[zz];
    }
    putchar('\n');
    printf("\nWahrscheinlichkeitsverteilung: \n");
    for (i = 0; i <= mzz; ++i) {
        printf("\n%4d : %.6f", i, (double)ip[i] / MAX_ANZ_ZZ);
    }
    printf("\n\n");

    return 0;
}
