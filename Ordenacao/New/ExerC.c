#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Horario
{
    int entrada;
    int fluxo;
} Horario;

/*
void swap(Horario *v, int i, int j)
{
    Horario t = v[i];
    v[i] = v[j];
    v[j] = t;
}

static size_t partition(Horario *v, int l, int r, int pivot)
{
    size_t pos, i;
    swap(v, pivot, r);
    pos = l;
    for (i = l; i < r; i++)
    {
        if (v[i].entrada == v[r].entrada)
        {
            if (v[i].fluxo > v[r].fluxo)
            {
                swap(v, i, pos);
                pos++;
            }
        }

        if (v[i].entrada < v[r].entrada)
        {
            swap(v, i, pos);
            pos++;
        }
    }
    swap(v, r, pos);
    return pos;
}

void quick_sort_helper(Horario *v, int l, int r)
{
    if (l < r)
    {
        size_t pos = partition(v, l, r, r);
        quick_sort_helper(v, l, pos - 1);
        quick_sort_helper(v, pos + 1, r);
    }
}

void quick_sort(Horario *v, size_t size)
{
    quick_sort_helper(v, 0, size - 1);
}
*/

int converteTempo(int hora, int minuto, int segundo)
{
    return segundo + 60 * minuto + 3600 * hora;
}

int compare(const void *a, const void *b)
{
    Horario *e1 = (Horario*)a;
    Horario *e2 = (Horario*)b;

    if (e1->entrada == e2->entrada)
    {
        return e2->fluxo - e1->fluxo;
    }
    return e1->entrada - e2->entrada;
}

int main()
{
    int n, segundos, minutos, horas;
    scanf("%d", &n);
    Horario *cliente = malloc(2 * sizeof(Horario) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d", &horas, &minutos, &segundos);
        cliente[2 * i].entrada = converteTempo(horas, minutos, segundos);
        cliente[2 * i].fluxo = 1;

        scanf("%d:%d:%d", &horas, &minutos, &segundos);
        cliente[2 * i + 1].entrada = converteTempo(horas, minutos, segundos);
        cliente[2 * i + 1].fluxo = -1;
    }
    //decidi usar a funcao da biblioteca para ver se o problema persiste
    qsort(cliente, n * 2, sizeof(Horario), compare);

    int contador = 0, cadeira = 0;
    for (int i = 0; i < n * 2; i++)
    {
        cadeira = cliente[i].fluxo + cadeira;
        if (cadeira > contador)
        {
            contador = cadeira;
        }
    }
    printf("%d", contador);
    free(cliente);
    return 0;
}