#include <stdio.h>
#define cant 30
char stringcompare(char[], char[]);
void ingresar_strings(char[], char[]);

int main (void){
    char str1[cant];
    char str2[cant];
    ingresar_strings(str1, str2);

    char igual=stringcompare(str1, str2);
    if(0==igual){
        printf("son iguales");
    }
    else{
        printf("son diferentes");
    }
}
void ingresar_strings(char str1[], char str2[]){
    printf("ingresa el primer string: ");
    gets(str1);
    printf("ingresa el segundo string: ");
    gets(str2);
}
char stringcompare(char str1[], char str2[]){
    int idx=0;
    while(str1[idx]!=0 || str2[idx]!=0){
        if(str1[idx]!=str2[idx]){
            return 1;
        }
        idx++;
    }
    return 0;
}