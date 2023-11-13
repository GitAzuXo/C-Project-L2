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

t_d_list * emptyLevelList(int nbLevel);

#endif //C_PROJECT_L2_LEVEL_LISTS_H
