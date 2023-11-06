//
// Created by hisla on 06/11/2023.
//

#ifndef C_PROJECT_L2_LEVEL_CELLS_H
#define C_PROJECT_L2_LEVEL_CELLS_H

typedef struct s_d_cell{
    int value;
    struct s_d_cell **nexts;
}t_d_cell;

t_d_cell * CreateCell(int value, int maxheight);


#endif //C_PROJECT_L2_LEVEL_CELLS_H
