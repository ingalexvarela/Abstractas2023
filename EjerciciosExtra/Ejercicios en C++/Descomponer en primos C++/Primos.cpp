/* función que muestre en pantalla la descomposición de un número en números primos. */

#include <iostream>

void descomponerEnPrimos(int num)
{
    std::cout << "Se descompuso el #" << num << " en primos como: ";
    // Descomponer el número en factores primos
    for (int i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            std::cout << i << " ";
            num /= i;
        }
    }
}

int main()
{
    int num;
    std::cout << "Ingrese un # entero positivo: ";
    std::cin >> num;
    descomponerEnPrimos(num);

    return 0;
}
