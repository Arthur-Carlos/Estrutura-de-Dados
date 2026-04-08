#include <stdio.h>
// esta eu estava usando o método errado para encontrar as cotas.
// esqueci de Ordenar, ops.

void merge(int *v, int *v1, int *v2, size_t size)
{

    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for (i = 0; j < size_v1 && k < size_v2; i++)
    {
        if (v1[j] <= v2[k])
        {
            v[i] = v1[j++];
        }
        else
        {
            v[i] = v2[k++];
        }
    }

    while (j < size_v1)
    {
        v[i++] = v1[j++];
    }
    while (k < size_v2)
    {
        v[i++] = v2[k++];
    }
}

void mergesort(int *v, size_t size)
{
    size_t mid;
    if (size > 1)
    {
        mid = size / 2;
        int v1[mid];
        int v2[size - mid];
        int i;
        for (i = 0; i < mid; i++)
        {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++)
        {
            v2[i - mid] = v[i];
        }
        mergesort(v1, mid);
        mergesort(v2, size - mid);
        merge(v, v1, v2, size);
    }
}

int cotaInf(int v[], int n, int x)
{
    int l = 0, r = n - 1, ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (v[mid] >= x)
        {
            if (v[mid] == x)
                ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

int cotaSup(int v[], int n, int x)
{
    int l = 0, r = n - 1, ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (v[mid] <= x)
        {
            if (v[mid] == x)
                ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    mergesort(v, n);
    while (q--)
    {
        int x;
        scanf("%d", &x);

        int l = cotaInf(v, n, x);

        if (l == -1)
        {
            printf("-1\n");
            continue;
        }

        int r = cotaSup(v, n, x);

        printf("%d %d\n", l+1, r+1);
    }

    return 0;
}