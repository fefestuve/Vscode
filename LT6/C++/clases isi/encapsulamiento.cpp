#include <iostream>

using namespace std;
/*Puedo inicializar los valores de una struct o clase usando parentesis o llaves.
si quiero definir las variables como locales en otra funcion tengo que ponerle nombre a la clase.
si tengo un metodo que se llama igual que la clase, al llamar la clase se ejecuta automaticamente el metodo tambien.
Hacer esto es un constructor.
Existen los destructores, al usar el cosito este~, se ejecutan al liberar de la memoria a la clase(anda a saber).
Hacer 2 metodos con mismo nombre pero diferentes parametros se llama polimorfismo, lo puedo usar con constructores
y con cualquier otro metodo*/
class punto{
    public:
        int x;
        int y;
        char nombre[30];
        punto(int x1, int y1){
            x=x1;
            y=y1;
            cout<<"punto creado\n";
        }
        punto(void){
            x=0;
            y=0;
            cout<<"punto creado\n";
        }
        void imprimir(){

        }
};

int main(){
    class punto punto1(2, 3), punto2();
    cout<<punto1.x<<endl;
    cout<<punto1.y<<endl;
    cout<<punto1.nombre<<endl;

}