#include<stdio.h>

int main (){
	
	int numero_par;

	printf("Introduzca un numero:\n");
	scanf("%d", &numero_par);

	if (numero_par%2==0){

		printf("Número par: %d\n", numero_par );

	}

	else{
		printf("El numero introducido no es par\n");
	}

	return 0;

}
