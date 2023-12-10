//
// Created by hisla on 10/12/2023.
//

#ifndef C_PROJECT_L2_NAMES_H
#define C_PROJECT_L2_NAMES_H
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "appointments.h"

#define BUFFER 1000

typedef struct s_contact{
    int levels;
    int nbAppointments;
    t_appointment **appointments;
    struct s_contact **next;
    char *name;
}t_contact;

t_contact * createContact(char* fn, char* ln, int nbLevels);

#endif //C_PROJECT_L2_NAMES_H
