#include <iostream>
#include <string> 
#include <sstream> 
#include <fstream>

#include "double_linked_list_ed.h"

template <class T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;



public:


    void interseccion(double_linked_list_ed_plus <T> & otra) {
        //Comprobamos que las listas no esten vacias
        if (otra.empty()) {
            if (this->empty()) {
                return;
            }
            else {
                Nodo* aux;
                aux = this->fantasma;
                this->fantasma = otra.fantasma;
                otra.fantasma = aux;
            }
        }
        //Para que el primer elemento de la lista sea siempre el menor se puede hacer como yo lo hice o con un swap
        if (this->fantasma->sig != this->fantasma && otra.fantasma->sig != otra.fantasma && this->fantasma->sig->elem > otra.fantasma->sig->elem) {
            Nodo* aux;
            aux = this->fantasma;
            this->fantasma = otra.fantasma;
            otra.fantasma = aux;
        }

        Nodo* act1 = this->fantasma->sig;
        Nodo* act2 = otra.fantasma->sig;

        while (act1 != this->fantasma && act2 != otra.fantasma) {
            if (act1->elem < act2->elem) {//Cuando el de arriba es menor avanza una posicion la lista
                //intercambiamos punteros para que dejen de apuntar al elemento que es menor, es decir sacarlo de la memoria
                Nodo* aux = act1->sig;
                this->borra_elem(act1);
                act1 = aux;

            }
            else if (act1->elem > act2->elem) {
                Nodo* aux = act2->sig;
                otra.borra_elem(act2);
                act2 = aux;
            }
            else {//Cuando son iguales se queda dentro del this
                
                act1 = act1->sig;
                Nodo* aux = act2->sig;
                otra.borra_elem(act2);
                act2 = aux;
            }
        }

        if (otra.empty()) {
            while (act1 != this->fantasma) {
                Nodo* aux = act1->sig;
                this->borra_elem(act1);
                act1 = aux;
            }
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

void resuelveCaso() {

    double_linked_list_ed_plus<int> lista;
    double_linked_list_ed_plus<int> lista2;
    int c;


    std::cin >> c;
    while (c != 0) {

        lista.push_back(c);
        std::cin >> c;
    }
    std::cin >> c;
    while (c != 0) {

        lista2.push_back(c);
        std::cin >> c;
    }

    lista.interseccion(lista2);

    std::cout << lista;
    


}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

}
