#include <stdio.h>

int power(int base, int exposant) {
    int result = 1; 

    
    for (int i = 0; i < exposant; i++) {
        result *= base; 
    }

    return result;
}

int main() {
    int base = 2;
    int exposant = 3;
    int result = power(base, exposant); 
    printf("%d^%d = %d\n", base, exposant, result);

    return 0;
}
