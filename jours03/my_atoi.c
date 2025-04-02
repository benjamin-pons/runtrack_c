#include <stdio.h>
#include <stdlib.h>

int my_atoi(char *str) {
    int nombre = atoi(str); 
    return nombre;       
}

int main() {
    char str[] = "123";
    int valeur = my_atoi(str); 

    printf("Nombre : %d\n", valeur);
    return 0;
}
