#include "Calculadora.hpp"
#include <iostream>

using namespace std;

int main()
{
    Calculadora calculadora; // se instancia
    int a = 10;
    int b = 2;

    // Suma
    int resultado_suma = calculadora.suma(a, b);
    calculadora.imprimirOperandos(a, b);
    cout << "Suma: " << resultado_suma << endl; // Resultado: 12

    // Resta
    int resultado_resta = calculadora.resta(a, b);
    cout << "Resta: " << resultado_resta << endl; // Resultado: 8

    // Multiplicación
    int resultado_multiplicacion = calculadora.multiplicacion(a, b);
    cout << "Multiplicación: " << resultado_multiplicacion << endl; // Resultado: 20

    // División
    float resultado_division = calculadora.division(a, b);
    cout << "División: " << resultado_division << endl; // Resultado: 5

    return 0;
}
