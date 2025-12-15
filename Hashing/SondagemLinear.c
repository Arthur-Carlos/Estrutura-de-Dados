#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000

typedef struct query
{
    int op;
    int valor;
} query;

int q, m;
query queries[MAX];
int table[MAX];

void solve()
{
    for (int i = 0; i < q; i++)
    {
        for (int k = 0; k < m; k++)
        {
            table[k] = -1;
        }

        int j = 0;
        int pos = queries[i].valor % m;
        int count = 1;
        do
        {
            if (table[pos + j] == -1)
            {
                if (queries[i].op == 1)
                {
                    table[pos + j] == queries[i].valor;
                    printf("%d %d\n", pos + j, count);
                }
                else
                {
                    printf("-1 %d\n", count);
                }
                break;
            }
            count++;
            j = (j + 1) % m;
        } while (count <= m);
        if (count > m)
        {
            printf("-1 %d", m);
        }
    }
}

int main()
{
    int q, m;
    scanf("%d %d", &q, &m);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &queries[i].op, &queries[i].valor);
    }
    solve();
    return 0;
}