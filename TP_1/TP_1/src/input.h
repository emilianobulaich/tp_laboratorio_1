/*

 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>

/// \fn IngresarFlotante()
/// \brief la funcion sirve para ingresar un flotante
/// \param mensaje que se imprime en consola
/// \return retorna el flotante ingresado
float IngresarFlotante(char mensaje[]);

/// \fn OpcionElegida()
/// \brief la funcion sirve para pedir al usuario una opcion
/// \param opcion minima, opcion maxima
/// \return retorna la opcion elegida
int OpcionElegida(int minimo, int maximo);

/// \fn ValidarOpcion()
/// \brief la funcion sirve para validar la opcion ingresada por el usuario
/// \param la opcion elegida, opcion minima, opcion maxima
/// \return retorna 0 si la opcion no fue validada, retorna 1 si fue validada
int ValidarOpcion (int opcion, int minimo, int maximo);

/// \fn RealizarOperacion()
/// \brief la funcion sirve realizar las operaciones mostradas en el menu
/// \param primer numero, segundo numero, opcion minima, opcion maxima
/// \return NO retorna nada, es un void
void RealizarOperacion(int minimo, int maximo, char mensaje[],char mensaje2[]);


#endif /* INPUT_H_ */
