/*
 * Nombre de los alumnos: Alvaro Velasco Garcia & José Antonio Tortosa Aranda
 *
 * Usuario de los alumnos: E66 & E65
 *
 * Comenta la representación que has escogido. Indica el coste de TODAS las operaciones
 */


#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>

 //Añade las librerías que necesites

 //

using namespace std;

using Alumno = string;
using Profesor = string;


typedef struct
{
    Profesor nombre_profesor;
    int puntuacion;

}tAlumno;


class Autoescuela {
private:

    // Por un lado tenemos, para cada alumna, sus datos agrupados
    //   - map porque necesitamos recorrer los alumnos en un determinado
    //     orden en la funcion examen.
    //   - struct porque de esta forma agrupamos el nombre de su profesor y puntuacion.
    map<Alumno, tAlumno> Alumnado;

    // Por un lado tenemos, para cada profesor, su listado de alumnos
    //   - unordered_map porque no necesitamos recorrer los profesores en un determinado
    //     orden.
    //   - set porque de esta forma agrupamos el nombre de los alumnos en orden, 
    //     permitiendo que su busqueda en el mapa sea más facil, y facilitando la 
    //     funcion aprobar y una sección de alta.
    unordered_map<Profesor, set<Alumno>> Profesorado;


public:

    //O(log N) Donde N es tanto el numero de alumnos como el de profesores
    void alta(const Alumno& alumno, const Profesor& profesor)
    {
        auto it_alumno = Alumnado.find(alumno);

        if (it_alumno == Alumnado.end())
        {
            // El alumno no está en el contenedor, lo añadimos con el profesor asignado
            Alumnado[alumno].nombre_profesor = profesor;
            Alumnado[alumno].puntuacion = 0;
            Profesorado[profesor].insert(alumno);
        }
        else if(it_alumno->second.nombre_profesor != profesor)
        {
            // Asignamos el nuevo profesor y actualizamos el contenedor de profesores
            Profesorado[it_alumno->second.nombre_profesor].erase(alumno);
            
            it_alumno->second.nombre_profesor = profesor;
            Profesorado[profesor].insert(alumno);
        }
    }





    //O(log N) Donde N es el numero de alumnos
    bool es_alumno(const Alumno& alumno, const Profesor& profesor) const
    {
        auto it = Alumnado.find(alumno);

        if (it!= Alumnado.end() && it->second.nombre_profesor == profesor)
            return true;
        
        return false;
    }

    //O(log N) Donde N es el numero de alumnos
    int puntuacion(const Alumno& alumno) const {

        auto it = Alumnado.find(alumno);

        if (it == Alumnado.end())
        {
            throw domain_error("El alumno A no esta matriculado.");
        }
        else
        {
            return it->second.puntuacion;
        }
    }

    //O(log N) Donde N es el numero de alumnos
    void actualizar(const Alumno& alumno, int puntos) {

        auto it = Alumnado.find(alumno);

        if (it == Alumnado.end())
        {
            throw domain_error("El alumno A no esta matriculado.");
        }
        else
        {
            it->second.puntuacion += puntos;
        }

    }

    //O(log N) Donde N es tanto el numero de alumnos como el de profesores
    vector<Alumno> examen(const Profesor& profesor, int N) const
    {
        vector<Alumno> aux;

        auto prof = Profesorado.find(profesor);
        
        if (prof != Profesorado.end())
        {
            auto alumnos = prof->second.cbegin();

            while (alumnos != prof->second.cend())
            {
                auto punt = Alumnado.find((*alumnos));

                if (punt->second.puntuacion >= N)
                {
                    aux.push_back((*alumnos));
                }

                alumnos++;
            }

            
        }
        
        return aux;
    }
    
    //O(log N) Donde N es el numero de alumnos
    void aprobar(const Alumno& alumno)
    {
        auto it = Alumnado.find(alumno);

        if (it == Alumnado.end())
        {
            throw domain_error("El alumno A no esta matriculado.");
        }
        else
        {
            Profesorado[Alumnado[alumno].nombre_profesor].erase(alumno);
            Alumnado.erase(it);

        }
    }

};

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------- */

bool resuelveCaso() {
    string op;
    cin >> op;
    if (!cin)
        return false;
    Autoescuela autoesc;

    while (op != "FIN") {
        try {
            if (op == "alta") {
                string alumno, profesor;
                cin >> alumno >> profesor;
                autoesc.alta(alumno, profesor);
            }
            else if (op == "es_alumno") {
                string alumno, profesor;
                cin >> alumno >> profesor;
                if (autoesc.es_alumno(alumno, profesor)) {
                    cout << alumno << " es alumno de " << profesor << endl;
                }
                else {
                    cout << alumno << " no es alumno de " << profesor << endl;
                }
            }
            else if (op == "puntuacion") {
                string alumno;
                cin >> alumno;
                int puntuacion = autoesc.puntuacion(alumno);
                cout << "Puntuacion de " << alumno << ": " << puntuacion << endl;
            }
            else if (op == "actualizar") {
                string alumno;
                int puntuacion;
                cin >> alumno >> puntuacion;
                autoesc.actualizar(alumno, puntuacion);
            }
            else if (op == "examen") {
                string profesor;
                int minimo_puntos;
                cin >> profesor >> minimo_puntos;
                cout << "Alumnos de " << profesor << " a examen:" << endl;
                for (const string& nombre : autoesc.examen(profesor, minimo_puntos)) {
                    cout << nombre << endl;
                }
            }
            else if (op == "aprobar") {
                string alumno;
                cin >> alumno;
                autoesc.aprobar(alumno);
            }
        }
        catch (std::exception& e) {
            cout << "ERROR" << endl;
        }

        cin >> op;
    }

    cout << "---\n";
    return true;
}



int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}