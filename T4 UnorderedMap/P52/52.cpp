//DRAGOS IONUT CAMARASAN
//C10


#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <utility>
#include <vector>


class autoescuela {

private:

    //Contiene el {profesor , set{alumnos}} para ir sabiendo quienes son los alumnos de cada profesor. Utilizo un set para que la busqueda del alumno sea mas eficiente
    std::unordered_map<std::string, std::set<std::string>> autoes;

    //Contiene el {alumno,par<profesor,puntuacion>} para saber quien es el profesor de cada alumno junto con la puntuacion que tiene cada alumno
    std::unordered_map< std::string, std::pair<std::string, int>> puntuacion;


public:

    autoescuela() {}

    //Sirve para cambiarle de profesor tambien
    void alta(std::string a, std::string p) {

        auto& aux = puntuacion[a];
        if (aux.first != p) //Significa que se cambia de profesor, por lo tanto se tiene que borrar de la lista de alumnos del profesor y se tiene que cambiar su profesor en puntuacion
            autoes[aux.first].erase(a);
        else {
            if (autoes.count(p) == 0)
                aux.second = 0;//Se pone a 0 cuando es una alta, en caso contrario no se modifica la puntuacion 
             //Tanto si esta como si no se a ade el alumno al profesor
           
        }
        autoes[p].insert(a);
        aux.first = p;//El profesor siempre se asigna al alumno 
    }

    //Escribe por salida si a es alumno de p o A no es alumno de P
    bool es_alumno(std::string a, std::string p) {
        return autoes[p].count(a);
    }

    void actualizar(std::string a, int puntos) {
        if (puntuacion.count(a)) {
            auto& aux = puntuacion[a].second;
            aux = aux + puntos;
        }
        else
            throw std::domain_error("ERROR");
    }

    //Escribe en una linea con los alumnos de P a examen seguido de una linea con cada alumno que se puede presentar a examen
    std::vector<std::string> examen(std::string p, int puntos) {
        std::vector<std::string> sol;
        auto al = autoes[p];
        auto it = al.begin();

        while (it != al.end()) {
            auto& aux = puntuacion[*it];

            if (aux.second >= puntos)
                sol.push_back(*it);

            it++;
        }
        return sol;
    }

    int puntuacio(std::string a) {
        if (puntuacion.count(a))
            return puntuacion[a].second;
        else
            throw std::domain_error("ERROR");
    }

    //Borra el alumno de la autoescuela
    void aprobar(std::string a) {
        if (puntuacion.count(a)) {
            auto profe = puntuacion[a].first;
            puntuacion.erase(a);
            autoes[profe].erase(a);
        }
        else
            throw std::domain_error("ERROR");
    }

};

bool resuelve() {

    std::string orden;

    std::cin >> orden;
    if (!std::cin) return false;

    autoescuela aescuela;

    std::string alumno, profesor;
    int punt;


    while (orden != "FIN") {
        try {
            if (orden == "alta") {
                std::cin >> alumno >> profesor;
                aescuela.alta(alumno, profesor);
            }
            else if (orden == "es_alumno") {
                std::cin >> alumno >> profesor;
                if (aescuela.es_alumno(alumno, profesor))
                    std::cout << alumno << " es alumno de " << profesor << '\n';
                else
                    std::cout << alumno << " no es alumno de " << profesor << '\n';
            }
            else if (orden == "examen") {
                std::cin >> profesor >> punt;

                auto v = aescuela.examen(profesor, punt);

                std::cout << "Alumnos de " << profesor << " a examen:\n";
                if (!v.empty()) {
                    for (int i = 0; i < v.size(); i++) {
                        std::cout << v[i] << '\n';
                    }
                }

            }
            else if (orden == "puntuacion") {
                std::cin >> alumno;
                int pts = aescuela.puntuacio(alumno);
                std::cout << "Puntuacion de " << alumno << ": " << pts << '\n';
            }
            else if (orden == "actualizar") {
                std::cin >> alumno >> punt;
                aescuela.actualizar(alumno, punt);
            }
            else if (orden == "aprobar") {
                std::cin >> alumno;
                aescuela.aprobar(alumno);
            }
            else
                std::cout << "ERROR\n";


        }
        catch (std::domain_error e) { std::cout << e.what() << '\n'; }

        std::cin >> orden;
    }
    std::cout << "---\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelve());
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;

}
