#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define PI 3.14159

int main()
{
    // int n;
    // printf("Enter Size of Array: ");
    // scanf("%d", &n);
    // int ar[n];
    // printf("Enter Array Elements: ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &ar[i]);
    // }
    int ar[] = {11, 5, 21, 3, 29, 17, 2, 43};
    int n = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
    // printf("Sorted Array: ");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", ar[i]);
    // }
    int num = 29;
    // printf("\nEnter the Number You Want to Search: ");
    // scanf("%d", &num);
    int min = 0, max = n - 1;
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (ar[mid] == num)
        {
            printf("%d is in Index %d", num, mid);
            break;
        }
        else if (ar[mid] < num)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    if (min > max)
    {
        printf("%d is NOT in this Array");
    }
    return 0;
}
