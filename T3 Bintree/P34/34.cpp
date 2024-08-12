// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tDatos {
    int diametro;
    int altura;

};

tDatos diametro(bintree<char> const & a) {
    tDatos d{0,0};
    if (a.empty()) {
        return d;
    }
    else {
       
        tDatos iz = diametro(a.left());
        tDatos dr = diametro(a.right());


        if (iz.altura > dr.altura) //Guardamos la mayor de las dos altruas
            d.altura = iz.altura;
        else 
            d.altura = dr.altura;

        d.altura++;

        int aux;
        if (iz.diametro > dr.diametro)//Guardamos el mayor de los dos diametros en una variable auxiliar
            aux = iz.diametro;
        else 
            aux = dr.diametro;
        


        if (iz.altura + dr.altura + 1 > aux) //Nos quedamos con el mayor entre la suma de las alturas totales y el mayor diametro hasta ahora
            d.diametro = iz.altura + dr.altura + 1;
        else 
            d.diametro = aux;
        
     
       

        return d;
    }


}


void resuelveCasos(int casos) {
    // leer los datos de la entrada

    bintree<char> arbol;
    while (casos--) {
        arbol = leerArbol('.');
        tDatos d = diametro (arbol);
        std::cout << d.diametro << '\n';

    }
    // escribir sol




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
