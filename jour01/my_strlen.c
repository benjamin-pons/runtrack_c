#include <stdio.h>


int my_strlen(const char *str) {
    int length = 0; 


    while (str[length] != '\0') {
        length++; 
    }

    return length; 
}

int main() {
    const char *chaine = "Bonjour, comment ça va ?";  

    int taille = my_strlen(chaine); 

    printf("La taille de la chaîne est : %d\n", taille);
    
    return 0;
}
