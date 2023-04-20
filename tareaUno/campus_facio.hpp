/**
 * @file campus_facio.hpp
 *
 * @brief Descripción breve del contenido de campus_facio.hpp
 *
 * Descripción detallada del contenido del archivo encabezado
 *
 * Este archivo encabezado que forma parte del proyecto "Campus" utiliza la licencia Creative Commons Legal Code CC0 1.0 Universal.
 *
 * @license
 * Creative Commons Legal Code CC0 1.0 Universal
 * Consulta la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author Alex Varela
 * @date 17 de abril de 2023
 */

#ifndef CAMPUS_FACIO_H
#define CAMPUS_FACIO_H
#include <string>
//-----------------------------------------------------------------------------CLASE EDIFICIOS
class EdificioAulas
{
public:
    bool ascensor;               // Variable booleana para indicar si tiene ascensor o no
    bool soda;                   // Variable booleana para indicar si tiene soda o no
    std::string nombre_edificio; // Nombre del edificio

    EdificioAulas(bool tieneAscensor, bool tieneSoda, std::string nombreEdificio);               // Constructor
    static void agregarEdificio(bool tieneAscensor, bool tieneSoda, std::string nombreEdificio); // Método para agregar información de edificio
    void imprimirEdificioAula();                                                                 // Método para imprimir información del objeto EdificioAulas

    // Variable de clase estática para almacenar la cantidad de objetos EdificioAulas creados
    static int cantidadEdificiosAulasCreados;
};
//----------------------------------------------------------------------------CLASE AULAS
class Aulas
{
public:
    std::string ubicacion_edificio;
    int aula_id;
    int cantidad_pupitres;
    int piso_edificio;
    bool tiene_proyector; // Variable booleana para indicar si tiene proyector o no

    Aulas(std::string ubicacionEdificio, int pisoEdificio, int cantidadPupitres, bool tieneProyector);                   // Constructor
    static void agregarAula(std::string ubicacionEdificio, int pisoEdificio, int cantidadPupitres, bool tieneProyector); // Método para agregar información aula
    void imprimirAula();                                                                                                 // Método para imprimir información del objeto Aulas

    // Variable de clase estática para almacenar la cantidad de objetos Aulas creados
    static int cantidadAulasCreadas;

private:
    int generarID();
};

void imprimirInfoAula(Aulas aula);                        // Función externa para imprimir información del objeto Aulas
void imprimirInfoEdificioAula(EdificioAulas edicioAulas); // Función externa para imprimir información del objeto edificios
#endif