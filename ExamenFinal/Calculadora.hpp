#ifndef CALCULADORA_HPP
#define CALCULADORA_HPP

#include <string>

// declaraciones
class Calculadora
{
public:
    // métodos
    int suma(int a, int b);
    int resta(int a, int b);
    int multiplicacion(int a, int b);
    float division(int a, int b);         // si da decimales
    void imprimirOperandos(int a, int b); // Solo imprime los operandos
};

#endif
