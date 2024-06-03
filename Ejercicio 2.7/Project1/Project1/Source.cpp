// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Queue.h"
#include "List.h"
using namespace std;

// función que resuelve el problema
int resolver(List<int>& r, Queue<int> &q)
{
    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numsobres;
    int numeroelegir;
    int aux;
    Queue<int> q;
    List<int> r;
    cin >> numsobres;
    cin >> numeroelegir;
   
    if (numsobres == 0 && numeroelegir == 0)
        return false;
    
    for (int i = 0; i < numeroelegir; i++)
    {
        cin >> aux;
        q.push_back(aux);
    }

    while (q.size() != numsobres)
    {
        cout << resolver(r, q) << " ";
        q.pop_front();
        cin >> aux;
        q.push_back(aux);
    }

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
