// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool mayusculas(string const& palabra) {
    for (int i = 0; i < palabra.size(); ++i) {
        if (!isupper(palabra[i])) return false;
    }
    return true;
}
//comprueba que tiene minusculas y números
bool minusculas(string const& palabra) {

    for (int i = 0; i < palabra.size(); ++i) {
        if (isalpha(palabra[i])) {
            if (isupper(palabra[i])) return false;
        }

    }
    return true;
}


bool comprobar_pertenencia(set<string>& vct, string alumno)
{
    return vct.find(alumno) != vct.end();

}

bool sortByDemand(const pair<string, int>& lhs, const pair<string, int>& rhs) {
    if (lhs.second != rhs.second) {
        return lhs.second > rhs.second;  // Orden descendente por demanda (int)
    }
    else {
        return lhs.first < rhs.first;  // Orden alfabético ascendente por nombre del deporte (string)
    }
}

// función que resuelve el problema
void resolver(unordered_map<string, set<string>>& juegos) {

    auto it = juegos.cbegin();

    vector <pair<string, int>> prueba;

    while (it != juegos.cend())
    {
        prueba.push_back({ it->first, it->second.size() });
        ++it;
    }

    sort(prueba.begin(), prueba.end(), sortByDemand);

    for (const auto& pair : prueba) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "---\n";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string aux;
    string deporte;
    //NOMBRE JUEGO, NUMERO GENTE
    unordered_map<string, set<string>> juegos;
    set<string> lista_negra;

    cin >> aux;
    if (!std::cin)
        return false;

    while (aux != "_FIN_")
    {

        if (mayusculas(aux))
        {
            juegos[aux];
            deporte = aux;
        }
        else if (isalpha(aux[0]) && minusculas(aux))
        {


            if (lista_negra.find(aux) != lista_negra.end())
            {
                auto it = juegos.begin();

                while (it != prev(juegos.end()))
                {
                    it->second.erase(aux);
                    it++;
                }

            }
            else if (!comprobar_pertenencia(juegos[deporte], aux))
            {
                juegos[deporte].insert(aux);
                lista_negra.insert(aux);
            }
        }

        cin >> aux;

    }

    resolver(juegos);


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
