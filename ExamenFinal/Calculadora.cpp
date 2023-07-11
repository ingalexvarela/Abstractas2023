#include "Calculadora.hpp"
#include <iostream>
using namespace std;
// implementaciones

// SUMA
int Calculadora::suma(int a, int b)
{
    return a + b;
}
// RESTA
int Calculadora::resta(int a, int b)
{
    return a - b;
}
// MULTIPLICACIÓN
int Calculadora::multiplicacion(int a, int b)
{
    return a * b;
}
// DIVISION
float Calculadora::division(int a, int b)
{
    if (b != 0)
    {
        return static_cast<float>(a) / b;
    }
    else // si es 0 hay bronca
    {
        cout << "Error: No se puede dividir entre cero, función indeterminada." << endl;
        return 0;
    }
}
// impresión
void Calculadora::imprimirOperandos(int a, int b)
{
    cout << "Operandos: " << a << " y " << b << endl; // imprime operandos
    cout << "Realizando operación: " << endl;         // mensaje
}
