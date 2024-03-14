#include <stdio.h>

union numeros{
    float var;
    unsigned char vect[4];
    struct{
        unsigned int signo : 1;
        unsigned int exponente : 8;
        unsigned int mantisa : 23;
    }bits;
};

int main(void){
    union numeros numero;
    printf("Ingresa un numero \n");
    scanf("%f",&numero.var);
    printf("El numero que ingresaste esta guardado en la memoria como 0x");
    for (int i = 3; i >= 0; i--){
        printf("%x|",numero.vect[i]);
    }
    printf(" en hexadecimal\n");
}