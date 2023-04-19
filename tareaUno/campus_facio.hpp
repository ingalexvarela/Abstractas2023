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

class Aulas
{
public:
    int aula_id;
    int cantidad_pupitres;
    bool tiene_proyector; // Variable booleana para indicar si tiene proyector o no

    Aulas(int cantidadPupitres, bool tieneProyector);                   // Constructor
    static void agregarAula(int cantidadPupitres, bool tieneProyector); // Método para agregar información aula
    void imprimirAula();                                                // Método para imprimir información del objeto Aulas

    // Variable de clase estática para almacenar la cantidad de objetos Aulas creados
    static int cantidadAulasCreadas;

private:
    int generarID();
};

void imprimirInfoAula(Aulas aula); // Función externa para imprimir información del objeto Aulas
#endif