#ifndef PELICULAS
#define PELICULAS

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Horas.h"

class peliculas {

public:
    //constructor de la clase debe comprobar que las horas son correctas
    peliculas() {}
    peliculas(Horas ini, Horas fin, std::string titulo) : ini(ini), titulo(titulo), fin(fin) {};

    bool operator< (peliculas const& p) {
        if (fin < p.fin) return true;
        else if (fin == p.fin) return (this->titulo < p.titulo);
        else return false;;
        
    }

    peliculas& operator= (peliculas const& p) {
        if (this != &p) {
            ini = p.ini;
            fin = p.fin;
            titulo = p.titulo;
        }

        return *this;

    }

    void suma() {
        fin = fin + ini;
    }
    
   
    Horas get_ini()const { return ini; }
    Horas get_fin() const { return fin; }
    std::string get_titulo()const { return titulo; }

private:
    
    std::string titulo;
    Horas ini;
    Horas fin;

};

inline std::ostream& operator<< (std::ostream& sal, peliculas const & p) {
    sal << p.get_fin() << p.get_titulo() << '\n';

    return sal;
}

inline std::istream& operator>> (std::istream& ent, peliculas & p) {

    Horas ini;
    Horas suma;
    std::string tit;
    ent >> ini;
    ent >> suma;
    std::getline(ent, tit);

    p = peliculas (ini,suma, tit);
    
    return ent;
}



#endif 