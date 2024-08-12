//DRAGOS IONUT CAMARASAN
//C10
//Video explicativo: https://www.youtube.com/watch?v=sNl9D0GJ_Pc

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

class urgencias {

    struct infoPaciente {
        int gravedad;
        std::list<std::string>::iterator enCola;
    
    };
    //Para saber donde esta el paciente dentro de la lista de gravedad es necesario mantener un iterador con esa informacion por si mejora
    std::unordered_map<std::string, infoPaciente> pacientes;
    //otra forma para hacer los recuperados es con un vector y luego ordenarlo
    std::set<std::string> lista_recup;
    //Siguiente. Necesitamos 3 listas para saber cuales son las 3 gravedades
    //Otr forma de hacerlo es con un vector con las 3 listas
    std::list<std::string> lista3;
    std::list<std::string> lista2;
    std::list<std::string> lista1;

    


public:

    void nuevo_paciente(const std::string & paciente, const int &gravedad) { //O(1) ya que cada operacion tiene coste constante
        if (gravedad < 1 || gravedad > 3) //O(1)
            throw std::domain_error("Gravedad incorrecta");
            
       
            if (!pacientes.count(paciente)) {
                if (gravedad == 3) {
                    lista3.push_back(paciente);//O(1)
                    pacientes.insert({ paciente,{gravedad,--(lista3.end())}});//O(1)
                }
                if (gravedad == 2) {
                    lista2.push_back(paciente); //O(1)
                    pacientes.insert({ paciente,{gravedad,--(lista2.end())}});//O(1)
                      
                }
                if (gravedad == 1) {
                    lista1.push_back(paciente);//O(1)
                    pacientes.insert({ paciente,{gravedad,--(lista1.end())}});//O(1)
                }
            }else
                throw std::domain_error("Paciente repetido");
       
           
        
    }

    int gravedad_actual(const std::string & paciente) {//O(1) 
        auto aux = pacientes.find(paciente);
        if (aux == pacientes.end())
            throw std::domain_error("Paciente inexistente");
        else
            return aux->second.gravedad;

    }

    std::string siguiente() {//O(1) ya que en el peor de los casos, hacer la comprobacion de que las 3 colas esten vacias es O(1)
        std::string sol;
        //Los que salen de la lista se recuperan
        if (!lista3.empty()) {
            sol = lista3.front();
            pacientes.erase(sol);
            lista3.pop_front();
        }
        else if (!lista2.empty()) {

            sol = lista2.front();
            pacientes.erase(sol);
            lista2.pop_front();
        }
        else if (!lista1.empty()) {
            sol = lista1.front();
            pacientes.erase(sol);
            lista1.pop_front();

        }
        else
            throw std::domain_error("No hay pacientes");

        return sol;

    }

    void mejora(std::string paciente) {//O(1) ya que se va a ejecutar una de las 3 condiciones. Y estas tienen un maximo de 3 operaciones constantes O(1)

       if (!pacientes.count(paciente)) 
           throw std::domain_error("Paciente inexistente"); 
       
       auto& aux = pacientes[paciente];//O(1)
       if (aux.gravedad == 3) {
           lista3.erase(aux.enCola);
           lista2.push_front(paciente);
           aux.enCola = lista2.begin();
       }
       else if (aux.gravedad == 2) {
           lista2.erase(aux.enCola);
           lista1.push_front(paciente);
           aux.enCola = lista1.begin();
       }
       else {//Estaba leve y se recupera
           lista1.erase(aux.enCola);
           lista_recup.insert(paciente);
           pacientes.erase(paciente);

       }
       aux.gravedad--;
      
    }


    std::vector<std::string>recuperados() {//O(recuperados)
        std::vector<std::string> l;
        
        for (auto it : lista_recup) {
            l.push_back(it);
        }
        return l;
    }
    



};



bool resuelve() {

    std::string orden;

    std::cin >> orden;
    if (!std::cin) return false;

    urgencias sp;

    while (orden != "FIN") {
        try {
            if (orden == "nuevo_paciente") {
                std::string nombre; int grav;
                std::cin >> nombre >> grav;
                sp.nuevo_paciente(nombre,grav);
            }
            else if (orden == "mejora") {
                std::string nombre;
                std::cin >> nombre;
                sp.mejora(nombre);
            }
            else if (orden == "siguiente") {
                std::string sig = sp.siguiente();
                std::cout << "Siguiente paciente: " << sig << '\n';
            }
            else if (orden == "gravedad_actual") {
                std::string nombre;
                std::cin >> nombre;
                int g = sp.gravedad_actual(nombre);
                std::cout << "La gravedad de " << nombre << " es " << g << '\n';
            }
            else if (orden == "recuperados") {
                std::vector<std::string> l = sp.recuperados();
                
                std::cout << "Lista de recuperados: ";
                if (!l.empty()) {
                    for (auto it : l) {//O(recuperados)
                        std::cout << it << ' ';
                    }
                }
                std::cout << '\n';
            }
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n'; 
        }
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


