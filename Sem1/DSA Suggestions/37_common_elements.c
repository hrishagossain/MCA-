#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define PI 3.14159

int main()
{
    int a[25], b[30], c[25];
    printf("Enter First Array Elements: ");
    for (int i = 0; i < 25; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter Second Array Elements: ");
    for (int i = 0; i < 30; i++)
    {
        scanf("%d", &b[i]);
    }
    int count = 0;
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (a[i] == b[j])
            {
                int flag = 0;
                for (int k = 0; k < count; k++)
                {
                    if (a[i] == c[k])
                    {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    c[count] = a[i];
                    count++;
                }
            }
        }
    }

    printf("Common Elements: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}
