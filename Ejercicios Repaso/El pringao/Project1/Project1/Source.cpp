// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"
using namespace std;
// función que resuelve el problema
void resolver(Queue<int> &principal, Queue<int> &bullys, int pringao) 
{
    
    principal.colar(bullys, pringao);
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Queue<int> principal, bullys;
    int pringao;

    int aux; 
    cin >> aux;
    while (aux != -1)
    {
        principal.push_back(aux);
        cin >> aux;
    }

    cin >> pringao;

    cin >> aux;
    while (aux != -1)
    {
        bullys.push_back(aux);
        cin >> aux;
    }

    cout << principal << endl;
    resolver(principal, bullys, pringao);
    cout << principal << endl;

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