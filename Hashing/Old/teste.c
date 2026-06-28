#include<stdio.h>

void init(int arr[], int tam)
{   
    int i;
    for(i = 0; i < tam; i++)
        arr[i] = -1;
}

void insert(int arr[], int value, int tam)
{   
    int key = value % tam;
    
    if(arr[key] == -1)
    {   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {   

        printf("Unable to insert %d\n",value);
    }
}

void print()
{
    int i;
    for(i = 0; i < tam; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

int main()
{
    int n, tam, valor;
    scanf("%d %d", &n, &tam);
    int arr[tam];
    init(arr[], tam);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &valor);
        insert(arr[], valor, tam);
    }
    
    return 0;
}
