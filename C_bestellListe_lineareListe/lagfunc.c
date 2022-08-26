#include <stdio.h>
#include <stdlib.h>

#include "lagfunc.h"

static struct artlst_t *putInList(struct artlst_t *, struct artikel_t);

struct artlst_t *makeOrderList(char *quellPfad) {
    int speicherVorh = 1;
    FILE *fqZeig;
    struct artikel_t e1;
    struct artlst_t *root = NULL;
    struct artlst_t *erg;

    if((fqZeig = fopen(quellPfad, "rb")) == NULL) {
        printf("%s kann nicht geoeffnet werden!\n", quellPfad);
    } else {

    }
}

void prtOrderList(struct artlst_t *wrzl) {
    const char *ueber  = "Lfd.Nr.  Art.Nr.  Artikel      BestellAnz  Einzelpr.";
    const char *ueber2 = "   Gesamtpr.\n";
    const char *line   = "----------------------------------------------------";
    const char *line2  = "------------\n";
    const char *form   = " %3d       %3d     %-18s  %3d   %8.2f   %9.2f\n";
    const char *sform  = "                                  Summe:  %14.2f\n\n";
    int lfdnr = 0;
    float gesamtpreis = 0.0;
    float gesamtartikelpreis;
    int bestellmenge;
    struct artlst_t *palt;
    printf(ueber);
    printf(ueber2);
    printf(line);
    printf(line2);
    palt = wrzl;
    while (palt != NULL) {
        bestellmenge = ANZ * palt->sArtikel.min - palt->sArtikel.bestand;
        gesamtartikelpreis = bestellmenge * palt->sArtikel.preis;
        gesamtpreis += gesamtartikelpreis;
        printf(form, ++lfdnr, palt->sArtikel.artnr, palt->sArtikel.artname, 
        bestellmenge, palt->sArtikel.preis, gesamtartikelpreis);
        palt = palt->next;
    }
    printf(line); 
    printf(line2);
    printf("     "); 
    printf(sform, gesamtpreis);
}

void remOrderList(struct artlst_t *wrzl) {
    struct artlst_t *pmrk, *palt;
    palt = wrzl;
    while(palt != NULL) {
        pmrk = palt;
        palt = palt->next;
        free(pmrk);
    }
}