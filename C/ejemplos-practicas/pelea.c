#include <stdio.h>

#define LONG_NOMBRE 30
#define CANT_DANIOS 3
#define CANT_PODERES 3

typedef struct{
    char nombre[LONG_NOMBRE];
    int puntos;
}atributos_t;

typedef struct{
    char nombre[LONG_NOMBRE];
    int vida;
    atributos_t danios[CANT_DANIOS];
    atributos_t poderes[CANT_PODERES];
}monster_t;

int pelea(monster_t monsters [] ,int monster1,int monster2){
    int ataque1, defensa1, puntaje1;
    int ataque2, defensa2, puntaje2;
    printf("Jugador 1:\n ");
    printf("Elige un ataque: escribe 1 para %s, 2 para %s o 3 para %s\n", monsters[monster1].danios[0].nombre, monsters[monster1].danios[1].nombre, monsters[monster1].danios[2].nombre);
    scanf("%d", &ataque1);
    printf("Elige una defensa: escribe 1 para %s, 2 para %s o 3 para %s\n", monsters[monster1].poderes[0].nombre, monsters[monster1].poderes[1].nombre, monsters[monster1].poderes[2].nombre);
    scanf("%d", &defensa1);

    printf("\n Jugador 2:");
    printf("Elige un ataque: escribe 1 para %s, 2 para %s o 3 para %s\n", monsters[monster2].danios[0].nombre, monsters[monster2].danios[1].nombre, monsters[monster2].danios[2].nombre);
    scanf("%d", &ataque2);
    printf("Elige un defensa: escribe 1 para %s, 2 para %s o 3 para %s\n", monsters[monster2].poderes[0].nombre, monsters[monster2].poderes[1].nombre, monsters[monster2].poderes[2].nombre);
    scanf("%d", &defensa2);

    puntaje1=monsters[monster1].danios[ataque1].puntos;
    puntaje1*=(monsters[monster2].poderes[defensa2].puntos)/100;
    puntaje2=monsters[monster2].danios[ataque2].puntos;
    puntaje2*=monsters[monster1].poderes[defensa1].puntos;

    if(puntaje1>puntaje2){
        monsters[monster2].vida -=puntaje1;
        return monster1;
    }else{
        monsters[monster1].vida -=puntaje2;
        return monster2;
    }
}
