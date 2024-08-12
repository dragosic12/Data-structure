// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

bool resuelveCaso() {
    std::string final = "_FIN_", aux, deporte;
    std::unordered_map <std::string, std::set<std::string>> v;
    std::unordered_map<std::string, std::string>j;


    bool primeraIter = false;

    std::cin >> aux;
    if (!std::cin)
        return false;

    deporte = aux;
    v.insert({ aux, {} });
    while (aux != final) {
        if (primeraIter) {
            if (std::all_of(aux.begin(), aux.end(), &::isupper) ) { //Comprobamos que sea un deporte, es decir que todas las letras del string esten en mayuscula
                v.insert({ aux, {} });
                //Cuando cambiamos de deporte vamos guardando el numero de jugadores de cada deporte

                deporte = aux;//Guardamos el ultimo deporte que se ha insertado en una variable auxiliar para luego poder insertar en el unordered el jugador perteneciente a dicho 
                //deporte
            }
            else {//Si no es mayuscula es un jugador
                if (!j.insert({ aux,deporte }).second && j[aux] != deporte)
                    v[(j[aux])].erase(aux);
                else
                    v[deporte].insert(aux);//Los repetidos no se van a insertar 
            }
        }
        std::cin >> aux;
        primeraIter = true;

    }

    std::vector <std::pair <std::string, int>>salida;

    for (auto const& it : v) {
        salida.push_back({ it.first,it.second.size() });

    }

    //Funcion para ordenar de mayor a menor en funcion del int y si son iguales en funcion del string
    std::sort(salida.begin(), salida.end(), [](std::pair <std::string, int> const& a, std::pair <std::string, int> const& b) {
        return (a.second > b.second) || (a.second == b.second && a.first < b.first);
        });
    
    for (auto it : salida) 
        std::cout << it.first << ' ' << it.second << '\n';
    
   
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
