/**
 * @file main.cpp
 *
 * @brief Acá se crean las instancias (objetos) y se asigna por gerarquia a otras clases que los recibe como vectores
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
    // Crear instancias de aulas
    Aula aula1("A1", 30, true, 6);
    Aula aula2("B1", 40, false, 5);
    Aula aula3("C1", 25, true, 8);

    // Crear instancias de edificios de aulas
    EdificioAulas edificioAulas1("Ingeniería eléctrica", true, true, 6);
    edificioAulas1.agregarAula(aula1);
    edificioAulas1.agregarAula(aula2);

    EdificioAulas edificioAulas2("Edificio Aulas 2", true, true, 7);
    edificioAulas2.agregarAula(aula3);

    // Crear instancias de edificios de parqueo
    EdificioParqueo edificioParqueo1("Parqueo sociales", 100, true, 12);
    EdificioParqueo edificioParqueo2("Parqueo ingenieria", 100, false, 25);

    // Crear instancias de facultades
    Facultad facultad1("Facultad de Ciencias");
    facultad1.agregarEdificioAulas(edificioAulas1);
    facultad1.agregarEdificioParqueo(edificioParqueo1);

    Facultad facultad2("Facultad de Ingeniería");
    facultad2.agregarEdificioAulas(edificioAulas2);
    facultad2.agregarEdificioParqueo(edificioParqueo2);

    Facultad facultad3("Facultad de Ingeniería");
    facultad3.agregarEdificioAulas(edificioAulas2);
    facultad3.agregarEdificioParqueo(edificioParqueo2);

    // Crear instancia de finca
    Finca finca("Universidad XYZ", true);
    finca.agregarFacultad(facultad1);
    finca.agregarFacultad(facultad2);

    // Crear instancia de finca
    Finca finca1("Universidad UCR", false);
    finca1.agregarFacultad(facultad3);

    // Crear instancia de campus
    Campus campus("Campus Principal");
    campus.agregarFinca(finca);
    campus.agregarFinca(finca1);

    // Imprimir información del campus y sus fincas llamando funcion externa
    imprimirInfoCampus(campus);
    return 0;
}