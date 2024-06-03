#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <stdexcept>
using namespace std;

class carnet_puntos{
private:
    
    unordered_map<string, int> carnet;
    vector<int> puntos_count;

public:
    carnet_puntos() : puntos_count(16, 0) {}
    void nuevo(string dni)
    {
        if (carnet[dni] > 0) {
            throw domain_error("Conductor duplicado");
        }
        else
        {
            carnet[dni] = 15;
            puntos_count[15]++;
        }
    }
    void quitar(string dni, int puntos)
    {
        auto it = carnet.find(dni);
        if (it == carnet.end()) {
            throw domain_error("Conductor inexistente");
        }


        int old_puntos = it->second;
        it->second = max(0, it->second - puntos);

        puntos_count[old_puntos]--; 
        puntos_count[it->second]++;
    }
    int consultar(string dni)
    {
        auto it = carnet.find(dni);
        if (it == carnet.end()) {
            throw domain_error("Conductor inexistente");
        }
        return it->second;
    }
    int cuantos_con_puntos(int puntos)
    {
        if (puntos < 0 || puntos > 15) {
            throw domain_error("Puntos no validos");
        }

        return puntos_count[puntos];
    }
};

bool resuelveCaso() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;
    
    carnet_puntos dgt;
    
    while (orden != "FIN") {
        try {
            if (orden == "nuevo") {
                cin >> dni;
                dgt.nuevo(dni);
            } else if (orden == "quitar") {
                cin >> dni >> punt;
                dgt.quitar(dni, punt);
            } else if (orden == "consultar") {
                cin >> dni;
                punt = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << punt << '\n';
            } else if (orden == "cuantos_con_puntos") {
                cin >> punt;
                int cuantos = dgt.cuantos_con_puntos(punt);
                cout << "Con " << punt << " puntos hay " << cuantos << '\n';
            } else
                cout << "OPERACION DESCONOCIDA\n";
        } catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}

int main() {
    
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
