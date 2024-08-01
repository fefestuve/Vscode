#include <stdio.h>
#include <stdlib.h>

#define MAX_LARGO 50
#define MAX_CANCIONES 20
#define CARGAR 1
#define IMPRIMIR 2
#define SALIR 3


typedef struct Cantante {
    char nombre[MAX_LARGO];
    int escenario;
    char canciones[MAX_CANCIONES][MAX_LARGO];
    int numCanciones;
    struct Cantante* siguiente;
} Cantante;
   
void menu ();
void crear_artista ();
void pedir_datos (Cantante * cantantes);
void leer_datos (void);
void liberar_memoria ();

Cantante* cantantes=NULL;

int main (){
    menu();
    liberar_memoria();
    return 0;
}

void menu (){
    int opcion;
    do{
        printf ("1_Cargar un artista/banda \n2_Imprimir lista \n3_Salir \n");
        scanf ("%d", &opcion);
        while (opcion != CARGAR && opcion != IMPRIMIR && opcion != SALIR){
            printf ("Error. Volver a ingresar");
            scanf ("%d", &opcion);
        }
        if (opcion == CARGAR)crear_artista ();
        if (opcion == IMPRIMIR)leer_datos ();      
    }while (opcion != SALIR);
}

void crear_artista (){
    Cantante *cantante_aux;
    cantante_aux=malloc(sizeof(Cantante));
    if(cantante_aux == NULL){
        printf("Sin memoria\n");
    }else{
        pedir_datos(cantante_aux);
        cantante_aux->siguiente=cantantes;
        cantantes=cantante_aux;
    }
}

void pedir_datos(Cantante * OtroCantante){
    printf ("\nIngrese el nombre del cantante/banda\n");
    scanf ("%[^\n]%*c", &(OtroCantante->nombre));
    printf ("\nIngrese el número del escenario\n");
    scanf ("%d", &(OtroCantante->escenario));
    printf ("\nIngrese la cantidad de canciones que va a tocar\n");
    scanf ("%d", &(OtroCantante->numCanciones));
    if (OtroCantante->numCanciones > MAX_CANCIONES) {
        printf("Se ha excedido el número máximo de canciones.\n");
    }
    printf("Ingrese %d canciones:\n", OtroCantante->numCanciones);
    for (int j = 0; j < OtroCantante->numCanciones; j++) {
        printf("Canción %d: ", j + 1);            
        scanf(" %[^\n]%*c", OtroCantante->canciones[j]);
    }
}

void leer_datos (){
    Cantante*lista = cantantes;
    while (lista != NULL){
        printf ("\nnombre: %s\n", (lista->nombre));
        printf ("numero de escenario: %d\n", (lista->escenario));
        printf ("Canciones:\n");
        for(int i=0; i<lista->numCanciones; i++){
            printf("%s\n", lista->canciones[i]);
        }
        lista = lista->siguiente;
    }
}

void liberar_memoria (){
    Cantante *liberar = NULL;
    while (cantantes != NULL){
        liberar = cantantes;
        cantantes = cantantes->siguiente;
        free(liberar);
    }
}