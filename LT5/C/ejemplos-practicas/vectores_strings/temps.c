#include <stdio.h>
#define cant 10
#define rangomax 20
#define rangomin 10

void ingresar_temps(int[]);
int calcular_prom(int[]);
int calcular_min(int[]);
int calcular_max(int[]);
int calcular_rango(int[]);
void print_resultados(int, int, int, int);


int main(void){
    int temp[cant];
    ingresar_temps(temp);
    int prom=calcular_prom(temp);
    int min=calcular_min(temp);
    int max=calcular_max(temp);
    int rango=calcular_rango(temp);
    print_resultados(prom, min, max, rango);

}
void ingresar_temps(int temp[]){
    for(int i=0; i<cant; i++){
        printf("ingresa la temperatura N%d: ",i+1);
        scanf("%d", &temp[i]);
    }
}
int calcular_prom(int temp[]){
    int prom=0;
    for(int i=0; i<cant; i++){
        prom+=temp[i];
    }
    prom/=cant;
    return prom;
}
int calcular_min(int temp[]){
    int min=temp[0];
    for(int i=0; i<cant; i++){
        if(temp[i]<min){
            min=temp[i];
        }
    }
    return min;
}
int calcular_max(int temp[]){
    int max=temp[0];
    for(int i=0; i<cant; i++){
        if(temp[i]>max){
            max=temp[i];
        }
    }
    return max;
}
int calcular_rango(int temp[]){
    int rango=0;
    for(int i=0; i<cant; i++){
        if(temp[i]>=rangomin && temp[i]<=rangomax){
            rango++;
        }
    }
    return rango;
}
void print_resultados(int prom, int min, int max, int rango){
    printf("el promedio de temperaturas es de: %d\n", prom);
    printf("la temperatura minima fue de: %dC y la maxima de: %dC\n", min, max);
    printf("hay %d temperaturas entre %d y %d\n", rango, rangomin, rangomax);
}