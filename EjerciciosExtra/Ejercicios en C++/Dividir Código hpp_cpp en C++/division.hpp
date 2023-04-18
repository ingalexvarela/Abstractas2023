/**
 * @file division.hpp
 *
 * @brief Descripción breve del contenido de division.hpp
 *
 * Descripción detallada del contenido del archivo encabezado
 *
 * Este archivo encabezado que forma parte del proyecto "" que utiliza la licencia Creative Commons Legal Code CC0 1.0 Universal.
 *
 * @license
 * Creative Commons Legal Code CC0 1.0 Universal
 * Consulta la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author Alex Varela
 * @date 17 de abril de 2023
 */

#ifndef DIVISION_H
#define DIVISION_H

class Student
{
public:
    double marks;

    Student(double m);
};

void calculateAverage(Student s1, Student s2);

#endif