// se eu nao me engano esta eu tinha feito e entregue corretamente.
// Essa questao devia ser passada como um teste de dislexia.

#include <stdio.h>
#include <stdlib.h>

typedef struct Num
{
    int valor;
    int resto;
} Num;

static void merge(Num *v, Num *v1, Num *v2, size_t size)
{
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;

    size_t i = 0, j = 0, k = 0;

    while (j < size_v1 && k < size_v2)
    {
        if (v1[j].resto != v2[k].resto)
        {
            if (v1[j].resto < v2[k].resto)
                v[i++] = v1[j++];
            else
                v[i++] = v2[k++];
        }
        else
        {
            if (v1[j].valor % 2 != 0 && !v2[k].valor % 2 != 0)
            {
                v[i++] = v1[j++];
            }
            else if (!v1[j].valor % 2 != 0 && v2[k].valor % 2 != 0)
            {
                v[i++] = v2[k++];
            }
            else
            {
                if (!v1[j].valor % 2 != 0 && !v2[k].valor % 2 != 0)
                {
                    if (v1[j].valor < v2[k].valor)
                        v[i++] = v1[j++];
                    else
                        v[i++] = v2[k++];
                }
                else
                {
                    if (v1[j].valor > v2[k].valor)
                        v[i++] = v1[j++];
                    else
                        v[i++] = v2[k++];
                }
            }
        }
    }

    while (j < size_v1)
        v[i++] = v1[j++];

    while (k < size_v2)
        v[i++] = v2[k++];
}

void mergesort(Num *v, size_t size)
{
    if (size > 1)
    {
        size_t meio = size / 2;
        Num *v1 = malloc(sizeof(Num) * meio);
        Num *v2 = malloc(sizeof(Num) * (size - meio));
        for (size_t i = 0; i < meio; i++)
        {
            v1[i] = v[i];
        }
        for (size_t i = meio; i < size; i++)
        {
            v2[i - meio] = v[i];
        }
        mergesort(v1, meio);
        mergesort(v2, size - meio);

        merge(v, v1, v2, size);
        free(v1);
        free(v2);
    }
}

int main()
{
    int n, m, entrada;
    scanf("%d %d", &n, &m);
    Num *v = malloc(sizeof(Num) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &entrada);
        v[i].valor = entrada;
        v[i].resto = entrada % m;
    }
    mergesort(v, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", v[i].valor);
    }
    free(v);
    return 0;
}