#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **array_clone(char **arr, int n) {
    if (arr == NULL || n <= 0) {
        return NULL;
    }
    
    char **clone = malloc((n + 1) * sizeof(char *));
    if (clone == NULL) {
        return NULL;
    }
    
    int i;
    for (i = 0; i < n && arr[i] != NULL; i++) {
        clone[i] = strdup(arr[i]);
        if (clone[i] == NULL) {
            // Libérer la mémoire en cas d'échec
            for (int j = 0; j < i; j++) {
                free(clone[j]);
            }
            free(clone);
            return NULL;
        }
    }
    clone[i] = NULL; // Terminer par un pointeur NULL
    
    return clone;
}

int main() {
    char *array[] = {"Hello", "World", "Test", NULL};
    int n = 3;
    
    char **cloned_array = array_clone(array, n);
    
    if (cloned_array) {
        for (int i = 0; cloned_array[i] != NULL; i++) {
            printf("%s\n", cloned_array[i]);
            free(cloned_array[i]); // Libérer la mémoire après utilisation
        }
        free(cloned_array);
    }
    
    return 0;
}