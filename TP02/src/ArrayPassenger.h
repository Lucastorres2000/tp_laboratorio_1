

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define NLEN 51
#define SUCCESS 0
#define ERROR -1
#define TRUE 1
#define FALSE 0

typedef struct{

	int id;
	char name[NLEN];
	char lastName[NLEN];
	float price;
	char flycode[NLEN];
	int typePassenger;
	int isEmpty;

}Passenger;

#endif
/** \brief	To indicate that all position in the array are empty,
*			this funciont put the flag (isEmpty) in TRUE in all
*			position of the array.
*
*	\param  list Passenger* Pointer to array of passenger.
*   \param 	len int Array lenght.
*
*\return int Return (-1) if Error [Invalide lenght or NULL pointer ].
*
*/
int initPassengers(Passenger* list, int len);


/** \brief 	add in a existing list of passengers the values received as parameters
* 			in the first empty position.
*
*	\param list passenger*
*	\param len int
* 	\param id int
* 	\param name[] char
*	\param lastName[] char
* 	\param price float
* 	\param typePassenger int
* 	\param flycode[] char
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok.
*
*/
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[] );


/** \brief 	find a Passenger by Id en returns the index position in array.
*
* 	\param list Passenger*
* 	\param len int
* 	\param id int
* 	\return Return passenger index position or (-1) if [Invalid length or
*			NULL pointer received or passenger not found].
*
*/
int findPassengerByid(Passenger* list, int len, int id);


/** \brief 	Remove a Passenger by Id (put isEmpty Flag in 1)
*
* 	\param list Passenger*
* 	\param len int
* 	\param id int
* 	\return int Return (-1) if Error [Invalid length or NULL pointer or if can't
*			find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);


/** \brief 	Sort the elements in the array of passengers, the argument order
			indicate UP or DOWN order
*
* 	\param list Passenger*
* 	\param len int
* 	\param order int [1] indicate UP - [0] indicate DOWN
* 	\return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassenger(Passenger* list, int len, int order);


/** \brief 	print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int lenght);


/**	\brief 	Sort the elements in the array of passengers, the argument order
*			indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
*
*/
int sortPassengerByCode(Passenger* list, int len, int order);

/**	\brief 	Sort an element of the passenger array
*
*
* \param list Passenger*
* \param
*
*/
void printOnePassenger(Passenger list);


/**	\brief 	Harcodea el array de pasajeros
*
*
* \param list Passenger*
* \param int len
* \param int* id
*/
int forcedData(Passenger* List,int len,int* id);
int pedirDatos(Passenger* list);
int loadUpPassenger(Passenger* list, int len,int* id);
int findEmptyIndex(Passenger* list, int len);
int modifyPassenger(Passenger* list,int len,int id);
int findPassengerbyId(Passenger* list, int len, int id);
int noData(Passenger* list, int len);
int sortPassengersByLastName(Passenger* list, int len, int order);
