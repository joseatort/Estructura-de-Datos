#ifndef TIEMPO_H
#define TIEMPO_H

#include <iostream>

#include <iomanip>
#include <fstream>
#include <iostream>
#include "error.h"
using namespace std;

class tiempo
{

	private:

		int hora;
		int minuto;
		int segundo;

	public:
	
		//Por defecto
		tiempo() : hora(0), minuto(0), segundo(0) {};

		//Con parametros 
		tiempo(int hora, int minuto, int segundo)
		{
			this->hora = hora;
			this->minuto = minuto;
			this->segundo = segundo;
		}

		int get_hora() const { return hora; }
		int get_minuto() const { return minuto; }
		int get_segundo() const { return segundo; }

		bool operator <(tiempo horas)
		{
			return ((hora < horas.hora) || (hora == horas.hora && minuto < horas.minuto)
				|| (hora == horas.hora && minuto == horas.minuto && segundo < horas.segundo));
		}

		bool operator ==(tiempo horas)
		{
			return (hora == horas.hora && minuto == horas.minuto && segundo == horas.segundo);
		}

		void imprimir(ostream& out)
		{
			out << setfill('0') << setw(2) << hora << ":"
				<< setw(2) << minuto << ":"
				<< setw(2) << segundo;
		}

		
		void leer(istream& out)
		{
			int horas, minutos, segundos;
			char puntos;

			cin >> horas >> puntos >> minutos >> puntos >> segundos;

			if (comprobar(horas, minutos, segundos))
			{
				hora = horas;
				minuto = minutos;
				segundo = segundos;
			}
			else
			{
				throw error("ERROR");
			}
		}

		bool comprobar(int h, int min, int s)
		{
			return ((h >= 0 && h <= 23) &&
				(min >= 0 && min <= 59) &&
				(s >= 0 && s <= 59));
		}

};

istream& operator>> (istream& is, tiempo& fecha)
{
	fecha.leer(is);
	return is;
}

ostream& operator<< (ostream& out, tiempo& fecha)
{
	fecha.imprimir(out);
	return out;
}

#endif //TIEMPO_H