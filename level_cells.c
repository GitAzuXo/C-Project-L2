//
// Created by hisla on 06/11/2023.
//

#include "level_cells.h"
#include <stdlib.h>

t_d_cell * CreateCell(int value, int maxheight){

    t_d_cell * cell = (t_d_cell *) malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->nexts = (t_d_cell **) calloc(maxheight, sizeof(t_d_cell*));

    return cell;

}
