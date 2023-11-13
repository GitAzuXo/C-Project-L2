//
// Created by hisla on 06/11/2023.
//

#include "level_lists.h"

t_d_list * emptyLevelList(int nbLevel){
    t_d_list * list = (t_d_list *) malloc(sizeof(t_d_list));
    t_d_cell** head = (t_d_cell **) malloc(sizeof(t_d_cell *) * nbLevel);

    for(int i=0; i<nbLevel; i++){
        head[i] = NULL;
    }

    list->heads = head;
    return list;
}

void insertCellatHead(t_d_cell * cell, t_d_list * list){

    // For all the levels in the cell insert at the head
    for(int i=1; i<(list->height - 1); i++){
        list->heads[i] = list->heads[i+1];
    }
    list->heads[0] = cell;

}

void displayListForLevel(t_d_list * list, int level){
    int cell = 0;
    t_d_cell *tmp;
    tmp = list->heads[level];
    while(tmp != NULL){
        printf("Level : %d, Cell : %d, Value : %d", level, cell, tmp->value);
        tmp = tmp->nexts[cell++];
    }

}

