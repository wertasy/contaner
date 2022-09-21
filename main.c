#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "slice.h"

struct user {
    char *name;
    int age;
};

#define ELEM_TYPE struct user
#define CTNR_TYPE user_slice
#include "slice.tplt"

int main() {
    char **strs = str_slice_make(0, 2);

    strs = str_slice_append(strs, strdup("Hello world! 1"));
    printf("%d, %d\n", slice_len(strs), slice_cap(strs));

    strs = str_slice_append(strs, strdup("Hello world! 2"));
    printf("%d, %d\n", slice_len(strs), slice_cap(strs));

    strs = str_slice_append(strs, strdup("Hello world! 3"));
    printf("%d, %d\n", slice_len(strs), slice_cap(strs));

    strs = str_slice_append(strs, strdup("Hello world! 4"));
    printf("%d, %d\n", slice_len(strs), slice_cap(strs));

    for (int i = 0; i < slice_len(strs); ++i) {
        printf("%s\n", strs[i]);
        free(strs[i]);
    }
    free(slice_cast(strs));

    int *ints = int_slice_make(0, 10);
    for (int i = 0; i < 20000; ++i) {
        ints = int_slice_append(ints, i+1);
    }

    for (int i = 0; i < slice_len(ints); ++i) {
        printf("%d ", ints[i]);
    }
    printf("\n%d, %d\n", slice_len(ints), slice_cap(ints));
    free(slice_cast(ints));

    return 0;
}