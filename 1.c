#include <stdio.h>
#include <stdlib.h>
int main() {
    int i = 0;
    int ** a = (int **)malloc(3*sizeof(int));
    for (i = 0; i < 3; i++) {
        a[i] = (int*)malloc(2*sizeof(int));
    }
    free(a[0]);
    free(a[1]);
    free(a[2]);
    free(a);
    return 0;
}

