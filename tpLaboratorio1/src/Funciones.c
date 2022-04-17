/*
 * Funciones.c
 *
 *  Created on: 16 abr. 2022
 *      Author: lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include "gets.h"
#include "calculos.h"
#define BTC 4507072.38
#define TIMER 3
int subPrecio(float* pAerolineas,float* pLatam){
	float buffer;
	int opc;
	int retorno=0;

		do{
		printf("----------------------------------------\n" );
		printf("\n 1 -> Precio Aerolineas ");
		printf("\n 2 -> Precio Latam");
		printf("\n 3 -> Salir");
		printf("\n----------------------------------------\n");
		scanf("%d",&opc);

	switch(opc){
		case 1:
			get_Numero(&buffer,"Indique el Precio: " ,"Escriba correctamente el precio...",TIMER);
			*pAerolineas=buffer;
			retorno=1;
			break;
		case 2:
			get_Numero(&buffer,"Indique el Precio: " ,"Escriba correctamente el precio...",TIMER);
			*pLatam=buffer;
			retorno=1;
			break;
	}
}while(opc!=3);
return retorno;
}
int calcularCostos(float precio,float km,float* pDebito,float* pCredito,float* pCrypto,float* pUnitario){
int retorno=0;

    if(precio>0){
            *pDebito=getDescuento(precio,10);
            *pCredito=getCredito(precio,25);
            *pCrypto=getCrypto(precio,BTC);
            *pUnitario=getPrecioUnitario(precio,km);
            retorno=1;
            printf("Calculando .....\n");
    }
    system("pause");
    system("cls");

return retorno;
}
void mostrarDatos(char* compania,float precio,float debito,float credito,float crypto,float unitario){
printf("\nel precio de %s :%f\n",compania,precio);
printf("A) El precio en debito es :%f\n",debito);
printf("B) El precio en credito es %f\n",credito);
printf("C) El precio en BTC es : %f\n",crypto);
printf("D) el precio unitario es : %f\n",unitario);


}
