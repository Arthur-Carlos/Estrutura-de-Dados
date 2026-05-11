#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int prazo;
    int valor;
} Curso;

int *aux;

int find_set(int x) {
    if (aux[x] != x)
        aux[x] = find_set(aux[x]);
    return aux[x];
}

void union_set(int x, int y) {
    aux[x] = y;
}

int compara_cursos(const void *a, const void *b) {
    Curso *ca = (Curso*)a;
    Curso *cb = (Curso*)b;
    return cb->valor - ca->valor;
}

int main() {
    int cursos, semanas;
    scanf("%d %d", &cursos, &semanas);

    Curso *lista = malloc(cursos * sizeof(Curso));
    for (int i = 0; i < cursos; i++) {
        scanf("%d %d", &lista[i].prazo, &lista[i].valor);
    }

    qsort(lista, cursos, sizeof(Curso), compara_cursos);

    aux = malloc((semanas + 2) * sizeof(int));
    for (int i = 0; i <= semanas + 1; i++) {
        aux[i] = i;
    }

    int totalConhecimento = 0;

    for (int i = 0; i < cursos; i++) {
        int prazo = lista[i].prazo;
        int valor = lista[i].valor;

        int limite = prazo < semanas ? prazo : semanas;

        int semanaOcupada = find_set(limite);

        if (semanaOcupada > 0) {
            totalConhecimento += valor;
            union_set(semanaOcupada, semanaOcupada - 1);
        }
    }

    printf("%d\n", totalConhecimento);

    free(lista);
    free(aux);
    return 0;
}
