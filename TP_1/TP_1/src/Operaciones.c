#include "Operaciones.h"

float Suma(float numero, float numero2){
    float resultado;

    resultado = (numero) + (numero2);

	return resultado;
}
float Resta(float numero, float numero2){
	float resultado;

    resultado = (numero) - (numero2);

	return resultado;
}
float Multiplicacion(float numero, float numero2){
	float resultado;

    resultado = numero * numero2;

	return resultado;
}
float Division(float numero, float numero2){
	float resultado;

    resultado = numero / numero2;

	return resultado;
}
float Factorial(float numero){
	float resultado;

	if(numero == 0){
		resultado = 1;
	}
	else{
		resultado = numero * Factorial(numero - 1);
	}
	return resultado;
}
