// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include "TreeMap.h"

using namespace std;

// función que resuelve el problema
void resolver(TreeMap<string, vector<int>> diccionario) 
{
    
    TreeMap<string, vector<int>>::ConstIterator it = diccionario.cbegin();

    while (it != diccionario.cend())
    {
        cout << it.key();
            

        for (int i = 0; i < it.value().size(); i++)
        {
            cout << " " << it.value()[i];
        }
        
        cout << endl;

        ++it;
    }
    
    cout << "---\n";
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numero_elems;

    string linea;
    string mayus;
    string minus;

    TreeMap<string, vector<int>> diccionario;


    cin >> numero_elems;
    cin.ignore();
    if (numero_elems == 0)
        return false;

    for (int i = 1; i <= numero_elems; i++)
    {
        getline(cin, linea);
        stringstream ss(linea);
        while (ss >> mayus)
        {
            minus = "";
            for (char c : mayus) {
                minus += tolower(c);
            }

            if (minus.size() > 2)
                if(diccionario[minus].size() == 0 || diccionario[minus].back() != i)
                    diccionario[minus].push_back(i);

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
