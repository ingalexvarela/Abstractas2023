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
#include <vector> // Incluir la biblioteca <vector>
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
    void imprimirAula() const;
    void imprimirTotalAulas(); // Método para imprimir información de todos los objeto Aulas

    // Variable de clase estática para almacenar la cantidad de objetos Aulas creados
    static int cantidadAulasCreadas;

private:
    int generarID();
};

//-----------------------------------------------------------------------------CLASE EDIFICIOS Aulas
class EdificioAulas
{
public:
    bool ascensor;                                                                               // Variable booleana para indicar si tiene ascensor o no
    bool soda;                                                                                   // Variable booleana para indicar si tiene soda o no
    std::string nombre_edificio;                                                                 // Nombre del edificio
    EdificioAulas(bool tieneAscensor, bool tieneSoda, std::string nombreEdificio);               // Constructor
    static void agregarEdificio(bool tieneAscensor, bool tieneSoda, std::string nombreEdificio); // Método para agregar información de edificio
    void agregarAula(Aulas aula);                                                                // Método para agregar un objeto Aulas al vector
    void imprimirAulasEnEdificio() const;                                                        // Método para imprimir la información de las aulas en el edificio
    void imprimirTotalEdificios();
    // Variable de clase estática para almacenar la cantidad de objetos Aulas creados en el edificio
    int AulasEdificioCreadas = 0;

    // Variable de clase estática para almacenar la cantidad de objetos EdificioAulas creados
    static int cantidadEdificiosAulasCreados;

    // Vector de clase estático para almacenar los objetos Aulas creados en el edificio
    // static
    std::vector<Aulas> aulasEdificioVec;
};
//-----------------------------------------------------------------------------CLASE EDIFICIOS Aulas
class EdificioParqueo
{
public:
    bool ascensor;
    int numero_pisos_parqueo;                                                                            // Variable booleana para indicar si tiene ascensor o no                                                                                // Variable booleana para indicar si tiene soda o no
    std::string nombre_parqueo;                                                                          // Nombre del edificio
    EdificioParqueo(int pisosParqueo, bool tieneAscensor, std::string nombreParqueo);                    // Constructor
    static void agregarEdificioParqueo(int pisosParqueo, bool tieneAscensor, std::string nombreParqueo); // Método para agregar información de edificio                                                    // Método para agregar un objeto Aulas al vector                                             // Método para imprimir la información de las aulas en el edificio
    void imprimirEdificioParqueos() const;
    void imprimirTotalEdificiosParqueo();

    // Variable de clase estática para almacenar la cantidad de objetos EdificioParqueo creados
    static int cantidadEdificiosParqueoCreados;
};

//-----------------------------------------------------------------------------CLASE EDIFICIOS
class TodosLosEdificios
{
public:                                                         // Variable booleana para indicar si tiene soda o no
    std::string nombre_finca;                                   // Nombre del edificio
    TodosLosEdificios(std::string nombreFinca);                 // Constructor
    static void agregarEdificiosFinca(std::string nombreFinca); // Método para agregar información de edificio
    void agregarEdificioAulas(EdificioAulas edificio);          // Método para agregar un objeto Aulas al vector
    void imprimirTotalEdificiosAyP();                           // Asociado a la finca
    // Variable de clase estática para almacenar la cantidad de objetos EdificioAulas creados en el edificio
    static int EdificioAulasCreados;
    static int EdificioParqueosCreados;
    // Variable de clase estática para almacenar la cantidad de objetos EdificioAulas y EdificioParueo creados
    static int cantidadEdificiosAyPCreados;
};

void imprimirInfoAula(Aulas aula);                                    // Función externa para imprimir información del objeto Aulas
void imprimirInfoEdificioAula(EdificioAulas edicioAulas);             // Función externa para imprimir información del objeto edificios
void imprimirInfoEdificioparqueo(EdificioParqueo newEdificioParqueo); // Función externa para imprimir información del objeto edificios parkeo
#endif