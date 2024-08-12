// DRAGOS IONUT CAMARASAN
// C10

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tprop {
    int numNodos;
    int numHojas;
    int altura;
}; 

template <class T >
class bintree_ext : public bintree <T > {
    using Link = typename bintree <T >::Link;
public:
    bintree_ext() : bintree <T >() {}
    bintree_ext(bintree_ext <T > const& l, T const& e, bintree_ext <T > const& r) :
        bintree <T >(l, e, r) {}
    bool equilibrado(){
        return equilibrado(this->raiz).eq;
    }

    int numNodos() {
        return numNodosAux(this->raiz);

    }

    int numHojas() {
        return numHojasAux(this->raiz);
    }

    int altura() {
        return tallaAux(this->raiz);

    }

private:
   
    int numNodosAux(Link ra) {
        if (ra == NULL)
            return 0;
        return 1 + numNodosAux(ra->left) + numNodosAux(ra->right);
    }

    int tallaAux(Link ra) {
        
        if (ra == NULL)
            return 0;

        int tallaiz = tallaAux(ra->left);
        int talladr = tallaAux(ra->right);
        if (tallaiz > talladr)
            return 1 + tallaiz;
        else
            return 1 + talladr;
    }

    int numHojasAux(Link ra) {
        if (ra == NULL)
            return 0;

        if ((ra->left == NULL) && (ra->right== NULL))
            return 1;

        return numHojasAux(ra->left) + numHojasAux(ra->right);
    }


};


template <typename T >
inline bintree_ext <T > leerArbol_ext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un arbol vacio
        return {};
    }
    else { // leer recursivamente los hijos
        bintree_ext <T > iz = leerArbol_ext(vacio);
        bintree_ext <T > dr = leerArbol_ext(vacio);
        return { iz , raiz , dr };
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree_ext<char> arbol = leerArbol_ext('.');
   
    std::cout << arbol.numNodos() << ' ' << arbol.numHojas() << ' ' << arbol.altura() << '\n';
    
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
