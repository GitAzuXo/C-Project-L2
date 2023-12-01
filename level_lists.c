//
// Created by hisla on 06/11/2023.
//

#include "level_lists.h"
#include "timer.h"

t_d_list * createEmptyList(int levels){

    t_d_list *newlist = (t_d_list*) malloc(sizeof(t_d_list));

    newlist->height = levels;
    newlist->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * levels);

    for(int i = 0; i<levels; i++){
        newlist->heads[i] = NULL;
    }

    return newlist;

}

t_d_list * createListToSearch(int maxvalue){

    t_d_list *newlist = (t_d_list*) malloc(sizeof(t_d_list));

    newlist->height = 7;
    newlist->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * 7);

    for(int i = 0; i<7; i++){
        newlist->heads[i] = NULL;
    }

    for(int i = 1; i<=maxvalue; i++){
        if(i%64 == 0){
            t_d_cell * newcell = createCell(i, 7);
            insertCellSorted(newlist, newcell);
        } else if(i%32 == 0){
            t_d_cell * newcell = createCell(i, 6);
            insertCellSorted(newlist, newcell);
        } else if(i%16 == 0){
            t_d_cell * newcell = createCell(i, 5);
            insertCellSorted(newlist, newcell);
        } else if(i%8 == 0){
            t_d_cell * newcell = createCell(i, 4);
            insertCellSorted(newlist, newcell);
        } else if(i%4 == 0){
            t_d_cell * newcell = createCell(i, 3);
            insertCellSorted(newlist, newcell);
        } else if(i%2 == 0){
            t_d_cell * newcell = createCell(i, 2);
            insertCellSorted(newlist, newcell);
        } else {
            t_d_cell * newcell = createCell(i, 1);
            insertCellSorted(newlist, newcell);
        }
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

int classicSearch(t_d_list * list, int value){

    startTimer();

    if(list->heads == NULL) {return 0;}

    t_d_cell * memory = list->heads[0];

    while(memory != NULL){
        if(memory->value == value){
            stopTimer();
            displayTime();
            return 1;
        }
        memory = memory->next[0];
    }
    stopTimer();
    displayTime();
    return 0;

}

int searchByLevel(t_d_list * list, int value){

    startTimer();

    if(list->heads[0] == NULL) {return 0;}

    t_d_cell * memory = list->heads[list->height - 1];

    for(int i = list->height - 1; i >= 0; i--){
        while(memory->next[i] != NULL && memory->next[i]->value < value){memory = memory->next[i];}
        if(memory->next[i] != NULL && memory->next[i]->value == value){
            stopTimer();
            displayTime();
            return 1;
        }
    }
    stopTimer();
    displayTime();
    return 0;
}

