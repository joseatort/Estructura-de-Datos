
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

using tjugador = string;
using tciudad = string;

class Grande {
private:

    set<tciudad> regiones_disputadas;
    unordered_map<tjugador, int> puntuacionJugador;

    typedef struct {

        unordered_map<tjugador, int>caballerosEnRegion;
        string dominante;
        int caballeros;

    }datosRegion;

    unordered_map<tciudad, datosRegion> regiones;


public:
    Grande() {}

    // Coste de la función y justificación
    void anyadir_jugador(tjugador const& id)
    {
        if (puntuacionJugador.find(id) != puntuacionJugador.end())
        {
            throw domain_error("Jugador existente");
        }

        puntuacionJugador[id] = 0;
    }

    // Coste de la función y justificación
    void colocar_caballero(tjugador const& id, tciudad const& p) 
    {
        if (puntuacionJugador.find(id) == puntuacionJugador.end())
        {
            throw domain_error("Jugador no existente");
        }
        else
        {
            
        }

    }

    // Coste de la función y justificación
    int puntuacion(tjugador const& id) 
    {
        if (puntuacionJugador.find(id) == puntuacionJugador.end())
            throw domain_error("ERROR: Jugador no existente");
        else {
            return puntuacionJugador[id];
        }
    }

    set<string> regiones_en_disputa()
    {
        return regiones_disputadas;
    }

    void expulsar_caballeros(tciudad const& p)
    {
        

    }

    
};

//////////////////////////////////////////////////////////////////////////////////////
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    Grande gr;
    std::cin >> op;  // operacion a realizar
    if (!std::cin)
        return false;
    std::string id, ciudad;
    while (op != "FIN") {
        try {
            if (op == "anyadir_jugador") {
                std::cin >> id;  // sector - numero de plantas
                gr.anyadir_jugador(id);
            }
            else if (op == "colocar_caballero") {
                std::cin >> id >> ciudad; // sector, plaga, numero de plantas afectadas
                gr.colocar_caballero(id, ciudad);
            }
            else if (op == "puntuacion") {
                std::cin >> id;
                int v = gr.puntuacion(id);
                // Escribir el resultado
                std::cout << "Puntuacion de  " << id << ": " << v << endl;

            }
            else if (op == "regiones_en_disputa") {
                set<string> v = gr.regiones_en_disputa();
                // Escribir el resultado
                std::cout << "Regiones en disputa:\n";
                for (auto const& s : v)
                    std::cout << s << endl;
            }
            else if(op == "expulsar_caballeros")
            {
                cin >> ciudad;
                gr.expulsar_caballeros(ciudad);
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
