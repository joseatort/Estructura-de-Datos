#ifndef Multiconjunto_H
#define Multiconjunto_H

#include <iostream>

#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_ELEMS = 2000;

class Multiconjunto
{

private:

	struct Elem {
		int valor;
		int multiplicidad;
	};
	Elem elems[MAX_ELEMS];
	int tamaño;

	void binSearch(const int& x, bool& found, int& pos) const;
	int binSearchAux(const int& x, int a, int b) const;

public:

	Multiconjunto()
	{
		this->tamaño = 0;
		
		for (int i = 0; i < tamaño; i++)
		{
			this->elems[i].valor = 0;
			this->elems[i].multiplicidad = 0;
		}
	}






	void anyadir(int elem);
	void eliminar(int elem);
	bool pertenece(int elem);



	

};

void Multiconjunto::anyadir(int elem)
{
	bool found;
	int pos;
	binSearch(elem, found, pos);
	if (found)
	{
		this->elems[this->tamaño].multiplicidad++;
	}
	else
	{
		this->elems[this->tamaño++].valor = elem;
	}

	//SE DEBEN ORDENAR O NO, PORQUE SI SE ORDENAN PIERDEN LA POSICION PARA DESPUES PONER EL RESULTADO

}

void Multiconjunto::eliminar(int elem)
{

}

bool Multiconjunto::pertenece(int elem)
{


	return true;
}

int Multiconjunto::binSearchAux(const int& x, int a, int b) const {
	// Pre: elems está ordenado entre 0 .. size-1
	//      ( 0 <= a <= size ) && ( -1 <= b <= size ) && ( a <= b+1 )
	//      todos los elementos a la izquierda de 'a' son <= x
	//      todos los elementos a la derecha de 'b' son > x

	int p, m;

	if (a == b + 1)
		p = a - 1;
	else if (a <= b) {
		m = (a + b) / 2;
		if (this->elems[m].valor <= x)
			p = binSearchAux(x, m + 1, b);
		else
			p = binSearchAux(x, a, m - 1);
	}
	return p;
	// Post: devuelve el mayor índice i (0 <= i <= size-1) que cumple
	//       elems[i] <= x
	//       si x es menor que todos los elementos de elems, devuelve -1
}

void Multiconjunto::binSearch(const int& x, bool& found, int& pos) const 
{
	pos = binSearchAux(x, 0, this->tamaño - 1);
	found = (pos >= 0) && (pos < this->tamaño) && (this->elems[pos].valor == x);
}
#endif //Multiconjunto_H