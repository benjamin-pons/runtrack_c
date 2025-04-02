#include <unistd.h>  // Pour la fonction write
#include <stdlib.h>  // Pour la fonction atoi


unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


void my_itoa(int num, char *str) {  
    int i = 0;
    int isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        str[i++] = (num % 10) + '0';
        num = num / 10;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

   
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 0;  
    }

    int n = atoi(argv[1]);  
    unsigned long long fact = factorial(n);  

    
    char result[20];
    my_itoa(fact, result);  

    
    write(1, result, sizeof(result) - 1);

    return 0;
}
