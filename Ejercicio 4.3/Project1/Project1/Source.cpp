// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeMap.h"

using namespace std;
// función que resuelve el problema
void resolver(TreeMap<string, int> &diccionario) {
    
    TreeMap<string, int>::ConstIterator it = diccionario.cbegin();

    while (it != diccionario.cend())
    {
        if (it.value() != 0)
        {
            cout << it.key() << ", " << it.value() << endl;
        }

        ++it;
    }
    cout << "---\n";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numeroelems;
    string aux;
    string aux2;
    TreeMap<string, int> diccionario;
    TreeMap<string, int>::ConstIterator it;

     cin >> numeroelems;
    cin.ignore();

    if (numeroelems == 0)
        return false;

    for (int i = 0; i < numeroelems; i++)
    {
        getline(cin, aux);

        it = diccionario.find(aux);

        if(it == diccionario.cend())
            diccionario.insert(aux, 0);
        cin >> aux2;
        cin.ignore();

        if (aux2 == "INCORRECTO")
        {
            diccionario[aux] -= 1;
        }
        else if(aux2 == "CORRECTO")
        {
            diccionario[aux] += 1;
        }


    }
    
 
    resolver(diccionario);
    
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
