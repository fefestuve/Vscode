/*herencia es una propuedad de la programacion orientada a objetos, una clase adopta atributos de otra clase
Herencia simple o multiple, heredas de solo una clase o de más
Hay clases que no son instanciadas, solo son heredadas, y se llaman abstractas
*/

#include <iostream>
using namespace std;

class animal{
    public:
        void come();
        void duerme();
        void respira();
};
void animal::come(void){}
void animal::duerme(void){}
void animal::respira(void){}

class mamifero: public animal{
    public:
        int tipo_sangre_caliente;
        void amamantar();
};
void mamifero::amamantar(void){}

class perro: public mamifero{
    public:
        int tipo_pelo;
        void ladrido();
        void trucos();
};
void perro::ladrido(void){}
void perro::trucos(void){}

class ovejero: public perro{
    public:
        bool pelo_largo;
        int tatuaje_POA;
        int displasia;
};

int main(void){
    ovejero Rintin= new ovejero;
    (*Rintin).ladrido();
    return 0;
}

