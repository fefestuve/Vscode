#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float Ingresar_Real();
float Ingresar_Imag();
char Ingresar_Formato();
void Print_Cartesiana(float RealTotal, float ImagTotal);
float Calcular_Modulo(float RealTotal, float ImagTotal);
float Calcular_Fase(float RealTotal, float ImagTotal);
void Print_Polar(float Modulo, float Fase);

int main (void){
    printf("ingresa los valores del primer numero");
    float Real1=Ingresar_Real();
    float Imag1=Ingresar_Imag();
    printf("ingresa los valores del segundo numero");
    float Real2=Ingresar_Real();
    float Imag2=Ingresar_Imag();
    char Formato=Ingresar_Formato();
    float RealTotal=Real1+Real2;
    float ImagTotal=Imag1+Imag2;
    if(Formato==0){
        Print_Cartesiana(RealTotal, ImagTotal);
    }
    else if(Formato==1){
        float Modulo=Calcular_Modulo(RealTotal, ImagTotal);
        float Fase=Calcular_Fase(RealTotal, ImagTotal);
        Print_Polar(Modulo, Fase);
    }
}
float Ingresar_Real(){
    float Real;
    printf("\nvalor de la parte real:");
    scanf("%f", &Real);
    return Real;
}
float Ingresar_Imag(){
    float Imag;
    printf("\nvalor de la parte imaginaria:");
    scanf("%f", &Imag);
    return Imag;
}
char Ingresar_Formato(){
    char Formato;
    printf("\ningresa 1 para obtener la respuesta en formato polar o 0 para cartesiana:");
    scanf(" %c", &Formato);
    return Formato;
}
void Print_Cartesiana(float RealTotal, float ImagTotal){
    if(ImagTotal>=0){
        printf("El numero en forma cartesiana es: %f+j%f", RealTotal, ImagTotal);
    }
    else{
        printf("El numero en forma cartesiana es: %f-j%f", RealTotal, ImagTotal);
    }
}
float Calcular_Modulo(float RealTotal, float ImagTotal){
    float Modulo;
    Modulo = sqrt(pow(fabs(RealTotal), 2)+pow(fabs(ImagTotal), 2));
    return Modulo;
}
float Calcular_Fase(float RealTotal, float ImagTotal){
    float Fase;
    Fase=atan2(ImagTotal, RealTotal)*180/PI;
    return Fase;
}
void Print_Polar(float Modulo, float Fase){
    printf("El numero en forma polar es: %f e^j %f", Modulo, Fase);
}