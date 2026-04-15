#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "grader.h"

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
