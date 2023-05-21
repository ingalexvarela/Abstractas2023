#include "empleados.hpp"

using namespace std;

bool validarEntrada(string entrada, string patron)
{
    regex exp(patron);
    return regex_match(entrada, exp);
}

vector<Empleado> leerArchivo(string nombreArchivo)
{
    vector<Empleado> empleados;
    ifstream archivo(nombreArchivo, ios::in | ios::binary);
    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string linea;
    while (getline(archivo, linea))
    {
        Empleado empleado;
        size_t pos = 0;
        string token;
        int contador = 0;
        while ((pos = linea.find(",")) != string::npos)
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
                empleado.edad = stoi(token);
                break;
            case 3:
                empleado.departamento = token;
                break;
            }
            linea.erase(0, pos + 1);
            contador++;
        }

        string salarioToken = linea.substr(linea.rfind(",") + 1);
        stringstream salarioStream(salarioToken);
        double salario;
        salarioStream >> salario;
        empleado.salario = salario;

        empleados.push_back(empleado);
    }

    archivo.close();
    return empleados;
}

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