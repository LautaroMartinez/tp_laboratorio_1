#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "Utilities.h"

#define LEN 2000

int menu();

int main(void) {

    setbuf(stdout, NULL);

    Passenger passengerList[LEN];
    int loop_menu = 1;
    int global_id = 1;
    int any_index;
    int empty_index;

    initPassengerArray(passengerList, LEN);

    do {
        switch(menu()) {
            case 1: ;
                empty_index = getEmptyPassengerIndex(passengerList, LEN);
                if(empty_index != -1) {
                    addPassengers(&passengerList[empty_index], &global_id);
                } else {
                    printf("No se puede agregar mas pasajeros\n");
                    system("pause");
                }
                printf("Passajero %i\n", passengerList[0].id);
                break;
            case 2: ;
                passengerList[0].is_empty = 0;
                any_index = getNotEmptyPassengerIndex(passengerList, LEN);
                if(any_index != -1) {
                    modifyPassenger(passengerList,LEN);
                } else {
                    printf("No hay pasajeros para modificar\n");
                    system("pause");
                }
                break;
            case 3: ;
                any_index = getNotEmptyPassengerIndex(passengerList, LEN);
                if(any_index != -1) {
                    removePassenger(passengerList, LEN);
                } else {
                    printf("No hay pasajeros para dar de baja\n");
                    system("pause");
                }
                break;
            case 4:
                any_index = getNotEmptyPassengerIndex(passengerList, LEN);
                if(any_index != -1) {
                    showPassengers(passengerList, LEN);
                } else {
                    printf("No hay pasajeros para mostrar\n");
                    system("pause");
                }
                break;
            case 5:
                printf("Salir");
                loop_menu = 0;
                break;
            default:
                printf("opcion invalida\n");
                system("pause");
        }
    } while(loop_menu);

    return EXIT_SUCCESS;
}

int menu() {
    int opt;

    printf("**** PASAJEROS ****\n");
    printf("1- Nuevo Pasajero\n");
    printf("2- Editar Pasajero\n");
    printf("3- Borrar Pasajero\n");
    printf("4- Mostrar Pasajeros\n");
    printf("5- Salir\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opt);

    return opt;
}
