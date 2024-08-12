// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus : public linked_list_ed <T>{
    using Nodo = typename linked_list_ed<T>::Nodo;
public:

    void duplicar() {
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            
            Nodo* insert = new Nodo(aux->elem);
            insert->sig = aux->sig;
            aux->sig = insert;
            
            aux = aux->sig->sig;
        }

    }

    void mostrar() {
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            std::cout << aux->elem << ' ';

            aux = aux->sig;
        }
        std::cout << '\n';

    }

};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int  aux = 1;
    linked_list_ed_plus <int> lista;
    std::cin >> aux;
    
    if (!std::cin) return false;

    
    while (aux != 0) {
        
        lista.push_back(aux);
        std::cin >> aux;
    }

    lista.duplicar();
    lista.mostrar();
    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
