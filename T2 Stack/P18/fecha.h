//
//  queue_eda.h
//
//  Implementación del TAD cola con nodos enlazados
//  y punteros al primero y al último nodo
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef fecha_h
#define fecha_h

#include <iostream>
#include <iomanip>
#include <stdexcept>  // std::domain_error


class fecha {

public:
    fecha() {};
    fecha(int d, int m, int a) :dia(d), mes(m), anyo(a) {
        if (d < 0 || d > MAX_DIA)
            throw std::invalid_argument("ERROR");
        else if (m < 0 || m > MAX_MES)
            throw std::invalid_argument("ERROR");

    }

    fecha& operator= (fecha const& o) {
        if (this != &o) {
            dia= o.dia; mes = o.mes; anyo = o.anyo;
        }
        return *this;
    }

    std::string  toString() {
        std::string aux(std::to_string(dia));
        std::string aux1(std::to_string(mes));
        std::string aux2(std::to_string(anyo));
        std::string fin = aux + '/' + aux1 +'/' + aux2;
        return fin;
    }

    bool operator!= (fecha const o) {
        return !(*this == o);
        
    }

    bool operator == (fecha const o) {
        return (dia == o.dia && mes == o.mes && anyo == o.anyo);

    }

    int get_dia() const { return dia; }
    int get_mes() const { return mes; }
    int get_anyo() const { return anyo; }


private:
    const int MAX_DIA = 32;
    const int MAX_MES = 13;
	int dia, mes, anyo;

};


inline std::ostream& operator<< (std::ostream& sal, fecha const& h) {
    fecha aux(0,0,0);
    if (aux != h) {
        sal << std::setfill('0') << std::setw(2) << h.get_dia() << '/' << std::setfill('0') << std::setw(2) << h.get_mes() << '/' << std::setfill('0') << std::setw(2) << h.get_anyo();
    }
    else {
        sal << "NO HAY" ;
    }
    sal << '\n';
    return sal;

}

inline std::istream& operator>> (std::istream& ent, fecha & h) {
    int dia, mes, anyo;
    char aux;
    ent >> dia;
    ent >> aux;
    ent >> mes;
    ent >> aux;
    ent >> anyo;
    h = fecha(dia, mes, anyo);
    return ent;
}

#endif // fecha
