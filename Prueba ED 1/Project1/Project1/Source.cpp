// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"

using namespace std;

// funcio?n que resuelve el problema
void  resolver(Set<int>& set1, Set<int> set2)
{
    set1.diff(set2);



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Set<int> set1;
    Set<int> set2;

    set1.read(cin);

    if (!std::cin)
        return false;

    set2.read(cin);

    resolver(set1, set2);

    // escribir sol


    if (set1.isEmpty())
    {
        cout << "e" << endl;
    }
    else
    {
        set1.write(cout);

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