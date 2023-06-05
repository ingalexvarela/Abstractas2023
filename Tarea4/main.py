import csv
import re


class Empleado:
    def __init__(self, nombre, correo, edad, departamento, salario):
        self.nombre = nombre
        self.correo = correo
        self.edad = edad
        self.departamento = departamento
        self.salario = salario


def leer_archivo(ruta_archivo):
    empleados = []
    try:
        with open(ruta_archivo, 'r', newline='') as file:
            reader = csv.reader(file)
            next(reader)  # Saltar la primera fila (encabezados)
            for row in reader:
                nombre, correo, edad, departamento, salario = row
                empleado = Empleado(nombre, correo, edad,
                                    departamento, salario)
                empleados.append(empleado)
    except FileNotFoundError:
        print("Error: No se encontró el archivo", ruta_archivo)
    return empleados


def buscar_por_departamento(empleados, departamento):
    resultados = []
    for empleado in empleados:
        if empleado.departamento.lower() == departamento.lower():
            resultados.append(empleado)
    return resultados


def buscar_por_salario(empleados, salario_minimo, salario_maximo):
    resultados = []
    for empleado in empleados:
        if (float(empleado.salario) >= salario_minimo and
                float(empleado.salario) <= salario_maximo):
            resultados.append(empleado)
    return resultados


def imprimir_resultados(resultados):
    if not resultados:
        print("No se encontraron empleados que cumplan"
              "con los criterios de búsqueda.")
        return
    for empleado in resultados:
        print("Nombre:", empleado.nombre)
        print("Correo:", empleado.correo)
        print("Edad:", empleado.edad)
        print("Departamento:", empleado.departamento)
        print("Salario:", empleado.salario)
        print()


def validar_entrada(entrada, patron):
    return re.match(patron, entrada) is not None


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
