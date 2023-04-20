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

int Aulas::cantidadAulasCreadas = 0;                  // Inicializar la variable de clase estática en 0
int EdificioAulas::cantidadEdificiosAulasCreados = 0; // Inicializar la variable de clase estática en 0

// Vector para almacenar los objetos Aulas creados
static vector<Aulas> aulasVec;                 // objetos Aulas creados
static vector<EdificioAulas> aulasEdificioVec; // objetos Edificio Aulas creados

//----------------------------------------------------------------------------CLASE EDIFICIO AULAS
// Constructor
EdificioAulas::EdificioAulas(bool tieneAscensor, bool tieneSoda, std::string nombreEdificio)
{
    ascensor = tieneAscensor;
    soda = tieneSoda;
    nombre_edificio = nombreEdificio;
    cantidadEdificiosAulasCreados++;
    aulasEdificioVec.push_back(*this); // Agregar el objeto actual al vector
}
// Método para agregar información de edificio
void EdificioAulas::agregarEdificio(bool tieneAscensor, bool tieneSoda, std::string nombreEdificio)
{
    EdificioAulas nuevoEdificio(tieneAscensor, tieneSoda, nombreEdificio); // Crear un nuevo objeto EdificioAulas con los parámetros dados
}
// Método para imprimir información del objeto EdificioAulas
void EdificioAulas::imprimirEdificioAula()
{
    cout << "Información sobre cada edificio de aulas:" << endl;
    cout << "Cantidad de edificios de aulas creados: " << cantidadEdificiosAulasCreados << endl;
    // Imprimir información de los objetos Aulas almacenados en el vector
    for (const auto &edicioAulas : aulasEdificioVec)
    {
        cout << "El Edificio " << nombre_edificio << ", " << (ascensor ? "si" : "no") << " tiene ascensor y "
             << (soda ? "si" : "no") << " tiene soda: " << endl;
        cout << "-----------------------" << endl;
    }
}

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
    Aulas nuevaAula(ubicacionEdificio, pisoEdificio, cantidadPupitres, tieneProyector); // Crear un nuevo objeto Aulas con los parámetros dados
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
void Aulas::imprimirAula()
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

// Función externa para imprimir información del objeto Aulas
void imprimirInfoAula(Aulas aula)
{
    aula.imprimirAula();
}

void imprimirInfoEdificioAula(EdificioAulas edicioAulas)
{
    edicioAulas.imprimirEdificioAula();
}
