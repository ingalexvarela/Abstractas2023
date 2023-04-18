/**
 * @file ejemplo.cpp
 *
 * @brief Descripción breve del contenido de ejemplo.cpp
 *
 * Descripción detallada del contenido del archivo fuente
 *
 * Este archivo fuente forma parte del proyecto "" que utiliza la licencia Creative Commons Legal Code CC0 1.0 Universal.
 *
 * @license
 * Creative Commons Legal Code CC0 1.0 Universal
 * Consulta la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author Alex Varela
 * @date 17 de abril de 2023
 */

#include <iostream>
#include "division.hpp"

using namespace std;

Student::Student(double m)
{
    marks = m;
}

void calculateAverage(Student s1, Student s2)
{
    double average = (s1.marks + s2.marks) / 2;
    cout << "Average Marks = " << average << endl;
}