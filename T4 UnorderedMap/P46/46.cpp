// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <set>



void resuelveCaso() {
    int numCapitulos, cap, contador = 0, max = 0;

    std::cin >> numCapitulos;

    std::unordered_map <int,int> mapita;
    
    int i = 0;

    while (i < numCapitulos) {
        std::cin >> cap;

        if (mapita.count(cap) && mapita[cap] >= contador)//Para los repetidos. Si ya tiene el elemeto y su posicion esta por delante, se actualiza esa posicion pasando al siguiente elemento
            contador = mapita[cap] + 1;
        max = std::max(max, i - contador + 1);//se va mirando si el maximo es mayor a la diferencia entre el contador y la i
        mapita[cap] = i;//se guarda para cada clave su indice como valor
        i++;
    }

    std::cout << max << '\n';


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    std::cin >> numCasos;

    while (numCasos--) {
        resuelveCaso();

    }



    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
