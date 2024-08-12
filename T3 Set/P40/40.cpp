//DRAGOS IONUT CAMARASAN
//C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "set_eda.h"

void resuelveCaso(int numC) {
    int aux, n;
    set<int> conj;
    for (int i = 0; i < numC; i++) {
        std::cin >> aux;
        conj.insert(aux);

    }
    std::cin >> aux;
    for (int j = 0; j < aux; j++) {
        std::cin >> n;
        auto result = conj.lower_bound(n);
        if (result.first) {
            std::cout << result.second << '\n';
        }
        else {
            std::cout << "NO HAY" << '\n';
        }
    }
    std::cout << "---" << '\n';



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
    while (numCasos != 0) {
        resuelveCaso(numCasos);
        std::cin >> numCasos;
    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
