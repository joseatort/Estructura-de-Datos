// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
using namespace std;

typedef struct
{
    bool orden;
    int max;
    int min;


}TResultado;

// función que resuelve el problema
TResultado resolver(const Arbin<int> &arbol) {

     if (arbol.esVacio())
    {
        return {true, -2, -2};
    }
    else
    {
        TResultado iz = resolver(arbol.hijoIz());
        TResultado dr = resolver(arbol.hijoDr());

        if (iz.orden && dr.orden)
        {

            if (((iz.max >= arbol.raiz()) && iz.max != -2) || ((dr.min <= arbol.raiz()) && dr.min != -2))
            {
                return { false, 0, 0 };
            }
            else if (!arbol.hijoIz().esVacio() && !arbol.hijoIz().esVacio())
            {
                return { true, max(dr.max, arbol.raiz()), min(iz.min, arbol.raiz()) };
            }
            else if (!arbol.hijoIz().esVacio())
            {

                return { true, max(iz.max, arbol.raiz()), min(iz.min, arbol.raiz()) };
            }
            else if (!arbol.hijoDr().esVacio())
            {
                return { true, max(dr.max, arbol.raiz()), min(dr.min, arbol.raiz()) };
            }
            else
            {
                return { true, arbol.raiz(), arbol.raiz() };
            }

           
        }
        else
        {
            return {false, 0, 0};
        }
       
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol;

    arbol = Arbin<int>::leerArbol(-1);

    if (resolver(arbol).orden)
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