// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <string>




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    std::cin >> tipo;

    if (!std::cin)
        return false;

    int i = 0, k;

    if (tipo == 'N') {//numeros
        std::set<int> conjN;
        int num;
        std::cin >> k;
        std::cin >> num;
        while (num != -1) {
            if (i < k) {
                if (!conjN.insert(num).second)
                    i--;
                conjN.insert(num);

            }
            else {
                if (*conjN.begin() < num && conjN.insert(num).second) {
                    conjN.erase(*conjN.begin());
                    conjN.insert(num);
                }
                
            }
            std::cin >> num;
            i++;
        }
        auto it = conjN.begin();
        while (it != conjN.end()) {
            std::cout << *it << " ";
            ++it;
        }
        

    }
    else {
        std::set<std::string> conjP;
        std::string palabra;
        
        std::cin >> k;
        std::cin >> palabra;
        while (palabra!= "FIN") {
            if (i < k) {
                if (!conjP.insert(palabra).second)
                    i--;
                conjP.insert(palabra);
            }
            else {
                if (*conjP.begin() < palabra && conjP.insert(palabra).second) {
                    conjP.erase(*conjP.begin());
                    conjP.insert(palabra);
                }

            }
            std::cin >> palabra;
            i++;
        }
        auto it = conjP.begin();
        while (it != conjP.end()) {
            std::cout << *it << " ";
            ++it;
        }
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
