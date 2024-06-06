//diferentes formas de inicializar variables

#include <iostream>
//si incluyo string existen
#include <string>
//con esta puedo manipular algunas cosas de i/o
#include <iomanip>
/*
algunas de las funciones son
*/

using namespace std;

int main(){
    int x = 0;
    int y (0);
    int z {0};

    //automaticamente decide que tipo de variable tiene que ser.
    auto pepe = x;
    decltype(pepe) variable;
    //deberian usarse solo cuando no haya otra forma de lograrlo o cuando ayuda a entenderse mejor.

    int ingresado;
    cin>>ingresado;
    cout<<"el valor ingresado es: "<<hex<<ingresado<<endl;
    //puedo usar hex, dec o oct para decidir en que formato decirlo

    string mystring;
    mystring = "esto es un string";
    cout << mystring;
    return 0;
}
