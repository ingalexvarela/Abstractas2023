# Tarea 5, Analisis de un conjunto de datos extraido de "El Bureau of Transportation Statistics (BTS)" 

## Uso 

Requisitos: Ejecutar los comandos en la terminal desde el directorio Tarea5

- Para compilar y ejecutar con el make en Linux:  
  **make**

- Para compilar y ejecutar con el make en Windows:  
  **mingw32-make -s**

- Para ejecutar de forma manual:  
  **python main.py** en Windows

  **python3 main.py** en Linux

## Descripción
BTS es una agencia del Departamento de Transporte de los Estados Unidos que recopila y proporciona datos relacionados con el
transporte aéreo, terrestre y marítimo, para la tarea se decide trabajar con el conjunto de datos sobre puntualidad de Aerolíneas
y Causas de Retrasos, para realizar el análisis de datos y desarrollo de conclusiones y representaciones gráficas. 

El link de descarga y visualización de estadisticas de la BTS es: - [Sitio web de datos](https://www.transtats.bts.gov/OT_Delay/)

Es de mención que este proyecto es la tarea 5 de programación y tiene por objetivo la creación de un programa modular desarrollado
en lenguaje de programación Python; que permita el análisis de un conjunto de datos descargados de la web una vez procesados por el
programa desarrollado. 

Esta tarea se desarrolla en el marco del curso Estructuras Abstractas de Datos y Algoritmos para Ingeniería IE-0217 y la documentación
del código fuente se puede consultar en la dirección: - [Sitio web del proyecto](https://esp8266alfa.000webhostapp.com/)


## Tabla de contenidos
- [Uso](#Uso)
- [Descripción](#descripción)
- [Resultados obtenidos](#resultados)
- [Instalación](#instalación)
- [Licencia](#licencia)
- [Contacto](#contacto)

## Resultados obtenidos

- **Primer resultado obtenido y su interpretación**

<p align="center">
  <a href="https://postimg.cc/gallery/Y4tQqgC">
    <img src="https://i.postimg.cc/rp792vZK/Figure-1.png" alt="Diagrama" />
  </a>
</p>

Esta primera gráfica representa el número de vuelos retrasados de los años 2018 a 2022 en EE.UU. por mes. Se puede interpretar 
que en general los años presentan un patrón similar de atrasos por mes, donde los máximos se dan en el periodo entre los meses
junio y agosto, periodo que coincide con el periodo de las vacaciones escolares conocido como (verano) en los Estados Unidos 
de Norte América. También se aprecia un aumento para el mes de diciembre, mes que coincide con la festividad de la Navidad y
con el periodo de invierno lo que explicaría que a mayor demanda y aumento en números de vuelos se den mayores atrasos, además
que el invierno puede generar atrasos por las malas condiciones del tiempo atmosférico.
Por su parte, el año 2020 tuvo los números más bajos en retrasos, eso se debe a que fue el año donde se dieron la restricción
de vuelos internacionales y nacionales en el planeta por medidas de seguridad sanitaria por el virus del covid19. Lo que vendría
a explicar que, tras una baja oferta de vuelos, puede haber menor retraso en los vuelos pues puede existir mayor tiempo de 
mantenimiento y de vigilancia en la operación de vuelo, lo que se traduce a menores retardos y demoras en comparación con 
los años donde la oferta de vuelos es mayor. Para validar la conclusión de los datos se hizo uso del siguiente gráfico donde
se muestra el comportamiento de los vuelos en América Latina y Caribe en el año 2020, reconociendo que también se puede
interpolar este mismo análisis a EE.UU. respecto a las restricciones de viajes aéreos.

•	un vuelo se considera retrasado si llegó (o partió) a la puerta de embarque 15 minutos o más después de la hora de llegada (salida) 

  <p align="center">
  <a href="https://postimg.cc/gallery/Y4tQqgC">
    <img src="https://i.postimg.cc/fRTCc70T/Captura.jpg" alt="Diagrama" />
  </a>
</p>


- **Segundo resultado obtenido y su interpretación**

La segunda gráfica representa las causas de retrasos por categoría para vuelos en EE.UU., por Año, dichas categorías agrupan las causas de las
demoras según 5 categorías que el Comité Asesor de Informes a Tiempo de Aerolíneas creo. Las categorías en ingles son Air Carrier, National Aviation System,
Weather, Late-Arriving Aircraft and Security. Y cada evento que agrupa se explica a continuación: 

•	Air Carrier (Aerolínea): La causa de la cancelación o demora se debió a circunstancias dentro del control de la aerolínea
 (p. ej., problemas de mantenimiento o de la tripulación, limpieza de la aeronave, carga de equipaje, abastecimiento de combustible, etc.).

•	Extreme Weather (Condiciones meteorológicas extremas): condiciones meteorológicas significativas (reales o pronosticadas) que, a juicio del transportista,
 retrasan o impiden la operación de un vuelo, como tornados, ventiscas o huracanes.

•	National Aviation System (NAS) (Sistema Nacional de Aviación): demoras y cancelaciones atribuibles al sistema nacional de aviación que se refieren a un
 amplio conjunto de condiciones, como condiciones climáticas no extremas, operaciones aeroportuarias, volumen de tráfico pesado y control de tráfico aéreo.

•	Late-arriving aircraft (Aeronave que llega tarde): un vuelo anterior con la misma aeronave llegó tarde, lo que provocó que el vuelo actual saliera tarde.

•	Security (Seguridad): Demoras o cancelaciones causadas por la evacuación de una terminal o vestíbulo, reembarque de la aeronave debido a una violación de
 la seguridad, equipo de control inoperativo y/o largas filas de más de 29 minutos en las áreas de control. 

Entendidas las categorías del gráfico se puede interpretar para el siguiente gráfico que La categoría que aporta mayor número de atrasos es Late Aircraft Delay
en el 2018 y 2019, pero para el 2020 fue mayor Carrier Delay, lo que se puede interpretar que se debió a mayores protocolos de limpieza de las unidades aéreas.
Para el 2021 se normaliza el número de vuelos aumentando así Late Aircraft Delay y la categoría Security Delay aumenta a partir del 2020 por los protocolos
instaurados de control por el Covid19. Finalmente para el año 2022 se mantiene constante Security Delay por el mantenimiento de los protocolos de control y
por su parte NAS Delay es relativamente constante por año al igual que Weather Delay lo que era esperable, porque las demoras por concepto de precaución y
orden de operación (National Aviation System (NAS)) son claves para la seguridad de los vuelos, por lo que se espera no se reduzca aunque del gráfico anterior
se nota que el 2020 fue un caso atípico de vuelos y de mayor planeamiento  por lo que también se nota de este gráfico que es el año que presenta los
números más bajos en todas las categoría.

<p align="center">
  <a href="https://postimg.cc/gallery/Y4tQqgC">
    <img src="https://i.postimg.cc/5273nHw5/Figure-2.png" alt="Diagrama" />
  </a>
</p>

- **Tercer resultado obtenido y su interpretación**

<p align="center">
  [![Figure-5.png](https://i.postimg.cc/Pf3KSDLM/Figure-5.png)](https://postimg.cc/7bzg6fnC)
</p>

El tercer gráfico evalua el desempeño de llegadas a tiempo para vuelos de EE.UU. en el periodo (2018 - 2022),Del gráfico podemos observar
que los porcentajes de cancelaciones de vuelos fue mayor para el año 2020, esto se debe a causa del Covid19, Por su parte se puede concluir
que para periodos normales los vuelos cancelados equivalen a menos del 3% del total de vuelos, nuevamente observamos como para el 2020 fueron
menos los vuelos demorados, por su parte en épocas sin crisis de la salud donde las operaciones aéreas no son singulares se observa que las
demoras más vuelos cancelas y desviados corresponde a un porcentaje mayor al 20% de las operaciones.

Las conclusiones más relevantes en orden son:
- El año 2020 fue un año diferente en los patrones de demora en los viajes aéreos de EE.UU. por causa del Covid19.
- Los años 2021 y 2022 cargados de protocolos tras la aplicación por causa del Covid19, aportaron algún porcentaje de retraso en los vuelos.
- La cantidad de demoras en vuelos para todos los años por mes sigue una tendencia, siendo mayores los casos de demoras en el mes de diciembre,
 que se marca por la festividad de la navidad y, siendo también mayores los casos de demora en las vacaciones de verano que abarcan los meses de
  junio, julio y agosto. 

Como posibles aplicaciones de los hallazgos, se puede concluir que:
- Reducir la cantidad de vuelos reduce las demoras por incrementar la planeación de los vuelos.
- Se debe intentar no viajar en tiempos de crisis de salud para evitar la cancelación de vuelos. 
- Por el análisis se logró concluir que aumentar las operaciones de vuelos en los meses de vacaciones de verano
 y mes de diciembre puede reducir las demoras en los vuelos.


## Instalación

Requisitos previos: 
- Conexión a Internet para descargar los archivos de instalación. 
- Windows 10 o posterior.

Pasos para la instalación:
Ve a la siguiente URL en tu navegador web: https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download
completa los pasos de https://dev.to/gamegods3/how-to-install-gcc-in-windows-10-the-easier-way-422j

Requisitos previos de paquetes en Python3: 
- requests: Este paquete se utiliza para realizar solicitudes HTTP y descargar archivos de la web.
- zipfile: Este paquete proporciona las herramientas necesarias para trabajar con archivos ZIP.
- io: Modulo para trabajar con flujos de entrada y salida, incluyendo el uso de BytesIO para leer y escribir datos en memoria.
- urllib3: Este paquete se utiliza para manejar solicitudes HTTP avanzadas, incluyendo la deshabilitación de advertencias de certificado SSL.
- Pandas es una biblioteca de código abierto escrita en Python que se utiliza para el análisis y manipulación de datos.

## Licencia

Creative Commons Legal Code CC0 1.0 Universal, Consulte la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/

## Contacto

- Autor: Alex Varela Quirós
- correo: alex.varela@ucr.ac.cr 
- tel: +50685525005

[![iconopeque.jpg](https://i.postimg.cc/hvtdRL0p/iconopeque.jpg)](https://postimg.cc/k6L4xtzb)