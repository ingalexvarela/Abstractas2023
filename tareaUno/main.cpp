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
    // Crear objetos Edificio Aulas y agregarlos al vector
    EdificioAulas edicioAulas1(true, true, "sociales");
    EdificioAulas::agregarEdificio(true, true, "ingenieria");
    imprimirInfoEdificioAula(edicioAulas1);

    // Crear objetos Aulas y agregarlos al vector
    Aulas aula1("sociales", 6, 20, true);
    Aulas aula2("ingenieria", 2, 20, true);
    Aulas aula3("matemática", 5, 20, true);
    Aulas::agregarAula("Hoy", 12, 20, true);
    imprimirInfoAula(aula1);
    return 0;
}