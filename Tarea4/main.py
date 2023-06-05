from empleados import (imprimir_resultados, leer_archivo,
                       buscar_por_departamento, buscar_por_salario)


def main():
    ruta_archivo = "../../employees.csv"
    empleados = leer_archivo(ruta_archivo)
    if not empleados:
        return

    while True:
        print("\n\t\t\tMENU DE CONSULTA DE INFORMACIÓN DE EMPLEADOS")
        print("Búsqueda de empleados:"
              "\n1. Por departamento\n2. Por rango de salario\n0. Salir")
        opcion = input("Ingrese su opción: ")

        if opcion == "1":
            departamento = input("Ingrese el nombre del departamento: ")
            resultados = buscar_por_departamento(empleados, departamento)
            print("\nLa información de los empleados del departamento " +
                  f"de {departamento} es:")
            imprimir_resultados(resultados)
        elif opcion == "2":
            salario_minimo = float(
                input("Ingrese el rango de salario mínimo: "))
            salario_maximo = float(
                input("Ingrese el rango de salario máximo: "))
            resultados = buscar_por_salario(
                empleados, salario_minimo, salario_maximo)
            print("\nLa información de los empleados dentro"
                  " del rango de salario " +
                  f"{salario_minimo} - {salario_maximo} es:")
            imprimir_resultados(resultados)
        elif opcion == "0":
            print("Programa finalizado.")
            break
        else:
            print("Opción inválida. Por favor, ingrese una opción válida.")


if __name__ == "__main__":
    main()
