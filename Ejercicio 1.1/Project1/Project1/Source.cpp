// Nombre del alumno José Antonio Tortosa Aranda
// Usuario del Juez E65


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Tiempo.h"
#include "error.h"

using namespace std;

// función que resuelve el problema
int resolver(vector<tiempo>& v, tiempo h, int inicio, int fin) 
{
    int mitad = (fin + inicio) / 2;
    int p = -1;


    //CASO BASE
    if (v[inicio] == h || h < v[inicio])
    {
        return inicio;
    }
    else if (inicio == fin + 1)
    {
        return p;
    }
    else
    {
        if ((h < v[mitad]))
        {
            return resolver(v, h, inicio, mitad - 1);
        }
        else if (h == v[mitad])
        {
            return mitad;

        }
        else
        {
            return resolver(v, h, mitad + 1, fin);
        }


    }

    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() 
{
    // leer los datos de la entrada
    int numerohoras, numeroresultados;

    cin >> numerohoras >> numeroresultados;

    if (numerohoras == 0 && numeroresultados == 0)
        return false;

    vector<tiempo> v(numerohoras);

    tiempo h;

    for (tiempo& aux: v)
    {
        try
        {
            cin >> aux;
        }
        catch (error e)
        {
            cout << e.getInfo() << endl;
        }
    }

    for (int i = 0; i < numeroresultados; i++)
    {
        try
        {
            cin >> h;
            

            if(v[v.size() - 1] <  h)
            {
                cout << "NO\n";
            }
            else
            {
                int sol = resolver(v, h, 0, v.size() - 1);
                cout << v[sol] << endl;
            }

        }
        catch (error e)
        {
            cout << e.getInfo() << endl;
        }
    }

    cout << "---\n";
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
