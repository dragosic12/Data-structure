// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    std::cin >> numCasos;
    if (numCasos == 0)
        return false;

    std::map<std::string, int> mapita;

    std::string alumno;
    std::string result;
    std::getline(std::cin, alumno);
    int i = numCasos;
    while (i > 0) {//Si es una pos par inserta ya que es el alumno
        std::getline(std::cin, alumno);
        if (!mapita.count(alumno))
            mapita.insert({ alumno,0 });

        std::getline(std::cin, result);

        if (result == "CORRECTO") 
            mapita.find(alumno)->second++;
        else 
            mapita.find(alumno)->second--;
        
        
        i--;
    }

    auto it = mapita.begin();
    while (it != mapita.end()) {
        if (it->second != 0)
            std::cout << it->first << ", " << it->second << '\n';

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
