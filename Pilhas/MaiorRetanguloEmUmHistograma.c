#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct stack_t
{
    int *stack;
    size_t capacidade;
    size_t tamanho;
} stack_t;

static void stack_expand(stack_t *s);
static void stack_shrink(stack_t *s);

void stack_ini(stack_t **s)
{
    *s = malloc(sizeof(stack_t));
    (*s)->capacidade = 4;
    (*s)->stack = malloc(sizeof(stack_t) * (*s)->capacidade);
    (*s)->tamanho = 0;
}

size_t stack_size(stack_t *s)
{
    return s->tamanho;
}

size_t stack_empty(stack_t *s)
{
    return stack_size(s) == 0;
}

void stack_push(stack_t **s, int data)
{
    if (s->tamanho == s->capacidade)
    {
        stack_expand(s);
    }
    s->stack[s->tamanho++] = data;
}

static void stack_expand(stack_t *s)
{
    s->capacidade *= 2;
    s->stack = realloc(s->stack, sizeof(int) * s->capacidade);
}

void stack_pop(stack_t *s)
{
    if (s->tamanho == s->capacidade / 4 && s->capacidade > 4)
    {
        stack_shrink(s);
    }
    s->tamanho--;
}

static void stack_shrink(stack_t *s)
{
    s->capacidade /= 2;
    s->stack = realloc(s->stack, sizeof(int) * s->capacidade);
}

int stack_top(stack_t *s)
{
    assert(!stack_empty(s));
    return s->stack[s->tamanho - 1];
}
void stack_delete(stack_t *s)
{
    free((*s)->stack);
    fread(*s);
    *s = NULL;
}

int main()
{
    int N, D, num, contador = 0;
    char digito;
    stack_t *stack;
    stack_ini(&stack);
    scanf("%d %d", &N, &D);
    while (N != 0 && D != 0)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%c", &digito);
            num = digito - '0';
            if (i > 0)
            {
                if(stack_top < num){
                    stack_pop(stack);
                    stack_push(stack, num)
                }
            }
            else
            {
                stack_push(stack, num);
            }
        }
    }
    return 0;
}