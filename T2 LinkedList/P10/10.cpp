#include <iostream>
#include <string> 
#include <sstream> 
#include <fstream>

#include "linked_list_ed.h"

template <class T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;
public:

    //
    // Aqui el método implementado por el alumno
    //
    void invertir() {
        //3 nodos
        Nodo* aux1 = this->prim;
        Nodo* aux2 = aux1->sig;
        
        bool ok = false;
        
        //Asignamos los 3 primeros elementos
        //prim, prim->sig, prim->sig->sig
        /*
        if (aux1 != nullptr) {
             aux2= aux1->sig;
             if (aux2 != nullptr)
                 aux3 = aux2->sig;
        }*/
        
        //comprobamos que la lista tenga mas de 2 elementos
        //Si el aux1 = ultimo, entonces la lista solo tiene 1 elementos
        if (aux1 == this->ult) {
            this->prim = this->ult;
        }
        //Si aux2 = ultimo, solo hay 2 elementos
        else if (aux2 == this->ult) {
            
            aux2->sig = aux1;
            this->prim = aux2;
            this->ult = aux1;
            aux1->sig = nullptr;
            //this->prim = aux2;
        }
        else {
            Nodo* aux3 = aux2->sig;
            aux1->sig = nullptr;
            this->ult = aux1;
            while (aux3 != nullptr && !ok) {
                aux2->sig = aux1;
                aux1 = aux2;
                aux2 = aux3;
                if (aux3->sig == nullptr) {
                    aux3->sig = aux1;
                    this->prim = aux3;
                    ok = true;
                }
                else
                    aux3 = aux3->sig;

            }

        }

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

bool resuelveCaso() {
   
    linked_list_ed_plus<int> lista;
    int c;
    std::cin >> c;
    if (!std::cin) return false;
    while(c != 0) {
        
        lista.push_back(c);
        std::cin >> c;
    }
    if (!lista.empty()) {
        lista.invertir();
    }

    std::cout << lista;

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

}
