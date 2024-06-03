// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

using namespace std;

// función que resuelve el problema
pair<int,bool> resolver(const Arbin<int> &arbol) 
{
    if (arbol.esVacio())
    {
        return {0, true};
    }
    else
    {
        pair<int, bool> iz = resolver(arbol.hijoIz());
        pair<int, bool> dr = resolver(arbol.hijoDr());


        if (iz.second && dr.second)
        {
            
            if (abs(iz.first - dr.first) > 1)
            {
                return { 0, false };
            }
            else
            {
                if (arbol.raiz() == 0)
                {
                    return{ iz.first + dr.first + 1, true };
                }
                else
                {
                    return{ iz.first + dr.first, true };
                }

            }

        }
        else
        {
            return { 0, false };
        }





    }
    


    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol;
    arbol = Arbin<int>::leerArbol(-1);
    
    if (resolver(arbol).second)
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
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
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