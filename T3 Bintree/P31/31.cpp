// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

template <class T>
class bintree_plus : public bintree<T> {
    using Link = typename bintree<T>::Link;


public:
    bintree_plus() : bintree <T >() {}
    bintree_plus(bintree_plus <T > const& l, T const& e, bintree_plus<T > const& r) :
        bintree <T >(l, e, r) {}

    T minimo() {
        
        return minimoAux(this->raiz);
       
    }


private:

    

    
    T minimoAux(Link ra) {
        T valor;
        if (ra->left == nullptr && ra->right == nullptr) {

            return ra->elem;
        }
        else if (ra->left == nullptr) {
            T dr = minimoAux(ra->right);
            if (dr > ra->elem)
                return ra->elem;
            else
                return dr;
        }
        else if (ra->right == nullptr) {
            T iz = minimoAux(ra->left);
            if (iz > ra->elem)
                return ra->elem;
            else
                return iz;
        }
        else {

            T iz = minimoAux(ra->left);
            T dr = minimoAux(ra->right);
            valor = ra->elem;
            if (valor > iz) {
                valor = iz;
            }
            if (valor > dr) {
                valor = dr;
            }


            return valor;
        }

    }

};

/*
template <typename T >
void resolver(bintree <T> a, T min) {
    if (raiz == vacio) { // es un arbol vacio
        return {};
    }
    else { // leer recursivamente los hijos
        a.left()
        
    }

}*/

template <typename T >
inline bintree_plus <T > leerArbol_plus(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un arbol vacio
        return {};
    }
    else { // leer recursivamente los hijos
        bintree_plus <T > iz = leerArbol_plus(vacio);
        bintree_plus <T > dr = leerArbol_plus(vacio);
        return { iz , raiz , dr };
    }
}

//3 formas de resolver el problema:
//1->Extendiendo la clase bintree
//2->Con una funcion externa que haga una busqueda recursiva
//3->Con iteradores
void resuelveCasos(const std::string tipo) {
    // leer los datos de la entrada

    if (tipo == "N") {//Enteros
        bintree_plus <int> arbol;
        arbol = leerArbol_plus(-1);
        //resolver(arbol, mini);
        std::cout << arbol.minimo();
    }
    else if (tipo == "P") {//string
        std::string vacio = "#";
        bintree_plus <std::string> arbol;
        arbol = leerArbol_plus(vacio);
        
        //resolver(arbol, minm);
        std::cout << arbol.minimo();
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

    std::string casos;
    std::cin >> casos;
    while (std::cin) {
        resuelveCasos(casos);
        //resuelveCasos(casos);
        std::cin >> casos;
    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
