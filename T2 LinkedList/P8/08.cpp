// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"
#include "Horas.h"

template <typename T>
class linked_list_ed_plus : public linked_list_ed <T>{
    using Nodo = typename linked_list_ed<T>::Nodo;

public:

    void eliminaPares() {
        
        int i = 1;
        if (!this->empty()) {

            Nodo* a_borrar = this->prim->sig;
            Nodo* ant = this->prim;
            Nodo* sig;
            
            while (a_borrar != nullptr) {
                if (i % 2 == 1) {//Es impar
                    sig = a_borrar->sig;
                    ant->sig = sig;
                    if (a_borrar == this->ult) {
                        this->ult = ant;
                    }
                    delete a_borrar;
                    ant = ant->sig;
                    a_borrar = sig;
                }
                else
                    a_borrar = a_borrar->sig;

                i++;
            }
        }
    }

    void pintar() {
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
    int numCasos;
    std::cin >> numCasos;
    if (numCasos == 0)
        return false;
    linked_list_ed_plus <Horas> lista;
    Horas aux;

    while (numCasos--) {
        std::cin >> aux;
        lista.push_back(aux);
    }
    
    lista.eliminaPares();
    lista.pintar();
    //TipoSolucion sol = resolver(datos);

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
