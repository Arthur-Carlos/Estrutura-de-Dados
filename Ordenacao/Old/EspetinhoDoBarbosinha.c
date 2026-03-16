#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Evento
{
    int tempo;
    int valor;
} Evento;

int tempoParaSegundos(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

int comparador(const void *a, const void *b)
{
    Evento *e1 = (Evento*)a;
    Evento *e2 = (Evento*)b;

    if (e1->tempo == e2->tempo)
    {
        return e2->valor - e1->valor;
    }
    return e1->tempo - e2->tempo;
}

int main()
{
    int entrada;
    int chegada, ent_hora, ent_minuto, ent_segundos;
    int saida, sai_hora, sai_minuto, sai_segundos;

    scanf("%d", &entrada);

    Evento *clientes = malloc(entrada * 2 * sizeof(Evento));

    for (int i = 0; i < entrada; ++i)
    {
        scanf("%d:%d:%d", &ent_hora, &ent_minuto, &ent_segundos);
        scanf("%d:%d:%d", &sai_hora, &sai_minuto, &sai_segundos);

        chegada = tempoParaSegundos(ent_hora, ent_minuto, ent_segundos);
        saida = tempoParaSegundos(sai_hora, sai_minuto, sai_segundos);

        clientes[2 * i].tempo = chegada;
        clientes[2 * i].valor = 1;
        clientes[2 * i + 1].tempo = saida;
        clientes[2 * i + 1].valor = -1;
    }

    qsort(clientes, 2 * entrada, sizeof(Evento), comparador);

    int cadeiras = 0, contador = 0;
    for (int i = 0; i < 2 * entrada; i++)
    {
        cadeiras += clientes[i].valor;
        if (cadeiras > contador)
        {
            contador = cadeiras;
        }
    }
    printf("%d\n", contador);
    free(clientes);

    return 0;
}