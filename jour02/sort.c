#include <stdio.h>
#include <string.h>

void sort(char **arr) {
    if (arr == NULL) return;
    
    int i, j;
    for (i = 0; arr[i] != NULL; i++) {
        for (j = 0; arr[j + 1] != NULL; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char *array[] = {"Banane", "Pomme", "Orange", "Abricot", NULL};
    
    printf("Avant le tri :\n");
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }
    
    sort(array);
    
    printf("\nAprès le tri :\n");
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }
    
    return 0;
}
