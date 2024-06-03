// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "dequeue.h"
#include "Queue.h"
using namespace std;

// función que resuelve el problema
int resolver(Dequeue <int> &dqmaximos, Queue <int> &colaK, int valor)
{
	if (dqmaximos.back() == -1)
	{
		return valor;
	}
	else if (dqmaximos.front() < colaK.front() && dqmaximos.back() < colaK.front() && colaK.front() >= valor)
	{
		return colaK.front();
	}
	else if (dqmaximos.front() > valor)
	{
		return dqmaximos.front();

	}
	else if(dqmaximos.back() > valor)
	{
		return dqmaximos.back();
	}
	else if (dqmaximos.front() >= valor)
	{
		return dqmaximos.front();

	}
	else if (dqmaximos.back() >= valor)
	{
		return dqmaximos.back();
	}
	else if (valor > dqmaximos.front())
	{
		dqmaximos.pop_front();
		dqmaximos.push_front(valor);
		return valor;
	}
	else if (valor > dqmaximos.back())
	{
		dqmaximos.pop_back();
		dqmaximos.push_back(valor);
		return valor;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, k;
	cin >> n >> k;
	if (n == 0 && k == 0)
		return false;

	Queue <int> colaK;
	Dequeue <int> dqmaximos;
	int valor;

	int contador = 0;

	int mayor1 = -1;
	int mayor2 = -1;

	for (int y = 0; y < n - k + 1; y++)
	{
		
		while (contador++ < k)
		{
			cin >> valor;
			colaK.push_back(valor);

			if (valor > mayor1)
			{
				mayor2 = mayor1;
				mayor1 = valor;
			}
			else if (mayor1 > valor > mayor2)
			{
				mayor2 = valor;
			}	

		}

		if (y == 0)
		{
			dqmaximos.push_front(mayor1);
			dqmaximos.push_back(mayor2);
			cout << resolver(dqmaximos, colaK, valor) << " ";
		}
		else
		{
			cin >> valor;
			


			if (colaK.front() == dqmaximos.front())
			{
				dqmaximos.pop_front();
				dqmaximos.push_front(valor);
			}

			if (colaK.front() == dqmaximos.back())
			{
				dqmaximos.pop_back();
				dqmaximos.push_back(valor);
			}

			colaK.push_back(valor);
			colaK.pop_front();







			cout << resolver(dqmaximos, colaK, valor) << " ";
			



		}

	}
	cout << endl;

	return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
