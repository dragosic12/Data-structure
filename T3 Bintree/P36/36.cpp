// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tDatos {
    int altura;
    int valor;
};


bool esPrimo(int numero) {
    // Casos especiales
    if (numero == 0 || numero == 1 || numero == 4) return false;
    for (int x = 2; x < numero / 2; x++) {
        if (numero % x == 0) return false;
    }
    // Si no se pudo dividir por ninguno de los de arriba, sí es primo
    return true;
}

tDatos busquedaPorAltura(bintree<int> a) {
    if (!a.empty()) {
        std::queue<std::pair<int,bintree<int>>> pendientes;
        pendientes.push({ 1,a });
        while (!pendientes.empty()) {
            auto sig = pendientes.front();
            pendientes.pop();

            if (!esPrimo(sig.second.root()) && sig.second.root() % 7 == 0) {//Si no hay primo y es multiplo de 7 se añade
                
                return { sig.first,sig.second.root()};
            }
            else if (!esPrimo(sig.second.root())) {//si en la raiz hay algun primo no se mira esa rama

                if (!sig.second.left().empty())
                    pendientes.push({ sig.first + 1, sig.second.left() });
                if (!sig.second.right().empty())
                    pendientes.push({ sig.first + 1, sig.second.right() });
            }
           
            
        }
    }
    return {0,0};
}

//Hay que recorrerlo por alturas
void resuelveCasos(int casos) {
    // leer los datos de la entrada

    bintree<int> arbol;
    while (casos--) {
        arbol = leerArbol(-1);
        auto v1 = busquedaPorAltura(arbol);
       
        if (v1.altura != 0) 
            std::cout << v1.valor << ' ' << v1.altura;
        else
            std::cout << "NO HAY";
        std::cout << '\n';
    }
   

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int casos;
    std::cin >> casos;
    resuelveCasos(casos);


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
