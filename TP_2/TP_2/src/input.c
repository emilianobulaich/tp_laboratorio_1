#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>



int ObtenerString(char mensaje[],char mensajeError[], char cadena[], int tam) {

    int retorno = 0;
    char auxiliarString[500];

        if (cadena != NULL && mensaje != NULL){


        	puts(mensaje);
			fflush(stdin);
			scanf("%s",auxiliarString);

			if(LaCadenaEsString(auxiliarString) == -1){

					puts(mensajeError);
					retorno = -1;

			}

        }
        strncpy(cadena,auxiliarString,tam);

    return retorno;

}
int LaCadenaEsString(char* cadena){
	int retorno = 0;

	for(int i=0; cadena[i]!='\0';i++){

		if(cadena[i]<='9' && cadena[i]>='0'){
			retorno = -1;
			break;
		}
	}

	return retorno;
}
int ObtenerEntero(int* pResultado, char mensaje[]){
	int retorno = -1;
	int auxiliarInt;
	int respuesta;

	if(pResultado!=NULL && mensaje!=NULL){
		do{
			printf("%s",mensaje);

			respuesta = CastearAEntero(&auxiliarInt);
			if(respuesta==0){
				*pResultado = auxiliarInt;
				retorno = 0;
			}
		}while(respuesta!=0);
	}

	return retorno;
}

int CastearAEntero(int* pResultado){
	int retorno = -1;
	char auxiliarIngresado[1000];

	fflush(stdin);
	scanf("%s",auxiliarIngresado);

	if(LaCadenaEsNumerica(auxiliarIngresado)){
		retorno = 0;
		*pResultado = atoi(auxiliarIngresado);
	}
	return retorno;
}

int LaCadenaEsNumerica(char* cadena){
	int retorno = -1;
	int i=0;

	if(cadena[0]=='-'){
		i=1;
	}

	for(; cadena[i]!='\0';i++){

		if(cadena[i]>'9' || cadena[i]<'0'){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

float ObtenerFlotante(float* pResultado, char mensaje[]){
	int retorno = -1;
	float auxiliarFloat;
	int respuesta;

	if(pResultado != NULL && mensaje != NULL){
		do{
			printf("%s",mensaje);

			respuesta = CastearAFlotante(&auxiliarFloat);
			if(respuesta==0){
				*pResultado = auxiliarFloat;
				retorno = 0;
			}
		}while(respuesta!=0);
	}
	return retorno;
}

int CastearAFlotante (float* pResultado){
	int retorno = -1;
	char auxiliarIngresado[1000];

	fflush(stdin);
	scanf("%s",auxiliarIngresado);

	if(LaCadenaEsFlotante(auxiliarIngresado)){
		retorno = 0;
		*pResultado = atof(auxiliarIngresado);
	}
	return retorno;
}

int LaCadenaEsFlotante(char* cadena){
	int retorno = -1;
	int i=0;

	if(cadena[0]=='-'){
		i=1;
	}

	for(; cadena[i]!='\0';i++){

		if(cadena[i]>'9' || cadena[i]<'0'){
			if(cadena[i]!='.'){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

