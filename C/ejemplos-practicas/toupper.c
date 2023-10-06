#include <stdio.h>
void mayusculas(char[]);

int main(void){
    char str[]="Hola";

    mayusculas(str);

    printf("%s", str);
}

void mayusculas(char str[]){
    for(int i=0; str[i]!=0; i++){
        if(str[i]>=97 && str[i]<=122){
            str[i]-=32;
        }
    }
}