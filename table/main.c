#include <stdlib.h>
#define size_t 10

void print_table(int** table, int row, int column){
    int* ptr = table;

    printf("Squares' table\n\n");
    for (int i = 0; i < row; i++) {
        printf("%6d", i);
    }
    printf("\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j == 0) {
                printf("%d ", i + 1);
            }

            printf("%6d", *(ptr + i * row + j));
        }
        printf("\n");
    }
}

void get_squares(int** table, int row, int column){
    int* ptr = table;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            *(ptr + i * row + j) = ((i + 1) * 10 + j) * ((i + 1) * 10 + j);
        }
    }
}

int main(void) {
    int a[7][7];
    get_squares(a, 6, 6);
    print_table(a, 6, 6);
    return 0;
}

