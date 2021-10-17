#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "ArrayEmployees.h"
#define TRUE 0
#define FALSE 1

int initEmployees(Employee* list, int len){
    setbuf(stdout,NULL);
    int retorno;
    retorno = -1;
	int i;
	if(list != NULL && len >= 0){

		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    setbuf(stdout,NULL);
	int retorno;
	retorno = -1;

	int i;
	for(i = 0; i < len; i++ ){
		if(list != NULL && len >= 0 && list[i].isEmpty == TRUE)
		{
		    list[i].id = id;
		    strcpy(list[i].name, name);
		    strcpy(list[i].lastName, lastName);
		    list[i].salary = salary;
		    list[i].sector = sector;
		    list[i].isEmpty= FALSE;
		    retorno = 0;
		    break;
		}

	}
	return retorno;
}

int findEmployeeById(Employee* list, int len,int id){
	int retorno = -1;

		for (int i = 0; i < len; ++i) {

				 if(list[i].id == id){

					 retorno = i;

				}
		 }

    return retorno;
}

int modifyEmployee( Employee* list, int len, int id){

	int ModificarMenu;
    int retorno;
     retorno = findEmployeeById(list,len,id);

	if(retorno != -1 ){
         printf("Que quiere modificar \n 1-Nombre \n 2- Apellido \n 3- Salario \n 4- Sector");
		 scanf ("%d",&ModificarMenu);

		 switch (ModificarMenu) {
			case 1:
				printf("Ingrese el nombre nuevo");
				fflush(stdin);
				fgets(list[retorno].name,sizeof(list[retorno].name),stdin);
				puts(list[retorno].name);

				break;
			case 2:
				printf("Ingrese el Apellido nuevo");
				fflush(stdin);
				fgets(list[retorno].lastName,sizeof(list[retorno].lastName),stdin);
				puts(list[retorno].lastName);
				break;

			case 3:
				printf("Ingrese el Salario nuevo");
				scanf("%f",&list[retorno].salary);
				printf("el nuevo salario es %f",list[retorno].salary);
				 break;
			case 4:
				printf("Ingrese el Sector nuevo");
				scanf("%d",&list[retorno].sector);
				printf("el nuevo sector es %d",list[retorno].sector);
				break;
		 }
	}
	return retorno;
}
int removeEmployee(Employee* list, int len, int id){

	int retorno = -1;

	retorno = findEmployeeById(list,len,id);
	if(retorno != -1 && list != NULL && len >= 0 && list[retorno].id == id && list[retorno].isEmpty == FALSE){

        list[retorno].isEmpty = TRUE;

	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order){

	int retorno = -1;

	if(list != NULL && len >= 0 && (order == 0 || order == 1)){
		retorno = 0;



				Employee auxiliarProducto;
				for(int i=0; i<len-1; i++)
				{
					for(int j=i+1; j<len; j++)
					{
						if(order == 1){
							//a b c d e ....

							if(strncmp(list[i].lastName, list[j].lastName,sizeof(list[i].lastName)) == 0)
							{
								if(list[i].sector > list[j].sector){
									auxiliarProducto = list[i];
									list[i] = list[j];
									list[j] = auxiliarProducto;
								}


							}else if(strncmp(list[i].lastName, list[j].lastName,sizeof(list[i].lastName)) > 0){
								auxiliarProducto = list[i];
								list[i] = list[j];
								list[j] = auxiliarProducto;
							}


						}
						else{
							//z y x w....
							if(strncmp(list[i].lastName, list[j].lastName,sizeof(list[i].lastName)) == 0)
							{
								if(list[i].sector < list[j].sector){
									auxiliarProducto = list[i];
									list[i] = list[j];
									list[j] = auxiliarProducto;
								}


							}
							else if(strncmp(list[i].lastName, list[j].lastName,sizeof(list[i].lastName)) < 0){
									auxiliarProducto = list[i];
									list[i] = list[j];
									list[j] = auxiliarProducto;
								}
						}
					}
				}
		}
	return retorno;
}
int printEmployees(Employee* list, int len){
	int retorno = -1;

	setbuf(stdout, NULL);
	if(list != NULL && len >= 0){
			retorno = 0;
			puts("|ID|         NOMBRE        |         APELLIDO          |     SALARIO    |    SECTOR   |");
			int i;
			for (i = 0; i < len; ++i) {
				if(list[i].isEmpty==FALSE){

					printf(" %d ",list[i].id);
					printf(" %15s ",list[i].name);
					printf("%25s ",list[i].lastName);
					printf(" %20.2f ",list[i].salary);
					printf(" %15d \n",list[i].sector);

				}

			}
	}

	return retorno;
}
int Salary(Employee* list, int len){
	int retorno = -1;
	if(list != NULL && len >= 0){

		float acumulador;
		int contador;
		int contadorPromedio;
		float promedio;

		contadorPromedio = 0;
		acumulador = 0;
		contador = 0;


		for(int i = 0; i < len ; i++){
			if(list[i].isEmpty == FALSE){
				contador++;
				acumulador = acumulador + list[i].salary;
			}

		}
		promedio = acumulador/contador;
		for(int i = 0; i < len; i ++){
			if(list[i].salary > promedio && list[i].isEmpty == FALSE){
				contadorPromedio++;
			}
		}

		printf("El total del salario es: %f\n",acumulador);
		printf("Y el promedio de los salarios es: %f\n",promedio);
		printf("La cantidad de salarios superiores al promedio es de: %d \n",contadorPromedio);

		retorno = 0;
	}
	return retorno;
}



