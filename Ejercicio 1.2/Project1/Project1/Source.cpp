// Nombre del alumno José Antonio Tortosa Aranda
// Usuario del Juez E65


#include <iostream>
#include <iomanip>
#include <fstream>
#include "polinomio.h"
#include <vector>
#include <math.h>

using namespace std;

// función que resuelve el problema
int resolver(vector<polinomio> poli, int x, int numeromonomios)
{
    int resultado = 0; 
    for (int i = 0; i < numeromonomios; i++)
    {
        resultado += poli[i].getcoeficiente() * pow(x, poli[i].getgrado());
    }
    return resultado;
}

bool sumar(vector<polinomio> &v, polinomio aux)
{

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].getgrado() == aux.getgrado())
        {
            v[i].sumar(aux.getcoeficiente());
            return true;
        }
    }

    return false;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
   
    int numerocasos;
    int x;
    vector<polinomio> v;
    polinomio aux;
    do 
    {
        cin >> aux;

        if (!std::cin)
            return false;

        if (aux.getcoeficiente() != 0 || aux.getgrado() != 0)
        {
            if (!sumar(v, aux))
            {
                v.push_back(aux);
            }
            
        }
    }
    while(aux.getcoeficiente() != 0 || aux.getgrado() != 0);

    cin >> numerocasos;

    for (int i = 0; i < numerocasos; i++)
    {
        cin >> x;
        int sol = resolver(v, x, v.size());
        cout << sol << " ";
    }

    cout << endl;

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