#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void proceso_hijo_uno();//funcion que sera el programa numero_impar
void proceso_hijo_dos();//funcion que sera el programa numero_par


int main() {

    pid_t pid1, pid2;
    int status1, status2;

    if((pid1=fork()) == 0 ){

        printf("El primer proceso hijo (impares) se esta ejecutando\n");
        proceso_hijo_uno();
        printf("El primer proceso hijo a finalizo con exito \n");
        //sleep(10);

    }

    else {
    
        waitpid(pid1, &status1, 0);// espera a que finalice el proceso hijo 1
        printf("El proceso padre continua\n");
        if((pid2=fork())== 0 ){

            printf("El segundo proceso hijo (pares) se esta ejecutando\n");
            proceso_hijo_dos();
            printf("El segundo proceso hijo ha finalizado con exito\n");
        }

        else {
           // waitpid(pid1, &status1, 0);// espera a que finalice el proceso hijo 1
            waitpid(pid2, &status2, 0);//espera a que finalice el proceso hijo 2
            printf("El proceso padre ha finalizado con exito\n");
        }
    }

    return 0;
}

void proceso_hijo_uno(){

    int numero;

        printf("Introduzca un numero:\n");
        scanf("%d", &numero);

    if (numero%2!=0){

        printf("Número impar: %d\n", numero );

    }

    else{
        printf("El numero introducido no es impar\n");
    }
}

void proceso_hijo_dos(){

    int numero_par;

    printf("Introduzca un numero:\n");
    scanf("%d", &numero_par);

    if (numero_par%2==0){

        printf("Número par: %d\n", numero_par );

    }

    else{
        printf("El numero introducido no es par\n");
    }
}
