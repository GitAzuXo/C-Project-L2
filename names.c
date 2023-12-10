//
// Created by hisla on 10/12/2023.
//

#include "names.h"

char* toLowerCase(char *string){
    for(int i = 0; string[i] != '\0'; i++){
        string[i] = tolower(string[i]);
    }
    return string;
}

t_contact * createContact(char* fn, char* ln, int nbLevels){
    char* firstname = toLowerCase(fn);
    char* lastname = toLowerCase(ln);
    unsigned long size = strlen(firstname) + strlen(lastname) + 1;
    char fullname[size];
    strcpy(fullname, lastname);
    strcat(fullname,"_");
    strcat(fullname,firstname);
    char* contactName = (char*) malloc(sizeof(char) * size);
    strcpy(contactName,fullname);

    t_contact * mycontact = (t_contact*) malloc(sizeof(t_contact));
    mycontact->name = contactName;
    mycontact->appointments = NULL;
    mycontact->nbAppointments = 0;
    mycontact->levels = 4;
    mycontact->next = (t_contact**) malloc(sizeof(t_contact*) * nbLevels);
    return mycontact;
}
