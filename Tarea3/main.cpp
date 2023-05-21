#include "empleados.hpp"

using namespace std;
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
