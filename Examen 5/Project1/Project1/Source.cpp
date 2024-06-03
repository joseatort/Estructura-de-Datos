// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Arbin.h"

using namespace std;

// función que resuelve el problema
typedef struct
{
    string lider;
    int numero;
}Tgrupo;



Tgrupo resolver(const Arbin<string> &arbol)
{
    if (arbol.esVacio())
    {
        return {"", 0};
    }
    else
    {
        Tgrupo iz = resolver(arbol.hijoIz());
        Tgrupo dr = resolver(arbol.hijoDr());

    


        if (arbol.raiz() == "-")
        {

            if (iz.numero > dr.numero)
            {
                return { iz.lider, iz.numero + dr.numero };

            }
            else if(iz.numero < dr.numero)
            {
                return { dr.lider, iz.numero + dr.numero };

            }
            else
            {
                if (iz.lider < dr.lider || dr.lider == "")
                {
                    return { iz.lider, iz.numero + dr.numero };
                }
                else
                {
                    return { dr.lider, iz.numero + dr.numero };
                }
            }


           

        }
        else if (arbol.raiz() == "Orcos")
        {

            if (iz.numero > dr.numero)
            {
                return { iz.lider, (iz.numero + dr.numero) / 2 };

            }
            else if (iz.numero < dr.numero)
            {
                return { dr.lider,  (iz.numero + dr.numero) / 2 };

            }
            else
            {
                if (iz.lider < dr.lider || dr.lider == "")
                {
                    return { iz.lider, (iz.numero + dr.numero) / 2 };
                }
                else
                {
                    return { dr.lider,  (iz.numero + dr.numero) / 2 };
                }
            }
        }
        else
        {
            return { arbol.raiz(), 1};
        }


    }


    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    Arbin<string> arbol;
    arbol = Arbin<string>::leerArbol(".");

    Tgrupo resultado = resolver(arbol);
    if (resultado.numero == 0)
    {
        cout << "Ninguno\n";
    }
    else
    {
        cout << resultado.lider << " " << resultado.numero << endl;
    }

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