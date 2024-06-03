// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
using namespace std;

// función que resuelve el problema

typedef struct
{
    int altura;
    int num_nodos;
    bool zurdo;

}tZurdo;

tZurdo resolver(const Arbin<char> &arbol)
{
    if (arbol.esVacio())
    {
        return {0, 0, true};
    }
    else
    {
        tZurdo iz = resolver(arbol.hijoIz());
        tZurdo dr = resolver(arbol.hijoDr());

        if (iz.zurdo && dr.zurdo)
        {

            if ((iz.altura >= dr.altura && iz.num_nodos > dr.num_nodos) || (iz.altura == 0 && dr.altura == 0))
            {
                return {max(iz.altura, dr.altura) + 1, iz.num_nodos + dr.num_nodos + 1, true };
            }
            else
            {
                return { 0, false };
            }



        }
        else
        {
            return{ 0, false };
        }

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<char> arbol = Arbin<char>::leerArbolInorden();
    //cout << arbol;
    if(resolver(arbol).zurdo)
    {
        cout << "SI\n";
    }
    else
    {
        cout << "NO\n";

    }
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