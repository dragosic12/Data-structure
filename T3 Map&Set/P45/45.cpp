// DRAGOS IONUT CAMARASAN
// C10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>



void resuelveCaso() {
    
   
    std::map <std::string, int> m1;
    std::map <std::string, int> m2;
    std::set<std::string>sum;
    std::set<std::string>rest;
    std::set<std::string>mul;


    std::string frase1,frase2,aux, aux1;
    int num = 0;

    
    std::getline(std::cin, frase1);
    std::getline(std::cin, frase2);


    std::stringstream ss(frase1);

    while (ss) {

        ss >> aux;
        ss >> num;
        m1.insert({ aux,num });
    }
    
    std::stringstream ss2 (frase2);

    while (ss2) {

        ss2 >> aux1;
        ss2 >> num;
        
        if (aux1 != "") {
            m2.insert({ aux1,num });

            if (m1.insert({ aux1,num }).second) //Si se ha podido insertar el valor significa que se añadio y se pone un +
                sum.insert(aux1);
        }
    }

    for (auto valor : m1) {
        
        if (!m2.count(valor.first) && valor.first != "") //Si el valor del primer vector no esta en el segundo se pone un menos 
            rest.insert(valor.first);
        else {
            if (valor.second != m2[valor.first])
                mul.insert(valor.first);
        }
        

    }
    if (!sum.empty()) {
        std::cout << "+ ";
        for (auto suma : sum) 
            std::cout << suma << ' ';
        std::cout << '\n';
    }

    
    if (!rest.empty()) {
        std::cout << "- ";
        for (auto resta : rest) 
            std::cout << resta << ' ';
        std::cout << '\n';
    }

    
    if (!mul.empty()) {
        std::cout << "* ";
        for (auto multi : mul) 
            std::cout << multi << ' ';
        std::cout << '\n';
    }

    if (sum.empty() && rest.empty() && mul.empty())
        std::cout << "Sin cambios\n";

   

    std::cout << "---\n";


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

    std::cin.ignore();
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
