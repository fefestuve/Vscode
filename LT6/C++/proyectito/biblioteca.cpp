#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase base para Libro
class Libro {
protected:
    string titulo;
    string autor;
    string ISBN;
    bool disponible;

public:
    Libro(string t, string a, string i) : titulo(t), autor(a), ISBN(i), disponible(true) {}
    virtual ~Libro() {}

    virtual void mostrarInfo() const {
        cout << "Titulo: " << titulo << ", Autor: " << autor << ", ISBN: " << ISBN << ", Disponible: " << (disponible ? "Sí" : "No") << endl;
    }

    friend ostream& operator<<(ostream& os, const Libro& libro) {
        libro.mostrarInfo();
        return os;
    }

    bool estaDisponible() const { return disponible; }
    void prestar() { disponible = false; }
    void devolver() { disponible = true; }
};

// Clase derivada para LibroDigital
class LibroDigital : public Libro {
private:
    string formato;
    int tamanoArchivo;

public:
    LibroDigital(string t, string a, string i, string f, int ta) 
        : Libro(t, a, i), formato(f), tamanoArchivo(ta) {}

    void mostrarInfo() const override {
        Libro::mostrarInfo();
        cout << "Formato: " << formato << ", Tamaño de Archivo: " << tamanoArchivo << " MB" << endl;
    }
};

// Clase derivada para LibroFisico
class LibroFisico : public Libro {
private:
    string ubicacion;

public:
    LibroFisico(string t, string a, string i, string u) 
        : Libro(t, a, i), ubicacion(u) {}

    void mostrarInfo() const override {
        Libro::mostrarInfo();
        cout << "Ubicación: " << ubicacion << endl;
    }
};

// Clase para Miembro
class Miembro {
private:
    string nombre;
    int id;
    vector<Libro*> librosPrestados;

public:
    Miembro(string n, int i) : nombre(n), id(i) {}
    
    void prestarLibro(Libro* libro) {
        if (libro->estaDisponible()) {
            libro->prestar();
            librosPrestados.push_back(libro);
        }
    }

    void devolverLibro(Libro* libro) {
        for (auto it = librosPrestados.begin(); it != librosPrestados.end(); ++it) {
            if (*it == libro) {
                libro->devolver();
                librosPrestados.erase(it);
                break;
            }
        }
    }

    void mostrarLibrosPrestados() const {
        cout << "Libros prestados por " << nombre << ":\n";
        for (const auto& libro : librosPrestados) {
            cout << *libro << endl;
        }
    }
};

int main() {
    LibroFisico* libro1 = new LibroFisico("C++ Primer", "Lippman", "123456789", "A1");
    LibroDigital* libro2 = new LibroDigital("Effective Modern C++", "Scott Meyers", "987654321", "PDF", 5);

    Miembro* miembro1 = new Miembro("Juan Perez", 1);

    cout << *libro1 << endl;
    cout << *libro2 << endl;

    miembro1->prestarLibro(libro1);
    miembro1->mostrarLibrosPrestados();

    miembro1->devolverLibro(libro1);
    miembro1->mostrarLibrosPrestados();

    delete libro1;
    delete libro2;
    delete miembro1;

    return 0;
}