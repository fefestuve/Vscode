#include <stdio.h>
#define PI 3.1415926
float Real(void);
float Imaginario(void);
float Frecuencia(void);
float Calcular(float, float);
void Imprimir(float, float, float);

int main(void){
    float real, imaginario, frecuencia, valorComponente;

    real=Real();
    imaginario=Imaginario();
    frecuencia=Frecuencia();
    
    valorComponente=Calcular(imaginario, frecuencia);
    Imprimir(valorComponente, real, imaginario);

}
float Real(void){
    float real;
    printf("ingresa el valor real (ohm):\n");
    scanf("%f", &real);
    return real;
}
float Imaginario(void){
    float imaginario;
    printf("\ningresa el valor imaginario (ohm):\n");
    scanf("%f", &imaginario);
    return imaginario;
}
float Frecuencia(void){
    float frecuencia;
    printf("\ningresa el valor de la frecuencia (Hz):\n");
    scanf("%f", &frecuencia);
    return frecuencia;
}
float Calcular(float imaginario,float frecuencia){
    float valorComponente=0;
    if(imaginario>0){
        valorComponente=imaginario/(2*PI*frecuencia);
    }
    if(imaginario<0){
        valorComponente=-1/(2*PI*imaginario*frecuencia);
    }
    return valorComponente;
}
void Imprimir(float valorComponente, float real, float imaginario){
    if(imaginario>0){
        printf("el valor del inductor es de: %fH\n", valorComponente);
    }
    if(imaginario<0){
        printf("el valor del capacitor es de: %fF\n", valorComponente);
    }
    printf("el valor de la resistencia es de: %f Ohms\n", real);
}
