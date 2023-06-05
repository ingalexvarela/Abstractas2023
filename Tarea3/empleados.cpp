/**
 * @file empleados.cpp
 *
 * @brief Este archivo contiene la implementación del codigo de las 5 funciones para el programa modular.
 *
 * Las funciones implementadas en este archivo son las siguientes:
 * - "validarEntrada": Función para validar la entrada del usuario.
 * - "leerArchivo": Función para leer el archivo y crear objetos Empleado.
 * - "buscarPorDepartamento": Función para buscar empleados por departamento.
 * - "buscarPorSalario": Función para buscar empleados por rango de salario.
 * - "imprimirResultados": Función para imprimir los resultados de la búsqueda.
 *
 * Se define el comportamiento de las 5 funciones para un programa modular que leé un archivo y almacena la información de cada empleado
 * en un objeto de una clase Empleado, con  los siguientes atributos: nombre, correo, edad, departamento y salario. Además como programa
 * modular permite al usuario realizar búsquedas de empleados por departamento o por rango de salario usando expresiones regulares para validar,
 * se desarrolla una función para buscar por departamento, otra para buscar por salario y una para validar entrada y así buscar en el archivo
 * únicamente los empleados que cumplan con los criterios de búsqueda, por último se desarrolla la última función para imprimir por pantalla
 * la información de los empleados que cumplan con los criterios de búsqueda.
 *
 * Este archivo fuente forma parte del proyecto "Empleados" que utiliza la licencia Creative Commons Legal Code CC0 1.0 Universal.
 *
 * @license
 * Creative Commons Legal Code CC0 1.0 Universal
 * Consulta la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author Alex Varela
 * @date 19 de abril de 2023
 */

#include "empleados.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

/**
 * @brief Valida la entrada del usuario.
 *
 * Esta función valida la entrada del usuario utilizando una expresión regular.
 *
 * @param entrada La cadena de entrada del usuario.
 * @param patron El patrón de validación en formato de expresión regular.
 * @return true si la entrada coincide con el patrón, false en caso contrario.
 */
bool validarEntrada(std::string entrada, std::string patron)
{
    regex exp(patron);                /**< Objeto regex para la expresión regular */
    return regex_match(entrada, exp); /**< Devuelve true si la cadena de entrada coincide con el patrón */
}

/**
 * @brief Lee un archivo y crea objetos Empleado.
 *
 * Esta función lee un archivo de texto que contiene datos de empleados y crea objetos Empleado
 * a partir de cada línea del archivo. Luego, los objetos Empleado se almacenan en un vector y se devuelve.
 *
 * @param nombreArchivo El nombre del archivo a leer.
 * @return Un vector de objetos Empleado creados a partir de los datos del archivo.
 */
std::vector<Empleado> leerArchivo(std::string nombreArchivo)
{
    std::vector<Empleado> empleados;                                       /**< Vector para almacenar los objetos Empleado */
    std::ifstream archivo(nombreArchivo, std::ios::in | std::ios::binary); /**< Flujo de archivo para leer el archivo */
    if (!archivo.is_open())
    {
        std::cerr << "No se pudo abrir el archivo" << std::endl; /**< Mensaje de error si no se pudo abrir el archivo */
        return empleados;                                        // Devuelve un vector vacío y finaliza la función sin generar un error en el Makefile
    }

    std::string linea; /**< Variable para almacenar cada línea del archivo */
    while (std::getline(archivo, linea))
    {
        Empleado empleado; /**< Objeto Empleado para almacenar los datos de cada empleado */
        size_t pos = 0;    /**< Posición actual en la línea */
        std::string token; /**< Variable para almacenar cada campo de la línea */
        int contador = 0;  /**< Contador para identificar el campo actual */
        while ((pos = linea.find(",")) != std::string::npos)
        {
            token = linea.substr(0, pos);
            switch (contador)
            {
            case 0:
                empleado.nombre = token; /**< Almacena el nombre del empleado en el objeto Empleado */
                break;
            case 1:
                empleado.correo = token; /**< Almacena el correo del empleado en el objeto Empleado */
                break;
            case 2:
                empleado.edad = std::stoi(token); /**< Almacena la edad del empleado en el objeto Empleado */
                break;
            case 3:
                empleado.departamento = token; /**< Almacena el departamento del empleado en el objeto Empleado */
                break;
            }
            linea.erase(0, pos + 1); /**< Elimina el campo procesado de la línea */
            contador++;              /**< Incrementa el contador de campo */
        }

        std::string salarioToken = linea.substr(linea.rfind(",") + 1); /**< Obtiene el campo de salario de la línea */
        std::stringstream salarioStream(salarioToken);                 /**< Crea un flujo de cadena para convertir el salario a double */
        double salario;
        salarioStream >> salario;   /**< Convierte el salario a double */
        empleado.salario = salario; /**< Almacena el salario del empleado en el objeto Empleado */

        empleados.push_back(empleado); /**< Agrega el objeto Empleado al vector de empleados */
    }
    archivo.close();  /**< Cierra el archivo después de leerlo */
    return empleados; /**< Devuelve el vector de empleados */
}

/**
 * @brief Busca empleados por departamento.
 *
 * Esta función busca empleados en un vector dado que pertenecen a un departamento específico.
 *
 * @param empleados El vector de empleados donde se realizará la búsqueda.
 * @param departamento El nombre del departamento para buscar empleados.
 * @return Un vector que contiene los empleados encontrados en el departamento especificado.
 */
std::vector<Empleado> buscarPorDepartamento(std::vector<Empleado> empleados, std::string departamento)
{
    std::vector<Empleado> resultados; /**< Vector para almacenar los empleados encontrados */
    for (Empleado empleado : empleados)
    {
        if (empleado.departamento == departamento)
        {
            resultados.push_back(empleado); /**< Agrega el empleado al vector de resultados */
        }
    }
    return resultados; /**< Devuelve el vector de empleados encontrados */
}

/**
 * @brief Busca empleados por rango de salario.
 *
 * Esta función busca empleados en un vector dado cuyo salario se encuentra dentro de un rango especificado.
 *
 * @param empleados El vector de empleados donde se realizará la búsqueda.
 * @param salarioMinimo El salario mínimo del rango.
 * @param salarioMaximo El salario máximo del rango.
 * @return Un vector que contiene los empleados cuyo salario se encuentra dentro del rango especificado.
 */
std::vector<Empleado> buscarPorSalario(std::vector<Empleado> empleados, double salarioMinimo, double salarioMaximo)
{
    std::vector<Empleado> resultados; /**< Vector para almacenar los empleados encontrados */
    for (Empleado empleado : empleados)
    {
        if (empleado.salario >= salarioMinimo && empleado.salario <= salarioMaximo)
        {
            resultados.push_back(empleado); /**< Agrega el empleado al vector de resultados */
        }
    }
    return resultados; /**< Devuelve el vector de empleados encontrados */
}

/**
 * @brief Imprime los resultados de la búsqueda de empleados.
 *
 * Esta función imprime los resultados de la búsqueda de empleados en un formato tabular.
 * Si no se encontraron resultados, muestra un mensaje indicando que no se encontraron resultados.
 *
 * @param resultados El vector de empleados encontrados.
 */
void imprimirResultados(std::vector<Empleado> resultados)
{
    if (resultados.empty())
    {
        cout << "No se encontraron resultados" << endl; /**< Imprime un mensaje indicando que no se encontraron resultados */
    }
    else
    {
        // Encontrar el ancho máximo del campo "Departamento"
        size_t maxAnchoDepartamento = 0;
        for (const Empleado &empleado : resultados)
        {
            maxAnchoDepartamento = std::max(maxAnchoDepartamento, empleado.departamento.size());
        }

        cout << "\t"
             << "Nombre y apellido\tCorreo electrónico\t\tEdad\tDepartamento\t\t\tSalario" << endl; /**< Imprime encabezados de la tabla */

        cout << "\t"
             << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl; /**< Imprime línea separadora */

        for (const Empleado &empleado : resultados)
        {
            cout << "\t" << empleado.nombre << "\t\t" << empleado.correo << "\t\t" << empleado.edad << "\t"
                 << std::setw(maxAnchoDepartamento) << std::left << empleado.departamento << "\t\t\t" << empleado.salario << endl; /**< Imprime información del empleado en cada fila con alineación del salario */
        }

        cout << "\t"
             << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl; /**< Imprime línea separadora */
    }
}