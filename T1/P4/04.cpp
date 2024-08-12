// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "pelicula.h"
#include "Horas.h"
#include <vector>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numCasos;

    std::cin >> numCasos;

    if (numCasos == 0)
        return false;

    std::vector <peliculas> p;
    peliculas pelis;

    while (numCasos--) {
        std::cin >> pelis;
        pelis.suma();
        p.push_back(pelis);        
    }
    
    std::sort(p.begin(),p.end());
   
    for (auto it : p) {
        std::cout << it;
    }
    std::cout << "---" << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
