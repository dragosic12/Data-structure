// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include "bintree_eda.h"


/*
// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree<T> leerArbol(T vacio) {
   T raiz;
   std::cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol(vacio);
      auto dr = leerArbol(vacio);
      return {iz, raiz, dr};
   }
*/

inline bintree <long int> arbolPostorden(std::vector <long int> & pre, std::vector <long int> & in) {

    bintree <long int> sol;//introducimos la raiz en el arbol que vamos a devolverç
    if (!pre.empty())
        sol = (pre[pre.size() - 1]);
    std::vector <long int> iz;
    std::vector <long int> dr;
    int i = 0;
    if (in.empty()){
        return {};
    }
    else {
        while (pre[pre.size() - 1] != in[i]) {
            iz.push_back(in[i]);
            i++;
        }
        i++;
        while (i < in.size()) {
            dr.push_back(in[i]);
            i++;
        }

        if (!pre.empty() && !in.empty()) {
            pre.pop_back();
        }
        auto aiz = arbolPostorden(pre, iz);
        auto adr = arbolPostorden(pre, dr);
        return { aiz,sol.root(),adr };
    }
    /*
    std::vector<int> iz;
    std::vector<int> dr;
    
    

    int i = 0, j = 0, medio;
    while (pre[j] != in[i]) {//obtenemos la posicion de la raiz del arbol en el inorden y guardamos en un vector aux la parte izquierda y en otro la parte derecha
        iz[i] = in[i];
        i++;

    }
    
    medio = i;
    j++;
    while (i < in.size()) {//obtenemos los datos en el vector derecho
        dr[i] = in[i];
        i++;
    }
    while (!dr.empty() && !iz.empty()) {
        sol.left()

    }*/
    
    return sol;

}


//Hay que recorrerlo por alturas
bool resuelveCasos() {
    // leer los datos de la entrada

    
    std::vector <long int> v1, v2;
    std::vector <int> enteros;
    std::string aux;
    std::getline(std::cin, aux);

    if (!std::cin) return false;

    int i = aux.size() -1, valor = 0, j = 0;
    while (i > -1) {
        while (i > -1 && aux[i] != ' ' ){
            valor = (aux[i] - '0') * pow(10,j) + valor;
            i--;
            j++;
        }
        v1.push_back(valor);
        valor = 0;
        j = 0;
        i--;
    }

    
    std::getline(std::cin, aux);
    i = 0;

    while (i < aux.size()) {
        while (i < aux.size() && aux[i] != ' ') {
            valor = (valor * 10) + (aux[i] - '0');
            i++;
            j++;
        }
        v2.push_back(valor);
        valor = 0;
        j = 0;
        i++;
    }

    auto arbol = arbolPostorden(v1,v2);
    auto v = arbol.postorder();
    i = 0;
    if (!v.empty()) {
        std::cout << v[i];
        i++;
    }
    while (i < v.size()) {
        std::cout << ' ' << v[i];
        i++;
    }

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

    
    while (resuelveCasos())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
