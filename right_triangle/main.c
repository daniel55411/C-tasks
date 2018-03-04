#include <stdio.h>

int pythagorean_theorem(float catheter_1,
                        float catheter_2,
                        float hypotenuse){
    return catheter_1 * catheter_1 + catheter_2 * catheter_2 == hypotenuse * hypotenuse;
}

int main(void) {
    float side_1, side_2, side_3;
    scanf("%f %f %f", &side_1, &side_2, &side_3);
    if (pythagorean_theorem(side_1, side_2, side_3)
        || pythagorean_theorem(side_1, side_3, side_2)
            || pythagorean_theorem(side_3, side_2, side_1)){
        puts("True");
    } else {
        puts("False");
    }
    return 0;
}