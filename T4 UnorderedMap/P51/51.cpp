

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


class carnet_puntos {

private:

    std::unordered_map<std::string, int> cond;
    std::unordered_map<int, std::set<std::string>> ptsCond;
    const int MAX_PTS = 15;

public:
    void nuevo(std::string dni) {
        //Si el dni del conductor esta duplicado lanzamos excepcion
        if (!cond.insert({ dni,MAX_PTS }).second)
            throw std::domain_error("ERROR: Conductor duplicado");
        else {
            ptsCond[MAX_PTS].insert(dni);
        }
    }

    //Resta puntos al conductor. Si se queda en negativo es un 0
    //Si no existe 
    void quitar(std::string dni,int puntos) {
        if (!cond.count(dni))
            throw std::domain_error("ERROR: Conductor inexistente");
        else {
            auto& aux = cond[dni];
            ptsCond[aux].erase(dni);
            aux = aux - puntos;
            if (aux < 0)
                aux = 0;
            ptsCond[aux].insert(dni);
        }
    }

    //Devuelve los puntos actuales del conductor
    int consultar(std::string dni) {
        if (!cond.count(dni))
            throw std::domain_error("ERROR: Conductor inexistente");
        else {
            return cond[dni];
        }
    }
    //devuelve cuántos conductores tienen un determinado número de puntos
    int cuantos_con_puntos(int puntos) {
        int sol = 0;
        if (puntos > MAX_PTS || puntos < 0) 
            throw std::domain_error("ERROR: Puntos no validos");
        return ptsCond[puntos].size();
        
    }


};

bool resuelve() {

    std::string orden;
    
    std::cin >> orden;
    if (!std::cin) return false;

    carnet_puntos dgt;

    std::string dni;
    int pts;

    while (orden!="FIN") {
        try {
            if (orden == "nuevo") {
                std::cin >> dni;
                dgt.nuevo(dni);
            }
            else if (orden == "cuantos_con_puntos") {
                std::cin >> pts;
                int numConduct = dgt.cuantos_con_puntos(pts);
                std::cout << "Con " << pts << " puntos hay " << numConduct << '\n';
            }
            else if (orden == "quitar") {
                std::cin >> dni >> pts;
                dgt.quitar(dni, pts);
            }
            else if (orden == "consultar") {
                std::cin >> dni;
                int puntos = dgt.consultar(dni);
                std::cout << "Puntos de " << dni << ": " << puntos << '\n';
            }


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
