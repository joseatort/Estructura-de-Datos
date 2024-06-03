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
    bool ok;

}estable;

estable resolver(const Arbin<int>& arbol)
{
    if(arbol.esVacio())
    {
        return {0, true};
    }
    else
    {
        estable iz = resolver(arbol.hijoIz());
        estable dr = resolver(arbol.hijoDr());

        //if ((iz.altura > dr.altura && iz.ok == true && dr.altura > 0) || (iz.altura < dr.altura && dr.ok == true && iz.altura > 0))

        if ((iz.altura > dr.altura && iz.ok == true) || (iz.altura < dr.altura && dr.ok == true))
        {
            return { 1 + max(iz.altura, dr.altura), true };
        }
        else if (iz.altura == dr.altura && iz.altura > 0 && dr.altura > 0)
        {
            return { 1 + max(iz.altura, dr.altura), true};
        }
        else 
        {
            return { 1 + max(iz.altura, dr.altura), false };
        }
        
    }
}


bool estable_altura(const Arbin<int> &arbol)
{
    if (arbol.esVacio())
    {
        return true;
    }
    else
    {

        estable resultado = resolver(arbol);
        
        return resultado.ok;
    }
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol;
    
    arbol = Arbin<int>::leerArbolInorden();

    if (estable_altura(arbol))
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