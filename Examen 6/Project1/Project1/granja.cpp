
// Problema Smart farming

// IMPORTANTE

// Nombre y apellidos del alumno
// Usuario del juez de clase
// Usuario que has utilizado en esta prueba

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <utility>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;


// Explicación de la representación elegida para resolver el problema.


// No olvides poner comentarios en el codigo para que se puedan entender bien
// las funciones.
// No olvides poner el coste de cada una de las funciones y explicarlo.

class smartFarming {
private:
    using tsector = string;
    using tplaga = string;

    struct TipoSector {
        int num_plantas;
        map<tplaga, int> infectadas;
    };

    unordered_map<tsector, TipoSector> granja;
    queue<pair<tsector, tplaga>> cola_fumigacion;

public:
    smartFarming() {}

    // Coste de la función y justificación
    void alta(tsector const& id, int n) {
        if (granja.count(id) == 0)
        {
            granja[id].num_plantas = n;
        }
        else
        {
            granja[id].num_plantas += n;
        }
    }

    // Coste de la función y justificación
    void datos(tsector const& id, tplaga const& p, int n) {

        bool encontrado = false;

        if (granja.count(id) == 0)
        {
            throw domain_error("Sector no existente");
        }
        else
        {
            auto it = granja[id].infectadas.begin();
            int contador = 0;

            while (it != granja[id].infectadas.end())
            {
                contador += it->second;

                it++;
            }

            if (granja[id].num_plantas < contador + n)
            {
                throw domain_error("Numero de plantas incorrecto");
            }
            else
            {
                if (granja[id].infectadas.count(p) == 0)
                {
                    granja[id].infectadas[p] = n;

                }
                else
                {
                    granja[id].infectadas[p] += n;

                    

                }
                
                if (granja[id].infectadas[p] >= (granja[id].num_plantas / 4))
                {
                    cola_fumigacion.push({ id,p });
                }



            }
        }



    }

    // Coste de la función y justificación
    vector<pair<tsector, tplaga>> fumigar() {

        vector<pair<tsector, tplaga>> vct;
        bool encontrado = false;
        int contador = cola_fumigacion.size();

        while (contador--)
        {
            if (granja[cola_fumigacion.front().first].infectadas[cola_fumigacion.front().second] != 0)
            {
                vct.push_back({ cola_fumigacion.front().first, cola_fumigacion.front().second });
            }
            
            granja[cola_fumigacion.front().first].infectadas[cola_fumigacion.front().second] = 0;
            cola_fumigacion.pop();

        }

        return vct;
    }


    // Coste de la función y justificación
    vector<pair<tplaga, int>> plagas(tsector const& id) {

        vector<pair<tplaga, int>> vct;

        if (granja.count(id) == 0)
        {
            throw domain_error("Sector no existente");
        }
        else
        {
            auto it = granja[id].infectadas.begin();

            while (it != granja[id].infectadas.end())
            {
                vct.push_back({ it->first, it->second });
                it++;
            }


        }

        return vct;

    }
};

//////////////////////////////////////////////////////////////////////////////////////
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    smartFarming sf;
    std::cin >> op;  // operacion a realizar
    if (!std::cin)
        return false;
    std::string id; std::string plaga; int n;
    while (op != "FIN") {
        try {
            if (op == "alta") {
                std::cin >> id >> n;  // sector - numero de plantas
                sf.alta(id, n);
            }
            else if (op == "datos") {
                std::cin >> id >> plaga >> n; // sector, plaga, numero de plantas afectadas
                sf.datos(id, plaga, n);
            }
            else if (op == "fumigar") {
                std::vector<std::pair<std::string, std::string>> v = sf.fumigar();
                // Escribir el resultado
                for (auto const& s : v) {
                    std::cout << "Fumigar la plaga " << s.second << " del sector";
                    std::cout << ' ' << s.first << '\n';
                }
            }
            else if (op == "plagas") {
                std::cin >> id; // sector
                std::vector<std::pair<std::string, int>> v = sf.plagas(id);
                // Escribir el resultado
                std::cout << "Plagas del sector " << id << " :";
                for (auto const& s : v)
                    std::cout << ' ' << s.first << ' ' << s.second;
                std::cout << '\n';
            }
        }
        catch (std::domain_error& d) {
            std::cout << "ERROR: " << d.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---" << '\n';

    return true;

}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
