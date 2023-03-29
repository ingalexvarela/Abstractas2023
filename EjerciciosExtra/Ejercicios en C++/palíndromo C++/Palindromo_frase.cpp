#include <iostream>
#include <string>
#include <cctype> // Incluimos la librería para usar std::tolower()

int main()
{
    std::string frase;
    std::cout << "Introduce una frase con un maximo de 15 palabras para verificar si es un palindromo: ";
    std::getline(std::cin, frase);
    std::string frase_original;
    // Verificamos si la frase ingresada tiene más de 15 palabras
    int palabras = 0;
    for (char c : frase)
    {
        if (c == ' ')
        {
            palabras++;
        }
    }
    palabras++; // Sumamos la última palabra
    if (palabras > 15)
    {
        std::cout << "La frase ingresada tiene mas de 15 palabras." << std::endl;
        return 0;
    }
    else
    {
        // Convertimos todas las letras de la frase a minúsculas
        frase_original = frase;
        for (char &c : frase) // Nota el uso de referencia (símbolo &)
        {
            c = std::tolower(c);
        }

        // Acá vamos a implementar el palíndromo
        std::cout << "La frase ingresada es: " << frase_original << std::endl;
        int longitud = frase.length();
        bool es_palindromo = true;
        std::cout << "La longitud de la frase es: " << longitud << std::endl;
        std::string cadena = ""; // Declaración de una cadena vacía

        for (int i = 0; i < longitud; i++)
        {
            if (frase[i] != ' ')
            {
                cadena += frase[i];
            }
        }

        longitud = cadena.length();
        for (int i = 0; i < longitud / 2; i++)
        {
            if (cadena[i] != cadena[longitud - i - 1])
            {
                std::cout << "La frase ingresada no es un palindromo." << std::endl;
                es_palindromo = false;
                break;
            }
        }
        if (es_palindromo)
        {
            std::cout << "La frase ingresada es un palindromo." << std::endl;
        }
        std::cout << "La cadena original y modificada es: " << frase << std::endl;
        return 0;
    }
}
