#include <stdio.h>

char ingresar_equipo(void);
char ingresar_punto(void);
void sumar_puntos (char valorDelPunto, int *triples, int *dobles, int *simples);
void sumar_anotaciones(char equipo,int *puntajeActual1, int *puntajeActual2, char valorDelPunto);
void print_totales(int triples, int puntosTotales, int dobles, int simples, int puntajeActual1, int puntajeActual2);


int main (void){
    char equipo;
    char valorDelPunto;
    int simples=0;
    int dobles=0;
    int triples=0;
    int puntajeActual1=0;
    int puntajeActual2=0;
    int puntosTotales=0;

    do{
    equipo = ingresar_equipo();
    if(equipo==0){
        print_totales(triples, puntosTotales, dobles, simples, puntajeActual1, puntajeActual2);
        return 0;
    }
    valorDelPunto=ingresar_punto();
    sumar_puntos(valorDelPunto, &triples, &dobles, &simples);
    sumar_anotaciones(equipo, &puntajeActual1, &puntajeActual2, valorDelPunto);
    puntosTotales++;
    }while(equipo!=0);
    
}
char ingresar_equipo(void){
    char equipo;
    do{
        printf("ingresa el equipo que hizo un punto\n");
        printf("Puede ser 1 o 2, escribe 0 para finalizar el programa\n");
        scanf("%d", &equipo);
    }while(equipo != 1 && equipo!=2 && equipo!= 0);
    return equipo;
}
char ingresar_punto(void){
    char valorDelPunto;
    do {
      printf("ingresa el valor del punto\n");
      scanf("%d", &valorDelPunto);
    }while(!(valorDelPunto > 0 && valorDelPunto < 4));
    return valorDelPunto;
}
void sumar_puntos (char valorDelPunto, int *triples, int *dobles, int *simples){
  switch (valorDelPunto) {
      case 1:
        *simples +=1;
        break;
      case 2:
        *dobles +=1; 
        break;
      case 3:
        *triples +=1;
        break;
    }
}
void sumar_anotaciones(char equipo,int *puntajeActual1, int *puntajeActual2, char valorDelPunto){
  if (equipo == 1) {
      *puntajeActual1 += valorDelPunto;
    } else if (equipo == 2) {
      *puntajeActual2 += valorDelPunto;
    }
}
void print_totales(int triples, int puntosTotales, int dobles, int simples, int puntajeActual1, int puntajeActual2){
  int porcentajetriples = triples * 100 / puntosTotales;
  int porcentajedobles = dobles * 100 / puntosTotales;
  int porcentajesimples = simples * 100 / puntosTotales;
  printf("El equipo 1 hizo en total %d puntos\n", puntajeActual1);
  printf("El equipo 2 hizo en total %d puntos\n", puntajeActual2);
  printf("En el partido hubo %d%% de triples, ", porcentajetriples);
  printf("%d%% de dobles, ", porcentajedobles);
  printf("%d%% de simples\n", porcentajesimples);
  if (puntajeActual1 > puntajeActual2) {
    printf("El ganador es el equipo 1");
  } else if (puntajeActual2 > puntajeActual1) {
    printf("El ganador es el equipo 2");
  } else {
    printf("Hubo un empate");
  }
}