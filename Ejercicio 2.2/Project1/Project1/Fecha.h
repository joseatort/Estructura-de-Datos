#ifndef TIEMPO_H
#define TIEMPO_H

#include <iostream>

#include <iomanip>
#include <fstream>
#include <iostream>
#include "error.h"
using namespace std;

class fecha
{

	private:

		int dia;
		int mes;
		int anio;
		int accidentados;
	public:
	
		//Por defecto
		fecha() : dia(0), mes(0), anio(0), accidentados(0){};

		//Con parametros 
		fecha(int dia, int mes, int anio, int accidentados)
		{
			this->dia = dia;
			this->mes = mes;
			this->anio = anio;
			this->accidentados = accidentados;
		}

		int get_dia() const { return dia; }
		int get_mes() const { return mes; }
		int get_anio() const { return anio; }
		int get_accidentados() const { return accidentados; }
		void leer(istream& out)
		{
			char barra;
			cin >> this->dia >> barra >> this->mes >> barra >> this->anio >> this->accidentados;

		}

		void write(ostream& out)
		{
			out << setfill('0') << setw(2) << dia << "/"
				<< setw(2) << mes << "/"
				<< setw(2) << anio;
		}

};

istream& operator>> (istream& is, fecha& fecha)
{
	fecha.leer(is);
	return is;
}

ostream& operator<< (ostream& os, fecha& fecha)
{
	fecha.write(os);
	return os;
}
#endif //TIEMPO_H