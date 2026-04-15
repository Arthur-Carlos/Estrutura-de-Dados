#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "grader.h"

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