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
    int caminos;
    int maximo_personas;
    bool hay_excursionistas;

}resultado;


resultado resolver(Arbin<int>const& arbol)
{
    if (arbol.esVacio())
    {
        return{0,0,false};
    }

    resultado izq = resolver(arbol.hijoIz());
    resultado der = resolver(arbol.hijoDr());



    if (arbol.raiz() == 0)
    {
        if (izq.hay_excursionistas || der.hay_excursionistas)
        {
            return { izq.caminos + der.caminos, max(izq.maximo_personas, der.maximo_personas), true };
        }
        else
        {
            return { 0, 0, false };
        }
    }
    else if (izq.hay_excursionistas || der.hay_excursionistas)
    {
        return{ izq.caminos + der.caminos, max(izq.maximo_personas + arbol.raiz(), der.maximo_personas + arbol.raiz()), true };
    }
    else
    {
        return { 1, max(izq.maximo_personas + arbol.raiz(), der.maximo_personas + arbol.raiz()),true };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol;
    
    resultado x;
    arbol = arbol.leerArbol(-1);

    x = resolver(arbol);
    
    // escribir sol
    cout << x.caminos << " " << x.maximo_personas << endl;
 
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