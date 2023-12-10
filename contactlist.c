//
// Created by hisla on 10/12/2023.
//

#include "contactlist.h"

t_d_contactlist * createEmptyContactList(int levels){

    t_d_contactlist *newlist = (t_d_contactlist *) malloc(sizeof(t_d_contactlist));

    newlist->height = levels;
    newlist->heads = (t_contact **) malloc(sizeof(t_contact *) * levels);

    for(int i = 0; i<levels; i++){
        newlist->heads[i] = NULL;
    }

    return newlist;

}

void insertContact(t_d_contactlist * list, t_contact * contact){

    for(int i = 0; i<contact->levels; i++){
        t_contact *memcontact = list->heads[i];
        list->heads[i] = contact;
        contact->next[i] = memcontact;
    }

}

void displayContactsForLevel(t_d_contactlist * list, int level){

    t_contact * displaycontact = list->heads[level];
    printf("[list head_%d @-]-->", level);
    while (displaycontact != NULL){
        printf("[ %s|@-]-->", displaycontact->name);
        displaycontact = displaycontact->next[level];
    }
    printf("NULL\n");
}

void insertContactSorted(t_d_contactlist * list, t_contact * contact){

    for(int i = 0; i<contact->levels; i++){

        t_contact * memory = list->heads[i];
        t_contact * previous = NULL;

        while(memory != NULL && memory->name[0] < contact->name[0]){
            previous = memory;
            memory = memory->next[i];
        }
        if(previous == NULL){
            list->heads[i] = contact;
        } else {
            previous->next[i] = contact;
        }
        contact->next[i] = memory;

    }

}

void displayContactsAllLevels(t_d_contactlist * list){

    for(int i = 0; i<list->height; i++){
        displayContactsForLevel(list, i);
    }

}