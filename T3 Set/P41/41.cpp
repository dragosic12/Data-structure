// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "set_eda.h"




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int jugadores, cartas,aux;
    std::cin >> jugadores >> cartas;

    if (!std::cin)
        return false;

    std::vector<set<int>> v(jugadores);

    int i = 0;

    std::cin >> aux;
    
    while (cartas--) {
        int pos = i % jugadores;
        
        if (v[pos].count(aux)) //Si el arbol ya tiene ese elemento no se inserta y se borra el que tenia
            v[pos].erase(aux);
        else
            v[pos].insert(aux);

        if (cartas > 0)
            std::cin >> aux;

        i++;
    }

    i = 0;
    while (i < v.size()) {
        std::cout << 'J' << i % jugadores + 1 << ": {";
        auto it = v[i].begin();
        while (it != v[i].end()) {
            std::cout << *it ;
            ++it;
            if (it != v[i].end())
                std::cout << ", ";
        }
        std::cout << "}\n";
        i++;
    }

    std::cout << "---\n";
    // escribir sol


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
