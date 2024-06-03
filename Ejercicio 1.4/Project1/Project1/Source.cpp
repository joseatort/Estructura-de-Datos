// Nombre del alumno José Antonio Tortosa Aranda
// Usuario del Juez E65


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "SetOfInts3.h"

using namespace std;

// función que resuelve el problema
void resolver(int cent, SetOfInts3 set, int numeroelementos)
{
    int aux;
    int x = 0;
    cin >> aux;

    do
    {
        set.add(aux);
        if (set.getSize() > numeroelementos)
        {
            set.removeMax();
        }
        cin >> aux;
    } while (aux != cent);

    set.write(cout);
    cout << endl;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numeroelementos;
    SetOfInts3 set;
    cin >> numeroelementos;

    if (numeroelementos == 0)
        return false;

    resolver(-1, set, numeroelementos);

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
