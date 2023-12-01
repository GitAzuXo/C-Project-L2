//
// Created by hisla on 06/11/2023.
//

#ifndef C_PROJECT_L2_LEVEL_LISTS_H
#define C_PROJECT_L2_LEVEL_LISTS_H

#include "level_cells.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_d_list{
    t_d_cell** heads;
    int height;
}t_d_list;

t_d_list * createEmptyList(int levels);
void insertCell(t_d_list * list, t_d_cell * cell);
void displayForLevel(t_d_list * list, int level);
void displayAllLevels(t_d_list * list);
void insertCellSorted(t_d_list * list, t_d_cell * cell);
int classicSearch(t_d_list * list, int value);
int searchByLevel(t_d_list * list, int value);
t_d_list * createListToSearch(int maxvalue);

#endif //C_PROJECT_L2_LEVEL_LISTS_H
