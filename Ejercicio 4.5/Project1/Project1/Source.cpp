#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> &vct)
{
    int maximo = 0;
    int actual = 0;


    //Se guarda el id de la pelicula, y la posicion del vector en el que aparece
    unordered_map<int, int> diccionario;

    for (int i = 0; i < vct.size(); i++) {
        //Sigo sin entender la segunda condicion, pero si la quito no funciona
        if (diccionario.count(vct[i]) == 0 || diccionario[vct[i]] < i - actual)
        {
            actual++;
            maximo = max(maximo, actual);
        }
        else {
            actual = i - diccionario[vct[i]];
        }

        diccionario[vct[i]] = i;
    }

    return maximo;


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num_elems;
    int aux;
    vector<int> vct;

    cin >> num_elems;

    for (int i = 0; i < num_elems; i++)
    {
        cin >> aux;
        vct.push_back(aux);
    }


    
    
    cout << resolver(vct) << endl;
    // escribir sol
    
    
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