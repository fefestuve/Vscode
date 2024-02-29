#include <stdio.h>

void ingresar_numeros(int, int[]);
void ordenar(int, int[]);
void print_ordenado(int, int[]);

int main(void){
    printf("ingresa la cantidad de numeros: ");
    int cant;
    scanf("%d", &cant);
    int numeros[cant];
    ingresar_numeros(cant, numeros);
    ordenar(cant, numeros);
    print_ordenado(cant, numeros);

}
void ingresar_numeros(int cant, int numeros[]){
    for(int i=0; i<cant; i++){
        printf("ingresa el numero %d: ", i+1);
        scanf("%d", &numeros[i]);
    }
}
void ordenar(int cant, int numeros[]){
    int extra;
    int index;
    for(int i=0; i<cant; i++){
        int mayor=0;
        for(int j=i; j<cant; j++){
            if(numeros[j]>mayor){
                mayor=numeros[j];
                index=j;
            }
        }
        extra=numeros[i];
        numeros[i]=numeros[index];
        numeros[index]=extra;
    }
}
void print_ordenado(int cant, int numeros[]){
    for(int i=0; i<cant; i++){
        printf("%d - ", numeros[i]);
    }
}