/**
 * @file campus_rodrigo_facio.cpp
 *
 * @brief Este codigo define los constructores de  clases y sus metodos, además una funcion externa
 *
 * Descripción detallada del contenido del archivo fuente
 *Se define el comportamiento de las clases creadas para la gestion de un campus universitario
 * Este archivo fuente forma parte del proyecto "Campus" que utiliza la licencia Creative Commons Legal Code CC0 1.0 Universal.
 *
 * @license
 * Creative Commons Legal Code CC0 1.0 Universal
 * Consulta la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author Alex Varela
 * @date 17 de abril de 2023
 */

#include <iostream>
#include <random>
#include <vector>
#include "campus_facio.hpp"
#include <string>

using namespace std;

// Variable estática para almacenar la cantidad de objetos EdificioAulas

//-----------------------------------------------AULA
Aula::Aula(const string &nombre, int cantidad_pupitres, bool tieneProyector)
    : nombre_(nombre), cantidad_pupitres_(cantidad_pupitres), tieneProyector_(tieneProyector), aula_id_(generarID()) {}

void Aula::imprimirInformacion() const
{
    cout << "El Aula " << nombre_ << " (ID: " << aula_id_ << ")"
         << " cuenta con " << cantidad_pupitres_ << " pupitres y " << (tieneProyector_ ? "si" : "no") << " tiene proyector" << endl;
}

int Aula::generarID()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(10000000, 99999999);
    return dis(gen);
}
//-----------------------------------------------EDIFICIO AULA

EdificioAulas::EdificioAulas(const std::string &nombre, bool tieneAscensor, bool tieneSoda)
{
    nombre_ = nombre;
    tiene_ascensor_ = tieneAscensor;
    tiene_soda_ = tieneSoda;
}

void EdificioAulas::agregarAula(const Aula &aula)
{
    aulas_.push_back(aula);
}

void EdificioAulas::imprimirInformacion() const
{
    cout << "El edificio de aulas es " << nombre_ << " y cuenta con " << aulas_.size() << " aulas, "
         << (tiene_ascensor_ ? "si" : "no") << " tiene ascensor y " << (tiene_soda_ ? "si" : "no")
         << " cuenta con soda" << endl;
    for (const auto &aula : aulas_)
    {
        aula.imprimirInformacion();
    }
}

void EdificioParqueo::imprimirInformacion() const
{
    cout << "El edificio de parqueo llamado " << nombre_ << " cuenta con capacidad para " << capacidad_ << " vehículos y "
         << (tiene_ascensor_ ? "si" : "no") << " tiene ascensor" << endl;
}

void Facultad::agregarEdificioAulas(const EdificioAulas &edificio)
{
    edificiosAulas_.push_back(edificio);
}

void Facultad::agregarEdificioParqueo(const EdificioParqueo &edificio)
{
    edificiosParqueo_.push_back(edificio);
}

void Facultad::imprimirInformacion() const
{
    cout << endl;
    cout << "La Facultad: " << nombre_ << ", cuenta con " << edificiosAulas_.size() << " edificios de aulas y con "
         << edificiosParqueo_.size() << " edificios de parqueo:" << endl;
    cout << "Información sobre los edificios de aulas:" << endl;
    for (const auto &edificioAulas : edificiosAulas_)
    {
        edificioAulas.imprimirInformacion();
    }
    cout << "Información sobre los edificios de parqueo:" << endl;
    for (const auto &edificioParqueo : edificiosParqueo_)
    {
        edificioParqueo.imprimirInformacion();
    }
}

void Finca::agregarFacultad(const Facultad &facultad)
{
    facultades_.push_back(facultad);
}

string Finca::getNombre() const
{
    return nombre_;
}

void Finca::imprimirInformacion() const
{
    cout << endl;
    cout << "La Finca " << nombre_ << ", cuenta con " << facultades_.size() << " facultades, y por está "
         << (pasa_bus_ ? "si" : "no") << " pasa el autobús externo" << endl;
    cout
        << "--------------------------------------------" << endl;
    for (const auto &facultad : facultades_)
    {
        facultad.imprimirInformacion();
    }
}

void Campus::agregarFinca(const Finca &finca)
{
    fincas_.push_back(finca);
}

void Campus::imprimirInformacion() const
{
    cout << endl;
    cout << "El Campus llamado ( " << nombre_ << " ), cuenta con " << fincas_.size() << endl;
    /* << " Fincas" << cantidadFacultades << " Facultades, " << cantidadEdificiosParqueoCreados
     << " Edificios de Parqueos y " << cantidadEdificiosAulasCreados << " Edificios de Aulas" << endl;*/
    for (const auto &finca : fincas_)
    {
        finca.imprimirInformacion();
    }
}

void imprimirInfoCampus(Campus campus)
{
    campus.imprimirInformacion();
}