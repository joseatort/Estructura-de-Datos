// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Fecha.h"
#include "Stack.h"

using namespace std;

// función que resuelve el problema
bool resolver(Stack<fecha> &h, fecha &f) 
{
    
    //return h.comprobar(f);
    //Stack<fecha> aux = h;
    while (!h.empty())
    {
        if (h.top().get_accidentados() > f.get_accidentados())
        {
            f = h.top();
            return true;
        }
        else
        {
            h.pop();
        }
    }
        

    //SI QUITO EL COMENTARIO ELIMINAR FUNCION COMPROBAR

    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numerofechas;
    bool check = false;
    fecha f;
    fecha auxiliar;
    Stack<fecha> h;
    cin >> numerofechas;

    if (!std::cin)
        return false;

    for (int i = 0; i < numerofechas; i++)
    {
        cin >> f;
        auxiliar = f;
  
       check = resolver(h, f);
      
        h.push(auxiliar); 

        if (check)
        {
            cout << f << endl;
        }
        else if (!check)
        {
            cout << "NO HAY\n";
        }
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