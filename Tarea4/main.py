from empleados import (imprimir_resultados, leer_archivo, validar_entrada,
                       buscar_por_departamento, buscar_por_salario)


def main():
    ruta_archivo = "../../employees.csv"
    empleados = leer_archivo(ruta_archivo)
    if len(empleados) == 0:
        print("Falló la lectura del archivo."
              " Revisar exista el archivo employees.csv"
              " y volver a ejecutar el programa")
        print("Fin del programa...")
        exit(0)

    opcion = None
    while opcion != 0:
        print("\n\t\t\tMENU DE CONSULTA DE INFORMACIÓN DE EMPLEADOS")
        print("Búsqueda de empleados:\t"
              "1. Por departamento\t2. Por rango de salario\t\t 0. Salir")
        opcion = input("Ingrese su opción: ")

        if opcion == "":
            print("No se ingresó ninguna opción. Volviendo al menú...")
            continue

        try:
            opcion = int(opcion)

            if opcion not in [1, 2, 0]:
                raise ValueError(
                    "Opción inválida. Por favor, ingrese una opción válida.")

            if opcion == 1:
                rango_valido1 = False
                opcion_invalida = True
                departamento = ""
                while not rango_valido1:
                    departamento = input(
                        "Ingrese el nombre del departamento: ")

                    if departamento == "":
                        print(
                            "No se ingresó ningún departamento. "
                            "Inserte nuevamente el nombre del departamento...")
                        continue

                    if not validar_entrada(departamento, "^[a-zA-Z0-9 ]+$"):
                        raise ValueError("Entrada inválida.")
                    else:
                        rango_valido1 = True

                print("\n\tLa información de los empleados "
                      "del departamento de ", departamento, " es:")
                resultados = buscar_por_departamento(empleados, departamento)
                imprimir_resultados(resultados)

                print("\t\t\tMENU DE SALIDA")
                print("Desea:\t4. Realizar nueva consulta\t0. Salir")

                opcion_invalida = True

                while opcion_invalida:
                    opcion = input("Ingrese su opción: ")
                    if opcion not in ["4", "0"]:
                        print("Opción inválida. Por favor,"
                              " ingrese opción nuevamente:"
                              " \t4. Realizar nueva consulta\t0. Salir.")
                    else:
                        opcion_invalida = False

                    if opcion == "0":
                        print("Saliendo del programa...")
                        exit(0)

            elif opcion == 2:
                salario_minimo, salario_maximo = 0.0, 0.0
                rango_valido = False

                while not rango_valido:
                    salario_minimo_str = input(
                        "Ingrese el rango de salario mínimo: ")

                    if salario_minimo_str == "":
                        print(
                            "No se ingresó ningún valor."
                            " Ingrese nuevamente el salario mínimo...")
                        continue

                    salario_maximo_str = input(
                        "Ingrese el rango de salario máximo: ")

                    if salario_maximo_str == "":
                        print(
                            "No se ingresó ningún valor."
                            " Ingrese nuevamente el salario máximo...")
                        continue

                    try:
                        salario_minimo = float(salario_minimo_str)
                        salario_maximo = float(salario_maximo_str)
                    except ValueError:
                        print(
                            "La entrada no es válida."
                            " Por favor, ingrese nuevamente los valores.")
                        continue

                    if salario_minimo > salario_maximo:
                        print(
                            "El rango de salario mínimo no puede ser mayor"
                            " que el máximo. Intente nuevamente.")
                    else:
                        rango_valido = True

                    print("")
                    print(f"\tLa información de los empleados dentro"
                          " del rango de salario "
                          f"₡{salario_minimo} - ₡{salario_maximo} es:")

                    resultados = buscar_por_salario(
                        empleados, salario_minimo, salario_maximo)
                    # Reemplaza 'imprimirResultados' con la lógica adecuada
                    imprimir_resultados(resultados)

                    print("\t\t\tMENU DE SALIDA")
                    print("Desea:\t4. Realizar nueva consulta\t0. Salir")

                    opcion_invalida = True

                    while opcion_invalida:
                        opcion = input("Ingrese su opción: ")
                        if opcion not in ["4", "0"]:
                            print("Opción inválida. Por favor,"
                                  " ingrese opción nuevamente: "
                                  " \t4. Realizar nueva consulta\t0. Salir.")
                        else:
                            opcion_invalida = False

                        if opcion == "0":
                            print("Saliendo del programa...")
                            exit(0)

        except ValueError:
            print("Error, se ingresó un carácter no "
                  "numérico o válido entre las opciones")
            print("Volviendo al menú principal...")

    if opcion == 0:
        print("Fin del programa...")


if __name__ == "__main__":
    main()
