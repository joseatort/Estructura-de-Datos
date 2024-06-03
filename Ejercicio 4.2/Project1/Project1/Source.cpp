// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeSetC.h"

using namespace std;

// función que resuelve el problema

template <typename T>
void resolver(int numero, TreeSetC<T> &s) {
    
    
    pair<bool, T> x = s.lower_bound(numero);
    
    if (x.first)
    {
        cout << x.second << endl;
    }
    else
    {
        cout << "NO HAY" << endl;
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int elems_arbol;
    int num_consultas;
    int aux;
    TreeSetC<int> s;
    
    cin >> elems_arbol;

    if (elems_arbol == 0)
        return false;
    
    for (int i = 0; i < elems_arbol; i++)
    {
        cin >> aux;
        s.insert(aux);
    }

    cin >> num_consultas;

    for (int i = 0; i < num_consultas; i++)
    {
        cin >> aux;
        resolver(aux, s);
    }
    
    cout << "---\n";
    
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
