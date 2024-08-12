#include <iostream>
#include <string> 
#include <sstream> 
#include <fstream>
#include <vector>
#include <stack>
#include <utility>


bool resuelveCaso() {
    int numCasos, aux;
    char c;
    std::stack <std::pair<int,int>> pila;
    std::vector <int> v;
    std::cin >> numCasos;
    int i = numCasos-1;
    int tam = 0;
    if (!std::cin) return false;

    while (numCasos--) {
        std::cin >> aux;
        v.push_back(aux);
    }
    numCasos = i + 1;
    std::pair <int, int> a;
    std::pair <int, int> fin;
    
    while (i > -1) {
        //v[i];
        a.first = v[i];
        a.second = i;
        
        if (pila.empty()) {
            pila.push(a);
        }
        else if (a < pila.top()) {
            pila.push(a);
        }
        else if (a >= pila.top()) {
            pila.pop();
            pila.push(a);
            
        }
        i--;
    }
    



    //std::cout << pila.size() << ' ';
    int indice = 0;
    
    if (!pila.empty())
        a = pila.top();
    while (!pila.empty()) {
        pila.pop();
        if (pila.size() > 0 && tam <=pila.top().second- a.second && pila.top().first > a.first) {

            tam = pila.top().second - a.second;
            indice = a.second;
            
            a = pila.top();
            
        }
        else if (!pila.empty()) {
            if (pila.top().first > a.first)
                a = pila.top();
        }
        //fin = pila.top();
        
        

    }

    if (tam <= numCasos - a.second) {
        tam = numCasos - a.second;
        indice = a.second;
    }
    
    
    std::cout << tam << ' ' << indice;

    std::cout << '\n';

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

}
