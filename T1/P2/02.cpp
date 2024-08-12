// DRAGOS IONUT CAMARASAN
// C10



#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "Horas.h"



void resuelveCaso() {
    // leer los datos de la entrada
    Horas h1;
    Horas h2;
    try {
        std::cin >> h1;
        std::cin >> h2;

        std::cout << h1 + h2 << '\n';

    }
    catch (std::invalid_argument& a) {
        std::cout << a.what() << '\n';
    }
    catch (std::overflow_error& b) {
        std::cout << b.what() << '\n';
    }
    //TipoSolucion sol = resolver(datos);
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
