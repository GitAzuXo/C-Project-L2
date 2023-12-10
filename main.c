#include "level_lists.h"
#include "timer.h"

int main() {

    /** Code pour le showcase de la partie 1
    t_d_list * list = createEmptyList(5);
    t_d_cell * cell = createCell(4, 3);
    t_d_cell * cellbis = createCell(87, 5);

    insertCell(list, cell);
    insertCellSorted(list, cellbis);
    printf("--- Affichage du level 2 ---\n\n");
    displayForLevel(list, 2);
    printf("\n");
    printf("--- Affichage de tous les levels ---\n\n");
    displayAllLevels(list); **/

    FILE *log_file = fopen("../log.txt", "w");
    char format[] = "%d\t%s\t%s\n";
    int level;
    char *time_lvl0;
    char *time_all_levels;

    srand( time( NULL ) );
    for(int j = 1; j<=64; j*=2) {
        int maxval = 1000 * j;
        t_d_list *list = createListToSearch(maxval);
        startTimer();
        for (int i = 0; i <= 10000; i++) {
            classicSearch(list, rand() % maxval + 1);
        }
        stopTimer();
        displayTime();
        time_lvl0 = getTimeAsString();
        startTimer();
        for (int i = 0; i <= 10000; i++) {
            int tosearch = rand() % 1001;
            searchByLevel(list, tosearch);
        }
        stopTimer();
        displayTime();
        time_all_levels = getTimeAsString();
        fprintf(log_file,format,maxval,time_lvl0,time_all_levels);
    }
    fclose(log_file);
    return 0;
}
