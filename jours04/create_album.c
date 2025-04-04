#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct album {
    char *artist;
    char *title;
    int year;
    struct album *next;
} album;


album *create_album(const char *artist, const char *title, int year) {
    
    album *new_album = (album *)malloc(sizeof(album));
    if (!new_album) {
        return NULL; 
    }

    
    new_album->artist = (char *)malloc(strlen(artist) + 1);
    if (!new_album->artist) {
        free(new_album);
        return NULL;
    }
    strcpy(new_album->artist, artist);

   
    new_album->title = (char *)malloc(strlen(title) + 1);
    if (!new_album->title) {
        free(new_album->artist);
        free(new_album);
        return NULL;
    }
    strcpy(new_album->title, title);

    
    new_album->year = year;
    new_album->next = NULL; 

    return new_album;
}


void free_album(album *alb) {
    if (alb) {
        free(alb->artist);
        free(alb->title);
        free(alb);
    }
}


int main() {

    album *my_album = create_album("Metallica", "Master of Puppets", 1986);
    
    if (my_album) {
        printf("\"%s\" by \"%s\" released in %d.\n", my_album->title, my_album->artist, my_album->year);
        free_album(my_album); 
    } else {
        printf("Erreur d'allocation mémoire !\n");
    }

    return 0;
}
