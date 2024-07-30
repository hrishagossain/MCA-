#include <stdio.h>
float cost[20][20];
int vis[20] = {0};
void main()
{
    int i, j, v, e, b, a, n, s, nc = 1, f, c;
    float w, min=9999, sum, s1;
    printf("\nEnter the number of vertices : ");
    scanf("%d", &v);
    printf("\nEnter the number of edges : ");
    scanf("%d", &e);
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            cost[i][j] = 9999;
    }
    for (i = 0; i < e; i++)
    {
        printf("\nEnter the end vertices for edge %d : ", i);
        scanf("%d %d", &a, &b);
        printf("\nEnter the edge weight for edge %d : ", i);
        scanf("%f", &w);
        cost[a][b] = w;
        cost[b][a] = w;
    }
    printf("\nThe cost matrix is : ");
    printf("\n");
    for (i = 0; i < v; i++)
    {
        printf("V%d\t", i);
        for (j = 0; j < v; j++)
        {
            if (i == j)
            {
                cost[i][j] = 0;
                printf("-\t");
            }
            else if (cost[i][j] == 9999)
                printf("INF\t");
            else
            {
                printf("%.2f\t", cost[i][j]);
                if(min>cost[i][j]) {
                    min=cost[i][j];
                    s=i;
                }
            }
        }
        printf("\n");
    }
    printf("\nINF stands for Infinity");
    do
    {
        c = 1;
        f = 0;
        vis[s] = 1;
        sum = 0.0;
        printf("\nEdges of the MST for component %d are : ", nc);
        while (c < v)
        {
            min = 9999;
            for (i = 0; i < v; i++)
            {
                if (vis[i] == 1)
                {
                    for (j = 0; j < v; j++)
                    {
                        if (cost[i][j] < min && vis[j] == 0)
                        {
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
            if (min != 9999)
            {
                printf("\n( %d , %d ) = %.2f ", a, b, min);
                sum = sum + min;
            }
            vis[b] = 1;
            c++;
        }
        printf("\nThe minimum cost for component %d = : %.2f", nc, sum);
        s1 = s1 + sum;
        for (i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                f = 1;
                s = i;
                break;
            }
        }
        if (f == 1)
            nc++;
        else
            break;
    } while (f == 1);
    printf("\nThe total minimum cost of the spanning forest = %.2f", s1);
    printf("\n");
}
