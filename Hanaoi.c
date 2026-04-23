#include <stdio.h>

void toh(int n, char x, char y, char z)
{
    if(n == 1)
    {
        printf("\nDisk %d : %c to %c", n, x, y);
    }
    else
    {
        toh(n-1, x, z, y);
        printf("\nDisk %d : %c to %c", n, x, y);
        toh(n-1, z, y, x);
    }
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    toh(n, 'A', 'B', 'C');

    return 0;
}
