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

    int casos, numActores, min;
    std::cin >> casos;

    if (casos == 0)
        return false;

    std::string pelicula, actor, pelis_emitidas;
    std::unordered_map <std::string, std::pair<int,std::vector <std::pair<std::string, int>>>> pelis_actores;
    std::unordered_map<std::string,int>actores;

    

    while (casos--) {
        std::cin >> pelicula;
        std::cin >> numActores;
        while (numActores--) {//Aquie aparecen los actores con el numero de 
            //actuaciones que han tenido en cada una de las peliculas
            std::cin >> actor;
            std::cin >> min;

            pelis_actores[pelicula].second.push_back({ actor,min });

        }
    }
    int emision, maximo = 0,maximoAct = 0;

    //Para meter todos los actores que tienen el maximo numero de mins
    std::set <std::string> actoresMasVistos;
    std::string peliMasVista;
    std::cin >> emision;
    while (emision--) {//Aqui vamos a contar el maximo numero de peliculas que se han emitido 
        //y el maximo de minutos que ha tenido cada actor en la pelicula mas emitida
        std::cin >> pelis_emitidas;
        
        auto it = pelis_actores.find(pelis_emitidas);

        //Aumentamos el numero de veces que se ha visto cada peli
        it->second.first++;

        if (it->second.first >= maximo) {
            maximo = it->second.first;
            peliMasVista = it->first;
        }

        //Aqui obtenemos todos los actores que salen por cada pelicula y los sumamos
        
        for (auto iter : it->second.second) {
            actores[iter.first] += iter.second;

            //Si el numero de minutos del actor es superior al maximo se borra todo el 
            //set y se actualiza el valor del maximoAct
            if (actores[iter.first] > maximoAct) {
                maximoAct = actores[iter.first];
                actoresMasVistos.clear();
                actoresMasVistos.insert(iter.first);

            }
            else if (actores[iter.first] == maximoAct)
                actoresMasVistos.insert(iter.first);
            

        }

    }

    
    std::cout << maximo << ' ' << peliMasVista<< '\n';
    //std::cout << pelisMasVistas.end()->second << ' ' << pelisMasVistas.end()->first << '\n';
    
    
    std::cout << maximoAct << ' ';
    for (auto it : actoresMasVistos){
            std::cout << it << ' ';
    }
    std::cout << '\n';

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
