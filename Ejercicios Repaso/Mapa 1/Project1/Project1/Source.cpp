// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

// función que resuelve el problema
void resolver() {
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int aux; 
    cin >> aux;
    cin.ignore();
    if (aux == 0)
        return false;
     
    string auxiliar;
    map<string, vector<int>> mapa;

    string linea;
    for (int i = 1; i <= aux; i++)
    {
        
        getline(cin, linea);    
        stringstream ss(linea);

        
        while (ss >> auxiliar) {
            for (char& s : auxiliar) {
                s = std::tolower(s);
            }
                
            if (auxiliar.size() > 2 && (mapa.count(auxiliar) == 0 || mapa[auxiliar].back() != i))
            {
                mapa[auxiliar].push_back(i);
            }
            
        }

    }

    auto it = mapa.begin();

    while (it != mapa.end())
    {
        cout << it->first << " ";
        
        auto it2 = it->second.begin();
        while (it2 != it->second.end())
        {
            cout << *it2 << " ";
            it2++;
        }
        cout << endl;

        it++;
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
