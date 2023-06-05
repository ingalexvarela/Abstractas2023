# Gestión de Información de empleados de una empresa.

Este proyecto es la tarea 3 de programación en C++ que tiene como objetivo implementar un programa modular que leé un archivo 
y almacenar la información de cada empleado en un objeto de una clase Empleado, con siguientes atributos: nombre, correo, edad, 
departamento y salario. Además el programa modular permite al usuario realizar búsquedas de empleados por departamento o por rango
de salario usando expresiones regulares para validar la entrada del usuario y buscar en el archivo únicamente los empleados que 
cumplan con los criterios de búsqueda para imprimir por pantalla la información de los empleados que cumplan con los criterios 
de búsqueda.

## Descripción
Esta tarea se desarrolla en el marco del curso Estructuras Abstractas de Datos y Algoritmos para 
Ingeniería IE-0217 y la documentación del código fuente se puede consultar en la dirección: 
- [Sitio web del proyecto](https://doxygenizi12.000webhostapp.com/)
## Tabla de contenidos

- [Instalación](#instalación)
- [Uso](#Uso)
- [Licencia](#licencia)
- [Contacto](#contacto)

## Instalación

Requisitos previos: 
- Conexión a Internet para descargar los archivos de instalación. 
- Windows 10 o posterior.

Pasos para la instalación:
Ve a la siguiente URL en tu navegador web: https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download
completa los pasos de https://dev.to/gamegods3/how-to-install-gcc-in-windows-10-the-easier-way-422j

## Uso 

Requisitos: Ejecutar los comandos en la terminal desde el directorio Tarea3.

- Para compilar y ejecutar con el make de Linux:  
  **mingw32-make all -s**

- Para compilar y ejecutar con el make de Windows:  
  **mingw32-make -s -f Makefile2**

- Para compilar de forma manual:  
  **g++ ./empleados.cpp ./main.cpp -o empleados.exe**

  Luego, para ejecutar el programa:  
  **.\empleados.exe**


## Licencia

Creative Commons Legal Code CC0 1.0 Universal, Consulte la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/

## Contacto

correo: alex.varela@ucr.ac.cr tel: +50685525005
