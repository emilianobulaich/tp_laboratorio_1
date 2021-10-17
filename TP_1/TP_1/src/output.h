#ifndef OUTPUT_H_
#define OUTPUT_H_

/// \fn MostrarMenu()
/// \brief la funcion sirve para mostrar el menu al usuario
/// \param NO tiene, es void
/// \return NO retorna nada, es un void
void MostrarMenu (void);


/// \fn Opcion()
/// \brief la funcion muestra "Opcion: " con un printf
/// \param NO tiene, es void
/// \return NO retorna nada, es un void
void Opcion(void);

/// \fn TercerCase()
/// \brief La funcion sirve para mostrar al usuario las operaciones que se realizarán al presionar la opcion 4
/// \param primer numero, segundo numero, bandera del primer numero, bandera del segundo numero
/// \return NO retorna nada, es un void
void TercerCase (float numero, float numero2, int flag1, int flag2);

/// \fn CuartoCase()
/// \brief La funcion sirve para mostrar al usuario las operaciones realizadas
/// \param primer numero, segundo numero, bandera del primer numero, bandera del segundo numero
/// \return NO retorna nada, es un void
void CuartoCase(float numero, float numero2, int flag1, int flag2);

/// \fn QuintoCase()
/// \brief La funcion sirve para mostrar al usuario un mensaje de despedida
/// \param NO tiene, es void
/// \return NO retorna nada, es un void
void QuintoCase(void);
#endif /* OUTPUT_H_ */
