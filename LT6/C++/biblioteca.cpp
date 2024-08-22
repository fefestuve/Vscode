#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // Para std::remove

using namespace std;

class libro {
public:
    string titulo;
    string autor;
    string identificacion;
    int cantidad;

    libro(string t, string a, string i, int c){ 
        titulo=t; 
        autor=a; 
        identificacion=i; 
        cantidad=c;
    }

    void mostrarInfo() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Identificacion: " << identificacion << endl;
        cout << "Cantidad disponible: " << cantidad << endl;
    }

    bool prestamo() {
        if (cantidad > 0) {
            cantidad--;
            return true;
        } else {
            cout << "No hay ejemplares disponibles para prestar." << endl;
            return false;
        }
    }

    void devolver() {
        cantidad++;
    }
};

class usuario {
public:
    string nombre;
    string IDusuario;
    vector<string> librosPrestados;

    usuario(string n, string ID){
        nombre=n;
        IDusuario=ID
    }

    void prestarLibro(string identificacion) {
        librosPrestados.push_back(identificacion);
    }

    void devolverLibro(string identificacion) {
        auto it = remove(librosPrestados.begin(), librosPrestados.end(), identificacion);
        if (it != librosPrestados.end()) {
            librosPrestados.erase(it, librosPrestados.end());
            cout << "Libro con ID " << identificacion << " devuelto con éxito." << endl;
        } else {
            cout << "El libro con ID " << identificacion << " no está en la lista de préstamos." << endl;
        }
    }

    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Identificacion de usuario: " << IDusuario << endl;
        cout << "Libros prestados: " << endl;
        for (const string& id : librosPrestados) {
            cout << "- " << id << endl;
        }
    }
};

class biblioteca {
public:
    vector<libro> catalogo;
    vector<usuario> usuarios;

    void agregarLibro(libro nuevoLibro) {
        catalogo.push_back(nuevoLibro);
    }

    void registrarUsuario(usuario nuevoUsuario) {
        usuarios.push_back(nuevoUsuario);
    }

    void prestarLibro(string identificacion, string IDusuario) {
        auto itLibro = find_if(catalogo.begin(), catalogo.end(), [&](const libro& l) {
            return l.identificacion == identificacion;
        });

        if (itLibro != catalogo.end() && itLibro->prestamo()) {
            auto itUsuario = find_if(usuarios.begin(), usuarios.end(), [&](const usuario& u) {
                return u.IDusuario == IDusuario;
            });

            if (itUsuario != usuarios.end()) {
                itUsuario->prestarLibro(identificacion);
                cout << "Libro prestado a " << itUsuario->nombre << "." << endl;
            } else {
                cout << "Usuario no encontrado." << endl;
                itLibro->devolver(); // Si el usuario no se encuentra, devolvemos el libro.
            }
        } else {
            cout << "Libro no encontrado o no disponible." << endl;
        }
    }

    void mostrarCatalogo() {
        for (const auto& lib : catalogo) {
            lib.mostrarInfo();
            cout << "-----------------" << endl;
        }
    }

    void mostrarUsuarios() {
        for (const auto& user : usuarios) {
            user.mostrarInfo();
            cout << "-----------------" << endl;
        }
    }
};

int menu() {
    int opcion;
    do {
        cout << "Menu:" << endl;
        cout << "1. Mostrar catálogo" << endl;
        cout << "2. Mostrar usuarios" << endl;
        cout << "3. Prestar libro" << endl;
        cout << "4. Devolver libro" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 5);

    return opcion;
}

int main() {
    biblioteca miBiblioteca;

    // Agregar algunas cosas para iniciar
    miBiblioteca.agregarLibro(libro("Harry Potter", "JK Rowling", "0000", 5));
    miBiblioteca.agregarLibro(libro("Las aventuras de Pedro", "Pedro Martinez", "0001", 3));

    usuario nuevoUsuario;
    nuevoUsuario.nombre = "Juan Pérez";
    nuevoUsuario.IDusuario = "U123";
    miBiblioteca.registrarUsuario(nuevoUsuario);

    int opcion;
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                miBiblioteca.mostrarCatalogo();
                break;
            case 2:
                miBiblioteca.mostrarUsuarios();
                break;
            case 3: {
                string idLibro, idUsuario;
                cout << "ID del libro: ";
                cin >> idLibro;
                cout << "ID del usuario: ";
                cin >> idUsuario;
                miBiblioteca.prestarLibro(idLibro, idUsuario);
                break;
            }
            case 4: {
                string idLibro, idUsuario;
                cout << "ID del libro: ";
                cin >> idLibro;
                cout << "ID del usuario: ";
                cin >> idUsuario;
                for (auto& user : miBiblioteca.usuarios) {
                    if (user.IDusuario == idUsuario) {
                        user.devolverLibro(idLibro);
                        for (auto& lib : miBiblioteca.catalogo) {
                            if (lib.identificacion == idLibro) {
                                lib.devolver();
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
