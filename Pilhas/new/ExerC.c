#include <stdio.h>

int main(void)
{
    int n, v;
    scanf("%d", &n);
    int arr[n + 1];
    int aux[n + 1];
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        while (top > 0 && arr[aux[top]] >= arr[i])
        {
            top--;
        }
        if (top == 0)
        {
            printf("0 ");
        }
        else
        {
            printf("%d ", aux[top]);
        }

        aux[++top] = i;
    }
    printf("\n");
    return 0;
}