#include "grader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void stack_shrink(stack_t *s);

void stack_pop(stack_t *s)
{
    if (s->size == s->capacity / 4 && s->capacity > 4)
    {
        stack_shrink(s);
    }
    s->size--;
}

static void stack_shrink(stack_t *s)
{
    s->capacity /= 2;
    s->stack = realloc(s->stack, sizeof(int) * s->capacity);
}