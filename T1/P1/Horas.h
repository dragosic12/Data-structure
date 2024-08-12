#ifndef HORAS
#define HORAS

#include <iostream>
#include <stdexcept>
#include <iomanip>

class Horas {

public:
    //constructor de la clase debe comprobar que las horas son correctas
    Horas() {};
    Horas(int h, int m, int s) :hora(h), min(m), seg(s) {
        if (h < 0 || h > MAX_HORAS)
            throw std::invalid_argument("Horas no validas");
        else if (m < 0 || m > MAX_MIN)
            throw std::invalid_argument("Horas no validas");
        else if (s < 0 || s > MAX_SEG)
            throw std::invalid_argument("Horas no validas");

    }

    int get_hora() const { return hora; }
    int get_min() const { return min; }
    int get_seg() const { return seg; }
    
    bool operator < (Horas const& h) const {
        if (hora < h.hora) return true;
        else if (hora > h.hora) return false;
        else if (min < h.min) return true;
        else if (min > h.min) return false;
        else if (seg < h.seg) return true;
        else return false;
        /*
        if (anyo < f.anyo) return true;
        else if (anyo > f.anyo) return false;
        else if (mes < f.mes) return true;
        else if (mes > f.mes) return false;
        else if (dia < f.dia) return true;
        else return false;
        */
    }

    bool operator == (Horas const& h) const {
        return hora == h.hora && min == h.min && seg == h.seg;
        //return anyo == f.anyo && mes == f.mes && dia == f.dia;
    }

    Horas& operator= (Horas const& o) {
        if (this != &o) {
            hora = o.hora; min = o.min; seg = o.seg;
        }
        return *this;
    }
    

    Horas& operator+(Horas const& o) {
        
        this->seg = this->seg + o.seg;
       
        if (this->seg  > MAX_SEG) {
            this->seg = this->seg - MAX_SEG - 1;
            this->min++;
        }
        
        this->min = o.min + this->min;
        if (this->min > MAX_MIN) {
            this->min = this->min - MAX_MIN - 1;
            this->hora++;
        }

        this->hora = o.hora + this->hora;

        if (this->hora > MAX_HORAS)
            throw std::overflow_error("hoy no");

        return *this;

    }


private:
    const int MAX_HORAS = 23;
    const int MAX_MIN = 59;
    const int MAX_SEG = 59;
    int hora, min, seg;

};

inline std::ostream& operator<< (std::ostream& sal, Horas const& h) {
    
    sal << std::setfill('0') << std::setw(2)<< h.get_hora() << ':' << std::setfill('0') << std::setw(2) << h.get_min() << ':' << std::setfill('0') << std::setw(2) << h.get_seg();
    return sal;

}

inline std::istream& operator>> (std::istream& ent, Horas & h) {
    int hora, min, seg;
    char aux;
    ent >> hora;
    ent >> aux;
    ent >> min;
    ent >> aux;
    ent>> seg;
    h = Horas(hora, min, seg);
    return ent;
}

#endif 