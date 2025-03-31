#include "my_putchar.c"

void my_putstr(const char *str) {
    while (*str) {     
        my_putchar(*str);
        str++;          
    }
}

int main() {
    const char *str = "Bonjour, comment ça va ?";
    my_putstr(str); 
    return 0;
}