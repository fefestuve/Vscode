#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void){
    printf("\ningresa los valores del voltaje:\n");
    float ModuloV=Ingresar_Modulo();
    float FaseV=Ingresar_Fase();
    printf("\ningresa los valores de la corriente:\n");
    float ModuloI=Ingresar_Modulo();
    float FaseI=Ingresar_Fase();
    float Frecuencia=Ingresar_Frecuencia();
    float ModuloZ=ModuloV/ModuloI;
    float FaseZ=FaseV-FaseI;
    float Real=Calcular_Real(ModuloZ, FaseZ);
    float Imag=Calcular_Imag(ModuloZ, FaseZ);



}
float Ingresar_Modulo(){
    float Modulo;
    printf("Valor del modulo:");
    scanf("%f", &Modulo);
    return (Modulo*sqrt(2));
}
float Ingresar_Fase(){
    float Fase;
    printf("Valor de la fase:");
    scanf("%f", &Fase);
    return (Fase*sqrt(2));
}
float Ingresar_Frecuencia(){
    float Frecuencia;
    printf("Valor de la frecuencia:");
    scanf("%f", &Frecuencia);
    return Frecuencia;
}
float Calcular_Real(float ModuloZ, float FaseZ){
    float Real;
    Real=cos(FaseZ*PI/180)*ModuloZ;
    return Real;
}
float Calcular_Imag(float ModuloZ, float FaseZ){
    float Imag;
    Imag=sin(FaseZ*PI/180)*ModuloZ;
    return Imag;
}