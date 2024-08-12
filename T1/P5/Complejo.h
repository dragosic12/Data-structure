#ifndef COMPLEJO
#define COMPLEJO


#include <iostream>
#include <math.h>
#include <tgmath.h>
using namespace std;

class Complejo {
private:
	float real;
	float imaginario;

public:
	Complejo() {};
	Complejo(float r, float i) : real(r), imaginario (i){};
	Complejo operator+(const Complejo &comp) const {
		Complejo aux;
		aux.real = real + comp.real;
		aux.imaginario = imaginario + comp.imaginario;
		return aux;
		//return *this;
	};
	Complejo operator*(const Complejo &comp) const {
		Complejo aux;
		aux.real = (real * comp.real) - (imaginario * comp.imaginario);
		aux.imaginario = (real * comp.imaginario) + (comp.real * imaginario);
		return aux;
	};

	Complejo& operator = (Complejo const & comp) {
		real = comp.real;
		imaginario = comp.imaginario;
		return *this;
	}
	

	float modulo() {
		return sqrt(real * real + imaginario * imaginario);
	}
};

inline std::istream& operator>> (std::istream& ent, Complejo& c) {

	float r, i;
	//char aux;
	ent >> r >> i;

	c = Complejo(r, i);


	return ent;
}

#endif 