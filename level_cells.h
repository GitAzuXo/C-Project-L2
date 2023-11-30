//
// Created by hisla on 06/11/2023.
//

#ifndef C_PROJECT_L2_LEVEL_CELLS_H
#define C_PROJECT_L2_LEVEL_CELLS_H

typedef struct s_d_cell{
    int value;
    int nblevel;
    struct s_d_cell **next;
}t_d_cell;

t_d_cell * createCell(int value, int levels);


#endif //C_PROJECT_L2_LEVEL_CELLS_H
