#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float Ingresar_Modulo();
float Ingresar_Fase();
float Calcular_Real(float Modulo, float Fase);
float Calcular_Imag(float Modulo, float Fase);
void Print_Cartesiana(float Real, float Imag);



int main(void){
    float Modulo=Ingresar_Modulo();
    float Fase=Ingresar_Fase();
    float Real=Calcular_Real(Modulo, Fase);
    float Imag=Calcular_Imag(Modulo, Fase);
    Print_Cartesiana(Real, Imag);
}
float Ingresar_Modulo(){
    float Modulo;
    printf("Ingrese el valor del modulo:\n");
    scanf("%f", &Modulo);
    return Modulo;
}
float Ingresar_Fase(){
    float Fase;
    printf("ingrese el valor de la fase:\n");
    scanf("%f", &Fase);
    return Fase;
}
float Calcular_Real(float Modulo, float Fase){
    float Real;
    Real=cos(Fase*PI/180)*Modulo;
    return Real;
}
float Calcular_Imag(float Modulo, float Fase){
    float Imag;
    Imag=sin(Fase*PI/180)*Modulo;
    return Imag;
}
void Print_Cartesiana(float Real, float Imag){
    if(Imag>=0){
        printf("El numero en forma cartesiana es: %f+j%f", Real, Imag);
    }
    else{
        printf("El numero en forma cartesiana es: %f-j%f", Real, Imag);
    }
    
}