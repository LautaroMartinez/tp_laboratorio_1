#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "ArrayPassengerAux.h"
#include "Utilities.h"

int findPassengerById(Passenger passengerList[], int len) {
    int foundFlag = 0;
    int idToFind;
    int i = 0;

    idToFind = getNumber(1, 10000, "Ingrese ID del Pasajero: ", "");

    while(foundFlag == 0 && i < len){

        if (passengerList[i].is_empty == 0 && passengerList[i].id == idToFind) {
            foundFlag = 1;
        } else {
            foundFlag = 0;
        }
        i++;
    }

    if (foundFlag) {
        i--;
        return i;
    } else {
        printf("ERROR: No se Encotro ese ID\n");
        if (yesOrNo("Quiere volver a intentear? (Y/N): ", "")) {
            return findPassengerById(passengerList, len);
        } else {
            return -1;
        }
    }
}

int menu() {
    int opt;

    printf("**** PASAJEROS ****\n");
    printf("1- Nuevo Pasajero\n");
    printf("2- Editar Pasajero\n");
    printf("3- Borrar Pasajero\n");
    printf("4- Mostrar Pasajeros\n");
    printf("5- Generar Pasajeros\n");
    printf("6- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}

int modifyMenu(Passenger passenger) {
    int opt;

    printf("**** EDICION DE -%s %s- ****\n", passenger.name, passenger.last_name);
    printf("1- Editar Nombre\n");
    printf("2- Editar Apellido\n");
    printf("3- Editar Precio\n");
    printf("4- Editar Codigo de Vuelo\n");
    printf("5- Editar Tipo\n");
    printf("6- Editar Status de Vuelo\n");
    printf("7- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}

int reportsMenu() {
    int opt;

    printf("**** INFORMES ****\n");
    printf("1- Apellido y Tipo (ASC)\n");
    printf("2- Apellido y Tipo (DEC)\n");
    printf("3- Codigo y Estado de vuelo (ASC)\n");
    printf("4- Codigo y Estado de vuelo (DEC)\n");
    printf("5- Total y Promedio de Precios\n");
    printf("6- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}

int getEmptyPassengerIndex(Passenger passengerList[], int len) {
    int foundFlag = 0;
    int i = -1;

    while(foundFlag == 0 && i < len){
        i++;
        foundFlag = passengerList[i].is_empty;
    }

    if (foundFlag) {
        return i;
    } else {
        return -1;
    }
}

int getNotEmptyPassengerIndex(Passenger passengerList[], int len) {
    int foundFlag = 0;
    int i = -1;

    while(foundFlag == 0 && i < len){
        i++;
        foundFlag = !passengerList[i].is_empty;
    }

    if (foundFlag) {
        return i;
    } else {
        return -1;
    }
}


void sortPassengers(Passenger passengerList[], int len, int order) {
    Passenger auxPassenger;
    int orderFlag = 0;
    int breakFlag = 0;
    int i; 
    int j;
    char passengerTypeName[15];
    char flightStatusName[15];

    for(i = 0; i < len; i++) {
        for(j = 0; j < len-i-1; j++) {
            orderFlag = 0;
            if (passengerList[j].is_empty == 0) {
                if (order) {
                    if (strcmp(passengerList[j].last_name,passengerList[j+1].last_name) > 0 ||
                       (strcmp(passengerList[j].last_name,passengerList[j+1].last_name) == 0 && 
                        passengerList[j].passenger_type > passengerList[j+1].passenger_type)) {
                        orderFlag = 1;
                    } else {
                        orderFlag = 0;
                    }
                } else {
                    if (strcmp(passengerList[j].last_name,passengerList[j+1].last_name) < 0 ||
                       (strcmp(passengerList[j].last_name,passengerList[j+1].last_name) == 0 && 
                        passengerList[j].passenger_type < passengerList[j+1].passenger_type)) {
                        orderFlag = 1;
                    } else {
                        orderFlag = 0;
                    }
                }
                if(orderFlag) {
                    auxPassenger = passengerList[j];
                    passengerList[j] = passengerList[j+1];
                    passengerList[j+1] = auxPassenger;
                    breakFlag = 1;
                } 
            }
        }

        if(breakFlag == 0) {
            break;
        }
    }
    
    printf("**** Pasajeros por Apellido y Tipo: ****\n");
    printf("Id | Nombre | Precio | Codigo de Vuelo | Tipo | Status de Vuelo\n");

    for(i = 0; i < len; i++) {
        if (passengerList[i].is_empty == 0) {
            getPassengerTypeName(passengerList[i].passenger_type, passengerTypeName);
            getFlightStatusName(passengerList[i].flight_status, flightStatusName);

            printf("%i | %s, %s | %.2f | %s | %s | %s \n", passengerList[i].id, passengerList[i].last_name, passengerList[i].name, passengerList[i].price,
        	                     passengerList[i].flight_code, passengerTypeName, flightStatusName);
        }
    }
    printf("**** Fin ****\n");
    system("pause");
}

void sortPassengersByCode(Passenger passengerList[], int len, int order) {
    Passenger auxPassenger;
    int orderFlag = 0;
    int breakFlag = 0;
    int i; 
    int j;
    char passengerTypeName[15];
    char flightStatusName[15];

    for(i = 0; i < len; i++) {
        for(j = 0; j < len-i-1; j++) {
            orderFlag = 0;
            if (passengerList[j].is_empty == 0) { 
                if (order) {
                    if (strcmp(passengerList[j].flight_code,passengerList[j+1].flight_code) > 0 ||
                       (strcmp(passengerList[j].flight_code,passengerList[j+1].flight_code) == 0 && 
                        passengerList[j].flight_status > passengerList[j+1].flight_status)) {
                        orderFlag = 1;
                    } else {
                        orderFlag = 0;
                    }
                } else {
                    if (strcmp(passengerList[j].flight_code,passengerList[j+1].flight_code) < 0 ||
                       (strcmp(passengerList[j].flight_code,passengerList[j+1].flight_code) == 0 && 
                        passengerList[j].flight_status < passengerList[j+1].flight_status)) {
                        orderFlag = 1;
                    } else {
                        orderFlag = 0;
                    }
                }
                if(orderFlag) {
                    auxPassenger = passengerList[j];
                    passengerList[j] = passengerList[j+1];
                    passengerList[j+1] = auxPassenger;
                    breakFlag = 1;
                } 
            }
        }

        if(breakFlag == 0) {
            break;
        }
    }
    
    printf("**** Pasajeros por Codigo y Estado de vuelo: ****\n");
    printf("Id | Nombre | Precio | Codigo de Vuelo | Tipo | Status de Vuelo\n");
    for(i = 0; i < len; i++) {
        if (passengerList[i].is_empty == 0) {
            getPassengerTypeName(passengerList[i].passenger_type, passengerTypeName);
            getFlightStatusName(passengerList[i].flight_status, flightStatusName);

        	printf("%i | %s, %s | %.2f | %s | %s | %s \n", passengerList[i].id, passengerList[i].last_name, passengerList[i].name, passengerList[i].price,
        	                     passengerList[i].flight_code, passengerTypeName, flightStatusName);
        }
    }
    printf("**** Fin ****\n");
    system("pause");
}

void informPricePercentage(Passenger passengerList[], int len) {
    float priceAcc = 0;
    float priceAvrg;
    int counter = 0;
    int counterMoreThanAvrg = 0;
    int priceList[len];
    int j = 0;

    for(int i = 0; i < len; i++) {
        if(passengerList[i].is_empty == 0) {
            counter++;
            priceAcc += passengerList[i].price;
            priceList[j] = passengerList[i].price;
            j++;
        }
    }

    priceAvrg = priceAcc / counter;

    printf("**** Total y Promedio de Precios: ****\n");
    printf("Total: %.2f\n", priceAcc);
    printf("Promedio: %.2f\n", priceAvrg);

    for(int k = 0; k < j; k++) {
        if(priceList[k] > priceAvrg) {
            counterMoreThanAvrg++;
        }
    }

    if(counterMoreThanAvrg == 0) {
        printf("No hay pasajeros que superen el promedio\n");
    } else {
        printf("Cantidad de pasajeros que superan el promedio: %d\n", counterMoreThanAvrg);
    }

    printf("**** Fin ****\n");
    system("pause");
}

void getPassengerTypeName(int passenger_type, char passengerTypeName[]) {
    switch(passenger_type) {
        case 1:
        	strcpy(passengerTypeName, "FirstClass");
            break;
        case 2:
        	strcpy(passengerTypeName, "ExecutiveClass");
            break;
        case 3:
        	strcpy(passengerTypeName, "EconomyClass");
            break;
        default:
        	strcpy(passengerTypeName, "Error");
            break;
    }
}

void getFlightStatusName(int flight_status, char flightStatusName[]) {
    switch(flight_status) {
        case 1:
            strcpy(flightStatusName, "Aterrizado");
            break;
        case 2:
            strcpy(flightStatusName, "En Horario");
            break;
        case 3:
            strcpy(flightStatusName, "En Vuelo");
            break;
        case 4:
            strcpy(flightStatusName, "Demorado");
            break;
        default:
            strcpy(flightStatusName, "Error");
            break;
    }
}
