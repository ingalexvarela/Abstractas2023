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
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Número de serie: " << num_serie << endl;
        cout << "Precio: $" << precio << endl;
    }
};

class TelefonoMovil : public Producto
{
public:
    float pantalla_TELE;
    string procesador_TELE;
    int RAM_TELE;
    int Almacenamiento_TELE;
    float camara_TELE;

    void mostrarcelular()
    {
        // Mostrar datos del producto base usando el método de la clase padre
        mostrarProducto();
        cout << "--------------------------------------" << endl;
        // mostrar datos especificos del celular
        cout << "pantalla: " << pantalla_TELE << " pulgadas" << endl;
        cout << "procesador: " << procesador_TELE << endl;
        cout << "RAM: " << RAM_TELE << " GB" << endl;
        cout << "Almacenamiento: " << Almacenamiento_TELE << " GB" << endl;
        cout << "Camara: " << camara_TELE << " MP" << endl;
    }
};

class Tableta : public Producto
{
public:
    float pantalla_TB;
    string procesador_TB;
    int RAM_TB;
    int Almacenamiento_TB;
    float camara_TB;

    void mostrarTableta()
    {
        // Mostrar datos del producto base usando el método de la clase padre
        mostrarProducto();
        cout << "--------------------------------------" << endl;
        // Mostrar datos específicos de la tableta
        cout << "Pantalla: " << pantalla_TB << " pulgadas" << endl;
        cout << "Procesador: " << procesador_TB << endl;
        cout << "RAM: " << RAM_TB << " GB" << endl;
        cout << "Almacenamiento: " << Almacenamiento_TB << " GB" << endl;
        cout << "Cámara: " << camara_TB << " MP" << endl;
    }
};

class ComputadoraPortatil : public Producto
{
public:
    float pantalla_LP;
    string procesador_LP;
    int RAM_LP;
    int Almacenamiento_LP;
    float Grafica_LP;

    void mostrarlaptop()
    {
        // Mostrar datos del producto base usando el método de la clase padre
        mostrarProducto();
        cout << "--------------------------------------" << endl;
        // Mostrar datos específicos de la computadora portátil
        cout << "Pantalla: " << pantalla_LP << " pulgadas" << endl;
        cout << "Procesador: " << procesador_LP << endl;
        cout << "RAM: " << RAM_LP << " GB" << endl;
        cout << "Almacenamiento: " << Almacenamiento_LP << " GB" << endl;
        cout << "Tarjeta gráfica: " << Grafica_LP << endl;
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
