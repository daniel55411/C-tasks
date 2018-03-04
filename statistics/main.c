#include <stdio.h>
#include <ctype.h>

int main() {
    int c;
    int digit_count = 0;
    int alpha_count = 0;
    while ((c = getc(stdin)) != EOF){
        if (isalpha(c)) {
            alpha_count += 1;
        } else if (isdigit(c)){
            digit_count += 1;
        }
    }
    printf("Digits: %d\n", digit_count);
    printf("Latin symbols: %d\n", alpha_count);
    return 0;
}