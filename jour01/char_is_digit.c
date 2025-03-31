#include <stdio.h>  // Pour utiliser printf (si autorisé pour les tests)

int char_is_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int str_is_digit(const char *str) {
    while (*str) {
        if (char_is_digit(*str) == 0) {
            return 0;
        }
        str++;
    }
    return 1;
}

int main() {
    // Test char_is_digit
    char c = '5';
    if (char_is_digit(c)) {
        printf("'%c' est un chiffre.\n", c);
    } else {
        printf("'%c' n'est pas un chiffre.\n", c);
    }

    // Test str_is_digit
    const char *str = "12345";
    if (str_is_digit(str)) {
        printf("La chaîne '%s' ne contient que des chiffres.\n", str);
    } else {
        printf("La chaîne '%s' ne contient pas que des chiffres.\n", str);
    }

    return 0;
}
