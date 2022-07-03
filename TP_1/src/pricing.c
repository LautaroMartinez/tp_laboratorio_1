#include <stdio.h>
#include <stdlib.h>
#include "pricing.h"
#include "Utilities.h"

void getCosts(float km, float priceTicket, float btc, float* priceDebit, float* priceCredit, float* priceBTC, float* priceUnit) {
    *priceDebit  = subPercentage(priceTicket, 0.10); // -10%
    *priceCredit = addPercentage(priceTicket, 0.25); // +25%
    *priceBTC    = divideWithValidation(priceTicket, btc, "Bitcoin");
    *priceUnit   = divideWithValidation(priceTicket, km, "Kilometros");
}

float getPriceDiff(float price1, float price2) {
    return price1 - price2;
}

void showResults(float km, float priceAereolineas, float priceLatam, float priceDebitAereolineas, float priceCreditAereolineas,
                float priceBTCAereolineas, float priceUnitAereolineas, float priceDebitLatam, float priceCreditLatam,
                float priceBTCLatam,float priceUnitLatam,float priceDiff) {

    printf("KMs Ingresados: %.2f km\n\n", km);

    printf("Precio Aereolineas: $%.2f\n", priceAereolineas);
    printf("a) Precio con tarjeta de debito: $%.2f\n", priceDebitAereolineas);
    printf("b) Precio con tarjeta de credito: $%.2f\n", priceCreditAereolineas);
    printf("c) Precio pagando con bitcoin: %.8f BTC\n", priceBTCAereolineas);
    printf("d) Precio unitario: $%.3f\n\n", priceUnitAereolineas);

    printf("Precio Latam: $%.2f\n",priceLatam);
    printf("a) Precio con tarjeta de debito: $%.2f\n", priceDebitLatam);
    printf("b) Precio con tarjeta de credito: $%.2f\n", priceCreditLatam);
    printf("c) Precio pagando con bitcoin: %.8f BTC\n", priceBTCLatam);
    printf("d) Precio unitario: $%.3f\n\n", priceUnitLatam);

    printf("La diferencia de precio es: $%.2f\n", priceDiff);
    system("pause");
}

float addPercentage(float num, float per) {
    return num * (1 + per);
}

float subPercentage(float num, float per) {
    return num * (1 - per);
}

float divideWithValidation(float n1, float n2, char desc[]) {
    if (n2 == 0) {
        printf("ERROR: Se intento dividir por 0, reingrese el valor de %s\n", desc);
        n2 = getFloatNoMinMax("Ingrese nuevo Valor: ", "");
        return divideWithValidation(n1, n2, desc);
    } else {
        return n1 / n2;
    }
}