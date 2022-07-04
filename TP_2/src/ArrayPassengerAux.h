#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"

#ifndef ARRAYPASSENGERAUX_H_
#define ARRAYPASSENGERAUX_H_

#endif /* ARRAYPASSENGERAUX_H_ */

int getEmptyPassengerIndex(Passenger passengerList[], int len);
int getNotEmptyPassengerIndex(Passenger passengerList[], int len);

int menu();
int modifyMenu(Passenger passenger);
int reportsMenu();

int findPassengerById(Passenger passengerList[], int len);
void sortPassengers(Passenger passengerList[], int len, int order);
void sortPassengersByCode(Passenger passengerList[], int len, int order);
void informPricePercentage(Passenger passengerList[], int len);

void getPassengerTypeName(int passenger_type, char passengerTypeName[]);
void getFlightStatusName(int flight_status, char flightStatusName[]);
