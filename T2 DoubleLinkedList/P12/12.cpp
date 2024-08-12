#include <iostream>
#include <string> 
#include <sstream> 
#include <fstream>

#include "double_linked_list_ed.h"



template <class T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;

private:
    const int NUM = 2;

public:


    void intercambiar (const int val) {
        if (this->empty()) return;

        Nodo* aux = this->fantasma->sig;
        int i = NUM-1;

        if (val > 2) {

            while (aux != this->fantasma) {
                if (i == 0 ) {//que entre aqui solo cuando sean pares
                    //intercambiamos aux, el anterior a aux y el siguiente a aux
                    Nodo* sig1 = aux->sig;
                    Nodo* ant1 = aux->ant;

                    aux->sig = ant1;
                    ant1->ant->sig = aux;
                    aux->ant = ant1->ant;
                    ant1->ant = aux;
                    ant1->sig = sig1;
                    sig1->ant = ant1;
                    aux = aux->sig;
                    i = NUM;
                }
                i--;
                aux = aux->sig;
            }
        }
        else if (val == 2) {//Entra qui cuando la cantidad de valores de la lista es 2 (caso especial)
            Nodo* aux1 = this->fantasma->sig;//1
            Nodo* aux2 = aux1->sig;//2
            aux1->sig = this->fantasma;
            aux1->ant = aux2;
            aux2->sig = aux1;
            aux2->ant = this->fantasma;
            this->fantasma->sig = aux2;
            this->fantasma->ant = aux1;
            

        }

    }




    void print(std::ostream& o) const {
        if (this->fantasma != nullptr) {
            Nodo* aux = this->fantasma->sig;

            while (aux != this->fantasma) {
                o << aux->elem << ' ';
                aux = aux->sig;
            }
            o << '\n';
        }
    }
};

template <typename T>
inline std::ostream& operator<< (std::ostream& o, double_linked_list_ed_plus<T> const& l) {
    l.print(o);
    return o;
}

bool resuelveCaso() {

    double_linked_list_ed_plus<int> lista;
    double_linked_list_ed_plus<int> lista2;
    int c,i=0, num;
    std::cin >> c;
    if (c == 0) return false;

    
    while (i < c) {

        std::cin >> num;
        lista.push_back(num);
        i++;
    }
   

    lista.intercambiar(c);

    std::cout << lista;


    return true;
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
