#include <unistd.h>  // Pour la fonction write
#include <stdlib.h>  // Pour la fonction atoi


unsigned long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    unsigned long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}


void my_itoa(unsigned long long num, char *str) {
    int i = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    while (num != 0) {
        str[i++] = (num % 10) + '0';
        num = num / 10;
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
    if (n < 0) return 0; 

    unsigned long long result = fibonacci(n);  


    char result_str[30];  
    my_itoa(result, result_str);


    write(1, result_str, sizeof(result_str) - 1);

    return 0;
}
