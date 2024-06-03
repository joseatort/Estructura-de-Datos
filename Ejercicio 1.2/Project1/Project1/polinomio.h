#ifndef polinomio_h
#define polinomio_h

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class polinomio
{
private:	
	int coeficiente;
	int grado;

public:

	polinomio() : coeficiente(0), grado(0) {};

	polinomio(int c, int g)
	{
		this->coeficiente = c;
		this->grado = g;
	}

	int getcoeficiente() { return coeficiente; };
	int getgrado() { return grado; };

	//cambiar a vectores

	void read(istream& is)
	{
		cin >> coeficiente;
		cin >> grado;

	}

	void sumar(int coeficient)
	{
		coeficiente += coeficient;
	}

};


istream& operator >> (istream& is, polinomio& monomio)
{
	monomio.read(is);
	return is;
}


#endif //polinomio_h