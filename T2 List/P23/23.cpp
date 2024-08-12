#include <fstream>
#include <list>
#include <iostream>
#include <string>


class persona {
public:
	persona(int edad, std::string const &nombre) : edad(edad), nombre(nombre) {}
	
	int get_edad() const {
		return this->edad;
	}

	std::string get_nombre() const{
		return this->nombre;
	}

	void print(std::ostream& o) {
		//Para quitar el primer elemento que es un espacio en blanco
		this->nombre.erase(nombre.begin(), nombre.begin() + 1);
		
		o << this->nombre << '\n';
	}

	
private:
	std::string nombre;
	int edad;
};


class filtro_edad {
public:
	filtro_edad(int min, int max) : max(max), min(min) {}
	bool operator ()(persona p) {
		return (p.get_edad() >= min && p.get_edad() <= max);
	}
private:
	int max;
	int min;
};


template <class T, class Predicate>
void remove_if(std::list <T >& lista, Predicate pred) {

	auto it = lista.begin();

	while (it != lista.end()) {

		if (!pred(*it)) {//el valor no esta en el rango
			//eliminamos de la lista el elemento
			it = lista.erase(it);
		}
		else {
			++it;
		}
	}

}


inline std::ostream& operator << (std::ostream& o, persona & p) {
	p.print(o);
	return o;
}


bool resuelveCaso() {
	int casos, min, max;
	std::cin >> casos >> min >> max;
	if (casos == 0 && min == 0 && max == 0) return false;
	
	std::list<persona>lista;
	int i = 0, edad;
	std::string nomb;
	while (i < casos) {
		std::cin >> edad;
		std::getline(std::cin,nomb);
		
		lista.push_back(persona(edad,nomb));
		i++;
	}

	
	remove_if(lista, filtro_edad(min,max));

	auto it = lista.begin();
	while (it != lista.end()) {
		std::cout << *it;
		++it;
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





