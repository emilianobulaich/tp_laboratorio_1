
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "input.h"
#include "output.h"

#define TAM 5
#define TRUE 0
#define FALSE 1
int main(void) {
	setbuf(stdout,NULL);

	int idInicial = 0;
	int idModificar;
	int idEliminar;
	char nombre[21];
	char apellido[21];
	float salario ;
	int sector;
	int opcion;
	int retornoFuncion;


	Employee listaEmpleados[TAM];

	initEmployees(listaEmpleados,TAM);

	do{
			MostrarMenu();
			ObtenerEntero(&opcion,"Ingrese una opcion");


			switch(opcion){
				case 1:
					do{
						retornoFuncion = ObtenerString("Ingrese el nombre del empleado","Error, cargue nuevamente",nombre,21);
						}while(retornoFuncion == -1);
					do{
						retornoFuncion = ObtenerString("Ingrese el apellido del empleado","Error, cargue nuevamente",apellido,21);
						}while(retornoFuncion == -1);

					do{
						 retornoFuncion = ObtenerFlotante(&salario,"Ingresar el salario del empleado");
					}while(retornoFuncion == -1);


					do{
						 retornoFuncion = ObtenerEntero(&sector,"Ingresar el sector del empleado");
					}while(retornoFuncion == -1);
					idInicial++;
					retornoFuncion = addEmployee(listaEmpleados,TAM,idInicial,nombre,apellido,salario,sector);
					if(retornoFuncion != -1){
						puts("El producto se cargo exitosamente\n");
					}else{
						idInicial--;
						puts("El producto no pudo cargarse\n");
					}
				break;
				case 2:
					printf("Ingrese el ID a modificar");
				    scanf("%d",&idModificar);

					retornoFuncion = modifyEmployee(listaEmpleados, TAM,idModificar);

					if(retornoFuncion != -1){
						puts("El producto se modificó exitosamente\n");
					}else{
						puts("El producto no pudo modificarse\n");
					}

				break;
				case 3:
					printf("Ingrese el ID a eliminar");
				    scanf("%d",&idEliminar);
					retornoFuncion=	removeEmployee(listaEmpleados, TAM,idEliminar);

					if(retornoFuncion!=-1)
					{
						printf("El producto se borro exitosamente.\n");
					}
					else
					{
						printf("no se pudo borrar el producto.\n");
					}

					break;

				case 4:



					sortEmployees(listaEmpleados, TAM, FALSE);
					printEmployees(listaEmpleados, TAM);
					Salary(listaEmpleados,TAM);


				break;
				case 5:
					printf("Ha salido con exito!");
					break;
			}

		}while(idInicial < TAM && opcion != 5);


	return EXIT_SUCCESS;
	}

