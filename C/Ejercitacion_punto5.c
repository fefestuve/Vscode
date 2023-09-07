#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float Ingresar_Modulo();
float Ingresar_Fase();
float Ingresar_Frecuencia();
float Calcular_Real(float ModuloZ, float FaseZ);
float Calcular_Imag(float ModuloZ, float FaseZ);
float Calcular_Ind(float Imag, float Frecuencia);
float Calcular_Cap(float Imag, float Frecuencia);
void Print_Inductor(float Real, float Imag, float Ind);
void Print_Capacitor(float Real, float Imag, float Cap);
void Print_Resistencia(float Real);

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
    if (Imag>0){
        float Ind = Calcular_Ind(Imag, Frecuencia);
        Print_Inductor(Real, Imag, Ind);
    }
    else if(Imag<0){
        float Cap = Calcular_Cap(Imag, Frecuencia);
        Print_Capacitor(Real, Imag, Cap);
    }
    else{
        Print_Resistencia(Real);
    }


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
float Calcular_Ind(float Imag, float Frecuencia){
    float Ind;
    Ind = Imag/(2*PI*Frecuencia);
    return Ind;
}
float Calcular_Cap(float Imag, float Frecuencia){
    float Cap;
    Cap = -1/(2*PI*Imag*Frecuencia);
    return Cap;
}
void Print_Inductor(float Real, float Imag, float Ind){
    printf("La impedancia es de %f + j%f, el valor del inductor es de %fH", Real, Imag, Ind);
}
void Print_Capacitor(float Real, float Imag, float Cap){
    printf("La impedancia es de %f - j%f, el valor del capacitor es de %fF", Real, Imag, Cap);
}
void Print_Resistencia(float Real){
    printf("La impedancia solo tiene parte real, la resistencia es de %fohms", Real);
}