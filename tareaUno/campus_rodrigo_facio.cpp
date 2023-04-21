/**
 * @file campus_rodrigo_facio.cpp
 *
 * @brief Descripción breve del contenido de campus_rodrigo_facio.cpp
 *
 * Descripción detallada del contenido del archivo fuente
 *
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

int Aulas::cantidadAulasCreadas = 0;                      // Inicializar la variable de clase estática en 0
int EdificioParqueo::cantidadEdificiosParqueoCreados = 0; // Inicializar la variable de clase estática en 0
// int EdificioAulas::AulasEdificioCreadas = 0;
int EdificioAulas::cantidadEdificiosAulasCreados = 0;

int TodosLosEdificios::cantidadEdificiosAyPCreados = 0;
int TodosLosEdificios::EdificioAulasCreados = 0;
int TodosLosEdificios::EdificioParqueosCreados = 0;
// Vector para almacenar los objetos
static vector<Aulas> aulasVec;                     // objetos Aulas creados
static vector<EdificioParqueo> parqueoEdificioVec; // objetos Edificio Parkeo creados
// static vector<Aulas> aulasEdificioVec;              // objetos Aulas creadas en Edificio
static vector<EdificioAulas> edificioVec;           // objetos Edificio Aulas creados
static vector<TodosLosEdificios> todosEdificiosVec; // objetos Edificios
static vector<EdificioAulas> edificiosFincaVec;     // objetos Edificios de finca

//----------------------------------------------------------------------------CLASE AULAS
// Constructor
Aulas::Aulas(std::string ubicacionEdificio, int pisoEdificio, int cantidadPupitres, bool tieneProyector)
{
    aula_id = generarID();
    cantidad_pupitres = cantidadPupitres;
    tiene_proyector = tieneProyector;
    ubicacion_edificio = ubicacionEdificio;
    piso_edificio = pisoEdificio;
    cantidadAulasCreadas++;
    aulasVec.push_back(*this); // Agregar el objeto actual al vector
}

// Método para agregar información aula
void Aulas::agregarAula(std::string ubicacionEdificio, int pisoEdificio, int cantidadPupitres, bool tieneProyector)
{
    Aulas nuevaAula(ubicacionEdificio, pisoEdificio, cantidadPupitres, tieneProyector); // Crear un nuevo objeto Aulas con los parámetros dados                                                      // Agregar el nuevo objeto al vector
}

// Método para generar ID del aula random
int Aulas::generarID()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(10000000, 99999999);
    return dis(gen);
}

// Método para imprimir información del objeto Aulas
void Aulas::imprimirAula() const
{
    cout << "El Aula: " << aula_id << ", localizada en el piso " << piso_edificio
         << " del edificio de " << ubicacion_edificio << " posee " << cantidad_pupitres
         << " pupitres y " << (tiene_proyector ? "si" : "no") << " tiene proyector: " << endl;
    cout << "-----------------------" << endl;
}

// Método para imprimir información del objeto Aulas
void Aulas::imprimirTotalAulas()
{
    cout << "Información sobre cada aula:" << endl;
    cout << "Cantidad de aulas creadas: " << cantidadAulasCreadas << endl;
    // Imprimir información de los objetos Aulas almacenados en el vector
    for (const auto &aula : aulasVec)
    {
        cout << "El Aula: " << aula.aula_id << ", localizada en el piso " << aula.piso_edificio
             << " del edificio de " << aula.ubicacion_edificio << " posee " << aula.cantidad_pupitres
             << " pupitres y " << (aula.tiene_proyector ? "si" : "no") << " tiene proyector: " << endl;
        cout << "-----------------------" << endl;
    }
}

//----------------------------------------------------------------------------CLASE EDIFICIO AULAS

// Constructor
EdificioAulas::EdificioAulas(bool tieneAscensor, bool tieneSoda, std::string nombreEdificio)
{
    // aulasEdificioVec.clear();
    ascensor = tieneAscensor;
    soda = tieneSoda;
    nombre_edificio = nombreEdificio;
    cantidadEdificiosAulasCreados++;
    edificioVec.push_back(*this); // Agregar el objeto actual al vector
}

// Método para agregar edificio
void EdificioAulas::agregarEdificio(bool tieneAscensor, bool tieneSoda, std::string nombreEdificio)
{
    EdificioAulas nuevoEdificio(tieneAscensor, tieneSoda, nombreEdificio); // Crear un nuevo objeto EdificioAulas con los parámetros dados
}

// Método para agregar un objeto Aulas al vector
void EdificioAulas::agregarAula(Aulas aula)
{
    aulasEdificioVec.push_back(aula); // Agregar el objeto Aulas al vector del edificio
    AulasEdificioCreadas++;
}

// Método para imprimir la información de las aulas en el edificio
void EdificioAulas::imprimirAulasEnEdificio() const
{
    cout << "El Edificio " << nombre_edificio << ", " << (ascensor ? "si" : "no") << " tiene ascensor y "
         << (soda ? "si" : "no") << " tiene soda: " << endl;
    cout << "Cantidad de aulas del Edificio: " << nombre_edificio << " es: " << AulasEdificioCreadas << endl;
    for (const auto &aula : aulasEdificioVec)
    {
        aula.imprimirAula(); // Llamar al método imprimirAula de la clase Aulas para imprimir la información del aula
    }
}

// Método para imprimir el total de los edificios Aulas
void EdificioAulas::imprimirTotalEdificios()
{
    cout << "Información sobre todos los edificios:" << endl;
    cout << "Cantidad de edificios creados: " << cantidadEdificiosAulasCreados << endl;
    // Imprimir información de los objetos edificios almacenados en el vector
    for (const auto &edificio : edificioVec)
    {
        cout << "El Edificio " << nombre_edificio << ", " << (ascensor ? "si" : "no") << " tiene ascensor y "
             << (soda ? "si" : "no") << " tiene soda: " << endl;
        cout << "-----------------------" << endl;
    }
}
//----------------------------------------------------------------------------CLASE EDIFICIO PARqUEO

// Constructor
EdificioParqueo::EdificioParqueo(int pisosParqueo, bool tieneAscensor, std::string nombreParqueo)
{
    // aulasEdificioVec.clear();
    nombre_parqueo = nombreParqueo;
    ascensor = tieneAscensor;
    numero_pisos_parqueo = pisosParqueo;
    cantidadEdificiosParqueoCreados++;
    parqueoEdificioVec.push_back(*this); // Agregar el objeto actual al vector
}

// Método para agregar creacion objeto EdificioParqueo
void EdificioParqueo::agregarEdificioParqueo(int pisosParqueo, bool tieneAscensor, std::string nombreParqueo)
{
    EdificioParqueo newEdificioParqueo(pisosParqueo, tieneAscensor, nombreParqueo); // Crear un nuevo objeto Aulas con los parámetros dados                                                      // Agregar el nuevo objeto al vector
}

// Método para imprimir información del objeto EdificioParqueo
void EdificioParqueo::imprimirEdificioParqueos() const
{
    cout << "El Edificio Parqueo llamado: " << nombre_parqueo << ", Tiene " << numero_pisos_parqueo
         << " Pisos, además " << (ascensor ? "si" : "no") << " ascensor" << endl;
    cout << "-----------------------" << endl;
}

// Método para imprimir información del objeto Edificio Parqueo
void EdificioParqueo::imprimirTotalEdificiosParqueo()
{
    cout << "Información sobre cada Edificio de parqueo :" << endl;
    cout << "Cantidad de Edificios de parqueos creados: " << cantidadEdificiosParqueoCreados << endl;
    // Imprimir información de los objetos Aulas almacenados en el vector
    for (const auto &newEdificioParqueo : parqueoEdificioVec)
    {
        cout << "El Edificio de parqueo llamado: " << newEdificioParqueo.nombre_parqueo << ", Tiene " << newEdificioParqueo.numero_pisos_parqueo
             << " Pisos, y además " << (ascensor ? "si" : "no") << " cuenta con ascensor" << endl;
        cout << "-----------------------" << endl;
    }
}

//----------------------------------------------------------------------------CLASE EDIFICIOS

// Constructor
TodosLosEdificios::TodosLosEdificios(std::string nombreFinca)
{
    nombre_finca = nombreFinca;
    cantidadEdificiosAyPCreados++;
    todosEdificiosVec.push_back(*this); // Agregar el objeto actual al vector
}

// Método para agregar edificios
void TodosLosEdificios::agregarEdificiosFinca(std::string nombreFinca)
{
    TodosLosEdificios newEdificio(nombreFinca); // Crear un nuevo objeto EdificioAulas o Parqueo
}
// Método para agregar un objeto Edificios Aula al vector (copia Parueo)
void TodosLosEdificios::agregarEdificioAulas(EdificioAulas edificio)
{
    edificiosFincaVec.push_back(edificio); // Agregar el objeto EdificiosAulas al vector del edificio
    EdificioAulasCreados++;
}
// Método para imprimir la información de todos los edificios asociados a finca
void TodosLosEdificios::imprimirTotalEdificiosAyP()
{
    cout << "La Cantidad de edificios de Aulas es: " << cantidadEdificiosAyPCreados << endl;
    cout << "La Cantidad de edificios de Parqueos es:" << cantidadEdificiosAyPCreados << endl;
    cout << "La Cantidad total de edificios de la finca " << nombre_finca << " es: " << cantidadEdificiosAyPCreados << endl;
    cout << "Los edificios asociados a la " << nombre_finca << ","
         << " son: " << endl;
    for (const auto &edificio : edificiosFincaVec)
    {
        edificio.imprimirAulasEnEdificio(); // Llamar al método imprimirAula de la clase Aulas para imprimir la información del aula
    }
}

//------------------------------------------------------------------------------------------------------
// Función externa para imprimir información del objeto Aulas
void imprimirInfoAula(Aulas aula)
{
    aula.imprimirTotalAulas();
}

void imprimirInfoEdificioAula(EdificioAulas edificio)
{
    edificio.imprimirTotalEdificios();
}

void imprimirInfoEdificioparqueo(EdificioParqueo newEdificioParqueo)
{
    newEdificioParqueo.imprimirTotalEdificiosParqueo();
}
