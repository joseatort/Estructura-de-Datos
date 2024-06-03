// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Stack.h"
using namespace std;


// función que resuelve el problema
void resolver(Stack<char> &pila, char ultimo) 
{
        
    if (pila.top() == ultimo - 1 || pila.top() == ultimo - 2)
    {
        pila.pop();

    }
    else
    {
        pila.push(ultimo);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Stack<char> pila;

    string auxiliar;
    char aux;
    getline(cin, auxiliar);
    if (! std::cin)
        return false;
    
    for (int i = 0; i < auxiliar.size(); i++)
    {
        aux = auxiliar[i];
        if (aux == '(' || aux == '[' || aux == '{')
        {
            pila.push(aux);
        }
        else if ((aux == ')' || aux == ']' || aux == '}') && pila.size() == 0)
        {
            cout << "NO\n";
            return true;
        }
        else if (aux == ')' || aux == ']' || aux == '}')
        {
            resolver(pila, aux);
            cout << pila;
        }


    }

    if (pila.size() == 0)
    {
        cout << "SI\n";
    }
    else
    {
        cout << "NO\n";

    }
    
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