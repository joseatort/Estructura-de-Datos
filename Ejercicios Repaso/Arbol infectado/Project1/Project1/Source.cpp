// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Arbin.h"
using namespace std;

// función que resuelve el problema
vector<int> perfil(const Arbin<int> &arbol)
{
    vector<int> ret;
    if (!arbol.esVacio()) {
        Queue<Arbin<int>> porProcesar;
        porProcesar.push_back(arbol);

        while (!porProcesar.empty()) {
            int aux = porProcesar.size();
            
            for (int i = 0; i < aux; i++)
            {
                Arbin<int> visita = porProcesar.front();
                porProcesar.pop_front();

                if (i == 0) {
                    ret.push_back(visita.raiz());
                }
                if (!visita.hijoIz().esVacio())
                    porProcesar.push_back(visita.hijoIz());
                if (!visita.hijoDr().esVacio())
                    porProcesar.push_back(visita.hijoDr());
            }
            
        }
    }
    return ret;

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    Arbin<int> arbol = Arbin<int>::leerArbolInorden();

    cout << arbol;
    vector<int> sol = perfil(arbol);
    
    for (int& x : sol)
        cout << x << " ";
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