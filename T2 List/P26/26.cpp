// DRAGOS IONUT CAMARASAN
// C10

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
#include <list>

template <class T>
class list_eda_plus : public list<T> {
    using Nodo = typename list<T>::Nodo;

    template <class Apuntado>
    class reverse_iterator {
        // puntero al nodo actual del recorrido
        Nodo* act;
        // puntero al nodo fantasma (para saber cuándo estamos fuera)
        Nodo* fan;

    public:
        reverse_iterator() : act(nullptr), fan(nullptr) {}

        // para acceder al elemento apuntado
        Apuntado& operator*() const {
            if (act == fan) throw std::out_of_range("fuera de la lista");
            return act->elem;
        }

        reverse_iterator& operator++() {
            act = act->ant;
            return *this;
        }

        bool operator==(reverse_iterator const& that) const {
            return act == that.act && fan == that.fan;
        }

        bool operator!=(reverse_iterator const& that) const {
            return !(*this == that);
        }

    private:
        // para que list pueda construir objetos del tipo iterador
        friend class list_eda_plus;

        // constructora privada
        reverse_iterator(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}
    };

public:
    using rev_it = reverse_iterator<T>;
   
    // devuelve un iterador al final del recorrido y fuera de este
    rev_it rbegin() {
        return rev_it(this->fantasma->ant, this->fantasma);
    }

    // devuelve un iterador al principio de la lista
    rev_it rend() {
        return rev_it(this->fantasma, this->fantasma);
    }
    
};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    list_eda_plus <int> lista;

    int aux;
    std::cin >> aux;
    while (aux != 0) {
        lista.push_back(aux);
        std::cin >> aux;
    }

    auto it = lista.rbegin();

    while (it != lista.rend()) {
        std::cout << *it << ' ';

        ++it;
    }

    std::cout << '\n';
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
