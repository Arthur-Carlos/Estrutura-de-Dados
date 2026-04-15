#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 200000

typedef struct {
    char *data;
    int top;
    int capacity;
} stack_t;

void stack_init(stack_t *s, int cap) {
    s->data = malloc(cap * sizeof(char));
    s->top = -1;
    s->capacity = cap;
}

int stack_empty(stack_t *s) {
    return s->top == -1;
}

char stack_top(stack_t *s) {
    return s->data[s->top];
}

void stack_push(stack_t *s, char c) {
    s->data[++s->top] = c;
}

char stack_pop(stack_t *s) {
    return s->data[s->top--];
}

void stack_free(stack_t *s) {
    free(s->data);
}

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int is_op(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

int main() {
    char expr[MAX];
    fgets(expr, MAX, stdin);

    stack_t st;
    stack_init(&st, MAX);

    char number[32];
    int nidx = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (isspace(c)) continue;

        // Construção de número
        if (isdigit(c)) {
            number[nidx++] = c;
            continue;
        }

        // Finaliza número antes de operador/parênteses
        if (nidx > 0) {
            number[nidx] = '\0';
            printf("%s ", number);
            nidx = 0;
        }

        if (c == '(') {
            stack_push(&st, c);
        }
        else if (c == ')') {
            while (!stack_empty(&st) && stack_top(&st) != '(') {
                printf("%c ", stack_pop(&st));
            }
            stack_pop(&st); // remove '('
        }
        else if (is_op(c)) {
            while (!stack_empty(&st) && is_op(stack_top(&st)) &&
                   prec(stack_top(&st)) >= prec(c)) {
                printf("%c ", stack_pop(&st));
            }
            stack_push(&st, c);
        }
    }

    // Flush do último número
    if (nidx > 0) {
        number[nidx] = '\0';
        printf("%s ", number);
    }

    // Desempilha resto
    while (!stack_empty(&st)) {
        char op = stack_pop(&st);
        if (op != '(')
            printf("%c ", op);
    }

    stack_free(&st);
    return 0;
}
