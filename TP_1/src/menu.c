#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(float km,float priceAereolineasinea, float priceLatam) {
    int option;

    printf("**** MENU PRINCIPAL ****\n");
    printf("1 - Ingresar Kilometros: (km = %.2f)\n", km);
    printf("2 - Ingresar Precio: (Aereolineas = %.2f, Latam = %.2f)\n",priceAereolineasinea,priceLatam);
    printf("3 - Calcular costos\n");
    printf("4 - Mostrar Informe\n");
    printf("5 - Carga de datos\n");
    printf("6 - FIN\n");
    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}