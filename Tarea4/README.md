# Gestión de Información de empleados de una empresa implementado en lenguaje de programación Python. 

Este proyecto es la tarea 4 de programación y tiene por objetivo la migración del programa modular desarrollado en la tarea 3
en lenguaje de programacion c++ a un programa modular desarrollado en lenguaje de programación Python.

La programación de la tarea 4 en Python, tiene como objetivo al igual que la tarea 3, implementar un programa modular que leé un
archivo y almacena la información de cada empleado en un objeto de una clase Empleado, con siguientes atributos: nombre, correo,
edad, departamento y salario. Además el programa modular permite al usuario realizar búsquedas de empleados por departamento o por
rango de salario usando expresiones regulares para validar la entrada del usuario y buscar en el archivo únicamente los empleados
que cumplan con los criterios de búsqueda para imprimir por pantalla la información de los empleados que cumplan con los criterios
de búsqueda.

Como acción adicional para esta tarea se verifica los datos del csv también; para no ingresar información erronea a las consultas. 

## Descripción
Esta tarea se desarrolla en el marco del curso Estructuras Abstractas de Datos y Algoritmos para 
Ingeniería IE-0217 y la documentación del código fuente se puede consultar en la dirección: 
- [Sitio web del proyecto](https://esp8266alfa.000webhostapp.com/)
## Tabla de contenidos

- [Investigación](#investigación)
- [Instalación](#instalación)
- [Uso](#Uso)
- [Licencia](#licencia)
- [Contacto](#contacto)

## Investigación
** Relacion entre las implementaciones de C++ y la nueva realizada en Python **

 El flujo del programa es el siguiente tanto en el código implementado en C++, como en python:
 1. Lectura de archivo y almacenamiento de datos de empleados en lista para python y vector para C++.
 2. Mostrar menú de opciones para consultar información sobre los empleados:
     - Opción 1: Búsqueda por departamento.
         - Solicitar al usuario el nombre del departamento.
         - Validar la entrada del usuario.
         - Mostrar la información de los empleados del departamento.
         - Mostrar un submenú de opciones.
     - Opción 2: Búsqueda por rango de salario.
         - Solicitar al usuario el salario mínimo y máximo.
         - Validar la entrada del usuario.
         - Realizar la búsqueda de empleados dentro del rango de salario.
         - Mostrar la información de los empleados encontrados.
         - Mostrar un submenú de opciones.
     - Opción 4: Realizar una nueva consulta.
         - Volver al menú principal.
     - Opción 0: Salir del programa.
         - Terminar la ejecución del programa.
 3. El programa continúa en bucle hasta que el usuario seleccione salida (0).

Las diferencias son:
  - Uso de vector en C++ y lista en Python.
  - En el programa de Python se verifica los datos del csv también.
  - Se hizo una verificación de opciones mejor para el MENU 2 en Python.

## Instalación

Requisitos previos: 
- Conexión a Internet para descargar los archivos de instalación. 
- Windows 10 o posterior.

Pasos para la instalación:
Ve a la siguiente URL en tu navegador web: https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download
completa los pasos de https://dev.to/gamegods3/how-to-install-gcc-in-windows-10-the-easier-way-422j

## Uso 

Requisitos: Ejecutar los comandos en la terminal desde el directorio Tarea4.

- Para compilar y ejecutar con el make de Linux:  
  **make**

- Para compilar y ejecutar con el make de Windows:  
  **mingw32-make -s -f Makefile2**

- Para ejecutar de forma manual:  
  **python main.py**

## Licencia

Creative Commons Legal Code CC0 1.0 Universal, Consulte la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/

## Contacto

correo: alex.varela@ucr.ac.cr tel: +50685525005

[![iconopeque.jpg](https://i.postimg.cc/hvtdRL0p/iconopeque.jpg)](https://postimg.cc/k6L4xtzb)