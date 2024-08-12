// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include "bintree_eda.h"

struct tDato {
    int altura;
    bool encontrado;
};


template <class T>
class bintree_ext : public bintree<T> {
    using Link = typename bintree <T>::Link;

public:
    // árbol vacío
    bintree_ext() : bintree <T >() {}


    // árbol con dos hijos
    bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree <T >(l, e, r) {}
    
    int primerNivel (T const & e) {
        if (!this->empty()) {
            tDato dato{-1,false};
            std::queue<std::pair<int, Link>> pendientes;
            pendientes.push({ 1, this->raiz });
            while (!pendientes.empty()) {
                auto sig = pendientes.front();
                pendientes.pop();

                if (sig.second->elem == e && dato.altura == sig.first && dato.encontrado) 
                    return sig.first;
                else if (sig.second->elem == e) {
                    dato.altura = sig.first;
                    dato.encontrado = true;
                }
                else if (dato.altura != sig.first) 
                    dato.encontrado = false;
                
                

                if (sig.second->left != nullptr)
                    pendientes.push({ sig.first + 1, sig.second->left });
                if (sig.second->right != nullptr)
                    pendientes.push({ sig.first + 1, sig.second->right });

                   
                
                
            }
        }
        return -1;
    }
    

};


template <typename T>
inline bintree_ext<T> leerArbolito(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    }
    else { // leer recursivamente los hijos
        auto iz = leerArbolito(vacio);
        auto dr = leerArbolito(vacio);
        return { iz, raiz, dr };
    }
}

//Hay que recorrerlo por alturas
void resuelveCasos(int n) {
    char tipo, encontrar;
    int valor;
    int nivel = 0;

    std::cin >> tipo;

    if (tipo == 'N') {//Numeros

        std::cin >> valor;
        bintree_ext <int> arbol = leerArbolito(-1);
        arbol.empty();
        nivel = arbol.primerNivel(valor);
    }
    else {

        std::cin >> encontrar;
        bintree_ext <char> arbol = leerArbolito('.');
        arbol.empty();
        nivel = arbol.primerNivel(encontrar);
    }

    


    if (nivel != -1) std::cout << nivel;
    else std::cout << "NO EXISTE";

    std::cout << '\n';
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
    while (numCasos--){
        resuelveCasos(numCasos);
        //std::cin >> numCasos;
    }
        


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
