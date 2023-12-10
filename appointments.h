//
// Created by hisla on 10/12/2023.
//

#ifndef C_PROJECT_L2_APPOINTMENTS_H
#define C_PROJECT_L2_APPOINTMENTS_H

typedef struct s_appointment{
    int Day;
    int Month;
    int Year;
    int Hour;
    int Minute;
    int Second;
    int Duration;
    char *Description;
}t_appointment;

#endif //C_PROJECT_L2_APPOINTMENTS_H
