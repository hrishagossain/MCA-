#include <stdio.h>
#define INF 99
int main()
{
    int N, L[100][100], status[100], i, j, cost, edge, a, b, min;
    printf("Enter number of vertices:");
    scanf("%d", &N);
    printf("Enter Length matrix:\n");
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            scanf("%d", &L[i][j]);
        }
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (L[i][j] == 0)
                L[i][j] = INF;
        }
    }
    for (i = 1; i <= N; i++)
        status[i] = 0;
    status[1] = 1;
    edge = 0;
    printf("\nSelected edges are:\n");
    while (edge != N - 1)
    {
        min = INF;
        for (i = 1; i <= N; i++)
        {
            if (status[i] == 1)
            {
                for (j = 1; j <= N; j++)
                {
                    if (status[j] == 0)
                    {
                        if (L[i][j] < min)
                        {
                            min = L[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }
        printf("(%d,%d)\n", a, b);
        cost = cost + min;
        L[a][b] = INF;
        L[b][a] = INF;
        status[b] = 1;
        edge++;
    }
    printf("Minimum weight of the MST=%d", cost);
    return 0;
}
