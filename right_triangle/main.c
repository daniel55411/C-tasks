#include <stdio.h>
#include <math.h>

#define EPS 0.00001

int cmp(float value_1, float value_2) {
    if (fabs(value_1 - value_2) < EPS) {
        return 0;
    }
    return value_1 > value_2 ? 1 : -1;
}

int pythagorean_theorem(float catheter_1,
                        float catheter_2,
                        float hypotenuse){
    int result = cmp(
            catheter_1 * catheter_1 + catheter_2 * catheter_2,
            hypotenuse * hypotenuse
    );
    return result == 0;
}

int is_triangle(float size_1, float size_2, float size_3) {
    return cmp(size_1, size_2 + size_3) <= 0;
}

int main(void) {
    float side_1, side_2, side_3;

    scanf("%f %f %f", &side_1, &side_2, &side_3);

    if (!is_triangle(side_1, side_2, side_3)
            || !is_triangle(side_2, side_3, side_1)
            || !is_triangle(side_3, side_1, side_2)) {
        return 1;
    }

    if (pythagorean_theorem(side_1, side_2, side_3)
        || pythagorean_theorem(side_1, side_3, side_2)
            || pythagorean_theorem(side_3, side_2, side_1)){
        puts("True");
    } else {
        puts("False");
    }

    return 0;
}