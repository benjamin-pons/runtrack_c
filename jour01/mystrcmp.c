#include <stdio.h>

int my_strcmp(const char *str1, const char *str2);

int main() {
    const char *str1 = "Bonjour";
    const char *str2 = "Bonjour";
    const char *str3 = "Salut";

    int result1 = my_strcmp(str1, str2);  
    int result2 = my_strcmp(str1, str3); 

    printf("Résultat de la comparaison entre \"%s\" et \"%s\": %d\n", str1, str2, result1);
    printf("Résultat de la comparaison entre \"%s\" et \"%s\": %d\n", str1, str3, result2);

    return 0;
}
