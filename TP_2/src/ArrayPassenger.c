#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "Utilities.h"

void initPassengerArray(Passenger passengerList[], int len) {
	for (int i = 0; i < len; ++i) {
        passengerList[i].is_empty = 1;
	}
}

void addPassengers(Passenger *passenger, int *globalId) {
    passenger->id = *globalId;
    getString(passenger->name, 51, "Ingrese el Nombre: ", "");
    getString(passenger->last_name, 51, "Ingrese el Apellido: ", "");
    passenger->price = getFloat(0, 10000, "Ingrese el Precio: ", "");
    getString(passenger->flight_code, 10, "Ingrese el Codigo de Vuelo: ", "");
    passenger->passenger_type = getNumber(0, 10, "Ingrese el Tipo de Pasajero: ", "");
    passenger->flight_status = getNumber(0, 1000, "Ingrese el Status: ", "");
    passenger->is_empty = 0;
    *globalId++;

    printf("Se ingreso correctamente el pasajero\n");
    system("pause");
}

void modifyPassenger(Passenger passengerList[], int len){
    int passagerIndex = findPassengerById(passengerList, len);
    int loop_menu = 1;

    if (passagerIndex != -1) {
        do {
            switch(modifyMenu(passengerList[passagerIndex])) {
                case 1: ;
                    getString(passengerList[passagerIndex].name, 51, "Ingrese el Nombre: ", "");
                    break;
                case 2: ;
                    getString(passengerList[passagerIndex].last_name, 51, "Ingrese el Apellido: ", "");
                    break;
                case 3: ;
                    passengerList[passagerIndex].price = getFloat(0, 10000, "Ingrese el Precio: ", "");
                    break;
                case 4: ;
                    getString(passengerList[passagerIndex].flight_code, 10, "Ingrese el Codigo de Vuelo: ", "");
                    break;
                case 5: ;
                    passengerList[passagerIndex].passenger_type = getNumber(0, 10, "Ingrese el Tipo de Pasajero: ", "");
                    break;
                case 6: ;
                    passengerList[passagerIndex].flight_status = getNumber(0, 1000, "Ingrese el Status: ", "");
                    break;
                case 7:
                    printf("Volviendo a Menu\n");
                    system("pause");
                    loop_menu = 0;
                    break;
                default:
                    printf("opcion invalida\n");
                    system("pause");
            }
        } while(loop_menu);
    } else {
        printf("Volviendo a Menu\n");
        system("pause");
    }
}

void removePassenger(Passenger passengerList[], int len){
    int passagerIndex = findPassengerById(passengerList, len);
    if (passagerIndex != 1) {
        passengerList[passagerIndex].is_empty = 1;
        printf("Pasajero -%s %s- dado de baja con exito\n", 
            passengerList[passagerIndex].name, passengerList[passagerIndex].last_name);
        system("pause");
    } else {
        printf("Volviendo a Menu\n");
        system("pause");
    }
}

void showPassengers(Passenger passengerList[], int len) {
    int loop_menu = 1;
    do {
        switch(reportsMenu()) {
            case 1: ;
                sortPassengers(passengerList, len, 1);
                break;
            case 2: ;
                sortPassengers(passengerList, len, 0);
                break;
            case 3:
                printf("Volviendo a Menu\n");
                system("pause");
                loop_menu = 0;
                break;
            default:
                printf("opcion invalida\n");
                system("pause");
        }
    } while(loop_menu);
}

//Aux Fn

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
    printf("3- Salir\n");
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
    for(i = 0; i < len; i++) {
        if (passengerList[i].is_empty == 0) {
            printf("- %s, %i\n", passengerList[i].last_name, passengerList[i].passenger_type);
        }
    }
    printf("**** Fin ****\n");
    system("pause");
}
