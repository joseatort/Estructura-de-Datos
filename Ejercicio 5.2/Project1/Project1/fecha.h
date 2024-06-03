#ifndef FECHA_H
#define FECHA_H

#include <iostream>

#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;
class fecha
{

private:

	int Dia;
	int hora;
	int minuto;

public:

	//Por defecto
	fecha() : Dia(0), hora(0), minuto(0) {};

	//Con parametros 
	fecha(int Dia, int hora, int minuto)
	{
		this->Dia = Dia;
		this->hora = hora;
		this->minuto = minuto;
	}

	int get_Dia() const { return Dia; }
	int get_hora() const { return hora; }
	int get_minuto() const { return minuto; }


	bool operator <(fecha horas) const
	{
		return ((Dia < horas.Dia) || (Dia == horas.Dia && hora < horas.hora)
			|| (Dia == horas.Dia && hora == horas.hora && minuto < horas.minuto));
	}

	bool operator ==(fecha horas)
	{
		return (Dia == horas.Dia && hora == horas.hora && minuto == horas.minuto);
	}

	void imprimir(ostream& out)
	{
		out << setfill('0') << setw(2) << hora << ":"
			<< setw(2) << minuto;
	}


};



ostream& operator<< (ostream& out, fecha& fecha)
{
	fecha.imprimir(out);
	return out;
}

#endif //FECHA_H