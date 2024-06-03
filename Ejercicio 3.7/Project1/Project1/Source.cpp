// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "Arbin.h"
using namespace std;


// función que resuelve el problema
template <typename T>
T resolver(const Arbin<T> & arbol)
{
    T auxiliar;

    if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio())
    {
        return arbol.raiz();
    }
    else
    {
        auxiliar = arbol.raiz();


        if (!arbol.hijoIz().esVacio())
        {
            T palabraiz = resolver(arbol.hijoIz());
            if (palabraiz < auxiliar)
            {
                auxiliar = palabraiz;
            }
        }
        
        if (!arbol.hijoDr().esVacio())
        {
            T palabradr = resolver(arbol.hijoDr());
            if (palabradr < auxiliar)
            {
                auxiliar = palabradr;
            }

        }

        return auxiliar;
    }


   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    Arbin<int> arbol_int;
    Arbin<string> arbol_string;

    cin >> tipo;
    if (! std::cin)
        return false;
    
    if (tipo == 'N')
    {
        arbol_int = Arbin<int>::leerArbolInorden();
        cout << resolver(arbol_int) << endl;
        
    }
    else if(tipo == 'P')
    {
        arbol_string = Arbin<string>::leerArbolInorden();
        cout << resolver(arbol_string) << endl;
    }

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