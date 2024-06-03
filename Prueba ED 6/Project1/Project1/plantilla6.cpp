/*
 * Nombre de los alumnos:
 *
 * Usuario de los alumnos:
 */

/* IMPORTANTE:
 *  - La plantilla sin más no compila puesto que hay decisiones que debes tomar en la implementación.
 *    Explica por qué eliges lo que eliges.
 *
 *  - Debes decidir si quieres usar un diccionario de los vistos en clase o de la STL.
 *    Tendrás que borrar el método de escritura que no necesites.
 *
 *  - Debes decidir si necesitas que el diccionario esté ordenado o no.
 *
 *  - Para mayor comodidad, sugiero que si un despacho está ocupado por un Jefe, se le asigne el valor -1.
 *    Los métodos de escritura están implementados con esto en mente, si usas otra implementación debes adaptarlo.
 *
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
//Descomenta la clase que uses

//#include "TreeMap.h"
//#include "HashMap.h"
//#include <map>
//#include <unordered_map>

//Completa usando el tipo de diccionario concreto que necesitas
using Diccionario = map<int, int>;

//Si usas un diccionario con TreeMap o HashMap usa este método. Bórralo si no
void escrituraPropia(const Diccionario& d){
    for (auto it = d.cbegin(); it != d.cend(); ++it ) {
        cout << it->first << " ";
        if(it->second == -1) //es jefe
            cout << "JEFE" << endl;
        else
            cout << it->second << endl;
    }
    cout << "---" << endl;
}


//Si usas un diccionario de la STL map o unordered_map usa este método. Bórralo si no.
void escrituraSTL(const Diccionario& d){
    for (auto it = d.cbegin(); it != d.cend(); ++it ) {
        cout << it->first << " ";
        if(it->second == -1) //es jefe
            cout << "JEFE" << endl;
        else
            cout << it->second << endl;
    }
    cout << "---" << endl;
}


bool resuelveCaso() {
  //Lectura de datos
  int C, N, M; //Capacidad de los despachos, número de empleados y número de directivos
  cin >> C >> N >> M;
  if (C == 0 && N == 0 && M == 0)
      return false;
  else{
      //Lee los datos de los despachos
      vector<int> currantes(N), jefes(M);
      for(int & d : currantes)
          cin>> d;
      for(int & d : jefes)
          cin>> d;

      //Llama a la función que asigna y resuelve el problema
      Diccionario despachos;



      while (jefes.size() != 0)
      {

          if (despachos.find(jefes.front()) == despachos.end())
          {
              despachos[jefes.front()] = -1;
          }
          else
          {
              int n = jefes.front();

              while (despachos[n] == -1)
                  n++;

              despachos[n] = -1;

          }

          jefes.erase(jefes.begin());
      }



      while (currantes.size() != 0)
      {

          if (despachos.find(currantes.front()) == despachos.end())
          {
              despachos[currantes.front()] = 1;
          }
          else
          {
              int n = currantes.front();

              while (despachos[n] >= C || despachos[n] == -1)
                  n++;

              despachos[n]++;

          }

          currantes.erase(currantes.begin());
      }














      //escritura de datos
      escrituraPropia(despachos);
      return true;
  }
}

int main() {

#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
