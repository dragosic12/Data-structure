#include <fstream>
#include <list>
#include <iostream>
#include "Horas.h"

bool resuelveCaso() {
	int casos;
	std::cin >> casos;
	if (casos == 0) return false;

	std::list <Horas> lista;
	Horas aux;
	int i = 0;
	while (i < casos) {
		std::cin >> aux;
		lista.push_back(aux);
		i++;
	}

	auto it = lista.begin();
	i = 0;
	while (it != lista.end()) {
		if (i % 2 == 1) {
			it = lista.erase(it);
			i++;
		}
		i++;
		if (it != lista.end()) {
			it++;
		}
	}

	it = lista.begin();
	if (it != lista.end()) {
		std::cout << *it;
		++it;
	}
	for (; it != lista.end(); ++it)
		std::cout << ' ' << *it;
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
