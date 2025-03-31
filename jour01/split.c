#include <stdlib.h>


int is_separator(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}


int count_words(const char *str) {
    int count = 0;
    while (*str) {
        while (*str && is_separator(*str)) {
            str++;
        }
        if (*str) { 
            count++;
            while (*str && !is_separator(*str)) {
                str++;
            }
        }
    }
    return count;
}


char *copy_word(const char *start, int length) {
    char *word = (char *)malloc(length + 1);
    if (word) {
        for (int i = 0; i < length; i++) {
            word[i] = start[i];
        }
        word[length] = '\0'; 
    }
    return word;
}


char **split(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int word_count = count_words(str);
    char **result = (char **)malloc((word_count + 1) * sizeof(char *)); // +1 pour NULL
    if (result == NULL) {
        return NULL;
    }

    int index = 0;
    while (*str) {
        while (*str && is_separator(*str)) { // Ignorer les espaces
            str++;
        }

        if (*str) { // Début d'un mot
            const char *start = str;
            int length = 0;

            while (*str && !is_separator(*str)) { // Aller à la fin du mot
                length++;
                str++;
            }

            result[index++] = copy_word(start, length);
        }
    }
    
    result[index] = NULL; // Terminer le tableau par NULL
    return result;
}
