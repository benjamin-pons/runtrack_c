#include <unistd.h> // Inclut la bibliothèque qui permet d'utiliser write()

void my_putchar(char c) { // Définition de la fonction my_putchar
    write(1, &c, 1);  // Écrit 1 caractère sur la sortie standard (écran)
}