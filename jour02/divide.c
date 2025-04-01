#include <stdio.h>

void divide(int *num) {
    if (num != NULL) {
        *num /= 2;
    }
}

int main() {
    int value = 10;
    printf("Avant : %d\n", value);
    divide(&value);
    printf("Après : %d\n", value);
    return 0;
}
    