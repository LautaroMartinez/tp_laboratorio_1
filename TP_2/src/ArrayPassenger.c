#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "ArrayPassengerAux.h"
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
    (*globalId)++;

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
                    printf("Opcion invalida\n");
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
            case 3: ;
                sortPassengersByCode(passengerList, len, 1);
                break;
            case 4: ;
                sortPassengersByCode(passengerList, len, 0);
                break;
            case 5:
                printf("Volviendo a Menu\n");
                system("pause");
                loop_menu = 0;
                break;
            default:
                printf("Opcion invalida\n");
                system("pause");
        }
    } while(loop_menu);
}