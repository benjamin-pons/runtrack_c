#include <stdio.h>

int my_sqrt(int n) {

    if (n < 0) {
        return 0;  
    }

   
    int left = 0, right = n, mid, square;


    while (left <= right) {
        mid = (left + right) / 2; 
        square = mid * mid;  

        if (square == n) {
            return mid; 
        } else if (square < n) {
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }

    return 0;  
}

int main() {
    int number = 16;
    int result = my_sqrt(number);

    if (result != 0) {
        printf("La racine carrée de %d est %d\n", number, result);
    } else {
        printf("La racine carrée de %d n'est pas un entier\n", number);
    }

    return 0;
}
