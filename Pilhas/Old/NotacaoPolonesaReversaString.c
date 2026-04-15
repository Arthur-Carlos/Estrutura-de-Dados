#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 200000

int prec(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int is_op(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main()
{
    char expr[MAX];
    fgets(expr, MAX, stdin);

    char stack[MAX];
    int top = -1;

    char number[32];
    int nidx = 0;

    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];

        if (isspace(c))
            continue;

        if (isdigit(c))
        {
            number[nidx++] = c;
            continue;
        }

        if (nidx > 0)
        {
            number[nidx] = '\0';
            printf("%s ", number);
            nidx = 0;
        }

        if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                printf("%c ", stack[top--]);
            }
            top--;
        }
        else if (is_op(c))
        {
            while (top >= 0 && is_op(stack[top]) && prec(stack[top]) >= prec(c))
            {
                printf("%c ", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    if (nidx > 0)
    {
        number[nidx] = '\0';
        printf("%s ", number);
    }

    while (top >= 0)
    {
        if (stack[top] != '(')
            printf("%c ", stack[top]);
        top--;
    }

    return 0;
}
