#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct
{
    int pos;
    int chegada;
} Pessoa;

typedef struct queue_t
{
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
    Pessoa *queue;
} queue_t;

static void queue_shrink(queue_t *q);
static void queue_expand(queue_t *q);

void queue_initialize(queue_t **q)
{
    (*q) = malloc(sizeof(queue_t));
    (*q)->front = 0;
    (*q)->back = 3;
    (*q)->size = 0;
    (*q)->capacity = 4;
    (*q)->queue = malloc(sizeof(Pessoa) * 4);
}

size_t queue_size(queue_t *q)
{
    return q->size;
}

bool queue_empty(queue_t *q)
{
    return queue_size(q) == 0;
}

void queue_push(queue_t *q, Pessoa data)
{
    if (q->size == q->capacity)
    {
        queue_expand(q);
    }
    q->back++;
    if (q->back == q->capacity)
    {
        q->back = 0;
    }
    q->queue[q->back] = data;
    q->size++;
}

static void queue_expand(queue_t *q)
{
    size_t old_capacity = q->capacity;
    q->capacity *= 2;
    q->queue = realloc(q->queue, sizeof(Pessoa) * q->capacity);
    if (q->front > q->back)
    {
        for (size_t i = q->front; i < old_capacity; i++)
        {
            q->queue[i + old_capacity] = q->queue[i];
        }
        q->front = q->front + old_capacity;
    }
}

void queue_pop(queue_t *q)
{
    assert(q->size > 0);
    if (q->size == q->capacity / 4 && q->capacity > 4)
    {
        queue_shrink(q);
    }
    q->front++;
    q->size--;
    if (q->front == q->capacity)
    {
        q->front = 0;
    }
}

static void queue_shrink(queue_t *q)
{
    size_t new_capacity = q->capacity / 2;
    if (q->front <= q->back)
    {
        for (size_t i = q->front, j = 0; i <= q->back; i++, j++)
        {
            q->queue[j] = q->queue[i];
        }
    }
    else
    {
        size_t front_len = q->capacity - q->front;
        for (int i = q->back; i >= 0; i--)
        {
            q->queue[i + front_len] = q->queue[i];
        }
        for (size_t i = q->front, j = 0; i < q->capacity; i++, j++)
        {
            q->queue[j] = q->queue[i];
        }
    }
    q->front = 0;
    q->back = q->size - 1;
    q->capacity = new_capacity;
    q->queue = realloc(q->queue, sizeof(Pessoa) * q->capacity);
}

Pessoa queue_front(queue_t *q)
{
    assert(q->front < q->capacity);
    return q->queue[q->front];
}

void queue_delete(queue_t **q)
{
    free((*q)->queue);
    free(*q);
    *q = NULL;
}

int main()
{
    /*
    o problema realmente estava entre o computador e a cadeira,
    hoje eu refiz tentando refazer do mesmo jeito que eu fiz na prova e consegui imprimir na ordem correta
    porém ao invés de imprimir posição do elemento, imprimi a entrada, na prova eu tentei resolver isto usando
    uma Queue auxiliar para salvar a posição de elemento que então era chamada no While para imprimir a posição
    e a hora de atendimento, isso era muito lento (eu acho), logo eu precisava encontrar uma maneira de salvar a
    pos e a chegada na mesma fila, o que me levou a tentar utilizar uma struct Pessoa, que a primeiro momento não funcionou
    nem na prova nem na versão anteriror que eu mandei nesta atividade, porém após pedir ajuda dos universitários
    fui informado que a maneira que "queria" utilizar a struct eu teria que alterar a struct da Queue para recebe-la
    e consequentemente alterar algumas das funções.
    eu alterei:
        a Struct Queue.             agora tem um ponteiro Pessoa *queue;
        a Função queue_front.       agora é Pessoa queue_front;
        a Função queue_push.        agora recebe Pessoa data;
        a Função queue_initialize.  agora o (*q)->queue = Malloc recebe o tamanho de Pessoa * a capacidade.
        e as funções shrink/expand. agora o Realloc recebe o tamanho de Pessoa * a capacidade.
    
    */

    int n, m, idade, chegada;
    scanf("%d %d", &n, &m);
    queue_t *idosos;
    queue_t *adultos;
    queue_initialize(&idosos);
    queue_initialize(&adultos);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &chegada, &idade);

        Pessoa p;
        p.pos = i + 1;
        p.chegada = chegada;
        if (idade >= 60)
        {
            queue_push(idosos, p);
        }
        else
        {
            queue_push(adultos, p);
        }
    }
    int contador = 1;
    int aux = 0;
    while (aux != n)
    {
        if (!queue_empty(idosos))
        {
            Pessoa p = queue_front(idosos);
            if (p.chegada <= contador)
            {
                printf("%d %d\n", p.pos, contador);
                queue_pop(idosos);
                contador += m;
                aux++;
                continue;
            }
        }

        if (!queue_empty(adultos))
        {
            Pessoa p = queue_front(adultos);
            if (p.chegada <= contador)
            {
                printf("%d %d\n", p.pos, contador);
                queue_pop(adultos);
                contador += m;
                aux++;
                continue;
            }
        }
            contador++;
    }

    return 0;
}
