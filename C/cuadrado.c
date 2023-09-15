#include <stdio.h>


int main(void){
    printf("lado:\n");
    int lado;
    scanf("%d", &lado);

    for(int i=0; i<lado; i++){
        for(int j=0; j<lado; j++){
            printf("#");
        }
        printf("\n");
    }
}