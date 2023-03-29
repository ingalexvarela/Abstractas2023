/* programa solicita al usuario que ingrese un número entre 5 y 10 y
 luego le pide al usuario que ingrese una lista de números del tamaño
 especificado. Luego pregunta al usuario si desea ordenar los números
 de menor a mayor o de mayor a menor y muestra los números ordenados
 según la opción ingresada. Finalmente, el programa pregunta al usuario
 si desea continuar ordenando conjuntos de números. */

#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    bool continuar = true;
    while (continuar)
    {
        int num;
        do
        {
            std::cout << "Elija un # entre 5 y 10: ";
            std::cin >> num;
            if (num < 5 || num > 10)
            {
                std::cout << "Error: El # debe estar entre 5 y 10. Inténtalo de nuevo." << std::endl;
            }
        } while (num < 5 || num > 10);

        std::cout << "El # elegido es: " << num << std::endl;

        int cant_num = num;
        std::list<int> numeros;
        int n;
        std::cout << "Ingrese " << cant_num << " #s " << std::endl;
        for (int i = 0; i < cant_num; i++)
        {
            std::cout << "Ingrese el # " << i + 1 << ": ";
            std::cin >> n;
            numeros.push_back(n);
        }

        // Preguntar al usuario si quiere ordenar de menor a mayor o de mayor a menor
        char opcion;
        do
        {
            std::cout << "¿Desea ordenar los #s de menor a mayor o de mayor a menor? (m/M para menor a mayor, n/N para mayor a menor): ";
            std::cin >> opcion;
        } while (opcion != 'm' && opcion != 'M' && opcion != 'n' && opcion != 'N');

        // Ordenar los números según la opción ingresada por el usuario
        if (opcion == 'm' || opcion == 'M')
        {
            numeros.sort();
        }
        else
        {
            numeros.sort(std::greater<int>());
        }

        // Mostrar los números ordenados
        std::cout << "Los #s ordenados son: ";
        auto last = std::prev(numeros.end());
        for (auto it = numeros.begin(); it != numeros.end(); ++it)
        {
            std::cout << *it;
            if (it != last)
            {
                std::cout << ",";
            }
        }
        std::cout << std::endl;

        // Preguntar al usuario si quiere continuar o salir del programa
        char respuesta;
        std::cout << "¿Desea ordenar otro conjunto de #s? (s/n): ";
        std::cin >> respuesta;
        continuar = (respuesta == 's' || respuesta == 'S');
    }

    return 0;
}