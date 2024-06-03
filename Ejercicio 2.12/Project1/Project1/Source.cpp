// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"
using namespace std;

// función que resuelve el problema
void resolver(List<int>& l)
{
    //l.reverse_iterator(cout);


    List<int>::ConstIterator cit = l.cend();

    while (cit != l.cbegin())
    {
        cout << *cit << " ";
        ++cit;
    }





}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int aux;
    List<int> l;

    do
    {
        cin >> aux;

        if (aux != 0)
        {
            l.push_back(aux);
        }

    } while (aux != 0);

    if (l.size() != 0)
    {
        resolver(l);
    }
    cout << endl;
    
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