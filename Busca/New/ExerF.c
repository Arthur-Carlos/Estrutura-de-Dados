#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *v, int i, int j)
{
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

static size_t partition(int *v, int l, int r, int pivot)
{
    size_t pos, i;
    swap(v, pivot, r);
    pos = l;
    for (i = l; i < r; i++)
    {
        if (v[i] < v[r])
        {
            swap(v, i, pos);
            pos++;
        }
    }
    swap(v, r, pos);
    return pos;
}

void quick_sort_helper(int *v, int l, int r)
{
    if (l < r)
    {
        size_t pos = partition(v, l, r, r);
        quick_sort_helper(v, l, pos - 1);
        quick_sort_helper(v, pos + 1, r);
    }
}

void quick_sort(int *v, size_t size)
{
    quick_sort_helper(v, 0, size - 1);
}

int busca_binaria(int *v, size_t n, int key)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (key == v[mid])
        {
            if (key == v[0])
            {
                return v[mid + 1];
            }
            if (abs(key - v[mid + 1]) < abs(key - v[mid - 1]))
            {
                return v[mid + 1];
            }
            else
            {
                return v[mid - 1];
            }
        }
        else if (key < v[mid] && (key - v[mid - 1] != key))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int removeDupe(int *v, int n){
    if(n == 0 || n ==1){
        return n;
    }
    int j = 0;
    for(int i = 0; i < n-1; i++){
        if(v[i] != v[i+1]){
            v[j++]= v[i];
        }
    }
    v[j++] = v[n-1];
    return j;
}

int main()
{
    int n, q, x;
    scanf("%d %d", &n, &q);
    int *ptr = malloc(sizeof(int) * n);
    if (ptr == NULL)
    {
        printf("Erro\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        ptr[i] = x;
    }
    quick_sort(ptr, n);
    removeDupe(ptr,sizeof(ptr));
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &x);
        int y = busca_binaria(ptr, n, x);
        printf("%d\n", y);
    }
    /*
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", ptr[i]);
    }*/
    free(ptr);
    return 0;
}
