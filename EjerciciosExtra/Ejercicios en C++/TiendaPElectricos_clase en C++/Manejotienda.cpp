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
    Producto productos[100];
    int num_productos = 0;

    void AgregadorProductosTienda(Producto nuevo_producto)
    {
        // Metodo agregar un producto a la tienda
        productos[num_productos] = nuevo_producto;
        num_productos++;
    }

    void MostradorProductosTienda()
    {
        // Metodo mostrar producto de la tienda
        cout << "Productos en la tienda:" << endl;
        // Para mostrar todo el contenido del arreglo de objetos tipo Producto
        for (int i = 0; i < num_productos; i++) {
            cout << "Producto " << i+1 << ":" << endl;
            productos[i].mostrarProducto();
            cout << "--------------------------------------" << endl;
            }
    }
};


int main()
{
    cout << "Aquí vamos a desarrollar el ejemplo de clases" << endl;

    // Crear objetos de las clases TelefonoMovil, Tableta y ComputadoraPortatil
    TelefonoMovil celular;
    celular.marca = "Samsung";
    celular.modelo = "Galaxy S21";
    celular.num_serie = 123456;
    celular.precio = 15000.00;
    celular.pantalla_TELE = 6.2;
    celular.procesador_TELE = "Exynos 2100";
    celular.RAM_TELE = 8;
    celular.Almacenamiento_TELE = 128;
    celular.camara_TELE = 64;

    Tableta tablet;
    tablet.marca = "Apple";
    tablet.modelo = "iPad Air";
    tablet.num_serie = 654321;
    tablet.precio = 20000.00;
    tablet.pantalla_TB = 10.9;
    tablet.procesador_TB = "A14 Bionic";
    tablet.RAM_TB = 4;
    tablet.Almacenamiento_TB = 256;
    tablet.camara_TB = 12;

    ComputadoraPortatil laptop;
    laptop.marca = "Dell";
    laptop.modelo = "XPS 13";
    laptop.num_serie = 789012;
    laptop.precio = 35000.00;
    laptop.pantalla_LP = 13.4;
    laptop.procesador_LP = "Intel Core i7-1185G7";
    laptop.RAM_LP = 16;
    laptop.Almacenamiento_LP = 512;
    laptop.Grafica_LP = 2;

    // Crear objeto de la clase Tienda y agregar productos
    Tienda miTienda;
    miTienda.AgregadorProductosTienda(celular);
    miTienda.AgregadorProductosTienda(tablet);
    miTienda.AgregadorProductosTienda(laptop);
    
    // Mostrar los productos de la tienda
    miTienda.MostradorProductosTienda();
    return 0;
}
