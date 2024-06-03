// Nombre del alumno José Antonio Tortosa Aranda
// Usuario del Juez E65


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"
#include <vector>

using namespace std;

template <class T>

// función que resuelve el problema
void resolver(T cent, int k) {
    
    Set<T> lista;
    T aux;
    cin >> aux;

    do
    {
        lista.add(aux);
        if (lista.getSize() > k)
        {
            lista.removeMin();
        }
        cin >> aux;
    } while (aux != cent);


    lista.write(cout);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    int numero_resultados;

    cin >> tipo;
    cin >> numero_resultados;

    if (!std::cin)
        return false;

    if (tipo == 'N')
    {
        resolver<int>(-1, numero_resultados);
    }
    else if (tipo == 'P')
    {
        resolver<string>("FIN", numero_resultados);
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