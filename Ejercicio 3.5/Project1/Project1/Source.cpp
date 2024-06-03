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
    int nodos;
    bool zurdo;

}ramas;

ramas resolver(const Arbin<char> &arbol)
{
    if (arbol.esVacio())
    {
        return {0, true};
    }
    else
    {
        ramas iz = resolver(arbol.hijoIz());
        ramas der = resolver(arbol.hijoDr());


        if (iz.nodos <= der.nodos && max(iz.nodos, der.nodos) > 0)
        {
            iz.zurdo = false;
        }

        if (iz.zurdo && der.zurdo)
        {
            return {iz.nodos + der.nodos + 1, true };
        }
        else
        {
            return { iz.nodos + der.nodos + 1, false};
        }
    } 
   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<char> arbol;
    arbol = arbol.leerArbolInorden();
  
    if (resolver(arbol).zurdo )
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