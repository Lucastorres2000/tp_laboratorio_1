/*
 * calculos.h
 *
 *  Created on: 16 abr. 2022
 *      Author: lucas
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
/*\brief realiza calculos para hacer el descuento
 *\param precio : precio a aplicar descuento
 * \param descuent : descuento a realizar
 * \return retorna el valor con el descuento
 * */
float getDescuento(float precio , float descuento);

/*\brief realiza calculos para hacer la sumatoria del credito
 *\param precio : precio a aplicar interes
 * \param interes: tasa de interes a aplicar
 * \return retorna el valor con el el interes
 * */
float getCredito(float precio,float interes);

/*\brief realiza calculos para hacer la conversion a criptomoneda
 *\param capital : total para hacer la conversion
 * \param moneda : criptomoneda
 * \return retorna el valor convertido a criptomoneda
 * */
float getCrypto(float capital, float moneda);

/*\brief realiza calculos para hacer el precio unitario
 *\param precio : precio total
 * \param cantidad : valor para dividir
 * \return retorna el valor por unidad
 * */
float getPrecioUnitario(float precio, float cantidad);


#endif /* CALCULOS_H_ */
