#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_song {
    char *artist;
    char *title;
    int year;
    struct s_song *next;
} t_song;

void free_list(t_song *list) {
    t_song *temp;
    while (list) {
        temp = list;
        list = list->next;
        free(temp->artist);
        free(temp->title);
        free(temp);
    }
}

int compare_artist(const void *a, const void *b) {
    return strcmp(((t_song *)a)->artist, ((t_song *)b)->artist);
}

int compare_title(const void *a, const void *b) {
    return strcmp(((t_song *)a)->title, ((t_song *)b)->title);
}

int compare_year(const void *a, const void *b) {
    return ((t_song *)a)->year - ((t_song *)b)->year;
}

void print_song(t_song *song) {
    printf("\"%s\" by \"%s\" released in %d.\n", song->title, song->artist, song->year);
}

void read_file(const char *filename, t_song **list) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "File not found.\n");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *artist = strtok(line, ",");
        char *title = strtok(NULL, ",");
        char *year_str = strtok(NULL, "\n");

        if (!artist || !title || !year_str) {
            fprintf(stderr, "Incorrect format.\n");
            fclose(file);
            exit(1);
        }

        t_song *new_song = malloc(sizeof(t_song));
        if (!new_song) {
            fprintf(stderr, "Memory allocation error.\n");
            fclose(file);
            exit(1);
        }

        new_song->artist = strdup(artist);
        new_song->title = strdup(title);
        new_song->year = atoi(year_str);
        new_song->next = *list;
        *list = new_song;
    }

    fclose(file);
}

void sort_list(t_song *list, const char *method) {
    int count = 0;
    t_song *temp = list;
    while (temp) {
        count++;
        temp = temp->next;
    }

    t_song *array = malloc(count * sizeof(t_song));
    if (!array) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    temp = list;
    for (int i = 0; i < count; i++) {
        array[i] = *temp;
        temp = temp->next;
    }

    if (strcmp(method, "artist") == 0) {
        qsort(array, count, sizeof(t_song), compare_artist);
    } else if (strcmp(method, "title") == 0) {
        qsort(array, count, sizeof(t_song), compare_title);
    } else if (strcmp(method, "year") == 0) {
        qsort(array, count, sizeof(t_song), compare_year);
    } else {
        fprintf(stderr, "Sort method does not exist.\n");
        free(array);
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        print_song(&array[i]);
    }

    free(array);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <sort_method>\n", argv[0]);
        return 1;
    }

    t_song *list = NULL;
    read_file(argv[1], &list);
    sort_list(list, argv[2]);
    free_list(list);

    return 0;
}
