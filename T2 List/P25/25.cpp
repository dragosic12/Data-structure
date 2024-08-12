// DRAGOS IONUT CAMARASAN
// C10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>


std::list<char> resolver(std::list <char> & lista) {
    std::list <char> aux;
    auto it = lista.begin();
    auto it2 = aux.begin();
    bool front = false;
    bool back = false;
    while (it != lista.end()) {
        if (*it == '-') {
            it2 = aux.begin();
        }
        else if (*it == '+') {
            it2 = aux.end();
        }
        else if (*it == '*') {
            if (it2 != aux.end())
                ++it2;
        }
        else if (*it == '3') {
            if (it2 != aux.end())
                it2 = aux.erase(it2);
        }
        else {//Metes las letras en la lista aux
            //Metemos la letra antes de la poscion indicada por it2
            aux.insert(it2, *it);
           
        }
        ++it;
    }

    return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string entrada;

    std::cin >> entrada;

    if (!std::cin)
        return false;

    std::list<char>lista;
    int i = 0;

    while (i < entrada.size()) {
        lista.push_back(entrada[i]);

        i++;
    }

    std::list <char> result = resolver(lista);

    auto it = result.begin();
    while (it != result.end()) {
        std::cout << *it;
        ++it;
    }
    std::cout << '\n';
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
