#include "input.h"
#include "output.h"
#include "Operaciones.h"

float IngresarFlotante(char mensaje[])
{
	float numeroIngresado;

	printf(mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}

int OpcionElegida (int minimo, int maximo){

	int opcion;
	int opcionValidada;

    do{
	scanf("%d",&opcion);

	opcionValidada = ValidarOpcion(opcion,minimo,maximo);

    }while(opcionValidada == 0);

    return opcion;
}
int ValidarOpcion (int respuesta, int minimo, int maximo){
	int retorno;

	if(respuesta < minimo || respuesta > maximo){
        printf("ERROR: opcion fuera de rango, ingrese opcion correcta\n");
        Opcion();
		retorno = 0;
	}
	else{
		retorno = 1;
	}
	return retorno;

}

void RealizarOperacion(int minimo, int maximo, char mensaje[],char mensaje2[]){
	int opcionIngresada;

    int flagOpcion1;
    int flagOpcion2;

    flagOpcion1 = 0;
    flagOpcion2 = 0;
    float numero;
    float numero2;


	do{
	opcionIngresada =  OpcionElegida(minimo, maximo);

		switch(opcionIngresada){

			case 1:
				numero = IngresarFlotante(mensaje);
				flagOpcion1 = 1;
				Opcion();
				break;
			case 2:
				numero2 = IngresarFlotante(mensaje2);
				flagOpcion2 = 1;
				Opcion();
				break;
			case 3:
			    TercerCase(numero,numero2,flagOpcion1,flagOpcion2);

				break;
			case 4:
				CuartoCase(numero,numero2,flagOpcion1,flagOpcion2);

				break;
			case 5:
				QuintoCase();
				break;
		}
	}while(opcionIngresada != 5);

}







