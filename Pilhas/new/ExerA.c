// Apagando e Ganhando
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct stack_t
{
    int *stack;
    size_t capacity;
    size_t size;
} stack_t;

void stack_initialize(stack_t **s)
{
    *s = malloc(sizeof(stack_t));
    (*s)->capacity = 4;
    (*s)->stack = malloc(sizeof(int) * (*s)->capacity);
    (*s)->size = 0;
}

size_t stack_size(stack_t *s)
{
    return s->size;
}

bool stack_empty(stack_t *s)
{
    return stack_size(s) == 0;
}

static void stack_expand(stack_t *s)
{
    s->capacity *= 2;
    s->stack = realloc(s->stack, sizeof(int) * s->capacity);
}

void stack_push(stack_t *s, int data)
{
    if (s->size == s->capacity)
    {
        stack_expand(s);
    }
    s->stack[s->size++] = data;
}

static void stack_shrink(stack_t *s)
{
    s->capacity /= 2;
    s->stack = realloc(s->stack, sizeof(int) * s->capacity);
}

void stack_pop(stack_t *s)
{
    if (s->size == s->capacity / 4 && s->capacity > 4)
    {
        stack_shrink(s);
    }
    s->size--;
}

int stack_top(stack_t *s)
{
    assert(!stack_empty(s));
    return s->stack[s->size - 1];
}

void stack_delete(stack_t **s)
{
    free((*s)->stack);
    free(*s);
    *s = NULL;
}

int main(void)
{
    int N, D;
    char num[100001];
    while (1)
    {
        scanf("%d %d", &N, &D);
        if (N == 0 && D == 0)
        {
            break;
        }
        scanf("%s", num);
        stack_t *stack;
        stack_initialize(&stack);
        int apagar = D;
        for (int i = 0; i < N; i++)
        {
            char atual = num[i];
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
        stack_delete(&stack);
    }
    return 0;
}