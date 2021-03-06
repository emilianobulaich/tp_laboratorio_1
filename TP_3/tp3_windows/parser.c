#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* pEmpleado;

	char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];

	if(pFile != NULL &&  pArrayListEmployee!= NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		while(!feof(pFile)){

			fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, horasTrabajadas, sueldo);
			printf("%s - %s - %s - %s\n", id, nombre, horasTrabajadas, sueldo);
			pEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			if(pEmpleado != NULL){
				if(ll_add(pArrayListEmployee, pEmpleado) == -1){
					puts("Error");

				}else{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* pEmpleado;

	if(pFile != NULL && pArrayListEmployee){
		 while(!feof(pFile)){
			 pEmpleado = employee_new();
			 if(pEmpleado != NULL){
				 fread(pEmpleado,sizeof(Employee),1,pFile);
				 if(!feof(pFile)){
					if(ll_add(pArrayListEmployee,pEmpleado) != -1){
						retorno = 0;
					}
				 }
			 }

		 }
	}

    return retorno;
}
int parserLastIdFromText(FILE* pFile){
	int retorno = -1;
	char Id[128];

	if(pFile != NULL){
		while(!feof(pFile)){
			fscanf(pFile, "%[^\n]\n", Id);
			retorno = atoi(Id);
		}
	}

	return retorno;
}
