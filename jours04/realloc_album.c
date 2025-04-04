#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char *title;
    char *artist;
    int year;
} album;


album *realloc_album(album *albums, int old_size, int new_size) {

    album *new_albums = (album *)malloc(new_size * sizeof(album));
    if (!new_albums) {
        return NULL; 
    }


    int min_size = (old_size < new_size) ? old_size : new_size;
    for (int i = 0; i < min_size; i++) {
        new_albums[i] = albums[i];
    }


    free(albums);

    return new_albums;
}


int main() {
    int old_size = 2;
    int new_size = 4;


    album *albums = (album *)malloc(old_size * sizeof(album));
    if (!albums) return 1;

    albums[0] = (album){"Master of Puppets", "Metallica", 1986};
    albums[1] = (album){"Back in Black", "AC/DC", 1980};

    // Réallocation
    albums = realloc_album(albums, old_size, new_size);
    if (!albums) return 1;

    
    for (int i = 0; i < old_size; i++) {
        printf("\"%s\" by \"%s\" released in %d.\n", albums[i].title, albums[i].artist, albums[i].year);
    }


    free(albums);

    return 0;
}
