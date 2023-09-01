 #include <stdio.h>
 #include <math.h>

 #define PI 3.1415926

float Ingresar_Real(void);
float Ingresar_Imag(void);
float Calcular_Modulo(float Real, float Imag);
float Calcular_Fase(float Real, float Imag);
void Print_Polar(float Modulo, float Fase);

 int main (void){
     float Real=Ingresar_Real();
     float Imag=Ingresar_Imag();
     float Modulo=Calcular_Modulo(Real, Imag);
     float Fase=Calcular_Fase(Real, Imag);
     Print_Polar(Modulo, Fase);
 }
 float Ingresar_Real(){
    float Real;
    printf("Ingrese el valor de la parte real:\n");
    scanf("%f", &Real);
    return Real;
 }
 float Ingresar_Imag(){
    float Imag;
    printf("Ingrese el valor de la parte imaginaria:\n");
    scanf("%f", &Imag);
    return Imag;
 }
 float Calcular_Modulo(float Real, float Imag){
    float Modulo;
    Modulo = sqrt(pow(fabs(Real), 2)+pow(fabs(Imag), 2));
    return Modulo;
 }
float Calcular_Fase(float Real, float Imag){
    float Fase;
    Fase=atan2(Imag, Real)*180/PI;
    return Fase;

}
void Print_Polar(float Modulo, float Fase){
    printf("El numero en forma polar es: %f e^j %f", Modulo, Fase);
}