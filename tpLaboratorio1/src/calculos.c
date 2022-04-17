/*
 * calculos.c
 *
 *  Created on: 16 abr. 2022
 *      Author: lucas
 */
#include <stdio.h>
#include <stdlib.h>
float getDescuento(float precio, float descuento ){
	float aux=0;
	float retorno=0;

			aux= precio * (descuento / 100);
			retorno= precio - aux;

return retorno;
}


float getCredito(float precio,float interes){
float aux =0;
float retorno =0;

aux= precio * (interes / 100);
retorno= precio + aux;
 return retorno;
}


float getCrypto(float capital, float moneda){
 float retorno;
retorno=moneda/capital;
return retorno;

}
float getPrecioUnitario(float precio, float cantidad){
float retorno;
retorno = precio/cantidad;
return retorno;
}

