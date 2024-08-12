// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "Complejo.h"
#include <vector>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    Complejo c;
    Complejo aux(0, 0);
    float result = 0;
    int n, i = 0;
    bool comp = true;
    std::cin >> c;


    std::cin >> n;

    while (i < n && comp) {
        aux = aux * aux + c;
        
        if (aux.modulo() > 2){
            comp = false;
        }
        i++;
    }

    if (!comp) 
        std::cout << "NO" << '\n';
    else
        std::cout << "SI" << '\n';
       
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
    while (numCasos--)
        resuelveCaso();
        


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
