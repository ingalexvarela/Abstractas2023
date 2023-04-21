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
{ // Crear un edificio de Parqueo
    EdificioParqueo newEdificioParqueo1(6, true, "Parqueo 1");
    EdificioParqueo newEdificioParqueo2(12, false, "Parqueo 2");
    //  Crear un edificio de aulas
    EdificioAulas edificio(true, false, "Ingeniería");
    EdificioAulas edificio1(true, false, "Sociales");
    // Crear objetos de la clase Aulas
    Aulas aula1("Aula 101", 10, 30, true);
    Aulas aula2("Aula 102", 1, 25, true);
    Aulas aula3("Aula 103", 2, 35, true);

    Aulas aula4("Aula 152", 10, 30, true);
    Aulas aula5("Aula 153", 1, 25, true);
    Aulas aula6("Aula 154", 2, 35, true);

    // Agregar las aulas al edificio
    edificio.agregarAula(aula1);
    edificio.agregarAula(aula2);
    edificio.agregarAula(aula3);

    edificio1.agregarAula(aula4);
    edificio1.agregarAula(aula5);
    edificio1.agregarAula(aula6);

    TodosLosEdificios bloque("ANA");
    bloque.agregarEdificioAulas(edificio);
    bloque.agregarEdificioAulas(edificio1);

    imprimirInfoEdificioparqueo(newEdificioParqueo1);
    // newEdificioParqueo2.imprimirEdificioParqueos();
    // bloque.imprimirTotalEdificiosAyP();
    // newEdificioParqueo1.imprimirTotalEdificiosParqueo();
    // newEdificioParqueo2.imprimirEdificioParqueos();
    // Imprimir la información de las aulas en el edificio
    // edificio.imprimirAulasEnEdificio();
    imprimirInfoAula(aula1);
    // imprimirInfoEdificioAula(edificio);
    return 0;
}