// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "List.h"
using namespace std;

// función que resuelve el problema
void resolver() {
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
   
    char c;
    std::cin >> c;
    if (!std::cin) return false;
    List<string> lista;
    string str;

    getline(cin, str); // para saltar el final de linea
    getline(cin, str); // lee la linea del caso
    stringstream ss (str); // construye el objeto ss de tipo stringstream

    while (ss) {
        string aux;
        ss >> aux;
        lista.push_back(aux);
    }

    while (lista.size())
    {
        if(lista.front()[0] == c)
            cout << lista.front() << " ";

        lista.pop_front();

    }
    
    cout << endl;
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