#include <stdio.h>

int cmp(float value_1, float value_2) {
    int int_value_1 = *(int*)&value_1;
    int int_value_2 = *(int*)&value_2;

    if (int_value_1 == int_value_2) {
        return 0;
    } else if (int_value_1 > int_value_2) {
        return 1;
    } else if (int_value_1 < int_value_2) {
        return -1;
    }
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

    if (!is_triangle(side_1, side_2, side_3)) {
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