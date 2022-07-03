#ifndef PRICING_H_
#define PRICING_H_

#endif /* PRICING_H_ */

void getCosts(float km, float priceTicket, float btc, float* priceDebit, float* priceCredit, float* priceBTC, float* priceUnit);
float getPriceDiff(float price1, float price2);
void showResults(float km, float priceAereolineas, float priceLatam, float priceDebitAereolineas, float priceCreditAereolineas, 
				 float priceBTCAereolineas, float priceUnitAereolineas, float priceDebitLatam, float priceCreditLatam, 
				 float priceBTCLatam, float priceUnitLatam, float priceDiff);

float addPercentage(float num, float per);
float subPercentage(float num, float per);
float divideWithValidation(float n1, float n2, char desc[]);