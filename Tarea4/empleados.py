import csv  # Importa el módulo csv para trabajar con archivos CSV.
import re  # Importa el módulo re para utilizar expresiones regulares.


class Empleado:
    """
    Clase que representa a un empleado.
    """

    def __init__(self, nombre, correo, edad, departamento, salario):
        """
        Constructor de la clase Empleado.

        :param nombre: Nombre del empleado.
        :type nombre: str
        :param correo: Correo electrónico del empleado.
        :type correo: str
        :param edad: Edad del empleado.
        :type edad: int
        :param departamento: Departamento del empleado.
        :type departamento: str
        :param salario: Salario del empleado.
        :type salario: float
        """
        self.nombre = nombre
        self.correo = correo
        self.edad = edad
        self.departamento = departamento
        self.salario = salario


def leer_archivo(ruta_archivo):
    """
    Lee archivo CSV que contiene información de empleados
      y devuelve una lista de objetos Empleado.

    :param ruta_archivo: Ruta del archivo CSV.
    :type ruta_archivo: str
    :return: Lista de empleados.
    :rtype: list[Empleado]
    """
    empleados = []
    try:
        with open(ruta_archivo, 'r', newline='') as file:
            reader = csv.reader(file)  # abrir archivo CSV modo lectura
            next(reader)  # Saltar la primera fila (encabezados)
            for row in reader:
                nombre, correo, edad, departamento, salario = row

                # Validar campos
                # 1. Validar el campo "nombre"
                if not nombre or not isinstance(nombre, str):
                    continue  # Saltar fila incompleta o incorrecta

                # 2. Validar el campo "correo"
                if not correo or not isinstance(correo, str) or \
                        "@" not in correo or not correo.endswith(".com"):
                    continue  # Saltar fila incompleta o incorrecta

                # 3. Validar el campo "edad"
                try:
                    edad = int(edad)
                    if not (0 <= edad <= 120):
                        continue  # Saltar fila incompleta o incorrecta
                except ValueError:
                    continue  # Saltar fila incompleta o incorrecta

                # 4. Validar el campo "departamento"
                if not departamento or not isinstance(departamento, str):
                    continue  # Saltar fila incompleta o incorrecta

                # 5. Validar el campo "salario"
                try:
                    salario = float(salario)
                except ValueError:
                    continue  # Saltar fila incompleta o incorrecta

                # Crear objeto Empleado y agregar a la lista
                empleado = Empleado(nombre, correo, edad,
                                    departamento, salario)
                empleados.append(empleado)

    except FileNotFoundError:
        # En caso de que se produzca un error de tipo FileNotFoundError,
        # se ejecuta el siguiente bloque de código.
        print("Error: No se encontró el archivo", ruta_archivo)

    return empleados


def buscar_por_departamento(empleados, departamento):
    """
    Busca empleados por departamento.

    :param empleados: Lista de empleados.
    :type empleados: list[Empleado]
    :param departamento: Departamento a buscar.
    :type departamento: str
    :return: Lista de empleados del departamento especificado.
    :rtype: list[Empleado]
    """
    resultados = []
    for empleado in empleados:
        # 1. Compara departamento con el departamento especificado
        if empleado.departamento.lower() == departamento.lower():
            # 2. Si el departamento coincide, se agrega el empleado a la lista.
            resultados.append(empleado)
    # 3. Devuelve la lista de empleados del departamento especificado.
    return resultados


def buscar_por_salario(empleados, salario_minimo, salario_maximo):
    """
    Busca empleados por rango de salario.

    :param empleados: Lista de empleados.
    :type empleados: list[Empleado]
    :param salario_minimo: Salario mínimo del rango.
    :type salario_minimo: float
    :param salario_maximo: Salario máximo del rango.
    :type salario_maximo: float
    :return: Lista de empleados con salarios dentro del rango.
    :rtype: list[Empleado]
    """
    resultados = []
    for empleado in empleados:
        # 1. Compara el salario del empleado con el rango especificado.
        #  Utiliza >= para verificar es mayor o igual al salario mínimo,
        #  y <= para verificar si el salario es menor o igual al máximo.
        if (float(empleado.salario) >= salario_minimo and
                float(empleado.salario) <= salario_maximo):
            # 2. Si el salario esta dentro del rango, se agrega a la lista.
            resultados.append(empleado)
    # 3. Devuelve la lista de empleados con salarios en el rango especificado.
    return resultados


def imprimir_resultados(resultados):
    """
    Imprime los resultados de la búsqueda de empleados en forma de tabla.

    :param resultados: Lista de empleados encontrados.
    :type resultados: list[Empleado]
    """
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
    """
    Valida una entrada utilizando un patrón regex.

    :param entrada: Entrada a validar.
    :type entrada: str
    :param patron: Patrón regex para validar la entrada.
    :type patron: str
    :return: True si la entrada es válida, False en caso contrario.
    :rtype: bool
    """
    # Utiliza la función re.match() para aplicar el patrón regex a la entrada.
    # Si el resultado de la coincidencia no es None, significa que la entrada
    # coincide con el patrón y se considera válida. Retorna True en ese caso,
    # de lo contrario, retorna False.
    return re.match(patron, entrada) is not None
