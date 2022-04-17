/*
 * Funciones.h
 *
 *  Created on: 16 abr. 2022
 *      Author: lucas
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/* \brief abre un submenu para ingresar los precios de las aerolineas
 * \param pAerolineas : puntero a Price_Aerolineas
 * \param pLatam : puntero a price_latam
 * \return retorna 1 si ingreso datos
 * */
int subPrecio(float* pAerolineas,float* pLatam);
/* \brief Llama a las funciones que calculan los costos
 * \param precio : puntero al precio de la aerolinea
 * \param km valor de kilometers
 * \param pDebito: puntero a debito
 * \param pCredito: puntero a credito
 * \param pDebito: puntero a debito
 * \param pCrypto: puntero a cripto
 * \param pUnitari: puntero a precio unitario
 * \return retorna 1 si calculo gastos , 0 si no lo hizo
 * */
int calcularCostos(float precio,float km,float* pDebito,float* pCredito,float* pCrypto,float* pUnitario);
/*\brief Mostrar calculos resueltos
 * \param *compania : puntero a empresa de vuelvo
 * \param precio : valor del vuelo
 * \param debito : valor de debito
 * \param credito : valor de credito
 * \param crypto : valor de cripto
 * \param unitario : valor del precio unitario
 * */
void mostrarDatos(char* compania,float precio,float debito,float credito,float crypto,float unitario);


#endif /* FUNCIONES_H_ */
