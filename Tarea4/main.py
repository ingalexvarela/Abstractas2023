"""
@file main.py
@brief archivo con código principal para consultar información de empleados.
* El flujo del programa es el siguiente:
 * 1. Lectura de archivo y almacenamiento de  datos de empleados en lista.
 * 2. Mostrar menú de opciones para consultar información sobre los empleados:
 *    - Opción 1: Búsqueda por departamento.
 *        - Solicitar al usuario el nombre del departamento.
 *        - Validar la entrada del usuario.
 *        - Mostrar la información de los empleados del departamento.
 *        - Mostrar un submenú de opciones.
 *    - Opción 2: Búsqueda por rango de salario.
 *        - Solicitar al usuario el salario mínimo y máximo.
 *        - Validar la entrada del usuario.
 *        - Realizar la búsqueda de empleados dentro del rango de salario.
 *        - Mostrar la información de los empleados encontrados.
 *        - Mostrar un submenú de opciones.
 *    - Opción 4: Realizar una nueva consulta.
 *        - Volver al menú principal.
 *    - Opción 0: Salir del programa.
 *        - Terminar la ejecución del programa.
 * 3. El programa continúa en bucle hasta que el usuario seleccione salida (0).
 * @author Alex Varela
 * @date 5 de junio de 2023
"""
# Importa las funciones necesarias del módulo 'empleados'.
from empleados import (imprimir_resultados, leer_archivo, validar_entrada,
                       buscar_por_departamento, buscar_por_salario)


def main():
    """
    Función principal que realiza la consulta de información de empleados,
      según la opción seleccionada.
    """
    ruta_archivo = "../../employees.csv"  # Ruta del archivo
    # Lee el archivo y guarda la información en la lista 'empleados'.
    empleados = leer_archivo(ruta_archivo)
    if len(empleados) == 0:  # Si lista es de tamaño 0
        print("Falló la lectura del archivo."
              " Revisar exista el archivo employees.csv"
              " y volver a ejecutar el programa")
        print("Fin del programa...")
        exit(0)  # Salir

    opcion = None  # Inicializa la variable 'opcion' con el valor None.
    while opcion != 0:  # Mientras la opción no es 0 mantenerce en el programa
        # MENU1
        print("\n\t\t\tMENU DE CONSULTA DE INFORMACIÓN DE EMPLEADOS")
        print("Búsqueda de empleados:\t"
              "1. Por departamento\t2. Por rango de salario\t\t 0. Salir")
        opcion = input("Ingrese su opción: ")  # solicita entrada

        if opcion == "":  # si usuario no digita nada
            print("No se ingresó ninguna opción. Volviendo al menú...")
            continue

        try:
            opcion = int(opcion)  # si usuario no digita nada

            if opcion not in [1, 2, 0]:  # si opción digitada no es valida
                # Salta excepción
                raise ValueError("Opción inválida. "
                                 "Por favor, ingrese una opción válida.")

            if opcion == 1:   # si usuario digita 1
                rango_valido1 = False  # Bandera validar nombre departamento.
                opcion_invalida = True  # Bandera, validación Menu 2.
                departamento = ""  # Para almacenar nombre
                while not rango_valido1:  # Sí rango no true mantiene ciclo
                    departamento = input("Ingrese el nombre "
                                         "del departamento: ")

                    if departamento == "":  # Sí no se ingresa nombre
                        print(
                            "No se ingresó ningún departamento. "
                            "Inserte nuevamente el nombre del departamento...")
                        continue  # volver a solicitar entrada
                    # Si entrada no cumple con el patrón establecido.
                    if not validar_entrada(departamento, "^[a-zA-Z0-9 ]+$"):
                        # Se lanza una excepción.
                        raise ValueError("Entrada inválida.")
                    else:
                        # bandera verdadera para salir del ciclo.
                        rango_valido1 = True

                print("\n\tLa información de los empleados "
                      "del departamento de ", departamento, " es:")
                # Realiza la búsqueda de empleados por departamento invocando
                resultados = buscar_por_departamento(empleados, departamento)
                # Imprime los resultados de la búsqueda por departamento.
                imprimir_resultados(resultados)
                # MENU secundario
                print("\t\t\tMENU DE SALIDA")
                print("Desea:\t4. Realizar nueva consulta\t0. Salir")

                opcion_invalida = True  # MENU 2

                while opcion_invalida:  # si no es false bandera se encicla
                    opcion = input("Ingrese su opción: ")
                    if opcion not in ["4", "0"]:  # para opción invalida
                        print("Opción inválida. Por favor,"
                              " ingrese opción nuevamente:"
                              " \t4. Realizar nueva consulta\t0. Salir.")
                    else:  # bandera false fin del ciclo MENU 2
                        opcion_invalida = False

                    if opcion == "0":  # si opción 0 salir
                        print("Saliendo del programa...")
                        exit(0)

            elif opcion == 2:  # si usuario digita 2
                salario_minimo, salario_maximo = 0.0, 0.0
                rango_valido = False  # Bandera para validar salario

                while not rango_valido:  # Banderano es True
                    salario_minimo_str = input(
                        "Ingrese el rango de salario mínimo: ")
                    # Si no se ingresa nada
                    if salario_minimo_str == "":
                        print(
                            "No se ingresó ningún valor."
                            " Ingrese nuevamente el salario mínimo...")
                        continue  # Volver a solicitar entrada

                    salario_maximo_str = input(
                        "Ingrese el rango de salario máximo: ")
                    # Si no se ingresa nada
                    if salario_maximo_str == "":
                        print(
                            "No se ingresó ningún valor."
                            " Ingrese nuevamente el salario máximo...")
                        continue  # Volver a solicitar entrada
                    # definiendo uso excepción
                    try:
                        salario_minimo = float(salario_minimo_str)
                        salario_maximo = float(salario_maximo_str)
                    except ValueError:
                        # Si se produce una excepción de tipo ValueError.
                        print(
                            "La entrada no es válida."
                            " Por favor, ingrese nuevamente los valores.")
                        continue
                    # Validar lo ingresado si tiene sentido
                    if salario_minimo > salario_maximo:
                        print(
                            "El rango de salario mínimo no puede ser mayor"
                            " que el máximo. Intente nuevamente.")
                    else:
                        # Ingreso exitoso
                        rango_valido = True

                    print("")
                    print(f"\tLa información de los empleados dentro"
                          " del rango de salario "
                          f"₡{salario_minimo} - ₡{salario_maximo} es:")

                    resultados = buscar_por_salario(  # invoca función
                        empleados, salario_minimo, salario_maximo)
                    # Imprime resultados de la búsqueda por rango de salario.
                    imprimir_resultados(resultados)

                    print("\t\t\tMENU DE SALIDA")  # MENU 2
                    print("Desea:\t4. Realizar nueva consulta\t0. Salir")

                    opcion_invalida = True  # Bandera para validar MENU2

                    while opcion_invalida:  # si no es false bandera se encicla
                        opcion = input("Ingrese su opción: ")
                        if opcion not in ["4", "0"]:  # para opción invalida
                            print("Opción inválida. Por favor,"
                                  " ingrese opción nuevamente: "
                                  " \t4. Realizar nueva consulta\t0. Salir.")
                        else:  # bandera false fin del ciclo MENU 2
                            opcion_invalida = False

                        if opcion == "0":  # Salida de MENU 2
                            print("Saliendo del programa...")
                            exit(0)

        except ValueError:  # Captura la excepción de tipo ValueError.
            print("Error, se ingresó un carácter no "
                  "numérico o válido entre las opciones")
            print("Volviendo al menú principal...")

    if opcion == 0:  # Para la Salida del MENU1
        print("Fin del programa...")


# Verifica si el script se está ejecutando como el programa principal.
if __name__ == "__main__":
    main()  # Llama a la función principal `main()`.
