//DRAGOS IONUT CAMARASAN
//C10


#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm> 
#include "bintree_eda.h"

struct tDatos {
    int maximo;
    int minimo;
};

struct tSol {
    bool binario;
    tDatos datos;
};

const int MAX = 2146483647;//Myor valor de un entero

//Hay que tener un maximo y un minimo de los valores devuluetos
tSol esBinario(bintree <int> const& a) {

    tDatos sol{-1,MAX};
    if (a.empty()) 
        return { true,sol };
    else {
        int minimoR;
        int maximoR;
        tSol iz = esBinario(a.left());
        if (iz.binario) {
            tSol dr = esBinario(a.right());
            if (dr.binario) {

                minimoR = std::min(iz.datos.minimo, dr.datos.minimo);
                maximoR = std::max(dr.datos.maximo, iz.datos.maximo);

                if (iz.datos.maximo < a.root() && dr.datos.minimo > a.root())//Si el mayor elemento del hijo izquierdo es menor y el mayor elemento del derecho es mayor es binario, en caso contrario no lo es
                    return { true,{std::max(maximoR, a.root()) ,std::min(minimoR, a.root()) } };
                else 
                    return { false,{std::max(maximoR, a.root()),std::min(minimoR, a.root())} };
                

            }
            else
                return { false,sol };

        }
        else
            return { false,sol };

    }
    
}

void resuelveCaso() {
   
    bintree<int> a = leerArbol(-1);

    
    if (esBinario(a).binario) {
        std::cout << "SI" << '\n';
    }
    else {
        std::cout << "NO" << '\n';
    }
    
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int num_casos;
    std::cin >> num_casos;
    while (num_casos--) {
        resuelveCaso();
    }


#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);

    //system("PAUSE");
#endif

    return 0;
}
