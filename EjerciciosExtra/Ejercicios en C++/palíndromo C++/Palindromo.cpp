#include <iostream>
#include <string>

int main()
{
    std::string palabra;
    std::cout << "Introduce una palabra menor a 15 caracteres: ";
    std::cin >> palabra;

    // Verificamos si la palabra ingresada tiene más de 15 caracteres
    if (palabra.length() > 15)
    {
        std::cout << "La palabra ingresada no cumple con ser menor a 15 caracteres." << std::endl;
    }
    else
    { // Acá vamos a implementar el palindromo
        std::cout << "La palabra ingresada es: " << palabra << std::endl;
        int longitud = palabra.length();
        bool es_palindromo = false;
        std::cout << "La longitud de la palabra es: " << longitud << std::endl;
        std::string cadena = ""; // Declaración de una cadena vacía

        for (int i = 0; i < longitud / 2; i++)
        {
            if (palabra[i] == palabra[longitud - i - 1])
            {
                es_palindromo = true;
                cadena += palabra[i];
                std::cout << "Estudiando la palabra:" << palabra << " Analizando:" << cadena << std::endl;
            }
            else
            {
                std::cout << "La palabra ingresada no es palindromo" << std::endl;
                es_palindromo = false;
                break;
            }
        }
        if (es_palindromo == true)
        {
            std::cout << "La palabra ingresada es palindromo y la palabra era :" << palabra << std::endl;
        }
        return 0;
    }
}