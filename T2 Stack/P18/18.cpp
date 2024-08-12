
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include "fecha.h"




bool resuelveCaso() {
    
    std::vector <std::pair <std::pair<fecha, int>, fecha>> aux;
    std::pair<fecha, int> par;
    std::stack<std::pair<std::pair <fecha, int>, int>> pila;
    int numCasos;
    bool ok = false;

    std::cin >> numCasos;
    if (!std::cin)return false;
    
    int i = numCasos - 1;

    while (numCasos--) {
        std::cin >> par.first >> par.second;
        aux.push_back({ par , fecha(0,0,0)});

    }
    
    while (i >= 0) {
        while (!pila.empty() && pila.top().first.second < aux[i].first.second) {
            aux[pila.top().second].second = aux[i].first.first;
            pila.pop();
        }

        pila.push({aux[i].first, i});
        i--;
    }
    for (auto acc : aux) { std::cout << acc.second; }
    
    std::cout << "---\n";
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
