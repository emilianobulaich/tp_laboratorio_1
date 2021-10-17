#ifndef INPUT_H_
#define INPUT_H_


/// \brief Pide una cadena a traves de un mensaje y si no contiene numeros lo devuelve por parametro
/// \param mensaje[] char
/// \param mensajeError[] char
/// \param cadena[] char
/// \param tam int
/// \return int Return (-1) si la cadena contiene numero/s  - (0) si esta Ok
int ObtenerString(char mensaje[],char mensajeError[], char cadena[], int tam);

/// \brief Verifica que la cadena no posea numeros
/// \param cadena char*
/// \return int Return (-1) si hay la cadena tiene letras o signos, excepto el "-" - (0) si esta Ok

int LaCadenaEsString(char* cadena);

/// \brief Pide un numero a traves de un mensaje y si es entero lo devuelve por parametro
/// \param pResultado int*
/// \param mensaje[] char
/// \return int Return (-1) si el numero no es entero  - (0) si esta Ok
int ObtenerEntero(int* pResultado, char mensaje[]);

/// \brief Castea la cadena de char a int
/// \param pResultado int*
/// \return int Return (-1) si la cadena no pudo castearse con exito  - (0) si esta Ok
int CastearAEntero(int* pResultado);

/// \brief Verifica que la cadena posea solo numeros
/// \param cadena char*
/// \return int Return (-1) si hay la cadena tiene letras o signos, excepto el "-" - (0) si esta Ok
int LaCadenaEsNumerica(char* cadena);

/// \brief Pide un numero a traves de un mensaje y si es float lo devuelve por parametro
/// \param pResultado float*
/// \param mensaje[] char
/// \return int Return (-1) si el numero no es flotante  - (0) si esta Ok
float ObtenerFlotante(float* pResultado, char mensaje[]);

/// \brief Castea la cadena de char a float
/// \param pResultado float*
/// \return int Return (-1) si la cadena no pudo castearse con exito  - (0) si esta Ok
int CastearAFlotante (float* pResultado);


/// \brief Verifica que la cadena posea solo numeros y puedan ser flotantes
/// \param cadena char*
/// \return int Return (-1) si hay la cadena tiene letras o signos, excepto el "-" - (0) si esta Ok
int LaCadenaEsFlotante(char* cadena);



#endif /* INPUT_H_ */