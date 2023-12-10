//
// Created by hisla on 10/12/2023.
//

#include "appointments.h"
#include <stdlib.h>
#include <names.h>
#include <stdio.h>

t_appointment *createAppointment(int day, int month, int year, int hour, int lengthMinute, char *purpose, int duration){
    t_appointment *myAppointment = (t_appointment *)malloc(sizeof(t_appointment ));
    myAppointment->Day = day;
    myAppointment->Month = month;
    myAppointment->Year = year;
    myAppointment->Hour = hour;
    myAppointment->Minute = lengthMinute;
    myAppointment->Duration = duration;
    myAppointment->Description = purpose;

    return myAppointment;
}

void displayAppointment(t_appointment *myAppointment){
    printf("-> %d/%d/%d - %dh for %d min: %s\n", myAppointment->Day, myAppointment->Month, myAppointment->Year, myAppointment->Hour, myAppointment->Minute, myAppointment->Description);
}

void displayAppointments(t_contact *myContact){
    printf("Appointments of %s:\n", myContact->name);
    if (myContact->nbAppointments >= 1){
        for (int i=0; i<myContact->nbAppointments; i++){
            displayAppointment(myContact->appointments[i]);
        }
    } else {
        printf("There is no appointment for this contact\n");
    }
}