
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

void borraPos(std::queue <int> & lls,const int n, const int saltos) {

    int i = 0;
    while (lls.size() != 1) {
        
        while (i < saltos) {
            lls.push(lls.front());
            lls.pop();

            i++;
        }
        i = 0;
        lls.pop();
    }
}





void resuelveCaso(const int n, const int& saltos) {
    std::queue <int> lls;
    for (int i = 1; i <= n; i++) {
        lls.push(i);
    }
    
    
    borraPos(lls,n, saltos);
    
    std::cout << lls.front() << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numAlumnos, saltos;
    std::cin >> numAlumnos;
    std::cin >> saltos;
    while (numAlumnos != 0 && saltos != 0) {
        resuelveCaso(numAlumnos, saltos);
        std::cin >> numAlumnos;
        std::cin >> saltos;
    }
   

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
