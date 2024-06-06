/*es como una estructura, pero como que le podes asignar funciones y esas cosas.
podes crear varios objetos de las mismas clases, asi que comparten las funciones.
Los atributos por defecto son privados, asi que solo se pueden acceder desde la class
*/
#include <iostream>
class puntos{
    public:
        int x;
        int y;
}punto1;

int main(void){
    punto1.x=10;
    punto1.y=5;

    std::cout << "X es " <<punto1.x <<std::endl;
    std::cout << "Y es " <<punto1.y <<std::endl;
}