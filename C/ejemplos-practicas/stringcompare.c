#include <stdio.h>
char stringcompare(char[], char[]);

int main (void){
    char str1[]="hola";
    char str2[]="holas";

    char igual=stringcompare(str1, str2);
    if(0==igual){
        printf("son iguales");
    }
    else{
        printf("son diferentes");
    }
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