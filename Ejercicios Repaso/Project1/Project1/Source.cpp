// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
using namespace std;

// función que resuelve el problema
template <typename T>
T resolver(const Arbin<T> &arbol) 
{
    if(arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio())
    {
        return arbol.raiz();
    }
    else
    {
        T iz = arbol.raiz(), dr = arbol.raiz();
        if(!arbol.hijoIz().esVacio())
            T iz = resolver(arbol.hijoIz());
        if (!arbol.hijoDr().esVacio())
            T dr = resolver(arbol.hijoDr());

        T aux = min(iz, dr);

        return { min(aux, arbol.raiz()) };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    char letra;
    cin >> letra;
    if (!std::cin)
        return false;

    if (letra == 'N')
    {
        Arbin<int> arbol = Arbin<int>::leerArbolInorden();
        cout << arbol;
        cout << resolver(arbol) << endl;;
    }
    else
    {
        Arbin<string> arbol = Arbin<string>::leerArbolInorden();
        cout << resolver(arbol) << endl;;
    }
    

    
    
    
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