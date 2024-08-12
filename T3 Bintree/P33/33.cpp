// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tDatos {
    int equipos;
    int mayorNumEx;

};

tDatos rescate(bintree <int> const& a) {
    tDatos d{0,0};
    if (a.empty()) {
        return d;
    }
    else {
        tDatos iz = rescate(a.left());
        tDatos dr = rescate(a.right());

        d.equipos = dr.equipos + iz.equipos;
        if (a.root() > 0 && d.equipos == 0)
            d.equipos++;
        
        d.mayorNumEx = std::max(iz.mayorNumEx, dr.mayorNumEx) + a.root();
        

        return d;

    }

}

void resuelveCasos(int casos) {
    // leer los datos de la entrada

    bintree<int> arbol;
    while (casos--) {
        arbol = leerArbol(-1);
        tDatos d = rescate(arbol);
        std::cout << d.equipos << ' ' << d.mayorNumEx << '\n';
        
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
