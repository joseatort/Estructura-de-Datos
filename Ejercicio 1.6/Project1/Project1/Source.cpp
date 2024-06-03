// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Multiconjunto.h"

using namespace std;

// función que resuelve el problema
void resolver(Multiconjunto multi1, Multiconjunto multi2)
{




}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numerodatos;
    Multiconjunto multi1;
    Multiconjunto multi2;
    int aux;
    cin >> numerodatos;


    if (numerodatos == 0)
        return false;


    for (int i = 0; i < numerodatos; i++)
    {
        cin >> aux;
        multi1.anyadir(aux);
    }

    for (int i = 0; i < numerodatos; i++)
    {
        cin >> aux;
        multi2.anyadir(aux);
    }

    resolver(multi1, multi2);

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
