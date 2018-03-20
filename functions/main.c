#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filter(
        void *from,
        void *to,
        size_t count,
        size_t size,
        int (*where)(void *)
);

void reduce(
        void *array,
        void *result,
        size_t count,
        size_t size,
        void (*consumer)(void *, void *)
);

int filter(
        void *from,
        void *to,
        size_t count,
        size_t size,
        int (*where)(void *)
) {
    char *from_bytes = (char *)from;
    char *to_bytes = (char *)to;

    int index = 0;
    for (size_t i = 0; i < count; i++) {
        if (where(from_bytes + size * i)) {
            memcpy(to_bytes + size * index, from_bytes + size * i, size);
            index++;
        }
    }
    return index;
}

void reduce(
        void *array,
        void *result,
        size_t count,
        size_t size,
        void (*consumer)(void *, void *)
) {
    if (size == 0) {
        return;
    }

    char *array_bytes = (char *)array;
    char *result_bytes = (char *)result;

    memcpy(result_bytes, array_bytes, size);

    for (int i = 1; i < count; i++) {
        consumer(result_bytes, array_bytes + size * i);
    }
}

int odd_filter(int* a) {
    return (*a) % 2 == 1;
}

int char_filter(char* a) {
    return isalpha(*a);
}

int sum(int *n_1, int *n_2) {
    *n_1 = *n_1 + *n_2;
}

int test_filter_1(int log) {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int expected[] = {1, 3};
    int count = 3;
    int size = sizeof(int);
    int actual[count];

    int length = filter(a, actual, count, size, odd_filter);

    for (int i = 0; i < length; i++) {
        if (log) {
            printf("%d ", actual[i]);
        }
        if (actual[i] != expected[i]) {
            if (log) {
                printf("\n");
            }
            return 0;
        }
    }
    if (log) {
        printf("\n");
    }
    return 1;
}

int test_filter_2(int log) {
    char a[] = "abc1234aab";
    char expected[] = "abc";
    int count = 7;
    int size = sizeof(int);
    char actual[count];

    int length = filter(a, actual, count, size, char_filter);

    return (length == 3 && strcmp(expected, actual));
}

int test_reduce_1(int log) {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int expected = 10;
    int count = 4;
    int size = sizeof(int);
    int actual;

    reduce(a, &actual, count, size, sum);

    if (log) {
        printf("%d\n", actual);
    }

    return actual == expected;

}

int test_reduce_2(int log) {
    char a[] = "1234567";
    char expected[] = "1234";
    int count = 4;
    int size = sizeof(char);
    char actual[10];

    reduce(a, actual, count, size, strcat);

    if (log) {
        printf("%d\n", *actual);
    }

    return strcmp(expected, actual);

}

int main(void) {
    printf("Test_1 for filter is success: %s\n", test_filter_1(0) ? "True" : "False");
    printf("Test_2 for filter is success: %s\n", test_filter_2(0) ? "True" : "False");
    printf("Test_1 for reduce is success: %s\n", test_reduce_1(0) ? "True" : "False");
    printf("Test_2 for reduce is success: %s\n", test_reduce_2(0) ? "True" : "False");
}