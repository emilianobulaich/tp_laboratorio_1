#include "input.h"
#include "output.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

    MostrarMenu();

    Opcion();
	RealizarOperacion(1, 5,"Ingresar primer operando: ","Ingresar segundo operando: ");

	return EXIT_SUCCESS;
}
