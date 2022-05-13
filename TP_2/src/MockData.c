#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "Utilities.h"
#include "MockData.h"

char nameMockArray[10][20] = {
    "Sallyann",
    "Ody",
    "Vinni",
    "Livy",
    "Lyndsay",
    "Yetta",
    "Brandi",
    "Lemmie",
    "Celestyn",
    "Darrelle"
};

char lastNameMockArray[10][20] = {
    "Bernaert",
    "Herrieven",
    "Stibbs",
    "Shorland",
    "Godlonton",
    "Hoofe",
    "Allmen",
    "Ridolfo",
    "Lassey",
    "Giacomasso"
};

float priceMockArray[10] = {
    1984.04,
    6126.03,
    4627.79,
    7673.91,
    1975.77,
    7678.2,
    8557.01,
    3424.87,
    6710.02,
    2873.92
};

char flightCodeMockArray[10][7] = {
    "HuWtqp",
    "WxVgzf",
    "ReXlry",
    "EwXiho",
    "NkDynq",
    "KaUnro",
    "HzLebo",
    "JzQmzs",
    "PvUesb",
    "IaClpo"
};

int statusMockArray[10] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9
};

int passengerTypeMockArray[10] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9
};

int checkQtyAvailable(Passenger passengerList[], int len, int qty) {
    int emptyCounter = 0;
    int i = 0;

    while(i < len && emptyCounter < qty) {
        if (passengerList[i].is_empty) {
            emptyCounter++;
        }
        i++;
    }

    if (emptyCounter == qty) {
        return 1;
    } else {
        printf("No hay lugar suficiente para crear %i Pasajeros\n", qty);
        return 0;
    }
}

void mockPassengers(Passenger passengerList[], int len, int* globalId){
    int qty = getNumber(0, len, "Ingrese la cantidad de Pasajeros a generar: ", "");
    if (checkQtyAvailable(passengerList, len, qty)) {
        for(int i = 0; i < qty; i++) {
            passengerList[i].id= *globalId;
            strcpy(passengerList[i].name, nameMockArray[rand() % 10]);
            strcpy(passengerList[i].last_name, lastNameMockArray[rand() % 10]);
            passengerList[i].price = priceMockArray[rand() % 10];
            strcpy(passengerList[i].flight_code, flightCodeMockArray[rand() % 10]);
            passengerList[i].flight_status = statusMockArray[rand() % 10];
            passengerList[i].passenger_type = passengerTypeMockArray[rand() % 10];
            passengerList[i].is_empty = 0;
            (*globalId)++;
        }
        printf("Pasajeros generados correctamente!\n");
        system("pause");
    } else {
        printf("Volviendo a Menu\n");
        system("pause");
    } 
}
