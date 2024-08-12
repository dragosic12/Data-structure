#include <iostream>
#include <string> 
#include <sstream> 
#include <fstream>

#include "linked_list_ed.h"

template <class T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;
public:

    template <typename P>
    void mezclar(linked_list_ed_plus<P>& lista) {
        //Recorro las dos listas con un puntero a ambas listas
        //cuando acaba una de las dos listas termino la otra
        //CASO ESPECIAL
        //8 9 10
        //1 2 3 

        //SE PUEDE HACER CON OTRA LISTA AUXILIAR PERO SIN HACER PUSH BACK

        //Para comprobar que ninguna de las listas es vacia
        if (lista.empty()) return;
        if (this->empty()) {
            this->prim = lista.prim;
            lista.prim = nullptr;
            return;
        }


        //Para que el primer elemento de la lista sea siempre el menor se puede hacer como yo lo hice o con un swap
        if (this->prim != nullptr && lista.prim != nullptr && this->prim->elem > lista.prim->elem) {
            Nodo* aux;
            aux = this->prim;
            this->prim = lista.prim;
            lista.prim = aux;
        }

        Nodo* act1 = this->prim;
        Nodo* act2 = lista.prim;
        while (act1->sig != nullptr && act2 != nullptr) {
            if (act1->sig->elem <= act2->elem) {
                act1 = act1->sig;
            }
            else {
                //Colocado en su sitio
                lista.prim = act2->sig;
                act2->sig = act1->sig;
                act1->sig = act2;
                act1 = act1->sig;
                act2 = lista.prim;
            }
        }
        if (lista.ult != nullptr) {
            act1->sig = lista.prim;
            lista.prim = nullptr;
        }

    };

    /*
    Nodo * act1 = this->prim;
    Nodo * act2 = lista.prim;
    if (this->prim->elem > lista.prim->elem){
        Nodo * mover = lista.prim;
        otra.prim = act2->sig;
        act2->sig = act1;
        this->prim = act2;
        act1 = act2;
        act2 = otra.prim;
    }
    Se podria hacer un while para meter todos los datos menores antes
    (mejor mi solucion)
    */

    /*
    while (act1->sig != nullptr && act2 != nullptr){
        if (act1->sig->elem <= act2->elem){
            act1 = act1->sig;
        }
        else{
            Colocado en su sitio
            otra.prim = act2->sig;
            act2->sig = act1->sig;
            act1->sig = act2;

            act1 = act1->sig;


        }


    }



    */


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
