#include <stdio.h>

void func_to_array(char **arr, void (*func)(char *)) {
    if (arr == NULL || func == NULL) return;
    
    for (int i = 0; arr[i] != NULL; i++) {
        func(arr[i]);
    }
}

void my_putstr(char *str) {
    while (*str) {
        putchar(*str);
        str++;
    }
    putchar('\n');
}

void strtoupper(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str -= ('a' - 'A');
        }
        str++;
    }
}

void strtolower(char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str += ('a' - 'A');
        }
        str++;
    }
}

int main() {
    char *array[] = {"Hello", "World", "Test", NULL};
    
    printf("Avant strtoupper:\n");
    func_to_array(array, my_putstr);
    
    func_to_array(array, strtoupper);
    
    printf("\nAprès strtoupper:\n");
    func_to_array(array, my_putstr);
    
    return 0;
}