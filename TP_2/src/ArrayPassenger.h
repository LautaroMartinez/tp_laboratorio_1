#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MENUOPT_H_
#define MENUOPT_H_

typedef struct myPassenger {
    int id;
    char name[21];
    char last_name[21];
    float price;
    char flight_code[7];
    int passenger_type;
    int flight_status;
    int is_empty;
} Passenger;

#endif /* MENUOPT_H_ */

int getEmptyPassengerIndex(Passenger passengerList[], int len);
int getNotEmptyPassengerIndex(Passenger passengerList[], int len);

void initPassengerArray(Passenger passengerList[], int len);
void addPassengers(Passenger *passenger, int *globalId);
void removePassenger(Passenger passengerList[], int len);
void showPassengers(Passenger passengerList[], int len);

int modifyMenu(Passenger passenger);
int reportsMenu();
void modifyPassenger(Passenger passengerList[], int len);
int findPassengerById(Passenger passengerList[], int len);
void sortPassengers(Passenger passengerList[], int len, int order);
