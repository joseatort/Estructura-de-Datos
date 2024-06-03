// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
using namespace std;

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Arbin.h"
using namespace std;

typedef struct {
    int sumaMaxima;
    int sumAux;
}tSol;

tSol resolver(Arbin<int>const& arbol) {
    if (arbol.esVacio()) {
        return { 0, 0 };
    }
    else {
        tSol iz = resolver(arbol.hijoIz());
        tSol dr = resolver(arbol.hijoDr());

        return { max({iz.sumAux + dr.sumAux + arbol.raiz(), iz.sumaMaxima, dr.sumaMaxima}), arbol.raiz() + max(iz.sumAux, dr.sumAux) };
    }
}


void resuelveCaso() {
    Arbin<int> arb = Arbin<int>::leerArbol(-1);
    cout << arb;
    cout << resolver(arb).sumaMaxima << endl;
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