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
//Añade las librerías que necesites:
//@ <answer>
#include <unordered_map>
#include <map>
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

    //Linea, conjunto de estaciones
    unordered_map<tLinea, map<int, tEstacion>> sistema;


    unordered_map<tEstacion, map<tLinea, int>> estaciones;
public:

    void nueva_linea(const tLinea& nombre)
    {
        if (sistema.count(nombre) == 0)
        {
            sistema[nombre];
        }
        else
        {
            throw domain_error("Linea existente");
        }
    }

    void nueva_estacion(const tLinea& linea, const tEstacion& nombre, int posicion)
    {
        if (sistema.count(linea) == 0)
        {
            throw domain_error("Linea no existente");
        }
        else
        {

            if (estaciones[nombre].count(linea) == 1)
            {
                throw domain_error("Estacion duplicada en linea");
            }

            if(sistema[linea].count(posicion) != 0 )
            {
                throw domain_error("Posicion ocupada");
            }

            estaciones[nombre][linea] = posicion;
            sistema[linea][posicion] = nombre;

        }
    }

    void eliminar_estacion(const tEstacion& estacion)
    {
        auto it = estaciones.find(estacion);

        if (it == estaciones.end())
        {
            throw domain_error("Estacion no existente");
        }

        auto it2 = it->second.begin();

        while (it2 != it->second.end())
        {
            sistema[it2->first].erase(it2->second);
            it2++;
        }
        estaciones.erase(estacion);
    }

    vector<string> lineas_de(const tEstacion& estacion) const
    {
        vector<string> vct;

        auto it = estaciones.find(estacion);
        
        if (it == estaciones.end())
        {
            throw domain_error("Estacion no existente");
        }

        auto it2 = it->second.begin();

        while (it2 != it->second.end())
        {
            vct.push_back(it2->first);
            it2++;
        }

        return vct;

    }

    string proxima_estacion(const tLinea& linea, const tEstacion& estacion) const
    {
        if (sistema.count(linea) == 0)
        {
            throw domain_error("Linea no existente");
        }


        auto aux = estaciones.find(estacion);
        
        if (aux == estaciones.end())
        {
            throw domain_error("Estacion no existente");
        }

        auto it = aux->second.find(linea);

        if (it == estaciones.find(estacion)->second.end())
        {
            throw domain_error("Estacion no existente");
        }


        auto it2 = sistema.find(it->first)->second.find(it->second);


        it2++;

        if (it2 == sistema.find(it->first)->second.end())
        {
            throw domain_error("Fin de trayecto");
        }

        return it2->second;
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
                for (const string& linea : lineas)
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
