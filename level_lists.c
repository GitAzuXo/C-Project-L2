//
// Created by hisla on 06/11/2023.
//

#include "level_lists.h"

t_d_list * createEmptyList(int levels){

    t_d_list *newlist = (t_d_list*) malloc(sizeof(t_d_list));

    newlist->height = levels;
    newlist->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * levels);

    for(int i = 0; i<levels; i++){
        newlist->heads[i] = NULL;
    }

    return newlist;

}

void insertCell(t_d_list * list, t_d_cell * cell){

    for(int i = 0; i<cell->nblevel; i++){
        t_d_cell *memcell = list->heads[i];
        list->heads[i] = cell;
        cell->next[i] = memcell;
    }

}

void displayForLevel(t_d_list * list, int level){

    t_d_cell * displaycell = list->heads[level];
    printf("[list head_%d @-]-->", level);
    while (displaycell != NULL){
        printf("[ %d|@-]-->", displaycell->value);
        displaycell = displaycell->next[level];
    }
    printf("NULL\n");
}

void displayAllLevels(t_d_list * list){

    for(int i = 0; i<list->height; i++){
        displayForLevel(list, i);
    }

}

void insertCellSorted(t_d_list * list, t_d_cell * cell){

    for(int i = 0; i<cell->nblevel; i++){

        t_d_cell * memory = list->heads[i];
        t_d_cell * previous = NULL;

        while(memory != NULL && memory->value < cell->value){
            previous = memory;
            memory = memory->next[i];
        }
        if(previous == NULL){
            list->heads[i] = cell;
        } else {
            previous->next[i] = cell;
        }
        cell->next[i] = memory;

    }

}

