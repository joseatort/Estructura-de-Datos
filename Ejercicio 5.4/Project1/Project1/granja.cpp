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

    unordered_map<tsector, set<tplaga>> granja;
    queue<pair<tsector, tplaga>> cola_fumigacion;
    
public:
    smartFarming() {}

    // Coste de la función y justificación
    void alta(tsector const& id) {
        if (granja.count(id) == 0)
        {
            granja[id];
        }
    }

    // Coste de la función y justificación
    void datos(tsector const& id, tplaga const& p) {

        bool encontrado = false;

        if (granja.count(id) == 0)
        {
            throw domain_error("Sector no existente");
        }
        else
        {
            if (granja[id].find(p) == granja[id].end())
            {
                granja[id].insert(p);
                cola_fumigacion.push({id, p});
            }
            else
            {
                throw domain_error("Plaga repetida");
            }
        }

    }

    // Coste de la función y justificación
    vector<tsector> fumigar(tplaga p) {

        vector<tsector> vct;
        bool encontrado = false;
        int contador = cola_fumigacion.size();
        while (contador--)
        {
            if (cola_fumigacion.front().second == p)
            {     
                granja[cola_fumigacion.front().first].erase(p);


                vct.push_back(cola_fumigacion.front().first);
                cola_fumigacion.pop();
            }
            else
            {
                cola_fumigacion.push(cola_fumigacion.front());
                cola_fumigacion.pop();
            }

        }
                

        if (vct.size() == 0)
        {
            throw domain_error("Plaga no existente");
        }

        return vct;

        
    }


    // Coste de la función y justificación
    vector<tplaga> plagas(tsector const& id) {

        vector<tplaga> vct;
        
        if(granja.count(id) == 0)
        {
            throw domain_error("Sector no existente");
        }
        else
        {
            auto it = granja[id].begin();
            while (it != granja[id].end())
            {
                vct.push_back(*it);
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
    std::string id; std::string plaga;
    while (op != "FIN") {
        try{
            if (op == "alta") {
                std::cin >> id;  // sector - numero de plantas
                sf.alta(id);
            }
            else if (op == "datos") {
                std::cin >> id >> plaga; // sector, plaga, numero de plantas afectadas
                sf.datos(id,plaga);
            }
            else if (op == "fumigar") {
                std::cin >> plaga;
                std::vector<std::string> v = sf.fumigar(plaga);
                // Escribir el resultado
                std::cout << "Fumigar la plaga " << plaga << " en los sectores :";
                for (auto const& s : v){
                    std::cout << ' ' << s;
                }
                cout << endl;
            }
            else if(op== "plagas") {
                std::cin >> id; // sector
                std::vector<std::string> v = sf.plagas(id);
                // Escribir el resultado
                std::cout << "Plagas del sector " << id << " :";
                for (auto const& s : v)
                    std::cout << ' ' << s;
                std::cout << '\n';
            }
        }
        catch (std::domain_error & d) {
            std::cout << "ERROR: " << d.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---" << '\n';

    return true;

}


int main(){
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
