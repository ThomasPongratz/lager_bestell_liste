#define MAXCHAR 40
#define ANZ 5

#define LAGERDATEINAME "lager.dat"

struct artikel_t {
    int artnr;
    char artname[MAXCHAR];
    float preis;
    int bestand;
    int min;
};

struct artlst_t {
    struct artikel_t sArtikel;
    struct artlst_t *next;
};

struct artlst_t *makeOrderList(char*);
void prtOrderList(struct artlst_t *);
void remOrderList(struct artlst_t *);