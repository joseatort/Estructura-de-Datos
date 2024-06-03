/*
 * Nombre y apellidos del alumno: José Antonio Tortosa Aranda & Alvaro Velasco García
 *
 * Usuario del juez: E65 & E66
 */

//El coste del algortimo empleado es lineal O(n)

#include <iostream>               
#include <fstream>
#include "Arbin.h"
 //#include "Arbin_Smart.h" //Puedes usar esta clase si lo prefieres
#include <vector>

 using namespace std;

/* Escribe el método externo
 * Puedes añadir métodos secundarios o las librerías que necesites
 *
 */
vector<int> perfil(Arbin<int> arbol)
{
    vector<int> ret;
    if (!arbol.esVacio()) {
        Queue<Arbin<int>> porProcesar;
        porProcesar.push_back(arbol);

        while (!porProcesar.empty()) {
            int aux = porProcesar.size();
            

             for (int i = 0; i < aux; i++) {
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


//No debes modificar nada de aquí hacia abajo
void resuelveCaso() {
    Arbin<int> arbol = Arbin<int>::leerArbolInorden();

    vector<int> sol = perfil(arbol);

    for (int& x : sol)
        cout << x << " ";
    cout << endl;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int casos;
    cin >> casos;
    while (casos--) {
        resuelveCaso();
    }
#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
