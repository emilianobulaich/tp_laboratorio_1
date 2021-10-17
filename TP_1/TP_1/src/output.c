#include "output.h"
#include "Operaciones.h"
#include <stdio.h>
void MostrarMenu (void){
	   printf("---------------> MENU <---------------");
	    printf("\n**************************************\n");
		printf("          Elija una opcion: \n");
		printf("**************************************\n");
		printf("|  1. Ingrese el primer operando     |\n");
		printf("|  2. Ingrese el primer operando     |\n");
		printf("|  3. Calcular todas las operaciones |\n");
		printf("|  4. Informar resultados            |\n");
		printf("|  5. Salir                          |\n");
		printf("**************************************\n");
}

void Opcion (void){
	printf("\nOpcion: ");
}
void TercerCase (float numero, float numero2, int flag1, int flag2){
	if(flag1 == 1 && flag2 == 1 ){
	printf("Calcular la suma (%.2f + %.2f)\n",numero,numero2);
	printf("Calcular la resta (%.2f - %.2f)\n",numero,numero2);
	printf("Calcular la multiplicacion (%.2f * %.2f)\n",numero,numero2);
	printf("Calcular la division (%.2f /% .2f)\n",numero,numero2);
	printf("Calcular el factorial de: %.2f:\n",numero);
	printf("Calcular el factorial de: %.2f:\n",numero2);
	Opcion();

	}

	else {
		if((flag1 == 0 && flag2 == 0) || (numero  == 0 && numero2 == 0))  {
			printf("Faltan ambos datos para hacer las operaciones, por favor ingresar opcion 1 y luego la 2 para ingreasarlos");
			Opcion();

		}
		else{
			printf("Falta un dato, por favor ingresar la opcion faltante para ingresarlo");
			Opcion();
		}
	}
}
void CuartoCase(float numero, float numero2, int flag1, int flag2){

	    float suma;
	    float resta;
	    float multiplicacion;
	    float division;
	    float factorial;
	    float factorial2;

	    if(flag1 == 1 && flag2 == 1 ){
		suma = Suma(numero, numero2);
		resta = Resta(numero, numero2);
		multiplicacion = Multiplicacion(numero,numero2);

		printf("El resultado de %.2f + %.2f es: %.2f\n",numero,numero2,suma);
		printf("El resultado de %.2f - %.2f es: %.2f\n",numero,numero2,resta);
		printf("El resultado de %.2f * %.2f es: %.2f\n",numero,numero2,multiplicacion);


		  if(numero2 == 0){
				printf("No se puede dividor por 0\n");

			}
			else{
				division = Division(numero,numero2);
				printf("El resultado de %.2f / %.2f es: %.2f\n",numero,numero2,division);
			}

			if(numero <0){
				printf("No se puede calcular el factorial de %.2f, porque es un numero negativo\n",numero);
			}
			else{
				factorial = Factorial(numero);
				printf("El factorial de: %.2f es: %.2f\n",numero,factorial);
			}
			if(numero2 <0){
				printf("No se puede calcular el factorial de %.2f, porque es un numero negativo\n",numero2);

			}
			else{
				factorial2 = Factorial(numero2);
				printf("El factorial de: %.2f es: %.2f\n",numero2,factorial2);
			}

			Opcion();

		}
		else {

			if(flag1 == 0 && flag2 == 0){
				printf("Faltan ambos datos para hacer las operaciones, por favor ingresar opcion 1 y luego la 2 para ingreasarlos");
				Opcion();
			}
			else{
				printf("Falta un dato, por favor ingresar la opcion faltante para ingresarlo");
				Opcion();
			}
		}

}
void QuintoCase(void){
	printf("Ha salido del programa con �xito, Vuelva pronto!");
}

