
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <stack>


bool esVocal(char c) {
    return
        c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u';
}

bool resuelveCaso() {
   
    std::string entrada;
    std::getline(std::cin, entrada);

    if (!std::cin)return false;

    std::queue <char> cola;
    int i;

    i = 0;
    while (i < entrada.size()) {
        if (i % 2 == 0)
            cola.push(entrada[i]);

        i++;
    }
    i = entrada.size() -1;
    
    while (i > -1) {
        if (i % 2 == 1)
            cola.push(entrada[i]);

        i--;
    }

    std::string salida;
    std::stack <char> aux;
    while (!cola.empty()) {
        //Pasamos todas las letras que comprobamos a minuscula
        
        while (!cola.empty() && !esVocal(std::tolower(cola.front()))) {
            aux.push(cola.front());
            cola.pop();
        }
        while (!aux.empty()) {
            salida.push_back(aux.top());
            aux.pop();
        }
        if (!cola.empty()) {
            salida.push_back(cola.front());
            cola.pop();
        }
       
    }

    std::cout << salida << '\n';

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
