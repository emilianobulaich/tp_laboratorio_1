#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Input.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
       if(path!= NULL && pArrayListEmployee != NULL){

    	pArchivo = fopen(path,"r");

       	if(pArchivo!=NULL && parser_EmployeeFromText(pArchivo,pArrayListEmployee) == 0){
       		retorno = 0;
       	}
       fclose(pArchivo);


       }
       return retorno;

}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pArchivo;
	if(path != NULL && pArrayListEmployee  != NULL){
		pArchivo = fopen(path,"rb");
        if(pArchivo != NULL && parser_EmployeeFromBinary(pArchivo,pArrayListEmployee) == 0){
        	retorno = 0;
        }
        fclose(pArchivo);
	}
    return retorno;
}


int controller_LastIdSaved(char* path){

	 int retorno = -1;
	 FILE* pArchivo;
	 pArchivo = fopen(path,"r");
		if(path!= NULL){
		if(pArchivo != NULL ){

				 retorno = parserLastIdFromText(pArchivo);

			 }
		}


     fclose(pArchivo);
	 return retorno;

}
int controller_LoadNextId(LinkedList* pArrayListEmployee){
    Employee* pEmpleadoAux;

    int id = -1;
    int idController;
    int aux;
    int len;
    int flag = 1;

    if(pArrayListEmployee != NULL){
        len = ll_len(pArrayListEmployee);
        if(len > 0){
            for(int i = 0; i<len; i++){
            	pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
            	if(pEmpleadoAux!= NULL){
            		employee_getId(pEmpleadoAux,&aux);

					if(aux > id || flag == 1){
						flag = 0;
						id = aux;
					}
            	}

            }
        }

    }
    idController =  controller_LastIdSaved("dataId.csv");
    if(id < idController){
    	id = idController;
    }
    return id;
}

int controller_saveLastIdAsText(char* path, int id){
	int retorno = -1;
	FILE* pFile;


	   if(path != NULL){

	        pFile = fopen(path,"w");

			fprintf(pFile,"%d\n",id);

	    	fclose(pFile);
	    	retorno = 0;

	    }
	return retorno;
}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){

    int retorno = -1;
	int id;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;


	Employee* pEmpleado;

	pEmpleado = employee_new();

	id = controller_LoadNextId(pArrayListEmployee);
	ObtenerString("Ingrese el nombre", nombre, sizeof(nombre),3);
	ObtenerEnteroMayorACero(&sueldo,"Ingrese el sueldo",3);
	ObtenerEnteroMayorACero(&horasTrabajadas,"Ingrese las horas trabajadas",3);

	if(pEmpleado != NULL){
		 id++;
		 employee_setId(pEmpleado,id);
		 employee_setNombre(pEmpleado,nombre);
		 employee_setHorasTrabajadas(pEmpleado,horasTrabajadas);
		 employee_setSueldo(pEmpleado,sueldo);
		 retorno = 0;
		 ll_add(pArrayListEmployee, pEmpleado);
		 controller_saveLastIdAsText("dataId.csv",id);
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){
	int retorno = -1;
	int id;
	int auxId;
	int opcion;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;

    Employee* pEmpleado;
	if(pArrayListEmployee !=NULL){
		ObtenerEntero(&id, "?Que empleado desea modificar? Ingresar ID: ",3);

		 for(int i = 0; i< ll_len(pArrayListEmployee); i++){

			 	pEmpleado = ll_get(pArrayListEmployee,i);
				employee_getId(pEmpleado, &auxId);
				if(auxId == id){

					printf("\n\n OPCIONES:");
					printf("\n 1- Modificar nombre.");
					printf("\n 2- Modificar sueldo.");
					printf("\n 3- Modificar horas trabajadas.");
					printf("\n 4- Salir.");
					printf("\n\n Opcion:");
					scanf("%d",&opcion);
					switch(opcion){
						case 1:
							 if(ObtenerString("Ingrese un nuevo nombre: ",nombre,sizeof(nombre),3) == 0){
								 employee_setNombre(pEmpleado, nombre);
								 retorno = 0;
							 }
							 break;
						case 2:
							if(ObtenerEnteroMayorACero(&sueldo,"Ingrese el nuevo sueldo: ",3) == 0){
								employee_setSueldo(pEmpleado,sueldo);
								retorno = 0;
							 }
							break;

						case 3:
							if(ObtenerEnteroMayorACero(&horasTrabajadas,"Ingrese las nuevas horas trabajadas",3) == 0){;
							employee_setHorasTrabajadas(pEmpleado,horasTrabajadas);
							retorno = 0;
							}
							break;
						case 4:
							printf("\nSaliendo...\n");
							break;
						default:
				           printf("Opcion inv?lida.");

					}


				}
		 }


	}
	 return retorno;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int id;
	int auxId;
	int opcion;

	Employee* pEmpleado;
		if(pArrayListEmployee !=NULL){
			ObtenerEntero(&id, "?Que empleado desea eliminar? Ingresar ID: ",3);

			 for(int i = 0; i< ll_len(pArrayListEmployee); i++){

				 	pEmpleado = ll_get(pArrayListEmployee,i);
					employee_getId(pEmpleado, &auxId);
					 if(auxId == id){
						printf("\n\n Est? seguro de que desea eliminar el empleado?");
						printf("\n 1-Si.");
						printf("\n 2-NO.");
						scanf("%d",&opcion);

							switch(opcion){
							case 1:

								ll_remove(pArrayListEmployee,i);
								retorno = 0;
								break;

							case 2:
								printf("\nSaliendo...\n");
								break;

							default:
								printf("\nOpcion invalida.\n");
								break;
							}
					  }

		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

		int retorno = -1;
	    Employee* pEmpleado;

	    int id;
	    int sueldo;
	    int horasTrabajadas;

	    char nombre[128];

	    if(pArrayListEmployee != NULL)
	    {
	        printf("\n\nID\t NOMBRE \t SUELDO \tHORAS \n\n");
	        retorno = 0;

	        for( int i=0; i < ll_len(pArrayListEmployee); i++)
	        {
	            pEmpleado = ll_get(pArrayListEmployee,i);
	            employee_getNombre(pEmpleado, nombre);
	            employee_getId(pEmpleado,&id);
	            employee_getSueldo(pEmpleado,&sueldo);
	            employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
	            printf("%d  %10s  %15d  %10d \n\n", id, nombre, sueldo, horasTrabajadas);
	        }
	    }
	    return retorno;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
   int retorno = -1;
   int opcion;

   if(pArrayListEmployee != NULL){


	   printf("Elija el criterio de ordenamiento:\n ");
	   printf("1 - Ordenar por ID\n");
	   printf("2 - Ordenar por nombre\n");
	   printf("3 - Ordenar por sueldo\n");
	   printf("4 - Ordenar por horas trabajadas\n");
	   ObtenerEnteroEntreRango(&opcion,"Opcion: ",1,4,3);
	   switch(opcion){
		   case 1:
			   if(ll_sort(pArrayListEmployee,employee_orderById,1) == 0){
				   retorno = 0;
			   }

			   break;
		   case 2:
			   if(ll_sort(pArrayListEmployee,employee_orderByName,1) == 0){
				   retorno = 0;
			   }

			   break;
		   case 3:
			   if(ll_sort(pArrayListEmployee,employee_orderBySalary,1) == 0){
				   retorno = 0;
			   }

			   break;
		   case 4:
			   if(ll_sort(pArrayListEmployee,employee_orderByHours,1) == 0){
				   retorno = 0;
			   }

			   break;
	   }
   }
	return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee){
	    FILE* pArchivo;
	    Employee* empleado;


	    int retorno = -1;
	    int id;
	    int i;
	    char nombre[128];
	    int sueldo;
	    int horas;

	    if(path != NULL && pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0){

	    	pArchivo = fopen(path, "w");

	        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

	        for(i=0; i< ll_len(pArrayListEmployee); i++) {
	        	empleado = ll_get(pArrayListEmployee,i);
	        	if(empleado == NULL){
	        		break;
	        	}

	            employee_getId(empleado,&id);
	            employee_getNombre(empleado, nombre);
	            employee_getSueldo(empleado,&sueldo);
	            employee_getHorasTrabajadas(empleado,&horas);
	            fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,sueldo,horas);
	        }

	        fclose(pArchivo);
	        if(ll_len(pArrayListEmployee) == i ){
	        	retorno = 0;
	        }
	    }
	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmpleado;
	FILE* pArchivo;
	int i;
	if(path != NULL &&  pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0){
		pArchivo = fopen(path,"wb");
       if(pArchivo != NULL){
    	   for(i = 0; i < ll_len(pArrayListEmployee); i++){
    		   pEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
    		   if(pEmpleado == NULL){
    			   break;
    		   }
    		   fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
    	   }
       }
       fclose(pArchivo);
       if(ll_len(pArrayListEmployee) == i){
    	   retorno = 0;
       }

	}
	retorno = 0;
    return retorno;
}

