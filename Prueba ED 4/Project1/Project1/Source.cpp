/*
 * Nombre y apellidos de los alumnos: Jose Antonio Tortosa Aranda, Alvaro Velasco Garcia
 *
 * Usuarios del juez: E65, E66
 */

//El coste del Algoritmo empleado seria lineal O(n)

#include <iostream>               
#include <fstream>
#include "Arbin.h"
//#include "Arbin_Smart.h" //Si lo prefieres puedes usar esta otra clase
#include <algorithm>
using namespace std;

/**
 * Escribe la función que resuelve el problema. Puedes usar funciones auxiliares si lo 
 * crees necesario. 
 * 
 * IMPORTANTE: - NO puedes usar parámetros que sean a la vez, entrada y salida 
 *             - Indica el coste de tu función
 * 
 */


typedef struct
{
    int nodos;
    int salvados;

}TSalvados;

TSalvados resolver(const Arbin<char> &arbol)
{
    if (arbol.esVacio())
    {
        return{0, 0};
    }
    else
    {
        TSalvados iz = resolver(arbol.hijoIz());
        TSalvados dr = resolver(arbol.hijoDr());

        return { 1 + iz.nodos + dr.nodos, max(iz.nodos + dr.salvados, dr.nodos + iz.salvados)};

    }

}


void resuelveCaso() {
    Arbin<char> arbol = Arbin<char>::leerArbolInorden();

    cout << resolver(arbol).salvados << endl;
    //Llamada a la función y escritura de los datos

}


///
int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
    int casos;
    cin >> casos;
    while (casos--) {
        resuelveCaso();
    }
#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
