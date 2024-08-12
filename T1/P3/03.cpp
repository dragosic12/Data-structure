// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Horas.h"
#include <vector>


// función que resuelve el problema
int buscaHoras(std::vector <Horas> const& v, Horas const& h) {
    int ini = 0, fin = v.size();
    while (ini < fin) {
        int mitad = (ini + fin) / 2;
        if (h < v[mitad]) fin = mitad;
        else if (v[mitad] < h) ini = mitad + 1;
        else return mitad;
    }
    return ini;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int trenes, consultas, pos;
    Horas aux, sol;
    std::cin >> trenes >> consultas;
    
    if (trenes == 0 && consultas == 0)
        return false;

    std::vector <Horas> v;
    int i = trenes;
    
    while (i--) {
        std::cin >> aux;
        v.push_back(aux);
    }
    
    while (consultas--) {
        try {
           std::cin >> aux;

           //Busca las horas
           pos = buscaHoras(v, aux);
           
           if (pos == -1 || pos >= v.size())
                std::cout << "NO" << '\n';
           else
            std::cout << v[pos] << '\n';
        }
        catch (std::invalid_argument const& a) {
            std::cout << a.what() << '\n';
        }
    }

    if (i != -1) {
        while (i--)
            std::cin >> aux;
    }
    
    if (consultas != -1) {
        while (consultas--)
            std::cin >> aux;
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
