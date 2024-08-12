//DRAGOS IONUT CAMARASAN
//C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <list>

bool resuelveCaso() {
    int n, aux;
    //Como necesitamos orden en funcion de la entrada, la uncia TAD que mantiene el orden de entrada son las listas
    std::list <std::pair<int,int>> lista;
    std::map <int, int> mapita;

    std::cin >> n;

    if (!std::cin)
        return false;

    while (n--) {
        std::cin >> aux;
        if (!mapita.count(aux))
            lista.push_back({aux,0});
        mapita[aux]++;

    }

    for (auto it : lista) {
        it.second = mapita.find(it.first)->second;
        std::cout << it.first << ' ' << it.second << '\n';

    }

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


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
