// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Stack.h"
#include <istream>
using namespace std;

// función que resuelve el problema
void resolver(Stack<char> &q, char aux)
{
     if (q.top() == aux - 1 || q.top() == aux - 2)
     {
        q.pop();

     }
     else
     {
        q.push(aux);
     }    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string auxiliar;
    char aux;
    Stack<char> q;

    getline(cin, auxiliar);

    if (!std::cin)
        return false;

    for (int i = 0; i < auxiliar.size(); i++)
    {
        aux = auxiliar[i];
        if (aux == '(' || aux == '[' || aux == '{')
        {
            q.push(aux);
        }
        else if((aux == ')' || aux == ']' || aux == '}' )&& q.size() == 0)
        {
            cout << "NO\n";
            return true;
        }
        else if (aux == ')' || aux == ']' || aux == '}')
        {
            resolver(q, aux);
        }


    }

    if (q.empty())
    {
        cout << "SI\n";
     }
    else
    {
        cout << "NO\n";
    }

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