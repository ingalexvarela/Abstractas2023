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

                # Validar campos
                if not nombre or not isinstance(nombre, str):
                    continue  # Saltar fila incompleta o incorrecta

                if not correo or not isinstance(correo, str) or \
                        "@" not in correo or not correo.endswith(".com"):
                    continue  # Saltar fila incompleta o incorrecta

                try:
                    edad = int(edad)
                    if not (0 <= edad <= 120):
                        continue  # Saltar fila incompleta o incorrecta
                except ValueError:
                    continue  # Saltar fila incompleta o incorrecta

                if not departamento or not isinstance(departamento, str):
                    continue  # Saltar fila incompleta o incorrecta

                try:
                    salario = float(salario)
                except ValueError:
                    continue  # Saltar fila incompleta o incorrecta

                # Crear objeto Empleado y agregar a la lista
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
    if len(resultados) == 0:
        # Imprime un mensaje indicando que no se encontraron resultados
        print("No se encontraron resultados")
    else:
        # Encontrar el ancho máximo del campo "Departamento"
        max_ancho_departamento = 0
        for empleado in resultados:
            max_ancho_departamento = max(
                max_ancho_departamento, len(empleado.departamento))

        # Imprime encabezados de la tabla
        print("\tNombre y apellido\tCorreo electrónico"
              "\t\tEdad\tDepartamento\t\t\tSalario")

        # Imprime línea separadora
        print("\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"
              "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"
              "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯")

        for empleado in resultados:
            print("\t{0}\t\t{1}\t\t{2}\t{3:<{4}}\t\t\t{5}"
                  .format(empleado.nombre, empleado.correo,
                          empleado.edad, empleado.departamento,
                          max_ancho_departamento, empleado.salario))
            # Imprime información en cada fila con alineación del salario

        # Imprime línea separadora
        print("\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"
              "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"
              "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯")


def validar_entrada(entrada, patron):
    return re.match(patron, entrada) is not None
