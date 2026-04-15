#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct stack_t
{
    char *stack;
    size_t capacidade;
    size_t tamanho;
} stack_t;

static void stack_expand(stack_t *s);
static void stack_shrink(stack_t *s);

void stack_ini(stack_t **s)
{
    *s = malloc(sizeof(stack_t));
    (*s)->capacidade = 8;
    (*s)->stack = malloc(sizeof(char) * (*s)->capacidade);
    (*s)->tamanho = 0;
}

size_t stack_size(stack_t *s)
{
    return s->tamanho;
}

size_t stack_empty(stack_t *s)
{
    return s->tamanho == 0;
}

void stack_push(stack_t *s, char data)
{
    if (s->tamanho == s->capacidade)
    {
        stack_expand(s);
    }
    s->stack[s->tamanho++] = data;
}

void stack_pop(stack_t *s)
{
    if (s->tamanho > 0)
    {
        s->tamanho--;
        if (s->tamanho <= s->capacidade / 4 && s->capacidade > 8)
        {
            stack_shrink(s);
        }
    }
}

char stack_top(stack_t *s)
{
    assert(!stack_empty(s));
    return s->stack[s->tamanho - 1];
}

static void stack_expand(stack_t *s)
{
    s->capacidade *= 2;
    s->stack = realloc(s->stack, sizeof(char) * s->capacidade);
}

static void stack_shrink(stack_t *s)
{
    s->capacidade /= 2;
    s->stack = realloc(s->stack, sizeof(char) * s->capacidade);
}

void stack_delete(stack_t *s)
{
    free(s->stack);
    free(s);
}

int main()
{
    int N, D;
    char numero[100010];

    while (1)
    {
        scanf("%d %d", &N, &D);
        if (N == 0 && D == 0)
            break;

        scanf("%s", numero);

        stack_t *stack;
        stack_ini(&stack);

        int apagar = D;
        for (int i = 0; i < N; i++)
        {
            char atual = numero[i];

            while (!stack_empty(stack) && apagar > 0 && stack_top(stack) < atual)
            {
                stack_pop(stack);
                apagar--;
            }
            stack_push(stack, atual);
        }

        while (apagar > 0)
        {
            stack_pop(stack);
            apagar--;
        }

        for (size_t i = 0; i < stack_size(stack); i++)
        {
            putchar(stack->stack[i]);
        }
        putchar('\n');

        stack_delete(stack);
    }

    return 0;
}
