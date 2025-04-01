#include <stdio.h>
#include <stdlib.h>

void delete_str_array(char ***arr) {
    if (arr == NULL || *arr == NULL) return;
    
    for (int i = 0; (*arr)[i] != NULL; i++) {
        free((*arr)[i]);
    }
    free(*arr);
    *arr = NULL;
}

int main() {
    char **array = malloc(4 * sizeof(char *));
    if (!array) return 1;
    
    array[0] = malloc(6);
    array[1] = malloc(6);
    array[2] = malloc(6);
    array[3] = NULL;
    
    if (!array[0] || !array[1] || !array[2]) {
        delete_str_array(&array);
        return 1;
    }
    
    snprintf(array[0], 6, "Hello");
    snprintf(array[1], 6, "World");
    snprintf(array[2], 6, "Test");
    
    printf("Avant suppression :\n");
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }
    
    delete_str_array(&array);
    
    printf("\nAprès suppression : %p\n", (void *)array);
    
    return 0;
}
