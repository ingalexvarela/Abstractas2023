PROPUESTA DE PROYECTO
=============
*Sistema de gestión de paquetes turísticos*
-------------

### **Visión general de la propuesta**
#### Tabla de Contenidos

- [Visión general de la propuesta](#visión-general-de-la-propuesta)
- [Explicación del proyecto](#explicación-del-proyecto)
- [Guía de acciones esperadas al crear el sistema](#guía-de-acciones-esperadas-al-crear-el-sistema)
- [Propuestas de las pantallas, funcionalidad y widgets para implementar las acciones esperadas](#propuestas-de-las-pantallas-funcionalidad-y-widgets-para-implementar-las-acciones-esperadas)
- [Diagrama de flujo de la interfaz gráfica](#diagrama-de-flujo-de-la-interfaz-gráfica)
- [Entregas del proyecto](#entregas-del-proyecto)
- [Contacto](#contacto)

### Explicación del proyecto
<div style="text-align: justify">

  El Sistema de Gestión de Paquetes Turísticos es una solución diseñada para facilitar y optimizar la gestión de paquetes turísticos tanto para el administrador como para los clientes. El sistema ofrecerá una interfaz de usuario intuitiva y atractiva, desarrollada utilizando el software Qt Design y el lenguaje de programación C++. Hecha la creación se espera proporcionar  una experiencia fluida y agradable al interactuar con las diferentes funcionalidades. Es importante reconocer que existen funcionalidades únicas para el Administrador y para el Cliente. 

  **Funcionalidades para el Administrador:** el administrador tiene acceso a un conjunto de herramientas y funciones específicas que le permiten gestionar eficientemente los paquetes turísticos y las reservas. 

  **Funcionalidades para el Cliente:** el cliente, a través de su propia interfaz de usuario, puede acceder a una serie de características diseñadas para facilitar la búsqueda, selección y reserva de paquetes turísticos. 

</div>

#### **Guía de acciones esperadas al crear el sistema**
- Inicio del programa:
		Existe una pantalla que llamaremos inicio, conecta el ingreso como administrador o cliente, y también llama al registro del cliente.
 
 A través de la interfaz de usuario dedicada al ***administrador***, se pueden realizar las siguientes acciones:

- Inicio de Sesión del Administrador:
		El administrador inicia sesión en el sistema utilizando sus credenciales únicas para acceder a las funciones administrativas.

- Panel de Control del Administrador:
    	El panel de control proporciona una visión general de las estadísticas relevantes, como la cantidad de reservas realizadas, ingresos generados, etc. También ofrece acceso rápido a las principales áreas de gestión.

- Gestión de Paquetes Turísticos:
    	El administrador puede agregar nuevos paquetes turísticos al sistema, mandar a editar los existentes y eliminar aquellos que ya no están disponibles.

- Plantilla de edición de paquete:
      El administrador puede editar los paquetes turísticos, esta funcionalidad incluye la posibilidad de cargar imágenes, descripciones detalladas, fechas disponibles y precios.

-	Gestión de Reservas:
			El administrador tiene acceso a una lista completa de todas las reservas realizadas por los clientes. Puede ver los detalles de cada reserva, realizar modificaciones si es necesario o cancelar una reserva específica.

- Informes y Estadísticas:
		El sistema genera informes y estadísticas automatizados que permiten al administrador analizar el rendimiento del negocio. Estos informes pueden incluir datos como la cantidad de reservas por período, ingresos generados, destinos más populares, entre otros.

A través de la interfaz de usuario dedicada al ***cliente***, se pueden realizar las siguientes acciones:

- Registro de Clientes:
    	Los clientes pueden registrarse en el sistema creando una cuenta personalizada. Se les solicitará información básica, como nombre, dirección de correo electrónico y contraseña, para crear su perfil.

- Inicio de Sesión del Cliente:
		Los clientes pueden acceder a su cuenta utilizando sus credenciales de inicio de sesión, lo que les permite acceder a todas las funcionalidades personalizadas y gestionar sus reservas.

- Búsqueda de Paquetes Turísticos:
		Los clientes pueden buscar paquetes turísticos utilizando diferentes criterios, como destino, fechas de viaje y presupuesto. El sistema mostrará resultados relevantes que se ajusten a las preferencias del cliente.

- Detalles del Paquete Turístico:
		Al seleccionar un paquete turístico en particular, los clientes pueden acceder a una página con detalles completos, incluyendo descripción, itinerario, imágenes y precios. También podrán realizar una reserva directamente desde esta página.

- Reservas del Cliente:
		Los clientes pueden ver y administrar todas sus reservas existentes. Tendrán acceso a información detallada de cada reserva y la posibilidad de realizar

#### **Propuestas de las pantallas, funcionalidad y widgets para implementar las acciones esperadas**

- Pantalla Inicio:
		Ventana de inicio, conecta el ingreso como administrador o cliente, y también llama al registro del cliente.
        Widgets:  botones para acceder como administrador o cliente, o bien hacer registro como cliente.
		

<p align="center">
  <img src="https://i.postimg.cc/Vkf4cNVg/Inicio.jpg" alt="Inicio" />
</p>


El Sistema de Gestión de Paquetes Turísticos permitirá  al administrador y  al cliente realizar las siguientes funciones principales según sea su roll:

***Interfaz de Usuario para el Administrador:***

1. Inicio de Sesión del Administrador:
		Ventana de inicio de sesión donde el administrador podrá acceder a su cuenta para gestionar el sistema.
        Widgets: campos de entrada de datos para el nombre de usuario y contraseña.

<p align="center">
  <img src="https://i.postimg.cc/Kvns2wvG/Admi1.jpg" alt="Inicio" />
</p>


2. Panel de Control del Administrador:
        Ventana principal del sistema para el administrador, que proporciona una visión general de las estadísticas, paquetes turísticos, reservas, etc.
        Widgets: paneles de información, gráficos interactivos, botones para acceder a otras ventanas.

<p align="center">
  <img src="https://i.postimg.cc/t4pvCkYh/Admi2.jpg" alt="Inicio" />
</p>


3. Gestión de Paquetes Turísticos:
        Ventana donde el administrador puede agregar, editar o eliminar paquetes turísticos.
        Widgets: lista de paquetes existentes, campo de entrada para seleccionar paquete, campo de entrada para agregar paquete, botones para acciones de edición, agregar o eliminación.
<p align="center">
  <img src="https://i.postimg.cc/BnpY8FKR/Admi3.jpg" alt="Descripción de la imagen">
</p>

4. Plantilla de edición de paquete:
        Ventana donde el administrador puede editar paquetes turísticos.
        Widgets: campos de entrada para cargar imagenes, descripción, fechas y precios.
<p align="center">
  <img src="https://i.postimg.cc/fbbHYb7y/Admi4.jpg" alt="Descripción de la imagen">
</p>


5. Gestión de Reservas:
        Ventana donde el administrador puede ver y administrar las reservas realizadas por los clientes.
        Widgets: lista de reservas, botones para modificar o cancelar reservas, filtros de búsqueda.
<p align="center">
  <img src="https://i.postimg.cc/cJ5FhNTm/Admi5.jpg" alt="Inicio" />
</p>

6. Informes y Estadísticas (Ventana opcional, pensada en la escalabilidad del proyecto):
        Ventana donde el administrador puede generar informes y ver estadísticas relacionadas con los paquetes turísticos y las reservas.
        Widgets: opciones para seleccionar el tipo de informe o estadística, gráficos interactivos, botón para generar informe.
<p align="center">
  <img src="https://i.postimg.cc/RF6XbbDz/Admi6.jpg" alt="Inicio" />
</p>


***Interfaz de Usuario para el Cliente:***

 1. Registro de Clientes:
        Ventana de registro donde los clientes pueden crear una cuenta para acceder al sistema y realizar reservas.
        Widgets: campos de entrada de datos para el nombre, dirección de correo electrónico, contraseña, etc.
<p align="center">
  <img src="https://i.postimg.cc/HxqBG4q8/Cliente1.jpg" alt="Inicio" />
</p>

2. Inicio de Sesión del Cliente:
        Ventana de inicio de sesión donde los clientes pueden acceder a su cuenta.
        Widgets: campos de entrada de datos para la dirección de correo electrónico y contraseña.
<p align="center">
  <img src="https://i.postimg.cc/mk7VT14X/Cliente2.jpg" alt="Inicio" />
</p>

3. Búsqueda de Paquetes Turísticos:
        Ventana donde los clientes pueden buscar paquetes turísticos por destino, fechas, presupuesto, etc.
        Widgets: campos de entrada de datos, menús desplegables, botones de búsqueda.
<p align="center">
  <img src="https://i.postimg.cc/T2btVFbV/Cliente3.jpg" alt="Inicio" />
</p>


4. Detalles del Paquete Turístico:
        Ventana que muestra información detallada sobre un paquete turístico seleccionado.
        Widgets: paneles de información, imágenes, botones para reservar o agregar a favoritos.
<p align="center">
  <img src="https://i.postimg.cc/bNj33g0K/Cliente4.jpg" alt="Inicio" />
</p>


5. Reservas del Cliente:
        Ventana donde los clientes pueden ver y administrar sus reservas existentes.
        Widgets: lista de reservas, botones para cancelar o modificar reservas.
<p align="center">
  <img src="https://i.postimg.cc/wTcFPN03/Cliente5.jpg" alt="Inicio" />
</p>


#### **Diagrama de flujo de la interfaz gráfica**

<p align="center">
  <a href="https://postimg.cc/t1Tsc2xf">
    <img src="https://i.postimg.cc/Pqb1P7rt/diagram-20230527-2.png" alt="Diagrama" />
  </a>
</p>



### Entregas del proyecto

- [x] Propuesta
    - [x] Explicación de lo que se desea realizar, sección wiki de su repositorio.
    - [x] Incluir propuestas de  pantallas, funciones y widgets  a implementar. 
- [ ] Avance 1:
    - [ ] Incluir Makefile que realice compilación y despliegue de la aplicación.
    - [ ] No es necesario la funcionalidad completa a este punto
- [ ] Avance final:
    - [ ] Entregable final con funcionalidad completa.

### Contacto
***Autor:* Alex Varela Quirós
*correo:* alex.varela@ucr.ac.cr 
*tel:* +50685525005**

[![iconopeque.jpg](https://i.postimg.cc/hvtdRL0p/iconopeque.jpg)](https://postimg.cc/k6L4xtzb)

