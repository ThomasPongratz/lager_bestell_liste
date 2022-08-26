#include <stdio.h>
#include <time.h>
#include <string.h>

void proc_cal_time_out(clock_t, time_t);
void warten(void);
void loc_time_out(struct tm *);

int main(void) {
    time_t zeit1, zeit2;
    clock_t clk1, clk2;
    double ctsec, ttdiff;
    struct tm *lzeit;
    char zeit_str[80];

    clk1 = clock();
    zeit1 = time(NULL);
    proc_cal_time_out(clk1, zeit1);
    warten();
    clk2 = clock();
    zeit2 = time(NULL);
    proc_cal_time_out(clk2, zeit2);
    ctsec = (double) (clk2 - clk2) / CLK_TCK;
    ttdiff = difftime(zeit2, zeit1);
    printf("\nWartezeit: %f Sek. (ermittelt ueber Prozessorzeit)", ctsec);
    printf("\n           %f Sek. (ermittelt ueber Kalenderzeit)\n", ttdiff);
    lzeit = localtime(&zeit2);
    loc_time_out(lzeit);
    strcpy(zeit_str, asctime(lzeit));
    printf("\nZeit-String: %s\n", zeit_str);
    return 0;
}

void proc_cal_time_out(clock_t ct, time_t tt) {
    printf("\nProzessorzeit = %ld Ticks", (long int)ct);
    printf("\nKalenderzeit = %ld\n", (long int)tt);
}

void warten(void) {
    printf("\nWarten bis Eingabe CR ");
    getchar();
}

void loc_time_out(struct tm *ltp) {
    printf("\nOrtszeit: Jahr  = %d", ltp->tm_year);
    printf("\n          Monat = %d", ltp->tm_mon);
    printf("\n          Tag   = %d", ltp->tm_mday);
    printf("\n          Zeit  = %d:%d:%d", ltp->tm_hour, ltp->tm_min, ltp->tm_sec);
    printf("\nSommerzeit-Flag : %d\n", ltp->tm_isdst);
}