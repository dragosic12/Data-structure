// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

/*
char c;
std::cin >> c;
if (!std::cin) return false;
linked list ed plus < std::string> lista;
std::string str;
getline(std::cin, str); // para saltar el final de linea
getline(std::cin, str); // lee la linea del caso
std::stringstream ss(str); // construye el objeto ss de tipo stringstream
while (ss) {
std::string aux;
ss >> aux;
lista.push back(aux);
}
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    std::cin >> numCasos;
    if (numCasos == 0)
        return false;

    std::map<std::string, std::set<int>> arbol;
    std::string frase;
    

    std::cin.ignore();
    int i = 0;
    while (i < numCasos) {
        std::getline(std::cin,frase);
        

        std::stringstream ss(frase);
        
        while (ss) {

            std::string aux;
            ss >> aux;
            for (int j = 0; j < aux.size(); j++) 
                aux[j] = tolower(aux[j]);
            
            if (aux != "" && aux.size() >2) {
                if (arbol.count(aux) == 0) {
                    std::set<int> v;
                    v.insert(i+1);
                    arbol.insert({ aux, v });
                }
                else
                    arbol[aux].insert(i+1);
            }
            //auto it = arbol.insert(frase[i]);


        }
        i++;

    }

    

    auto it = arbol.begin();
    i = 0;
    while (it != arbol.end()) {

        std::cout << it->first;
        auto conj = it->second.begin();
        while (conj != it->second.end()) {
            std::cout << " " << *conj ;
            conj++;
        }
        std::cout << '\n';
        i = 0;
        

        ++it;
    }

    std::cout << "---\n";
    //TipoSolucion sol = resolver(datos);

    // escribir sol

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
