#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

int main()
{
    int n;
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int *stack = malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        while (top >= 0 && v[stack[top]] >= v[i])
            top--;

        if (top >= 0)
            printf("%d ", stack[top] + 1);
        else
            printf("0 ");

        stack[++top] = i;
    }

    free(v);
    free(stack);
    return 0;
}
