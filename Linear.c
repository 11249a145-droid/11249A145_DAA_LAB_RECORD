#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ls(int a1[], int begin, int stop, int search)
{
    if(begin == stop)
        printf("Element not found");
    else if(a1[begin] == search)
        printf("Element found at position %d", begin + 1);
    else
        ls(a1, begin + 1, stop, search);
}

int main()
{
    int a[10000], n = 10000, key, i;
    clock_t start, end;

    for(i = 0; i < n; i++)
        a[i] = rand() % 1000;

    key = rand() % 1000;

    start = clock();

    ls(a, 0, n, key);

    end = clock();

    printf("\nTotal time taken for execution is %lf",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
