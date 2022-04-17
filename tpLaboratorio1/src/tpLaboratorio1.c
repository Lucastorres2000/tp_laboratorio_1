/*
 ============================================================================
 Name        : tpLaboratorio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "gets.h"
#include "calculos.h"
#define BTC 4507072.38
int main()
{
int option;
setbuf(stdout,NULL);
float kilometers;// X
float price_Aerolineas=0;// Y
float price_Latam=0;// Z

//
    int validateCostsAero;
    int validateCostsLatam;
    int validatePrices;



    float priceDebitAero;
    float priceCreditAero;
    float priceCriptoAero;
    float priceUnitaryAero;


    float priceDebitLatam;
    float priceCreditLatam;
    float priceCryptoLatam;
    float priceUnitaryLatam;



    do{

            printf("----------------------------------------\n" );
            printf("\n 1 -> Enter kilometers ");
            printf("\n 2 -> Enter flight price ");
            printf("\n 3 -> Calculate costs ");
            printf("\n 4 -> Inform prices");
            printf("\n 5 -> Forced data upload");
            printf("\n 6 -> Exit ");
            printf("\n----------------------------------------\n");

            scanf("%d",&option);



    switch(option){

        case 1:
            	get_Numero(&kilometers,"Write the kilometers","Error in kilometers.Try again ...",3);

        break;

        case 2:
        	validatePrices= subPrecio(&price_Aerolineas,&price_Latam);

        break;

        case 3:
        	if(validatePrices==1){
                 validateCostsAero= calcularCostos(price_Aerolineas,kilometers,&priceDebitAero,&priceCreditAero,& priceCriptoAero,&priceUnitaryAero);
                 validateCostsLatam=calcularCostos(price_Latam,kilometers,&priceDebitLatam,&priceCreditLatam,&priceCryptoLatam,&priceUnitaryLatam);
        	}else{
        		printf("You must first enter the flight costs...");
        	}
                 break;

        case 4:
            if( validateCostsAero == 1 &&  validateCostsLatam == 1){
            printf("Kilometers: %f",kilometers);
            mostrarDatos("Aerolineas",price_Aerolineas,priceDebitAero,priceCreditLatam, priceCriptoAero,priceUnitaryAero);
            mostrarDatos("Latam",price_Latam,priceDebitLatam,priceCreditLatam,priceCryptoLatam,priceUnitaryLatam);
        }else{
        printf("No data. Try again ...");
        }
        break;

        case 5:
            kilometers=7090;
            price_Aerolineas=162965;
            price_Latam=159339;
            validatePrices=1;
        break;
    }

    system("pause");
    system("cls");
}while(option != 6);

    return 0;
}
