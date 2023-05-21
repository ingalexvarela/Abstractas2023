/**
 * @file main.cpp
 *
 * @brief Implementación de la función principal que proporciona una interfaz interactiva para buscar y mostrar información de los empleados.
 * El programa permite realizar consultas basadas en diferentes criterios de búsqueda, como departamento y rango de salario.
 *
 * El flujo del programa es el siguiente:
 * 1. Lectura de un archivo y almacenamiento de los datos de los empleados en un vector de objetos de la clase Empleado.
 * 2. Mostrar un menú de opciones para consultar información sobre los empleados:
 *    - Opción 1: Búsqueda por departamento.
 *        - Solicitar al usuario el nombre del departamento.
 *        - Validar la entrada del usuario.
 *        - Mostrar la información de los empleados del departamento.
 *        - Mostrar un submenú de opciones.
 *    - Opción 2: Búsqueda por rango de salario.
 *        - Solicitar al usuario el salario mínimo y máximo.
 *        - Validar la entrada del usuario.
 *        - Realizar la búsqueda de empleados dentro del rango de salario.
 *        - Mostrar la información de los empleados encontrados.
 *        - Mostrar un submenú de opciones.
 *    - Opción 4: Realizar una nueva consulta.
 *        - Volver al menú principal.
 *    - Opción 0: Salir del programa.
 *        - Terminar la ejecución del programa.
 * 3. El programa continúa en un bucle hasta que el usuario seleccione la opción de salida (0).
 *
 * Este archivo fuente forma parte del proyecto "Empleados" y se distribuye bajo la licencia Creative Commons Legal Code CC0 1.0 Universal.
 * Consulte la licencia para obtener más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author Alex Varela
 * @date 19 de mayo de 2023
 *
 */
#include "empleados.hpp"

#include <regex>
#include <limits>
#include <iostream>

using namespace std;

/**
 * @brief Función principal del programa.
 *
 * La función principal del programa realiza consultas de información de empleados mediante un menú de opciones.
 * Permite buscar empleados por departamento o por rango de salario.
 * El programa lee los datos de empleados desde un archivo y los almacena en un vector de empleados.
 * Utiliza otras funciones como `validarEntrada`, `buscarPorDepartamento`, `buscarPorSalario` e `imprimirResultados` para realizar las operaciones.
 *
 * @return El valor de retorno de la función main.
 */

int main()
{
    std::vector<Empleado> empleados = leerArchivo("empleados.csv");
    int opcion;
    bool opcionValida = false; // Variable para verificar si la opción ingresada es válida
    do
    {
        std::cout << "" << std::endl;
        std::cout << "\t\t\tMENU DE CONSULTA DE INFORMACIÓN DE EMPLEADOS" << std::endl;
        std::cout << "Búsqueda de empleados:\t 1. Por departamento\t2. Por rango de salario\t\t 0. Salir" << std::endl;
        std::cout << "Ingrese su opción: ";

        std::string input;
        std::getline(std::cin, input);

        if (input.empty())
        {
            std::cout << "No se ingresó ninguna opción. Volviendo al menú..." << std::endl;
            continue;
        }

        try
        {
            opcion = std::stoi(input);

            if (opcion != 1 && opcion != 2 && opcion != 0)
            {
                throw std::runtime_error("Opción inválida. Por favor, ingrese una opción válida.");
            }

            if (opcion == 1)
            {
                bool rangoValido1 = false;
                std::string departamento;
                do
                {
                    std::cout << "Ingrese el nombre del departamento: ";
                    std::getline(std::cin, departamento);

                    if (departamento.empty())
                    {
                        std::cout << "No se ingresó ningún departamento. Inserte nuevamente el nombre del departamento..." << std::endl;
                        continue;
                    }

                    if (!validarEntrada(departamento, "^[a-zA-Z0-9 ]+$"))
                    {
                        throw std::runtime_error("Entrada inválida.");
                    }

                    else
                    {
                        rangoValido1 = true;
                    }
                } while (!rangoValido1);
                std::cout << "" << std::endl;
                std::cout << "\tLa información de los empleados del departamento de " << departamento << " es:" << std::endl;

                std::vector<Empleado> resultados = buscarPorDepartamento(empleados, departamento);
                imprimirResultados(resultados);

                std::cout << "\t\t\tMENU DE SALIDA" << std::endl;
                std::cout << "Desea:\t4. Realizar nueva consulta\t0. Salir" << std::endl;
                std::cout << "Ingrese su opción: ";
                std::getline(std::cin, input);

                opcion = std::stoi(input);

                if (opcion != 4 && opcion != 0)
                {
                    throw std::runtime_error("");
                }
            }
            else if (opcion == 2)
            {
                double salarioMinimo, salarioMaximo;
                bool rangoValido = false;
                std::string salarioMinimoStr, salarioMaximoStr;

                do
                {
                    std::cout << "Ingrese el rango de salario mínimo: ";
                    std::getline(std::cin, salarioMinimoStr);

                    if (salarioMinimoStr.empty())
                    {
                        std::cout << "No se ingresó ningún valor. Inserte nuevamente el salario mínimo..." << std::endl;
                        continue;
                    }

                    std::cout << "Ingrese el rango de salario máximo: ";
                    std::getline(std::cin, salarioMaximoStr);

                    if (salarioMaximoStr.empty())
                    {
                        std::cout << "No se ingresó ningún valor. Inserte nuevamente el salario mínimo..." << std::endl;
                        continue;
                    }

                    bool entradaValida = validarEntrada(salarioMinimoStr, R"(^\d+(,\d+)?(\.\d+)?$)") &&
                                         validarEntrada(salarioMaximoStr, R"(^\d+(,\d+)?(\.\d+)?$)");

                    if (!entradaValida)
                    {
                        std::cout << "La entrada no es válida. Por favor, ingrese nuevamente los valores." << std::endl;
                        continue;
                    }

                    salarioMinimo = std::stod(salarioMinimoStr);
                    salarioMaximo = std::stod(salarioMaximoStr);

                    if (salarioMinimo > salarioMaximo)
                    {
                        std::cout << "El rango de salario mínimo no puede ser mayor que el máximo. Por favor, intente nuevamente." << std::endl;
                    }
                    else
                    {
                        rangoValido = true;
                    }
                } while (!rangoValido);

                std::cout << "" << std::endl;
                std::cout << "\tLa información de los empleados dentro del rango de salario ₡" << salarioMinimo << " - ₡" << salarioMaximo << " es:" << std::endl;

                std::vector<Empleado> resultados = buscarPorSalario(empleados, salarioMinimo, salarioMaximo);
                imprimirResultados(resultados);

                std::cout << "\t\t\tMENU DE SALIDA" << std::endl;
                std::cout << "Desea:\t4. Realizar nueva consulta.\t0. Salir del programa." << std::endl;
                std::cout << "Ingrese su opción: ";
                std::getline(std::cin, input);

                opcion = std::stoi(input);

                if (opcion != 4 && opcion != 0)
                {
                    throw std::runtime_error("");
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error, se ingreso un caracter no númerico o valido entre las opciones" << std::endl; // << e.what()
            std::cout << "Volvemos al menu principal..... " << std::endl;
            continue;
        }
    } while (opcion != 0);

    std::cout << "Programa finalizado." << std::endl;

    return 0;
}
