#include <stdio.h>

typedef struct {
    char *title;
    char *artist;
    int year;
} album;

void print_album(album *a) {
    if (a) {
        printf("\"%s\" by \"%s\" released in %d.\n", a->title, a->artist, a->year);
    }
}

int main() {
    album metallica = {"Master of Puppets", "Metallica", 1986};
    print_album(&metallica);
    return 0;
}
