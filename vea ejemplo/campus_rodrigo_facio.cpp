#include <iostream>
#include <vector>

// Clase que representa el objeto que deseas almacenar en un vector
class Objeto
{
public:
    Objeto(int valor) : valor_(valor) {}

    void imprimir() const
    {
        std::cout << "Valor del objeto: " << valor_ << std::endl;
    }

private:
    int valor_;
};

// Clase que almacena objetos de la clase Objeto en un vector
class ClaseQueAlmacenaObjetos
{
public:
    // Método para agregar un objeto al vector
    void agregarObjeto(const Objeto &objeto)
    {
        objetos_.push_back(objeto);
    }

    // Método para acceder a la información de los objetos almacenados en el vector
    void imprimirObjetos()
    {
        std::cout << "Informacion de los objetos almacenados:" << std::endl;
        for (const auto &objeto : objetos_)
        {
            objeto.imprimir();
        }
    }

private:
    std::vector<Objeto> objetos_;
};

int main()
{
    // Crear un objeto de la clase Objeto
    Objeto objeto1(1);

    // Crear otro objeto de la clase Objeto
    Objeto objeto2(2);

    // Crear un objeto de la clase ClaseQueAlmacenaObjetos
    ClaseQueAlmacenaObjetos claseAlmacenaObjetos;

    // Agregar los objetos al vector en la ClaseQueAlmacenaObjetos
    claseAlmacenaObjetos.agregarObjeto(objeto1);
    claseAlmacenaObjetos.agregarObjeto(objeto2);

    // Acceder a la información de los objetos almacenados en el vector
    claseAlmacenaObjetos.imprimirObjetos();

    return 0;
}
