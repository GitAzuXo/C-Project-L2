//
// Created by hisla on 10/12/2023.
//

#include "names.h"

t_contact * createContact(char* fn, char* ln, int nbLevels){
    size_t size = strlen(fn) + strlen(ln) + strlen("_") + 1;
    char fullname[size];
    strcpy(fullname, ln);
    strcat(fullname,"_");
    strcat(fullname,fn);
    char* contactName = (char*) malloc(sizeof(char) * size);
    strcpy(contactName,fullname);

    t_contact * mycontact = (t_contact*) malloc(sizeof(t_contact));
    mycontact->name = contactName;
    mycontact->levels = 4;
    mycontact->next = (t_contact**) malloc(sizeof(t_contact*) * nbLevels);
    return mycontact;
}
