//
// Created by hisla on 06/11/2023.
//

#include "level_cells.h"
#include <stdlib.h>

t_d_cell * createCell(int value, int levels){

    t_d_cell * cell = (t_d_cell *) malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->nblevel = levels;
    cell->next = (t_d_cell **) malloc(sizeof(t_d_cell*));

    for(int i = 0; i<levels; i++){
        cell->next[i] = 0;
    }

    return cell;

}
