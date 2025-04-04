#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct album {
    char *artist;
    char *title;
    int year;
    struct album *next;
} album;


void album_del_one(album **head, album *to_delete) {
    if (!head || !*head || !to_delete) {
        return;
    }

    album *temp = *head;
    album *prev = NULL;


    if (temp == to_delete) {
        *head = temp->next; 
        free(temp);
        return;
    }


    while (temp && temp != to_delete) {
        prev = temp;
        temp = temp->next;
    }


    if (temp) {
        prev->next = temp->next;
        free(temp);
    }
}


void print_albums(album *head) {
    while (head) {
        printf("\"%s\" by \"%s\" released in %d.\n", head->title, head->artist, head->year);
        head = head->next;
    }
}


int main() {
    // Création des albums dynamiquement
    album *a1 = malloc(sizeof(album));
    album *a2 = malloc(sizeof(album));
    album *a3 = malloc(sizeof(album));

    a1->artist = strdup("Metallica");
    a1->title = strdup("Master of Puppets");
    a1->year = 1986;
    a1->next = a2;

    a2->artist = strdup("Pink Floyd");
    a2->title = strdup("The Dark Side of the Moon");
    a2->year = 1973;
    a2->next = a3;

    a3->artist = strdup("Nirvana");
    a3->title = strdup("Nevermind");
    a3->year = 1991;
    a3->next = NULL;

    album *playlist = a1;

    printf("Liste des albums avant suppression :\n");
    print_albums(playlist);


    album_del_one(&playlist, a2);

    printf("\nListe des albums après suppression :\n");
    print_albums(playlist);

    // Libération mémoire restante
    album_del_one(&playlist, a1);
    album_del_one(&playlist, a3);

    return 0;
}
