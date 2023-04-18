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
#include "campus_facio.hpp"

using namespace std;

// Constructor
Aulas::Aulas(int aulaId, int cantidadPupitres)
{
    aula_id = aulaId;
    cantidad_pupitres = cantidadPupitres;
}

// Método para agregar información aula
void Aulas::agregarAula(int aulaId, int cantidadPupitres)
{
    aula_id = aulaId;
    cantidad_pupitres = cantidadPupitres;
}

// Método para imprimir información del objeto Aulas
void Aulas::imprimirAula()
{
    cout << "Aula ID: " << aula_id << endl;
    cout << "Cantidad de pupitres: " << cantidad_pupitres << endl;
}

// Función externa para imprimir información del objeto Aulas
void imprimirInfoAula(Aulas aula)
{
    aula.imprimirAula();
}
