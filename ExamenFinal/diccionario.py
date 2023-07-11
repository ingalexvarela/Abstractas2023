'''
Función toma como parámetro cadena de texto, devuelve
diccionario con frecuencia de aparición de cada clave
que representa una palabra encontrada en la cadena'''

import re

cadena = "Hola mundo cómo está, cómo está .. .."


def contar_frecuencia_palabras(cadena):
    '''
    Separar la cadena en palabras omitiendo los signos de puntuación
      con expresiones regulares '''
    palabras = re.findall(r'\b\w+\b', cadena)

    # Diccionario vacío para almacenar la frecuencia de cada palabra
    frecuencia = {}

    # Ciclo for, recorrer cada elemento en palabras y cuenta su frecuencia
    for i in palabras:
        if i in frecuencia:
            frecuencia[i] += 1  # para la clave aumenta 1 su valor
        else:
            frecuencia[i] = 1  # caso inicial

    return frecuencia


resultado = contar_frecuencia_palabras(cadena)  # Llamada a la función
print(resultado)  # Impresión de resultado
