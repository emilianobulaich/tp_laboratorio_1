#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main(){
		setbuf(stdout,NULL);

        LinkedList* listaEmpleados = ll_newLinkedList();

        int option;
        int opcionArchivo;

        int flagArchivo = 0;

        do
        {
            Menu();

            ObtenerEnteroEntreRango(&option,"\nOpcion: ",1,10,3);

            switch(option)
            {
            case 1:

                if(flagArchivo== 0){
                    if(controller_loadFromText("data.csv",listaEmpleados) == 0){
                        printf("\nArchivo cargado exitosamente.\n\n");
                    }
                    else{
                        printf("\nEl archivo no ha podido ser cargado.\n\n");
                    }
                    flagArchivo=1;
                }
                else
				   {
					ObtenerEnteroEntreRango(&opcionArchivo,"Ya hay un archivo cargado ?Desea abrir este, y cerrar el otro? 1-Si 2-No.",1,2,3);
					if(opcionArchivo == 1){
						ll_clear(listaEmpleados);
						if(controller_loadFromText("data.csv",listaEmpleados) == 0){
							printf("\nArchivo cargado exitosamente.\n\n");
						}
						else{
							printf("\nEl archivo no ha podido ser cargado.\n\n");
						}
					}
				   }
                break;

           case 2:

                if(flagArchivo == 0){

                    if(controller_loadFromBinary("data.bin",listaEmpleados) == 0){
                        printf("\nArchivo cargado exitosamente.\n\n");
                    }
                    else{
                        printf("\nEl archivo no ha podido ser cargado.\n\n");
                    }
                    flagArchivo =1;
                }
                else
                {
                    ObtenerEnteroEntreRango(&opcionArchivo,"Ya hay un archivo cargado ?Desea abrir este, y cerrar el otro? 1-Si 2-No.",1,2,3);
                    if(opcionArchivo == 1){
                    	ll_clear(listaEmpleados);
                    	if(controller_loadFromBinary("data.bin",listaEmpleados) == 0){
							printf("\nArchivo cargado exitosamente.\n\n");
						}
						else{
							printf("\nEl archivo no ha podido ser cargado.\n\n");
						}
                    }
                }

                break;

            case 3:
            	if(flagArchivo== 1){
            		if(controller_addEmployee(listaEmpleados) == 0){
						printf("\nEmpleado cargado exitosamente.\n\n");
					}
					else{
						printf("\nNo se pudo cargar el empleado.\n\n");
					}
            	}else{
            		printf("\nAntes de a?adir un empleado, necesita cargar un archivo \n\n");
            	}

                break;

            case 4:
            	if(flagArchivo== 1){
					if(controller_editEmployee(listaEmpleados) == 0){
						printf("\nEmpleado modificado exitosamente.\n\n");
					}
					else{
						printf("\nNo se pudo modificar el empleado.\n\n");
					}
            	}else{
            		printf("\nAntes de editar un empleado, necesita cargar un archivo \n\n");
            	}
                break;

            case 5:
            	if(flagArchivo== 1){
					if(controller_removeEmployee(listaEmpleados) == 0){
						  printf("\nEmpleado eliminado exitosamente.\n\n");
					}

					else{
						 printf("\nNo se pudo eliminar el empleado.\n\n");
					}
            	}else{
					printf("\nAntes de eliminar un empleado, necesita abrir un archivo (opcion 1 o 2)\n\n");
				}
                break;

            case 6:
                if(controller_ListEmployee(listaEmpleados) != 0){
                	 printf("\nNo existe ninguna lista.\n\n");
                }
                break;

            case 7:

                if(controller_sortEmployee(listaEmpleados) == 0){
                    printf("\nLista ordenada exitosamente.\n\n");
                }
                else{
                    printf("\nNo se pudo ordenar la lista.\n\n");
                }
                break;

            case 8:

                if(controller_saveAsText("data.csv",listaEmpleados) == 0){
                    printf("\nArchivo guardado exitosamente.\n\n");
                }
                else{
                    printf("\nNo se pudo guardar el archivo.\n\n");
                }
                break;

            case 9:
                if(controller_saveAsBinary("data.bin",listaEmpleados) == 0){
                    printf("\nArchivo guardado exitosamente.\n\n");
                }
                else{
                    printf("\nNo se pudo guardar el archivo.\n\n");
                }
                break;

            case 10:

                printf("\nSaliendo...\n\n");
                break;

            default:
                printf("Error. Usted eligio una opcion invalida.\n");
            }

        }
        while(option != 10);

   return 0;
}


