/*
Se desarrolla un programa que maneje una tienda de productos electrónicos que cuenta con tres tipos de productos:
- Teléfonos móviles
- Tabletas
- Computadoras

El programa permitirá al usuario ingresar nuevos productos
*/

#include <iostream> // Para entrada y salida por consola
#include <string>   // Para manipular cadenas de texto
#include <vector>   // Para manejar arreglos dinámicos
#include <cmath>    // Para funciones matemáticas
#include <fstream>  // Para leer y escribir archivos

using namespace std;

class Producto
{
public:
    string marca;
    string modelo;
    int num_serie;
    float precio;

    void mostrarProducto()
    {
        // mostrar datos del producto
    }
};

class TelefonoMovil : public Producto
{
public:
    void mostrarcelular()
    {
        // mostrar datos especificos del producto
    }
};

class Tableta : public Producto
{
public:
    void mostrarTableta()
    {
        // mostrar datos especificos del producto
    }
};

class ComputadoraPortatil : public Producto
{
public:
    void mostrarlaptop()
    {
        // mostrar datos especificos del producto
    }
};

class Tienda
{
public:
    // Arreglo de objetos tipo producto
    void AgregadorProductosTienda()
    {
        // Agregar un producto a la tienda
    }

    void MostradorProductosTienda()
    {
        // mostrar producto de la tienda
    }
};

int main()
{
    cout << "Aquí vamos a desarrollar el ejemplo de clases" << endl;

    // Código del programa
    return 0;
}
