// versión inicial se compila: g++ ./empleados.cpp -o empleado.exe
// se ejecuta: .\empleado.exe

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

// Definición de la clase Empleado
class Empleado
{
public:
    string nombre;
    string correo;
    int edad;
    string departamento;
    double salario;
};

// Función para validar la entrada del usuario
bool validarEntrada(string entrada, string patron)
{
    regex exp(patron);
    return regex_match(entrada, exp);
}

// Función para leer el archivo y crear objetos Empleado
std::vector<Empleado> leerArchivo(std::string nombreArchivo)
{
    std::vector<Empleado> empleados;
    std::ifstream archivo(nombreArchivo, std::ios::in | std::ios::binary);
    if (!archivo.is_open())
    {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string linea;
    while (std::getline(archivo, linea))
    {
        Empleado empleado;
        size_t pos = 0;
        std::string token;
        int contador = 0;
        while ((pos = linea.find(",")) != std::string::npos)
        {
            token = linea.substr(0, pos);
            switch (contador)
            {
            case 0:
                empleado.nombre = token;
                break;
            case 1:
                empleado.correo = token;
                break;
            case 2:
                empleado.edad = std::stoi(token);
                break;
            case 3:
                empleado.departamento = token;
                break;
            }
            linea.erase(0, pos + 1);
            contador++;
        }

        std::string salarioToken = linea.substr(linea.rfind(",") + 1);
        std::stringstream salarioStream(salarioToken);
        double salario;
        salarioStream >> salario;
        empleado.salario = salario;

        empleados.push_back(empleado);
    }

    /*
    cout << "Valores de salario leídos:" << endl;
    for (auto empleado : empleados)
    {
        cout << empleado.salario << endl;
    }
    */

    archivo.close();
    return empleados;
}

// Función para buscar empleados por departamento
vector<Empleado> buscarPorDepartamento(vector<Empleado> empleados, string departamento)
{
    vector<Empleado> resultados;
    for (Empleado empleado : empleados)
    {
        if (empleado.departamento == departamento)
        {
            resultados.push_back(empleado);
        }
    }
    return resultados;
}

// Función para buscar empleados por rango de salario
vector<Empleado> buscarPorSalario(vector<Empleado> empleados, double salarioMinimo, double salarioMaximo)
{
    vector<Empleado> resultados;
    for (Empleado empleado : empleados)
    {
        if (empleado.salario >= salarioMinimo && empleado.salario <= salarioMaximo)
        {
            resultados.push_back(empleado);
        }
    }
    return resultados;
}

// Función para imprimir los resultados de la búsqueda
void imprimirResultados(vector<Empleado> resultados)
{
    if (resultados.empty())
    {
        cout << "No se encontraron resultados" << endl;
    }
    else
    {
        cout << "\t"
             << "Nombre y apellido\tCorreo electrónico\t\tEdad\tDepartamento\tSalario" << endl;
        cout << "\t"
             << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
        for (Empleado empleado : resultados)
        {
            cout << "\t" << empleado.nombre << "\t\t" << empleado.correo << "\t\t" << empleado.edad << "\t"
                 << empleado.departamento << "\t" << empleado.salario << endl;
        }
        cout << "\t"
             << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
    }
}

int main()
{
    vector<Empleado> empleados = leerArchivo("empleados.csv");
    string opcion;
    do
    {
        cout << "\t\t\t"
             << "MENU DE CONSULTA DE INFORMACIÓN DE EMPLEADOS" << endl;
        cout << "Búsqueda de empleados: "
             << "\t"
             << "1. Por departamento"
             << "\t"
             << "2. Por rango de salario"
             << "\t\t"
             << "0. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
        if (opcion == "1")
        {
            string departamento;
            cout << "Ingrese el nombre del departamento: ";
            cin.ignore(); // Ignorar el salto de línea anterior
            getline(cin, departamento);
            if (!validarEntrada(departamento, "^[a-zA-Z0-9 ]+$"))
            {
                cerr << "Entrada inválida" << endl;
                continue;
            }
            cout << "" << endl;
            cout << "\t"
                 << "La información de los empleados del departamento de " << departamento << ", es:" << endl;
            vector<Empleado> resultados = buscarPorDepartamento(empleados, departamento);
            imprimirResultados(resultados);
            cout << "\t\t\t"
                 << "MENU DE SALIDA" << endl;
            cout << "Desea: "
                 << "\t"
                 << "4. Realizar nueva consulta"
                 << "\t"
                 << "0. Salir" << endl;
            cout << "Ingrese su opción: ";
            cin >> opcion;
        }
        else if (opcion == "2")
        {
            double salarioMinimo, salarioMaximo;
            bool rangoValido = false;

            do
            {
                cout << "Ingrese el salario mínimo: ";
                string salarioMinimoStr;
                cin >> salarioMinimoStr;
                cout << "Ingrese el salario máximo: ";
                string salarioMaximoStr;
                cin >> salarioMaximoStr;

                // Validar la entrada del usuario
                bool entradaValida = validarEntrada(salarioMinimoStr, R"(^\d+(,\d+)?(\.\d+)?$)") && validarEntrada(salarioMaximoStr, R"(^\d+(,\d+)?(\.\d+)?$)");

                try
                {
                    if (entradaValida)
                    {
                        // Reemplazar la coma por el punto decimal
                        replace(salarioMinimoStr.begin(), salarioMinimoStr.end(), ',', '.');
                        replace(salarioMaximoStr.begin(), salarioMaximoStr.end(), ',', '.');

                        salarioMinimo = stod(salarioMinimoStr);
                        salarioMaximo = stod(salarioMaximoStr);
                        if (salarioMinimo > salarioMaximo)
                        {
                            cerr << "El salario mínimo debe ser menor o igual que el salario máximo" << endl;
                            cerr << "Por favor, inserte nuevamente el rango de salarios:" << endl;
                        }
                        else
                        {
                            rangoValido = true;
                        }
                    }
                    else
                    {
                        cerr << "Entrada inválida, deben ser salarios decimales con separador (.) o bien (,)" << endl;
                        cerr << "Por favor, inserte nuevamente el rango de salarios:" << endl;
                    }
                }
                catch (...)
                {
                    cerr << "Conversión de cadena a double falló debido a una entrada incorrecta por parte del usuario" << endl;
                    cerr << "Entrada inválida, deben ser salarios decimales con separador (.) o bien (,)" << endl;
                    cerr << "Por favor, inserte nuevamente el rango de salarios:" << endl;
                }
            } while (!rangoValido);

            vector<Empleado> resultados = buscarPorSalario(empleados, salarioMinimo, salarioMaximo);

            imprimirResultados(resultados);

            cout << "\t\t\t"
                 << "MENU DE SALIDA" << endl;
            cout << "Desea: "
                 << "\t"
                 << "4. Realizar nueva consulta"
                 << "\t"
                 << "0. Salir" << endl;
            cout << "Ingrese su opción: ";
            cin >> opcion;
        }
        else if (opcion == "4")
        {
            cerr << "Volviendo al menu ..... " << endl;
            cerr << "" << endl;
            continue;
        }

    } while (opcion != "0");
    return 0;
}
