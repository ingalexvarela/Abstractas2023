#ifndef EMPLEADOS_HPP
#define EMPLEADOS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <sstream>

// Definición de la clase Empleado
class Empleado
{
public:
    std::string nombre;
    std::string correo;
    int edad;
    std::string departamento;
    double salario;
};

// Función para validar la entrada del usuario
bool validarEntrada(std::string entrada, std::string patron);

// Función para leer el archivo y crear objetos Empleado
std::vector<Empleado> leerArchivo(std::string nombreArchivo);

// Función para buscar empleados por departamento
std::vector<Empleado> buscarPorDepartamento(std::vector<Empleado> empleados, std::string departamento);

// Función para buscar empleados por rango de salario
std::vector<Empleado> buscarPorSalario(std::vector<Empleado> empleados, double salarioMinimo, double salarioMaximo);

// Función para imprimir los resultados de la búsqueda
void imprimirResultados(std::vector<Empleado> resultados);

#endif // EMPLEADOS_HPP
