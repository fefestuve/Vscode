/*se supone que es retrocompatible con c, todo lo que hago en c lo puedo hacer en c++ pero ahora 
tambien hay clases y objetos. El nucleo es mucho mas grande, todas las cosas para compilarlo y eso. asi que C sigue
siedo mas usado en sistemas embebidos
*/
#include <iostream> //como el stdio.h
using namespace std; //por alguna razon simplifica el resto, si ve palabras asume que son del estandar

int main(void){ //normal
    cout << "Hola mundo" << endl; //a cout le enviamos Hola mundo y despues endl seria como el \n
    return 0;
}
//puedo no agregar el using namespace std y escribo std::cout << "Hola mundo" <<std::endl;
//tambien puedo usar stdio.h y printf como siempre

//si tengo una variable numero puedo escribir cout <<"el valor es "<<numero<<endl;
//cin>>numero ya sabe de que tipo de variable es
//existe variable booleana (claramente no ocupa un bit)
//hay datos strings