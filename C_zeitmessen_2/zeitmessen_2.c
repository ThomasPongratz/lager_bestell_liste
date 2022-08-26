// beim Zeitmessen (Ausfuehrungsdauer) 
// immer den Compiler-Modus (Release) aktivieren
#include <stdio.h>
#include <time.h>

void do_something() {
    volatile double value = 0.0;
    for (unsigned int i = 0; i < 100000000; ++i) {
        value += i;
    }
}

int main() {
    clock_t time_start = clock();
    for (unsigned int i = 0; i < 10; ++i) {
        do_something();
    }
    
    clock_t time_end = clock();
    clock_t duration = time_end - time_start;
    //clock_t duration_10 = time_end - time_start;
    //clock_t duration = (double)duration_10 / 10;

    double s = ((double)duration / 10) / CLOCKS_PER_SEC;
    double ms = 1000.0 * s;
    double us = 1000.0 * ms;
    double ns = 1000.0 * us;

    printf("s:  %lf\n", s);
    printf("ms: %lf\n", ms);
    printf("us: %lf\n", us);
    printf("ns: %lf\n", ns);

    return 0;
}