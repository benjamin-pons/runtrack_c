#include <unistd.h>
#include <stdlib.h>

int str_len(const char *str) {
    int len = 0;
    while (str[len]) len++;
    return len;
}

char *str_trim(const char *str) {
    while (*str == ' ' || *str == '\t') str++;
    int len = str_len(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) len--;
    
    char *trimmed = malloc(len + 1);
    if (!trimmed) return NULL;
    
    for (int i = 0; i < len; i++) {
        trimmed[i] = str[i];
    }
    trimmed[len] = '\0';
    return trimmed;
}

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void sort_strings(char **arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int k = 0;
            while (arr[j][k] && arr[j + 1][k] && arr[j][k] == arr[j + 1][k]) k++;
            if (arr[j][k] > arr[j + 1][k]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void print_strings(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        if (i > 0) write(1, " ", 1);
        write(1, arr[i], str_len(arr[i]));
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv) {
    if (argc < 2) return 0;
    
    char **trimmed_args = malloc((argc - 1) * sizeof(char *));
    if (!trimmed_args) return 1;
    
    int count = 0;
    for (int i = 1; i < argc; i++) {
        trimmed_args[count] = str_trim(argv[i]);
        if (trimmed_args[count]) count++;
    }
    
    if (count > 0) {
        sort_strings(trimmed_args, count);
        print_strings(trimmed_args, count);
    }
    
    for (int i = 0; i < count; i++) {
        free(trimmed_args[i]);
    }
    free(trimmed_args);
    
    return 0;
}