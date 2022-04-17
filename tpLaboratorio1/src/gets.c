/*
 * gets.c
 *
 *  Created on: 16 abr. 2022
 *      Author: lucas
 */


#include <stdio.h>
#include <stdlib.h>

int get_Numero(float* numero,char* mensaje,char* mensajeError,int itera){
 float buffer;
 int retorno = 0;
    printf("%s",mensaje);
    scanf("%f",&buffer);

	 if(buffer>=0){
	  *numero=buffer;
	  retorno=1;
	 }else{
	     printf("%s",mensajeError);
	 }



 return retorno;
}


