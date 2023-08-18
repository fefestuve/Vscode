#include <stdio.h>
#include <stdint.h>

int main (void)
{
    // declarar variables
    int numero;
    int cantidad;
    uint8_t devuelta;
    do
    {
        // pedir datos
        printf("escribi un numero y te dire la tabla\n");
        scanf("%d", &numero);
        printf("escribi cuantos multiplos queres\n");
        scanf("%d", &cantidad);
        printf("\n");
        // printear los resultados
        for (int i = 1; i <= cantidad; i++)
        {
            printf("%d x %d = %d\n", numero, i, i * numero);
        }
        // hacerlo de vuelta o no
        printf("queres hacerlo de vuelta? escribi 1 para si y 0 para no\n");
        scanf("%d", &devuelta);
    } while (devuelta == 1);
}