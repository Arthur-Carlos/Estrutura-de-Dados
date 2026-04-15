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
    stack_t *stack;
    stack_initialize(&stack);
    for (int i = 0; i < 100000; i++)
    {
        stack_push(stack, i);
    }
    while (!stack_empty(stack))
    {
        printf("%d ", stack_top(stack));
        stack_pop(stack);
    }
    printf("\n");
    stack_delete(&stack);
    return 0;
}