/**
 * @file empleados.hpp
 *
 * @brief Este archivo encabezado contiene la declaración de la clase Empleado y de 5 funciones que se utilizan en un programa modular para realizar la búsqueda de empleados en un archivo.
 *
 * Las declaraciones en este archivo son las siguientes:
 * - "class Empleado": Representa a un empleado y sus características.
 * - "validarEntrada": Función para validar la entrada del usuario.
 * - "leerArchivo": Función para leer el archivo y crear objetos Empleado.
 * - "buscarPorDepartamento": Función para buscar empleados por departamento.
 * - "buscarPorSalario": Función para buscar empleados por rango de salario.
 * - "imprimirResultados": Función para imprimir los resultados de la búsqueda.
 *
 * Este archivo encabezado forma parte del proyecto "Empleados" y utiliza la licencia Creative Commons Legal Code CC0 1.0 Universal.
 *
 * @license
 * Creative Commons Legal Code CC0 1.0 Universal
 * Consulta la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author
 * Alex Varela
 *
 * @date
 * 19 de mayo de 2023
 */

#ifndef EMPLEADOS_HPP
#define EMPLEADOS_HPP

#include <iostream>
#include <vector>

/**
 * @brief Clase Empleado que representa a un empleado con su información básica.
 */
class Empleado
{
public:
    std::string nombre;       /**< Nombre del empleado. */
    std::string correo;       /**< Correo electrónico del empleado. */
    int edad;                 /**< Edad del empleado. */
    std::string departamento; /**< Departamento al que pertenece el empleado. */
    double salario;           /**< Salario del empleado. */
};

/**
 * @brief Función para validar la entrada del usuario.
 *
 * @param entrada La cadena de entrada del usuario.
 * @param patron El patrón de validación en formato de expresión regular.
 * @return true si la entrada coincide con el patrón, false en caso contrario.
 */
bool validarEntrada(std::string entrada, std::string patron);

/**
 * @brief Función para leer el archivo y crear objetos Empleado.
 *
 * @param nombreArchivo El nombre del archivo a leer.
 * @return Un vector de objetos Empleado que contiene los empleados leídos del archivo.
 */
std::vector<Empleado> leerArchivo(std::string nombreArchivo);

/**
 * @brief Función para buscar empleados por departamento.
 *
 * @param empleados El vector de empleados en el que buscar.
 * @param departamento El departamento por el que filtrar la búsqueda.
 * @return Un vector de objetos Empleado que contiene los empleados del departamento especificado.
 */
std::vector<Empleado> buscarPorDepartamento(std::vector<Empleado> empleados, std::string departamento);

/**
 * @brief Función para buscar empleados por rango de salario.
 *
 * @param empleados El vector de empleados en el que buscar.
 * @param salarioMinimo El salario mínimo del rango de búsqueda.
 * @param salarioMaximo El salario máximo del rango de búsqueda.
 * @return Un vector de objetos Empleado que contiene los empleados dentro del rango de salario especificado.
 */
std::vector<Empleado> buscarPorSalario(std::vector<Empleado> empleados, double salarioMinimo, double salarioMaximo);

/**
 * @brief Función para imprimir los resultados de la búsqueda.
 *
 * @param resultados El vector de empleados que se imprimirán.
 */
void imprimirResultados(std::vector<Empleado> resultados);

#endif
