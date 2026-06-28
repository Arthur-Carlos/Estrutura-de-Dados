#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000

typedef struct query
{
    int pos;
    int valor;
} query;

query queries[MAX];

int main(){
    int qtde, tam;
    scanf("%d %d", &qtde, &tam);
    int table[tam];
    for (int i = 0; i < qtde; i++)
    {
        scanf("%d", &queries[i].valor);
        queries[i].pos = i+1;
    }

    for (int i = 0; i < qtde; i++)
    {
        printf("%d %d \n", queries[i].valor, queries[i].pos);
    }
    
    return 0;
}
