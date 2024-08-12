#include <iostream>
#include <string> 
#include <sstream> 
#include <fstream>

#include "double_linked_list_ed.h"

template <class T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;



public:


    void partcion(int pivote) {
        double_linked_list_ed_plus<T> otra;

        Nodo* aux;
        aux = this->fantasma;
        
        if (this->empty()) return;
        aux = aux->sig;
        Nodo* ultimo = this->fantasma->ant;

        while (aux != ultimo) {
            if (aux->elem > pivote) {
                Nodo* sig = aux->sig;
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
                aux->ant = this->fantasma->ant;
                this->fantasma->ant->sig = aux;
                aux->sig = this->fantasma;
                this->fantasma->ant = aux;
                aux = sig;

            }
            else {
                aux = aux->sig;
            }
        }

        if (ultimo->elem > pivote) {
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
            aux->ant = this->fantasma->ant;
            this->fantasma->ant->sig = aux;
            aux->sig = this->fantasma;
            this->fantasma->ant = aux;
            
        }


    }




    void print(std::ostream& o) const {
        Nodo* aux = this->fantasma->sig;

        if (aux != this->fantasma) {
            o << aux->elem;
            aux = aux->sig;
        }
        while (aux != this->fantasma) {
            o << ' ' << aux->elem;
            aux = aux->sig;
        }
        o << '\n';

    }
};

template <typename T>
inline std::ostream& operator<< (std::ostream& o, double_linked_list_ed_plus<T> const& l) {
    l.print(o);
    return o;
}

bool resuelveCaso() {

    double_linked_list_ed_plus<int> lista;
    int pivote, numCasos, aux;
    std::cin >> numCasos >> pivote;
    if (!std::cin) return false;

    while (numCasos--) {
        std::cin >> aux;
        lista.push_back(aux);
    }
    
    lista.partcion(pivote);

    std::cout << lista;
    return true;
    //std::cout << lista;



}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;
        

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

}
