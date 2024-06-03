// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

using namespace std;

typedef struct
{
    int max_excursionistas;
    int caminos;
}TExcursionistas;
// función que resuelve el problema
TExcursionistas resolver(const Arbin<int> &arbol) 
{
    if (arbol.esVacio())
    {
        return { 0, 0 };
    }
    else
    {
        TExcursionistas iz = resolver(arbol.hijoIz());
        TExcursionistas dr = resolver(arbol.hijoDr());

        if (iz.caminos == 0 && dr.caminos == 0 && arbol.raiz() != 0)
        {
            return {arbol.raiz(), 1 };
        }
        else
        {
            return { max(iz.max_excursionistas, dr.max_excursionistas) + arbol.raiz(), iz.caminos + dr.caminos };
        }

         

    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    
    Arbin<int> h;
    h = Arbin<int>::leerArbol(-1);

    cout << resolver(h).caminos << " " << resolver(h).max_excursionistas << endl;;
    // escribir sol
    
    
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