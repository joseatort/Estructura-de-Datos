// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"

using namespace std;

// función que resuelve el problema
void resolver(Queue<int> &h)
{
     h.invertir();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Queue<int> h;
    int aux;

    do
    {
        cin >> aux;

        if (!std::cin)
            return false;

        if (aux != 0)
        {
            h.push_back(aux);
        }
        
    } while (aux != 0);
 
    if (h.size() != 0)
    {
        resolver(h);
    }
    h.write(cout);
    cout << endl;

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