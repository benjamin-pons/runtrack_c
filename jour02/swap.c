#include <stdio.h>

void swap(int *a, int *b) {
    if (a != NULL && b != NULL) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    int x = 5, y = 10;
    printf("Avant l'échange : x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Après l'échange : x = %d, y = %d\n", x, y);
    return 0;
}