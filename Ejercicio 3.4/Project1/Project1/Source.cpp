// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Arbin.h"
using namespace std;

// función que resuelve el problema
void resolver(vector<int>& preorden, vector<int>& inorden, Arbin<int> &arbol)
{
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int aux;
    string linea;
    string linea2;
    vector<int> preorden;
    vector<int> inorden;
    vector<int> postorden;
    Arbin<int> arbol;

    getline(cin, linea);
    getline(cin, linea2);
    
    if (! std::cin)
        return false;
    
    istringstream ss(linea); 
    istringstream ss2(linea2);

    while (ss >> aux) {
        preorden.push_back(aux);
    }


    while (ss2 >> aux) { 
        inorden.push_back(aux);
    }

    resolver(preorden, inorden, arbol);

    for (int i = 0; i < postorden.size(); i++) {
        cout << postorden[i] << " ";
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