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
#include <sstream>

void resuelveCaso() {

    std::string entrada;
    std::getline(std::cin, entrada);
    std::unordered_map<std::string, std::pair<int,int>>ejs;//equipo, first: el maximo de puntos y second: el total de ejs resueltos
    std::unordered_map<std::string, std::unordered_map<std::string,std::pair<int, std::pair<int, bool>>>>result;//equipo, {problema, {fallos,tiempo, acertado}}
    //Para leer los datos
    while (entrada != "FIN") {
        std::stringstream ss(entrada);
        std::string equipo, problema, resultado;
        int tiempoEmpleado;
        ss >> equipo >> problema >> tiempoEmpleado >> resultado;
        
        auto& it = result[equipo][problema];//Hay que tener en cuenta que el problema ya se sumo y que esta repetido
        auto& sal = ejs[equipo];
        if (!it.second.second) {
            if (resultado == "AC") {

                it.second.first = tiempoEmpleado + 20 * it.first;
                it.second.second = true;
                sal.first = sal.first + it.second.first;//aumentamos el valor del tiempo empleado
                sal.second++;//aumentamos el numero de ejercicios resueltos por ese equipo
            }
            else {
                it.first++;
            }
        }


        std::getline(std::cin, entrada);
    }

    std::vector <std::pair <std::string,std::pair<int, int>>>salida;

    for (auto const& it : ejs) {
        salida.push_back({ it.first,{it.second.first,it.second.second} });

    }

    //Funcion para ordenar de mayor a menor en funcion del int y si son iguales en funcion del string
    std::sort(salida.begin(), salida.end(), [](std::pair <std::string, std::pair<int,int>> const& a, std::pair <std::string,std::pair<int, int>> const& b) {
        return  (a.second.second > b.second.second) || (a.second.second == b.second.second && a.second.first < b.second.first) || (a.second.second == b.second.second && a.second.first == b.second.first && a.first < b.first);
        });

    
    for (auto it : salida)
        std::cout << it.first << ' ' << it.second.second << ' ' << it.second.first<< '\n';
    
   
    std::cout << "---\n";

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

    std::cin.ignore();
    while (numCasos--) {
        resuelveCaso();

    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
