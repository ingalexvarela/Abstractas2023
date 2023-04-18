/**
 * @file main.cpp
 *
 * @brief Descripción breve del contenido de main.cpp
 *
 * Descripción detallada del contenido del archivo fuente
 *
 * Este archivo fuente que forma parte del proyecto "Campus" utiliza la licencia Creative Commons Legal Code CC0 1.0 Universal.
 *
 * @license
 * Creative Commons Legal Code CC0 1.0 Universal
 * Consulta la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author Alex Varela
 * @date 17 de abril de 2023
 */

#include "campus_facio.hpp"

int main()
{
    // Crear objeto de tipo Aulas
    Aulas miAula(1, 30);

    // Imprimir información del objeto Aulas usando el método de la clase
    miAula.imprimirAula();

    // Agregar información al objeto Aulas usando el método de la clase
    miAula.agregarAula(2, 25);

    // Imprimir información del objeto Aulas usando la función externa
    imprimirInfoAula(miAula);

    return 0;
}