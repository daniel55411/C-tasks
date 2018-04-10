#include <string.h>

int get_length(char* string) {
    char c;
    int index = 0;

    while ((c = string[index]) != 0) {
        index++;
    }

    return index;
}

char* _strncat(char* destptr, char* srcptr, int count) {
    //TODO: check count > length(srcptr)
    int length = get_length(destptr);

    for (int i = 0; i < count; i++) {
        destptr[length + i] = srcptr[i];
    }

    destptr[length + count] = 0;

    return destptr;
}


int main(void) {
    char dest[] = "begin";
    char* src = "endandsome";

    char* test1 = _strncat(dest, src, 3);
    if (strcmp("beginend", test1) != 0) {
        puts("Fail test 1");
        return 1;
    }


    char new_dest[] = "begin";
    char* test2 = _strncat(new_dest, src, 10);

    if (strcmp("beginendandsome", test2) != 0) {
        puts("Fail test 2");
        return 1;
    }

    puts("Success");
    return 0;
}