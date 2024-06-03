#include <iostream>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <string>
#include <list>
#include <vector>
#include "fecha.h"
using namespace std;

using medico = string;
using paciente = string;


class Consultorio {
public:
    void nuevoMedico(medico m);
    void pideConsulta(paciente p, medico m, fecha f);
    paciente siguientePaciente(medico m);
    void atiendeConsulta(medico m);
    vector<pair<fecha, paciente>> listaPacientes(medico m, fecha f);

private:

    using  pacientes = map<fecha, paciente>;

    unordered_map<medico, pacientes> medicos; // Mapa de pacientes por medico
    
};

void Consultorio::nuevoMedico(medico m) {
    if (medicos.find(m) == medicos.end())
    {
        medicos[m] = pacientes();
    }
}

void Consultorio::pideConsulta(paciente p, medico m, fecha f)
{
    if (medicos.find(m) == medicos.end())
    {
        throw invalid_argument("Medico no existente");
    }
    else
    {
        if (medicos[m].find(f) != medicos[m].end())
        {
            throw invalid_argument("Fecha ocupada");
        }
        else
        {
            medicos[m][f] = p;
        }
    }
}

paciente Consultorio::siguientePaciente(medico m)
{
    if (medicos.find(m) == medicos.end())
    {
        throw invalid_argument("Medico no existente");
    }
    else if (medicos[m].empty())
    {
        throw invalid_argument("No hay pacientes");
    }
    else
    {
        auto it = medicos[m].begin();
        return it->second;
    }


}

void Consultorio::atiendeConsulta(medico m)
{
    if (medicos.find(m) == medicos.end())
    {
        throw invalid_argument("Medico no existente");
    }
    else if (medicos[m].empty())
    {
        throw invalid_argument("No hay pacientes");
    }
    else
    {
        auto it = medicos[m].begin();
        medicos[m].erase(it);

    }


}

vector<pair<fecha, paciente>> Consultorio::listaPacientes(medico m, fecha f)
{
    vector<pair<fecha, paciente>> pacientes;

    if (medicos.find(m) == medicos.end())
    {
        throw invalid_argument("Medico no existente");
    }
    else
    {
        auto it = medicos[m].begin();

        while (it != medicos[m].end())
        {
            if (it->first.get_Dia() == f.get_Dia())
            {
                pacientes.push_back({ it->first, it->second });
            }
            it++;
        }

    }

    return pacientes;
}