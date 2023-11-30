#include <stdio.h>
#include "level_lists.h"

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

    t_d_list * list = createEmptyList(5);
    t_d_cell * cell = createCell(4, 3);
    t_d_cell * cellbis = createCell(87, 5);
    t_d_cell * cell3 = createCell(32, 5);

    insertCell(list, cell);
    insertCellSorted(list, cellbis);
    displayAllLevels(list);

    return 0;
}
