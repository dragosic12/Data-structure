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
#include <queue>
#include <utility>
#include <vector>
#include <list>
#include <unordered_set>

using empleo = std::string;
using nombre = std::string;
using persona = std::string;

class oficinaEmpleo {
    
    //empleo y lista de empleados
    std::unordered_map <empleo, std::list<nombre>> emp;
    //nombre del empleado, sus empleos y los iteradores de cada empleo, indicando la pocicion en la que se encuentra cada empleado en la lista de empleos
    std::unordered_map <nombre, std::unordered_map<empleo, std::list<std::string>::iterator> > empleados;

public:


    void altaOficina(std::string nombre, std::string empleo) {
        auto & it = emp[empleo];

        auto& aux = empleados[nombre];//Aqui metemos los nuevos empleados con su empleo

        if (!aux.count(empleo)) {
            auto a = it.insert(it.end(), nombre);
            aux[empleo] = a;
        }
       

    }

    persona ofertaEmpleo(std::string empleo) {
        persona sol;

        auto& it = emp[empleo];

        if (it.empty() )
            throw std::domain_error("No existen personas apuntadas a este empleo");
        

        sol = it.front();//
        //La persona dejara de estar apuntada
        //primero la quitamos de todas las listas de empleo
        auto i = empleados[sol];//a lo mejor se va de coste aqui, en ese caso habria que a adir algun iterador
        for (auto aux : i) {
            auto& otro = emp[aux.first];
            otro.erase(aux.second);

            if (otro.size() == 0)
                emp.erase(aux.first);
            
        }

        empleados.erase(sol);
        
        return sol;
    }

    std::vector<std::string>listadoEmpleos(std::string persona) {
        if (!empleados.count(persona))
            throw std::domain_error("Persona inexistente");

        std::vector<std::string> sol;

        auto& aux = empleados[persona];
        for (auto it : aux) //Recorremos los empleos del empleado para buscar luego mirar en la lista si coincide con que es el primero
            sol.push_back(it.first);
        

        sort(sol.begin(), sol.end(), [](std::string const& a, std::string const& b) {
            return (a < b);

            });

            //ordenamos el vector
                return sol;
    }



};



bool resuelve() {

    std::string orden;

    std::cin >> orden;
    if (!std::cin) return false;

    oficinaEmpleo oe;


    while (orden != "FIN") {
        try {
            if (orden == "altaOficina") {
                std::string empleo, nombre;
                std::cin >> nombre >> empleo;
                oe.altaOficina(nombre, empleo);
            }
            else if (orden == "ofertaEmpleo") {
                std::string empleo;
                std::cin >> empleo;
                std::string sol = oe.ofertaEmpleo(empleo);
                std::cout << empleo << ": " << sol << '\n';
            }
            else if (orden == "listadoEmpleos") {
                std::string nombre;
                std::cin >> nombre;
                std::vector<std::string> sol = oe.listadoEmpleos(nombre);
                std::cout << nombre << ':';
                for (auto it : sol) {
                    std::cout << ' ' << it;
                }
                std::cout << '\n';

            }
        }
        catch (std::domain_error e) { std::cout << "ERROR: " << e.what() << '\n'; }

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


