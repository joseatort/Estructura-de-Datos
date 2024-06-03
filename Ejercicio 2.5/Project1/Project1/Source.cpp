// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"

using namespace std;

// función que resuelve el problema
void resolver(Queue<int> &cola, Queue<int> &colegas, int pringao)
{
    cola.IntroducirCola(colegas, pringao);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int aux;
    int pringao;
    Queue<int> cola;
    Queue<int> colegas;
    do
    {
        cin >> aux;

        if (aux != -1)
        {
            cola.push_back(aux);
        }

    } while (aux != -1);
 
    cola.write(cout);
    cout << endl;

    cin >> pringao;


    do
    {
        cin >> aux;

        if (aux != -1)
        {
            colegas.push_back(aux);
        }

    } while (aux != -1);


    resolver(cola, colegas, pringao);
    
    cola.write(cout);
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