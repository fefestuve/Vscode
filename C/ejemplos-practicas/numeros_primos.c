//Este codigo imprime todos los números primos entre un número mínimo y uno máximo
#include <stdio.h>

int prime(int number);

int main(void)
{
    int min;
    do
    {
        printf("Minimo: ");
        scanf("%d", &min);
    }
    while (min < 1);

    int max;
    do
    {
        printf("Maximo: ");
        scanf("%d", &max);
    }
    while (min >= max); 

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

int prime(int i)
{
    int pepe =1;
    if(i==1){
        pepe=0;
        return pepe;
    }
    for (int j = 2; j < i; j++){

        if (i % j == 0){
            pepe = 0;
            return pepe;
        }
    }
    return pepe;
}
