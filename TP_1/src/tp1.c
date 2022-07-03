#include <stdio.h>
#include <stdlib.h>
#include "Utilities.h"
#include "pricing.h"
#include "menu.h"

#define BTC 4606954.55

int main(void) {
    setbuf(stdout, NULL);

    float kms = 0;
    float priceAerolineas = 0;
    float priceLatam = 0;
    float priceDebitAereolineas;
    float priceCreditAereolineas;
    float priceBTCAereolineas;
    float priceUnitAereolineas;

    float priceDebitLatam;
    float priceCreditLatam;
    float priceBTCLatam;
    float priceUnitLatam;

    float priceDiff;

    int continueLoop = 1;
    int priceLoaded = 0;
    int costsLoaded = 0;

    do {

        switch(menu(kms, priceAerolineas, priceLatam)){
            case 1:
                kms = getFloat(1 , 50000, "Ingrese kilometros (Desde 1 - Hasta 50.000): ", "");
                break;
            case 2:
                printf("Ingrese el Precio de vuelo.\n");
                
                priceAerolineas = getFloat(1 , 1000000, "Precio de Aereolineas: (Desde 1 - Hasta 1.000.000): ", "");
                priceLatam      = getFloat(1 , 1000000, "Precio de Latam: (Desde 1 - Hasta 1.000.000): ", "");
                priceLoaded = 1;
                
                break;
            case 3:
                if(kms && priceLoaded) {
                    getCosts(kms, priceAerolineas, BTC, &priceDebitAereolineas, &priceCreditAereolineas, 
                             &priceBTCAereolineas, &priceUnitAereolineas);
                    getCosts(kms, priceLatam, BTC, &priceDebitLatam  ,&priceCreditLatam, &priceBTCLatam , &priceUnitLatam);
                        priceDiff = getPriceDiff(priceLatam,priceAerolineas);
                    printf("Se calcularon los precios con exito\n");
                    costsLoaded = 1;
                }else {
                    printf("ERROR: Primero ingresar los kilometros y precios\n");
                    system("pause");
                }
                break;
            case 4:
                if(costsLoaded){
                    showResults(kms,priceAerolineas,priceLatam,priceDebitAereolineas,priceCreditAereolineas,priceBTCAereolineas,
                                    priceUnitAereolineas,priceDebitLatam,priceCreditLatam,priceBTCLatam,priceUnitLatam,priceDiff);
                } else {
                    printf("ERROR: Primero calcular los costos\n");
                    system("pause");
                }
                break;
            case 5:
                getCosts(7090, 162965, BTC, &priceDebitAereolineas, &priceCreditAereolineas, &priceBTCAereolineas, &priceUnitAereolineas);
                getCosts(7090, 159339, BTC, &priceDebitLatam, &priceCreditLatam, &priceBTCLatam, &priceUnitLatam);
                priceDiff = getPriceDiff(162965, 159339);
                showResults(7090, 162965, 159339, priceDebitAereolineas, priceCreditAereolineas, priceBTCAereolineas,
                            priceUnitAereolineas, priceDebitLatam, priceCreditLatam, priceBTCLatam, priceUnitLatam, priceDiff);
                break;
            case 6:
                printf("Fin del programa\n");
                continueLoop = 0;
                break;
            default:
                printf("ERROR: Ingrese un numero dentro del menu (1 a 6)\n");
        }
    } while(continueLoop);
    
    system("pause");
    return EXIT_SUCCESS;
}