#include <stdio.h>
#include <stdlib.h>


typedef struct album {
    char *artist;
    char *title;
    int year;
    struct album *next;
} album;

void push_back_album(album **head, album *new_album) {
    if (!head || !new_album) {
        return; 
    }

    if (*head == NULL) { 
        *head = new_album;
        return;
    }

    album *current = *head;
    while (current->next) { 
        current = current->next;
    }
    
    current->next = new_album;
}


void print_albums(album *head) {
    while (head) {
        printf("\"%s\" by \"%s\" released in %d.\n", head->title, head->artist, head->year);
        head = head->next;
    }
}


int main() {

    album album1 = {"Metallica", "Master of Puppets", 1986, NULL};
    album album2 = {"Pink Floyd", "The Dark Side of the Moon", 1973, NULL};
    album album3 = {"Nirvana", "Nevermind", 1991, NULL};

    album *playlist = NULL;


    push_back_album(&playlist, &album1);
    push_back_album(&playlist, &album2);
    push_back_album(&playlist, &album3);


    print_albums(playlist);

    return 0;
}
