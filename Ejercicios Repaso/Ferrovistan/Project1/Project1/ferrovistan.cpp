//-------------------------------------------------------
// Ejercicio 3: Ferrovistán. Mayo 2022
// Escribe tu nombre y respuestas en las zonas indicadas
//-------------------------------------------------------
//@ <answer>
// Nombre :
// Usiario del Juez de Clase :
// Usuario del Juez de Exámenes :
//@ </answer>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
//Añade las librerías que necesites:
//@ <answer>

//@ </answer>

using namespace std;

// Elige el tipo representante adecuado para el TAD Ferrovistan e
// implementa sus operaciones. Puedes añadir métodos o funciones privadas
// si lo consideras conveniente. Justifica la elección de los tipos y el
// coste de todas las operaciones.
//@ <answer>

using tLinea = string;          //Nombres de líneas
using tEstacion = string;       //Nombres de estaciones

class Ferrovistan {

private:
    
    unordered_map<tEstacion, set<tLinea>> estaciones;
    unordered_map<tLinea, unordered_map<tEstacion, int>> lineas;
    unordered_map<tLinea, map<int, tEstacion>> posiciones;

public:

    void nueva_linea(const tLinea &nombre) {
        if (lineas.count(nombre) > 0)
            throw domain_error("Linea existente");
        
        lineas[nombre];
    }

    void nueva_estacion(const tLinea &linea, const tEstacion &nombre, int posicion) 
    {
        if (lineas.count(linea) == 0)
            throw domain_error("Linea no existente");

        if(lineas[linea].count(nombre) != 0)
            throw domain_error("Estacion duplicada en linea");

        if (posiciones[linea].count(posicion) != 0)
            throw domain_error("Posicion ocupada");

        lineas[linea].insert({nombre , posicion});
        estaciones[nombre].insert(linea);
        posiciones[linea][posicion] = nombre;

    }

    void eliminar_estacion(const tEstacion &estacion) 
    {
           if(estaciones.count(estacion) == 0)
               throw domain_error("Estacion no existente");

           auto it = estaciones[estacion].begin();
           while (it != estaciones[estacion].end())
           {
               auto it2 = lineas[*it].begin();

               posiciones[*it].erase(it2->second);
               lineas[*it].erase(estacion);
               it++;
           }

           estaciones.erase(estacion);
    }

    vector<string> lineas_de(const tEstacion &estacion) const 
    {
        vector<string> vct;

        if(estaciones.count(estacion) == 0)
            throw domain_error("Estacion no existente");

        auto it = estaciones.find(estacion);

        auto it2 = it->second.begin();
        
        while (it2 != it->second.end())
        {
            vct.push_back(*it2);
            it2++;
        }
           
        return vct;
    }

    string proxima_estacion(const tLinea &linea, const tEstacion &estacion) const 
    {
        if (lineas.count(linea) == 0)
            throw domain_error("Linea no existente");
        
        auto aux = lineas.find(linea);
        if (aux->second.count(estacion) == 0)
            throw domain_error(" Estacion no existente");



        auto it = lineas.find(linea);

        auto it2 = it->second.find(estacion);

        auto it3 = posiciones.find(linea);


        auto it4 = it3->second.find(it2->second);


        if(it4 == it3->second.end())
            throw domain_error("Fin de trayecto");

        ++it4;
        return it4->second;

    }

};

//@ </answer>
//
// ¡No modifiques nada debajo de esta línea!
// ----------------------------------------------------------------

bool resuelveCaso() {
    Ferrovistan trenes;
    string operacion;
    cin >> operacion;

    if (!cin)
        return false;

    while (operacion != "FIN") {
        try {
            if (operacion == "nueva_linea") {
                string nombre;
                cin >> nombre;
                trenes.nueva_linea(nombre);
            }
            else if (operacion == "nueva_estacion") {
                string linea, nombre;
                int posicion;
                cin >> linea;
                cin >> nombre;
                cin >> posicion;
                trenes.nueva_estacion(linea, nombre, posicion);
            }
            else if (operacion == "eliminar_estacion") {
                string estacion;
                cin >> estacion;
                trenes.eliminar_estacion(estacion);
            }
            else if (operacion == "lineas_de") {
                string estacion;
                cin >> estacion;
                vector<string> lineas = trenes.lineas_de(estacion);
                cout << "Lineas de " << estacion << ":";
                for (const string &linea: lineas)
                    cout << " " << linea;
                cout << endl;
            }
            else if (operacion == "proxima_estacion") {
                string linea, estacion;
                cin >> linea;
                cin >> estacion;
                string proxima = trenes.proxima_estacion(linea, estacion);
                cout << proxima << endl;
            }
        }
        catch (exception& e) {
            cout << "ERROR: " << e.what() << endl;
        }
        cin >> operacion;
    }
    cout << "---" << endl;

    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
    ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif


    return 0;

} // main
