#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "ArrayPassengerAux.h"
#include "Utilities.h"
#include "MockData.h"

#define LEN 2000

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
                break;
            case 2: ;
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
            case 4: ;
                any_index = getNotEmptyPassengerIndex(passengerList, LEN);
                if(any_index != -1) {
                    showPassengers(passengerList, LEN);
                } else {
                    printf("No hay pasajeros para mostrar\n");
                    system("pause");
                }
                break;
            case 5: ;
                empty_index = getEmptyPassengerIndex(passengerList, LEN);
                if(any_index != -1) {
                    mockPassengers(passengerList, LEN, &global_id);
                } else {
                    printf("No se puede agregar mas pasajeros\n");
                    system("pause");
                }
                break;
            case 6:
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
