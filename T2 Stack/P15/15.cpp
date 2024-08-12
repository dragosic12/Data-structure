//DRAGOS IONUT CAMARASAN
//GRUPO C10

#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

const int tam = 3;
const static char abierto[] = { '(','{','[' };
const static char cerrado[] = { ')','}',']' };

static bool estaAbierto(char c) {
	int i = 0;
	while (i < tam && abierto[i] != c) 
		++i;
	return i < tam;
}

static char inverso(char c) {
	for (int i = 0; i < tam; i++)
		if (cerrado[i] == c)
			return abierto[i];
	return ' ';
}

static bool esParentesis(char c) {
	int i = 0;
	while (i < tam && abierto[i] != c && cerrado[i] != c) ++i;
	return i < tam;
	
}

bool resuelveCaso() {
	bool ok = true;
	string v;
	getline(cin, v);
	if (!std::cin)
		return false;
	stack<char> c;
	int i = 0;
	while (i < v.size() && ok){
		if (esParentesis(v[i])) {
			//Si es abierto el parentesis se añade a la pila
			if (estaAbierto(v[i])) 
				c.push(v[i]);
			else {
				//Si es cerrado se comprueba que el ultimo elemento de la pila es del mismo tipo y en ese caso se elimina de la lista 
				if (c.empty()) {
					ok = false;
				}
				else if (c.top() != inverso(v[i])) {
					ok = false;
				}
				else 
					c.pop();
			}
		}
		++i;
	}
	//Si la pila esta vacia los parentesis estan equilibrados
	if (!c.empty())
		ok = false;

	if (ok) 
		cout << "SI" << endl;
	else 
		cout << "NO" << endl;
	

	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE

	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
