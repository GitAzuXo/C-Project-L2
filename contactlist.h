//
// Created by hisla on 10/12/2023.
//

#ifndef C_PROJECT_L2_CONTACTLIST_H
#define C_PROJECT_L2_CONTACTLIST_H
#include "names.h"
#include <stdlib.h>

typedef struct s_d_contactlist{
    t_contact** heads;
    int height;
}t_d_contactlist;

t_d_contactlist * createEmptyContactList(int levels);
void insertContact(t_d_contactlist * list, t_contact * contact);
void displayContactsForLevel(t_d_contactlist * list, int level);
void insertContactSorted(t_d_contactlist * list, t_contact * contact);
void displayContactsAllLevels(t_d_contactlist * list);

#endif //C_PROJECT_L2_CONTACTLIST_H
