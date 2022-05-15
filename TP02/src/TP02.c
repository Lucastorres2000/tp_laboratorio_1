/*
 ============================================================================
 Name        : TP02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 *
 * ArrayPassenger.c
 *
 *  Created on: 27 abr. 2022
 *      Author: lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "UTN.h"
#define AMOUNT_PASSENGER 9


int main(void) {
	setbuf(stdout,NULL);
	int id=1;
	int bufferId;
	float totalPrices;
	float averagePrices;
	int aboveAveragePrices;
	int optionPrint;
	Passenger PassengerList[AMOUNT_PASSENGER];
	initPassengers(PassengerList,AMOUNT_PASSENGER);
	char option;

	    do
	    {
	        printf("\n----------------------------------------------------------------------------------------\n");
	        printf("\n                        Choose an option\n ");
	        printf("\n                    [ 1 ]--> Add an Passenger");
	        printf("\n                    [ 2 ]--> Modify an Passenger");
	        printf("\n                    [ 3 ]--> Delete Passenger" );
	        printf("\n                    [ 4 ]--> Report Passenger list");
	        printf("\n                    [ 5 ]--> Forced Data\n ");
	        printf("\n                    [ 6 ]--> Leave program\n ");
	        printf("\n----------------------------------------------------------------------------------------\n");

	        printf("\nChoose an option : ");
	        fflush(stdin);
	        scanf("%c",&option);
	       while(option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6')
	        {
	            printf("\n!! This option is not valid !!\n");
	            printf("Choose a valid option: ");
	            fflush(stdin);
	            scanf("%c", &option);
	        }

	    switch (option)
	 {
	        case '1':
	        	loadUpPassenger(PassengerList,AMOUNT_PASSENGER,&id);
	            break;
	        case '2':
	        	if(noData(PassengerList,AMOUNT_PASSENGER)==TRUE)//checks that there is data loaded
	        						{
	        							printPassenger(PassengerList,AMOUNT_PASSENGER);
	        							if(utn_getNumber(&bufferId,"\n\nIngrese el id del pasajero que quiere modificar: ","\nError",0,999999,3)==SUCCESS &&
	        									modifyPassenger(PassengerList,AMOUNT_PASSENGER,bufferId) == SUCCESS)
	        							{
	        								printf("\nModificacion realizada con exito\n");
	        							} else {
	        								printf("\nNo se puedo realizar la modificacion o no existen cargas con ese id\n");
	        							}
	        						} else {
	        							printf("\nPrimero debe cargar Datos");
	        						}
	        						break;
	        					case 3:

	            break;
	        case '3':
	        	if(noData(PassengerList,AMOUNT_PASSENGER)){
	        		printPassenger(PassengerList,AMOUNT_PASSENGER);
	        	       if(utn_getNumber(&bufferId,"\n\nIngrese el id del empleado que quiere eliminar: ","\nError",0,999999,3)==SUCCESS &&
	        	    		   removePassenger(PassengerList,AMOUNT_PASSENGER,bufferId) == SUCCESS)
								{
									printf("\nBaja realizada con exito\n");
								} else {
									printf("\nNo se puedo realizar la baja o no existen cargas con ese id\n");
								}
						}else{
	        	        		printf("no Data ");
	        	        	}

	        	break;

	        case '4':
	        	if(noData(PassengerList,AMOUNT_PASSENGER)){
	        		//if(utn_getNumber(&optionPrint,"Choose an option \n 1- alphabetically ordered \n 2- Total y Average \n 3-Order by flight code ","Error",0,3,3)==SUCCESS)
	        		if(utn_getNumber(&optionPrint,"Choose an option \n 1- alphabetically ordered \n 2- Total y Average \n ","Error",0,2,3)==SUCCESS)
	        		{



	        					switch(optionPrint)
	        					       {
	        								case 1:
	        										sortPassengersByLastName(PassengerList,AMOUNT_PASSENGER,1);

	        										printf("\n----------------------------------------------------------------------------------------\n");
	        										printf("\n%s %10s %10s %10s %10s %10s \n", "ID", "NAME", "LASTNAME", "PRICE", "FLYCODE","TYPEPASSENGER");

	        										printPassenger(PassengerList,AMOUNT_PASSENGER);
	        								break;

	        								case 2:

	        										sumPrices(PassengerList ,AMOUNT_PASSENGER,&totalPrices,&averagePrices );
	        										aboveAveragePrices=aboveAveragePassenger(PassengerList ,AMOUNT_PASSENGER,averagePrices);
	        										printf("Total Prices : %f \n",totalPrices);
	        										printf("Total Average Prices  : %f \n ",averagePrices);
	        										printf("Overall above average : %d ",aboveAveragePrices);

	        					        		break;
	        					       }
	        		}

	        	}else{

	        				printf("no se puede mostrar sin primero hacer una carga \n");
	        	}
	        	//
	         //   printf("\n----------------------------------------------------------------------------------------\n");
	         //   printf("\n%10s %10s %10s %10s %10s %10\n", "ID", "NAME", "LASTNAME", "PRICE", "FLYCODE","TYPEPASSENGER");
	         //   printf("\n----------------------------------------------------------------------------------------\n");
					break;
	        case '5':
	        	forcedData(PassengerList,AMOUNT_PASSENGER,&id);
	        	break;
	        case '6':
	        	printf("CERRANDO APLICACION... ");
	        	break;
	 }

	    system("pause");
	    system("cls");
	 }while(option!='6');

	return EXIT_SUCCESS;
}
