//
// Created by hisla on 30/11/2023.
//

#include "search.h"

int classicSearch(t_d_list * list, int value){

    if(list->heads == NULL) {return 0;}

    t_d_cell * memory = list->heads[0];

    while(memory != NULL){
        if(memory->value == value){
            return 1;
        }
        memory = memory->next[0];
    }

    return 0;

}

int searchByLevel(t_d_list * list, int value){

    if(list->heads[0] == NULL) {return 0;}

    t_d_cell * memory = list->heads[list->height - 1];

    for(int i = list->height - 1; i >= 0; i--){
        while(memory->next[i] != NULL && memory->next[i]->value < value){memory = memory->next[i];}
        if(memory->next[i] != NULL && memory->next[i]->value == value){return 1;}
    }
    return 0;
}