#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool list_is_rotation(list_t *l1, list_t *l2)
{
    if (list_empty(l1) && list_empty(l2))
    {
        return true;
    }
    if (list_size(l1) != list_size(l2))
    {
        return false;
    } // as mesmas verificações que eu fiz na prova, porem eu removi a de ver se somente uma delas era vazia
    list_node_t *atual1 = l1->head;
    list_node_t *atual2 = l2->head;
    size_t tam1 = list_size(l1);
    for (size_t i = 0; i < tam1; i++)
    {
        if (atual1->data == atual2->data)
        {
            list_node_t *aux1 = atual1;
            list_node_t *aux2 = atual2;
            size_t contador = 0; // adicionei um contador que vai tentar percorrer a L1
            while (contador < tam1)
            {
                if (aux1->data != aux2->data)
                {
                    break;
                }
                if (aux1->next != NULL)
                {
                    aux1 = aux1->next;
                }
                else
                {
                    aux1 = l1->head; // caso o prox elemento seja o NULL, o aux1 vai receber apontar para a cabeça, na primeira iteraçao isso nao vai alterar nada, mas nas proximas isso sera importante
                }
                aux2 = aux2->next;
                contador++; // sempre que L1 for igual a L2 ele aumenta
            }
            if (contador == tam1)
            {
                return true; // e no final, caso ele tenha aumentado ate o tamanho de L1 (ou seja, todos os elementos sao iguais), ele aceita
            }
        }
        atual1 = atual1->next; // caso contrario, ele "rola" o L1 e como o contador vai de 0 ate o tamanho de L1, ele vai chegar no final de L1 e continuar ate dar a volta
    }
    return false; // Um chute educado, brincadeiras a parte, caso tudo falhe, ele recusa.
}