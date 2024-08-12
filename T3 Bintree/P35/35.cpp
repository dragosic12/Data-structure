// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool especular(bintree<char> const& iz, bintree<char>const& dr) {

    if (iz.empty() && dr.empty()) {
        return true;
    }
    else if (iz.empty() && !dr.empty()) {
        return false;
    }
    else if (dr.empty() && !iz.empty()) {
        return false;
    }
    else {
        bool iz1 = especular(iz.left(), dr.right());
        bool dr1 = especular(iz.right(), dr.left());
            
        return iz1 && dr1;


    }
}




void resuelveCasos(int casos) {
    // leer los datos de la entrada

    bintree<char> arbol;
    while (casos--) {
        arbol = leerArbol('.');
        
        if (especular(arbol.left(), arbol.right())) {
            std::cout << "SI" << '\n';
        }
        else {
            std::cout << "NO" << '\n';
        }
        //std::cout << d.diametro << '\n';

    }
    // escribir sol




}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int casos;
    std::cin >> casos;
    resuelveCasos(casos);


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
