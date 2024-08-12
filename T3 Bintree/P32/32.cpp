// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tDatos {
    int total;
    int numNodos;
};


tDatos numeroNodosAcum(bintree<int> const& a) {
    tDatos datos{ 0,0 };
    if (!a.empty()) {
    
    
    
        tDatos iz = numeroNodosAcum(a.left());
        tDatos dr = numeroNodosAcum(a.right());

        if (a.root() == iz.total + dr.total) //root() == elem
            datos.numNodos = iz.numNodos + dr.numNodos + 1;
        


        datos.total = a.root() + iz.total + dr.total;

        if (datos.numNodos == 0)
            datos.numNodos = iz.numNodos + dr.numNodos;

        return datos;

    }
    else {
        return datos;
    }

}



void resuelveCasos(int casos) {
    // leer los datos de la entrada

    bintree<int> arbol;
    while (casos--) {
        arbol = leerArbol(-1);
        if (!arbol.empty()) {
            tDatos d = numeroNodosAcum(arbol);
            
            std::cout << d.numNodos;
        }
        else
            std::cout << '0';
        std::cout << '\n';
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
