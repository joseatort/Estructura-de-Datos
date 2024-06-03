// Nombre del alumno José Antonio Tortosa Aranda
// Usuario del Juez E65


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Tiempo.h"
#include "error.h"
#include "List.h"
using namespace std;

// función que resuelve el problema
void resolver(List<tiempo> &horas)
{
    horas.eliminarpares();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() 
{
    // leer los datos de la entrada
    int numerohoras;

    cin >> numerohoras;

    if (numerohoras == 0)
        return false;

    vector<tiempo> v(numerohoras);

    tiempo h;
    List<tiempo> horas;

    for (int i = 0; i < numerohoras; i++)
    {
        try
        {
            cin >> h;
            horas.push_back(h);
        }
        catch (error e)
        {
            cout << e.getInfo() << endl;
        }
    }

    resolver(horas);

    horas.write(cout);
    cout << endl;
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
