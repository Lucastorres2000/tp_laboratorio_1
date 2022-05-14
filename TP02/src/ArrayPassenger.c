/*
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
#define MAX 999999
int forcedData(Passenger* List,int len,int *id){
int i;
 int retorno = -1;
 char name[][NLEN] = {"Jacob","Michael","Ethan","William","Emily","Ava","Olivia","Emma","Andrew"};
 char  lastName[][NLEN] = {"Novak","Connor","Lum","Forbis","Green","King","White","Stone","Garfield"};
 int idAux [10]={27,89,21,34,78,95,37,54,78};
 char flycode[][NLEN]={"AAA","BBB","CCC","DDD","EEE","FFF","GGG","HHH","III"};
 float price [10]={2000,3000,4000,5000,6000,7000,8000,9000};

 for(i=0;i<len;i++){

	 strcpy(List[i].name, name[i]);
	 strcpy(List[i].lastName, lastName[i]);
	 List[i].price = price[i];
	 strcpy(List[i].flycode,flycode[i]);
	 List[i].id = idAux[i];
	 List[i].isEmpty=FALSE;
	 (*id)++;
 }


 return retorno;
};

void printOnePassenger(Passenger list){
printf("%5d %10s %10s %10.2f %10s\n", list.id,
		                               list.name,
		                               list.lastName,
		                               list.price,
		                               list.flycode);



};

int initPassengers(Passenger* list, int len){
	int retorno=0;
	int i;
	if(list!=NULL && len > 0 ){
		retorno=1;
		 	 for(i=0;i<len;i++){

		 		 list[i].isEmpty=TRUE;
		 	 }

	}

	return retorno;

};
int findEmptyIndex(Passenger* list, int len)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}
int loadUpPassenger(Passenger* list, int len, int* id)
{
	int result= ERROR;
	Passenger bufferPassenger;

	if(list!=NULL && len>0 && findEmptyIndex(list,len)!=ERROR)//in addition to validating the parameters, ensures that there is room before making the user load data
	{
		if(utn_getName(bufferPassenger.name,NLEN,"\nIngrese nombre: ","\nError, debe ingresar un nombre", 3)==SUCCESS &&
			utn_getName(bufferPassenger.lastName,NLEN,"\nIngrese apellido: ","\nError, debe ingresar un apellido", 3)==SUCCESS &&
			utn_getFloatNumber(&bufferPassenger.price, "\nIngrese precio: ","\nError, debe ingresar un precio valido",0,MAX,3)==SUCCESS &&
			utn_getNumber(&bufferPassenger.typePassenger, "\n1 = Turista - 2 = Ejecutivo : ","\nError, debe ingresar una clase correcta",0,2,3)==SUCCESS &&
			utn_getName(bufferPassenger.flycode,NLEN ,"\nIngrese codigo de vuelo: ","\nError, debe ingresar un codigo de vuelo valido",3)==SUCCESS &&
			addPassenger(list,len,*id,bufferPassenger.name,bufferPassenger.lastName,bufferPassenger.price,bufferPassenger.typePassenger,bufferPassenger.flycode)==SUCCESS)
		{
			(*id)++;
			result = SUCCESS;
		}
	}
	return result;
}
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[] ){

	int result = ERROR;
		int index;

		if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && price>=0 && typePassenger>0)//I don't ask if there is space because I already check it when I ask for the data
		{
			index = findEmptyIndex(list,len);
			list[index].id = id;
			strncpy(list[index].name, name,NLEN);
			strncpy(list[index].lastName,lastName,NLEN);
			list[index].price = price;
			list[index].typePassenger = typePassenger;
			strncpy(list[index].flycode,flycode,NLEN);
			list[index].isEmpty = FALSE;
			result = SUCCESS;
		}
		return result;
	}

int findPassengerbyId(Passenger* list, int len, int id){
	int result = ERROR;
		int i;

		if(list!=NULL && len>0)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty == FALSE && list[i].id == id)
				{
					result = i;
					break;
				}
			}
		}
		return result;
};

int removePassenger(Passenger* list, int len, int id){

	int result = ERROR;
		int index;
		char bufferAnswer[10];
		index = findPassengerbyId(list,len,id);
		printPassenger(list,len);
		if(list!=NULL && len>0 && index != ERROR && list[index].isEmpty == FALSE)
		{
			if(utn_getName(bufferAnswer,10,"\nSeguro que desea eliminar? Debe ingresar 'Si' para proseguir con la baja ", "\nError,ingrese una respuesta valida.",3)== SUCCESS && strncasecmp(bufferAnswer,"si",10)==0)
			{
			list[index].isEmpty = TRUE;
			result = SUCCESS;
			}
		}
		return result;
};

int sortPassenger(Passenger* list, int len, int order){
	return 0;
};

int printPassenger(Passenger* list, int lenght){
	int retorno=0;
		int i;
		if(list!=NULL && lenght > 0 ){
			retorno=1;
			 	 for(i=0;i<lenght;i++){
			 		 if(list[i].isEmpty==FALSE){
			 			printOnePassenger(list[i]);

			 		 }

			 	 }

		}

		return retorno;
};

int sortPassengerByCode(Passenger* list, int len, int order){
	return 0;
};
int modifyPassenger(Passenger* list, int len, int id){
	int result = ERROR;
		int index;
		int option;
		Passenger bufferPassenger;
		index = findPassengerbyId(list,len,id);
		if(list!=NULL && len>0 && index != ERROR && list[index].isEmpty == FALSE)
	{
			do {
				system("cls");
				if(utn_getNumber(&option,"\n\nIngrese una opcion: "
						"\n1.Modificar Nombre "
						"\n2.Modificar Apellido "
						"\n3.Modificar price "
						"\n4.Modificar flyCode"
						"\n5.Modificar typePassenger"
						"\n6.Volver al menu principal\n", "Error, elija una opcion valida\n", 1, 6, 3)==SUCCESS) {
					switch(option)
					{
					case 1:
						if(utn_getName(bufferPassenger.name,NLEN,"\nIngrese nombre: ","\nError, debe ingresar un nombre", 3)==SUCCESS) {
							strncpy(list[index].name,bufferPassenger.name,NLEN);
							result = SUCCESS;
						} else {
							result = ERROR;
						}
						break;
					case 2:
						if(utn_getName(bufferPassenger.lastName,NLEN,"\nIngrese apellido: ","\nError, debe ingresar un apellido", 3)==SUCCESS) {
							strncpy(list[index].lastName,bufferPassenger.lastName,NLEN);
						result = SUCCESS;
						} else {
							result = ERROR;
						}
						break;
					case 3:
						if(utn_getFloatNumber(&bufferPassenger.price, "\nIngrese precio: ","\nError, debe ingresar un precio valido",0,MAX,3)==SUCCESS) {
							list[index].price = bufferPassenger.price;
							result = SUCCESS;
						} else {
							result = ERROR;
						}
						break;
					case 4:
							if(utn_getName(bufferPassenger.flycode,NLEN,"\nIngrese flycode: ","\nError, debe ingresar un flycode ", 3)==SUCCESS) {
								strncpy(list[index].flycode,bufferPassenger.flycode,NLEN);
							result = SUCCESS;
						} else {
								result = ERROR;
						}
						break;
					case 5:
					if(utn_getNumber(&bufferPassenger.typePassenger, "\nIngrese typePassenger 1 Turista -- 2 Ejecutivo: ","\nError, debe ingresar un typePassenger valido (1 o 2)",0,3,3)==SUCCESS) {
						list[index].typePassenger= bufferPassenger.typePassenger;
											result = SUCCESS;
							} else {
									result = ERROR;
							}
							break;
					}
				}
			}while(option!=6);
		}
		return result;
}
int noData(Passenger* list, int len)
{
	int i;
	int result = FALSE;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				result = TRUE;
				break;
			}
		}
	}
	return result;
}
int sortPassengersByLastName(Passenger* list, int len, int order)
{
	Passenger auxPassenger;
	int retorno = -1;

	if (list != NULL)
		{
			if (len >= 0)
			{
				if (order == 1)
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if (strcmp(list[i].lastName, list[j].lastName) > 0)
							{
								auxPassenger = list[j];
								list[j] = list[i];
								list[i] = auxPassenger;
							}
							if(strcmp(list[i].lastName, list[j].lastName) == 0)
							{
								if(list[i].typePassenger > list[j].typePassenger)
								{
									auxPassenger = list[j];
									list[j] = list[i];
									list[i] = auxPassenger;
								}
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if (strcmp(list[i].lastName, list[j].lastName) < 0)
							{
								auxPassenger = list[j];
								list[j] = list[i];
								list[i] = auxPassenger;
							}
							if(strcmp(list[i].lastName, list[j].lastName) == 0)
							{
								if(list[i].typePassenger > list[j].typePassenger)
								{
									auxPassenger = list[j];
									list[j] = list[i];
									list[i] = auxPassenger;
								}
							}
						}
					}
				}
				retorno = 0;
			}
		}

	return retorno;
};
