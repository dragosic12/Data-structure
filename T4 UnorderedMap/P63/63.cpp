#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

using jugador = std::string;
using equipo = std::string;


class gestor_futbolistas {

	struct infoJug {
		std::list<std::string>::iterator it;
		equipo e;
	};

	std::unordered_map<jugador, infoJug> jug;
	std::unordered_map<jugador, std::unordered_set<std::string>> numEquipos;
	std::unordered_map<equipo, std::list<std::string>> equipos;



public:

	void fichar(std::string const&jugador, std::string const &equipo) {
		
		/*
		auto aux = jug.find(jugador);
		numEquipos[jugador].insert(equipo);
		//Si existe el futbolita lo cambiamos de equipo
		if (aux != jug.end()) {
			if (equipo != jug[jugador].e) {
				equipos[aux->second.e].erase(aux->second.it);
				auto & aux1 = jug[jugador];
				aux1.e = equipo;
				auto& aux2 = equipos[equipo];
				aux1.it = aux2.insert(aux2.begin(), jugador);

			}

		}
		else {//Si no existe el futbolista se le añade un equipo 
			auto& otro = jug[jugador];
			otro.e = equipo;
			auto& otro1 = equipos[equipo];
			otro.it = otro1.insert(otro1.begin(), jugador);

		}*/
		
		auto & j = jug[jugador];
		if (j.e != equipo) {//si el equipo es diferente se le asigna el nuevo equipo. Hay que ver si esto se cumple cuando el primer valor es vacio
			if (j.e != "") {//En caso de que ya tenga asignado un equipo todavia
				equipos[j.e].erase(j.it);
				//Borramos el jugador de su equipo actual, no del nuevo


			}
			auto& aux = equipos[equipo];
			auto a = aux.insert(aux.begin(), jugador);//Insertamos el jugador en el nuevo equipo
			j.it = a;

			j.e = equipo;
			numEquipos[jugador].insert(equipo);
		}
		
		//Si es el mismo equipo no se hace nada
			

		

	}

	std::string equipo_actual(std::string const& jugador) {
		std::string sol;

		if (!jug.count(jugador))
			throw std::domain_error("Jugador inexistente");
		sol = jug[jugador].e;

		return sol;

	}

	int fichados(std::string const& equipo) {
		int sol = 0;

		if (!equipos.count(equipo))
			throw std::domain_error("Equipo inexistente");
		sol = equipos[equipo].size();

		return sol;

	}

	std::vector<std::string> ultimos_fichajes(std::string const& equipo, int& n) {
		std::vector<std::string> sol;

		if (!equipos.count(equipo))
			throw std::domain_error("Equipo inexistente");

		auto & aux = equipos[equipo];
		auto it = aux.begin();
		while (n--) {
			if (it != aux.end()) {
				sol.push_back(*it);
				//sol.push_front(*it);

				++it;
			}
		}

		return sol;
	}

	int cuantos_equipos(std::string const & jugador) {
		int sol = 0;

		if (!jug.count(jugador))
			return 0;

		sol = numEquipos[jugador].size();

		return sol;
	}


};

bool resuelveCaso() {
	
	gestor_futbolistas gestor;
	std::string action;
	std::cin >> action;
	if (!std::cin)  return false; 

	while (action != "FIN") {

		try {
			if (action == "fichar") {
				std::string jugador, equipo;
				std::cin >> jugador >> equipo;
				gestor.fichar(jugador, equipo);
			}
			else if (action == "equipo_actual") {
				std::string jugador, equipo;
				std::cin >> jugador;
				equipo = gestor.equipo_actual(jugador);
				std::cout << "El equipo de " << jugador << " es " << equipo << "\n";
			}
			else if (action == "fichados") {
				std::string jugador, equipo;
				std::cin >> equipo;
				int n = gestor.fichados(equipo);
				std::cout << "Jugadores fichados por " << equipo << ": " << n << "\n";
			}

			else if (action == "ultimos_fichajes") {
				std::string jugador, equipo;
				int n;
				std::cin >> equipo >> n;
				std::vector<std::string> l = gestor.ultimos_fichajes(equipo, n);
				
				std::cout << "Ultimos fichajes de " << equipo << ":";
				for (auto it : l) {
					std::cout << ' ' << it;
					
				}
				std::cout << "\n";
			}
			else if (action == "cuantos_equipos") {
				std::string jugador, equipo;
				
				std::cin >> jugador;
				int n = gestor.cuantos_equipos(jugador);
				std::cout << "Equipos que han fichado a " << jugador << ": " << n << "\n";
			}
		}
		catch (std::domain_error& err) {
			std::cout << "ERROR: " << err.what() << "\n";
		}

		std::cin >> action;
	}

	std::cout << "---\n";
	return true;
}



int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif

	return 0;

}
