/**
 * Nombres: Jose Antonio Tortosa Aranda & Alvaro Velasco Garcia
 * Usuarios: E65 & E66
 * S�lo debes rellenar la funci�n cuela.
 */

#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;


bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;
    Queue<int> q;
    cin >> n;
    if (n == -1)
        return false;
    while (n != -1){
        q.push_back(n);
        cin >> n;
    }
    cin >> a >> b;

    // llamada a metodo
        q.cuela(a, b);
    // escribir sol
    cout<< q <<endl;

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
