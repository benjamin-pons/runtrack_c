#include <stdio.h>


typedef struct {
    int x;
    int y;
} point;


#define ABS(x) ((x) < 0 ? -(x) : (x))


int manhattan(point p1, point p2) {
    return ABS(p1.x - p2.x) + ABS(p1.y - p2.y);
}

int main() {
    point a = {3, 5};
    point b = {1, 1};

    printf("Distance de Manhattan entre A et B : %d\n", manhattan(a, b));

    return 0;
}
