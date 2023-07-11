# Examen Final

Este es el reporte del examen final del curso.

## Descripción
Este es el examen final, se desarrolla en el marco del curso Estructuras Abstractas de Datos y Algoritmos para 
Ingeniería IE-0217.

## Tabla de contenidos

- [Parte Teórica](#teoria)
- [Uso](#Uso)
- [Licencia](#licencia)
- [Contacto](#contacto)

##  Parte Teórica
1. Diferencia entre paso por valor y paso por referencia en C++.

Al trabajar pasando un parámetro por valor, se pasa el valor de la variable como argumento a la función 
dicha función trabaja con una copia local de la variable y los cambios realizados en la copia no afectan
a la variable original fuera de la función. Por su parte al trabajar parámetros por referencia, la función
trabaja directamente con la variable original y cualquier cambio realizado en la referencia se refleja en 
la variable original fuera de la función. Esa es la diferencia entre paso por valor y paso por referencia en C++.

2. Recursividad y cuándo es útil utilizarla en la programación? 

La recursividad es cuando una función se llama a sí misma, esto es útil para hacer actualización de variables
que maneja la función. En lugar de resolver un problema de manera iterativa con el uso de ciclos, se divide en
subproblemas resolviendo cada uno llamando a la misma función de manera repetida hasta llegar a un subproblema
que se resuelve sin necesidad de una llamada nuevamente. es útil en Algoritmos conocidos o pequeños, también en
pequeños programas donde no se hace extenso el código por su uso o en problemas donde como en estructuras 1 se
explica el famoso divide y vencerás, donde un problema complejo se le reduce el nivel con cada llamada recursiva. 

3. Diferencia entre Listas y tuplas en Python? cunado se prefiere su uso?

La diferencia más significativa es que las listas son mutables "se pueden modificar" luego de crearlas, mientras
su creación. una tupla definida ya no se pueden modificar, no se puede agregar ni eliminar elementos. La lista se
prefiere cuando la colección de elementos puede cambiar en la ejecución del programa y debe actualizarse, mientras
si la colección de elementos se desea sea fija y se consulte siempre, porque se debe utilizar por otras funciones
entonces viene a ser útiles. 

4. Concepto Herencia?
El concepto de herencia viene ligado al uso de clases donde estas pueden heredar propiedades, digase métodos o atributos
de otra clase, creando una relación de jerarquía entre ellas. Llamada padre o hijas a las clases.

5. Comprensión de listas en Python? ejemplo de uso y como utilizar para simplificar el código?

La Comprensión de listas permite crear listas de manera concisa y legible en una sola línea de código.
Como ejemplo en la sintaxis para la comprensión se recurre a una expresión condicional que filtra los
elementos de la lista_original según definición del programador y con esto fácilmente se crea una lísta
con elementos extrayendo elementos y no se necesita recurir a iteradores para crear la misma, o bien 
manualmente crearla, ello simplifica el código al crear listas sin tener que hacer uso de codigo condición 
ni iteradores exterior al reglón. 

6. Concepto templates en C++, utilidad y como se utiliza en programación generica.
Es una plantilla de código que permite definir funciones o clases genéricas,se utiliza para 
trabajar con diferentes tipos de datos sin necesidad de implementarlas múltiples veces.
No es necesario crear más si se desea cambiar el tipo de dato por ejemplo. 

7. Sobrecarga de operadores en C++? ejemplo, como mejora legibilidad y usabilidad de código.
Es una característica que permite definir un comportamiento personalizado para operadores en una clase. 
Se utiliza mediante la definición de funciones miembro en una clase que tienen el mismo nombre que el 
operador que se desea sobrecargar, permite por ejemplo definir cómo los operadores aritméticos, de
comparación, de asignación, y demás. Un ejemplo es cuando se crear una forma estetica de imprimir los objetos
dentro de una clase según el programador le sea conveniente, esto permite mejorar la apariencia de impresión y
permite heredar un metodo de impresión diferente a otras clases.

8. Explique la diferencia entre función y un metodo en Python? como se accede a metodo de una clase y que es el argumento self?
La diferencia entre función y metodo en Python es 

Una función se define fuera de cualquier clase y puede ser utilizada en cualquier parte del programa, mientras un metodo
solo se define dentro de una clase y operan en el contexto de un objeto específico y el método se llama a través de un objeto
o una clase, utilizando la notación de punto una vez creada la instancia. Por último el argumento self se usa dentro de los métodos
para referirse al objeto en sí mismo sin necesitar indicar el nombre, esto en c++ es this. 




## Uso 

Requisitos: Ejecutar los comandos en la terminal desde el directorio ExamenFinal.


- Para compilar de forma manual la calculadora simple:  
  **g++ ./Calculadora.cpp ./main.cpp -o calculadorasimple.exe**

  Luego, para ejecutar el programa:  
  **.\calculadorasimple.exe**

- Para ejecutar de forma manual lo implementado en python:  
  **python diccionario.py**


 
## Licencia

Creative Commons Legal Code CC0 1.0 Universal, Consulte la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/

## Contacto

correo: alex.varela@ucr.ac.cr tel: +50685525005
