#include <unistd.h>
#include <stdlib.h>

char *str_to_lower(const char *str) {
    if (str == NULL) return NULL;
    
    int i = 0;
    while (str[i]) i++; // Calcul de la longueur
    
    char *lower = malloc(i + 1);
    if (lower == NULL) return NULL;
    
    for (int j = 0; j < i; j++) {
        lower[j] = (str[j] >= 'A' && str[j] <= 'Z') ? str[j] + ('a' - 'A') : str[j];
    }
    lower[i] = '\0';
    
    return lower;
}

void print_str(const char *str) {
    if (str) {
        int len = 0;
        while (str[len]) len++;
        write(1, str, len);
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        char *lower = str_to_lower(argv[i]);
        if (lower) {
            print_str(lower);
            free(lower);
        }
    }
    return 0;
}
