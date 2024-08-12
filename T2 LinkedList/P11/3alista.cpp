#include <iostream>
#include <string> 
#include <sstream> 
#include <fstream>

#include "linked_list_ed.h"

template <class T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;
public:


    void mezclar(linked_list_ed_plus<T>& lista) {
        linked_list_ed_plus<T> otra;
        Nodo* act3 = otra.prim;

        //Para comprobar que ninguna de las listas es vacia
        if (lista.empty()) {
            return;
        }
        if (this->empty()) {
            this->prim = lista.prim;
            lista.prim = nullptr;
            return;
        }

        //Insertamos el primer valor en la 3a lista 

        if (this->prim->elem < lista.prim->elem) {
            otra.prim = this->prim;
            act3 = this->prim;
            otra.ult = act3->sig;
            this->prim = this->prim->sig;
        }
        else if (this->prim->elem >= lista.prim->elem) {
           
            otra.prim = lista.prim;
            act3 = lista.prim;
            otra.ult = act3->sig;
            lista.prim = lista.prim->sig;
        }
        else {
            otra.prim = this->prim;
            otra.prim->sig = lista.prim;
            this->prim = this->prim->sig;
            lista.prim = lista.prim->sig;
        }


        while (this->prim != nullptr && lista.prim != nullptr) {
            if (this->prim->elem < lista.prim->elem) {
                
                act3->sig = this->prim;
                otra.ult = act3->sig;
                this->prim = this->prim->sig;
            }
            else if (this->prim->elem >= lista.prim->elem) {
                
                act3->sig = lista.prim;
                otra.ult = act3->sig;
                lista.prim = lista.prim->sig;
            }
            else {//son iguales metemos el que queramos y avanzamos ambos
                act3->sig = this->prim;
                this->prim = this->prim->sig;
                act3->sig->sig = lista.prim;
                otra.ult = lista.prim;
                lista.prim = lista.prim->sig;

            }
            act3 = act3->sig;



        };
        if (lista.ult != nullptr && lista.prim != nullptr) {
            act3->sig = lista.prim;
            lista.prim = nullptr;
        }
        else if (this->ult != nullptr && this->prim != nullptr) {
            act3->sig = this->prim;
            this->prim = nullptr;
        }

        //Ponemos los datos en la lista this
        this->prim = otra.prim;
        otra.prim = nullptr;


    }
    

    void print(std::ostream& o) const {
        Nodo* aux = this->prim;
        if (aux != nullptr) {
            o << aux->elem;
            aux = aux->sig;
        }
        while (aux != nullptr) {
            o << ' ' << aux->elem;
            aux = aux->sig;
        }
        o << '\n';
    }
};

template <typename T>
inline std::ostream& operator<< (std::ostream& o, linked_list_ed_plus<T> const& l) {
    l.print(o);
    return o;
}


void resuelveCaso() {

    linked_list_ed_plus<int> lista;
    linked_list_ed_plus<int> lista2;
    int c;

    int i = 2;


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

    lista.mezclar(lista2);

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
