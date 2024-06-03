// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

using namespace std;

typedef struct
{
    int alturas;
    int num_mayores;

}tAguasLimpias;



// función que resuelve el problema
tAguasLimpias resolver(const Arbin<int> & arbol)
{

    if (arbol.esVacio())
    {
        return {0 , 0};
    }
    else
    {
        tAguasLimpias iz = resolver(arbol.hijoIz());
        tAguasLimpias dr = resolver(arbol.hijoDr());

        if (!arbol.hijoIz().esVacio() && arbol.hijoIz().raiz() > 0)
        {
            iz.alturas -= arbol.hijoIz().raiz();

            if(iz.alturas < 0)
            {
                iz.alturas = 0;
            }

        }

        if (!arbol.hijoDr().esVacio() && arbol.hijoDr().raiz() != 0)
        {
            dr.alturas -= arbol.hijoDr().raiz();

            if (dr.alturas < 0)
            {
                dr.alturas = 0;
            }
        }

        if (iz.alturas >= 3)
        {
            iz.num_mayores++;
        }
        
        if (dr.alturas >= 3)
        {
            dr.num_mayores++;
        }       


        //Distinguimos si es un manatial o no
        if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio())
        {
            return{ iz.alturas + dr.alturas + 1, iz.num_mayores + dr.num_mayores };
        }
        else
        {
            return { iz.alturas + dr.alturas, iz.num_mayores + dr.num_mayores };

        }


    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol;


    arbol = arbol.leerArbol(-1);

    cout << resolver(arbol).num_mayores << endl;
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