// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "dequeue.h"
using namespace std;

// función que resuelve el problema
void resolver(Dequeue<int> &xs, Dequeue<int> &zs)
{
    xs.zip(zs);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int aux_num_elems;
    int aux;
    Dequeue<int> xs;
    Dequeue<int> zs;

    cin >> aux_num_elems;
    
    for (int i = 0; i < aux_num_elems; i++)
    {
        cin >> aux;

        xs.push_back(aux);
    }

    cin >> aux_num_elems;
    for (int i = 0; i < aux_num_elems; i++)
    {
        cin >> aux;

        zs.push_back(aux);
    }
    
    resolver(xs, zs);
    // escribir sol
    
    xs.display();

    cout << endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
     for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}