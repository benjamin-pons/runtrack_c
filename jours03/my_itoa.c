#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int num) {
    if (num == 0) {
        char *str = (char *)malloc(2 * sizeof(char)); 
        if (str == NULL) {
            return NULL;
        }
        str[0] = '0';
        str[1] = '\0';
        return str;
    }


    int temp = num, length = 0, is_negative = 0;


    if (num < 0) {
        is_negative = 1;
        num = -num; 
    }


    while (temp != 0) {
        temp /= 10;
        length++;
    }

    if (is_negative) {
        length++;
    }


    char *str = (char *)malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        return NULL; 
    }

    str[length] = '\0'; 


    for (int i = length - 1; i >= 0; i--) {
        str[i] = (num % 10) + '0'; 
        num /= 10;
    }


    if (is_negative) {
        str[0] = '-';
    }

    return str;
}

int main() {
    int number = -1234;
    char *str = my_itoa(number);

    if (str != NULL) {
        printf("La chaîne est : %s\n", str);
        free(str); 
    } else {
        printf("Erreur d'allocation mémoire.\n");
    }

    return 0;
}
