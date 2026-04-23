#include <stdio.h>

int main()
{
    int n, i, j;
    float bin[10], item[10], cap;
    int used_bins = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%f", &cap);

    // Input item sizes
    for(i = 0; i < n; i++)
    {
        printf("Enter size of item %d: ", i + 1);
        scanf("%f", &item[i]);

        bin[i] = cap;   // initialize bin capacity
    }

    // First Fit Algorithm
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(bin[j] >= item[i])
            {
                bin[j] -= item[i];

                if(j + 1 > used_bins)
                    used_bins = j + 1;

                break;
            }

            if(j == n - 1)
                printf("Item %d cannot be placed in any bin\n", i + 1);
        }
    }

    printf("\nRemaining space in bins:\n");

    for(i = 0; i < used_bins; i++)
        printf("Bin %d: %.2f\n", i + 1, bin[i]);

    return 0;
}
