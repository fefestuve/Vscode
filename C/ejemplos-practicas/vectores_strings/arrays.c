#include <stdio.h>
#define CANT_MAX 10

int main (void){
    
    int temp[CANT_MAX];
    for(int i=0; i<CANT_MAX;i++){
        printf("Ingresa la temperatura %d: ", i+1);
        scanf("%d", &temp[i]);
    }
    
    for(int i=0; i<CANT_MAX;i++){
        printf("la temperatura %d es de: %d\n", i+1, temp[i]);
    }

    return 0;
}