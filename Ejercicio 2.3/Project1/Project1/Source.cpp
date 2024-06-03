// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"
using namespace std;

// función que resuelve el problema
int resolver(Queue<int> &h, int intervalos) 
{
    int contador = 0;
    
    do
    {
        for (int i = 0; i < intervalos; i++)
        {
            h.push_back(h.front());
            h.pop_front();
        }

        h.pop_front();

    } while (h.size() != 1);

    return h.front();

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numeroalumnos;
    int saltos;
    Queue<int> h;
    cin >> numeroalumnos;
    cin >> saltos;

    if (numeroalumnos == 0 && saltos == 0)
        return false;


    for (int i = 0; i < numeroalumnos; i++)
    {

        h.push_back(i + 1);

    }

    cout << resolver(h, saltos) << endl;;
    
    // escribir sol
    
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
