// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "dequeue.h"
using namespace std;

// función que resuelve el problema
void resolver(Dequeue<int> & l, int inicio, int suma)
{
    //Leer enunciado para ver si es nodo fantasma, cuidado con nodo fantasma   

    l.cambio(inicio, suma);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int elems, inicio = 0, suma = 0, aux;
    Dequeue<int> l;
    cin >> elems;
    cin >> inicio;
    cin >> suma;

    if (elems == 0 && inicio == 0 && suma == 0)
        return false;
    
    for (int i = 0; i < elems; i++)
    {
        cin >> aux;
        l.push_back(aux);
    }


    resolver(l, inicio, suma);
    cout << l << endl;
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
