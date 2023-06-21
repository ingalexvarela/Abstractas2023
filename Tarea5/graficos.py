# Importar el módulo 'matplotlib.pyplot' y
# asignarlo a 'plt' para trazar gráficos
import matplotlib.pyplot as plt
# Importar el módulo 'numpy' y asignarlo a 'np'
# para trabajar con matrices y funciones matemáticas
import numpy as np


# Primera función para generar el gráfico 1
def generar_grafica(monthly_delays_2018, monthly_delays_2019,
                    monthly_delays_2020, monthly_delays_2021,
                    monthly_delays_2022):
    # Crear una lista de los doce meses del año
    months = ['January', 'February', 'March', 'April', 'May', 'June',
              'July', 'August', 'September', 'October', 'November', 'December']
    # Crear una figura y un eje para el gráfico lineal
    fig, ax = plt.subplots(figsize=(12, 5))
    # Graficar los datos del año 2022 en forma de línea
    plt.plot(months, monthly_delays_2018,
             marker='o', linestyle='-', label='2018')
    # Graficar los datos del año 2022 en forma de línea
    plt.plot(months, monthly_delays_2019,
             marker='o', linestyle='-', label='2019')
    # Graficar los datos del año 2020 en forma de línea
    plt.plot(months, monthly_delays_2020,
             marker='o', linestyle='-', label='2020')
    # Graficar los datos del año 2021 en forma de línea
    plt.plot(months, monthly_delays_2021,
             marker='o', linestyle='-', label='2021')
    # Graficar los datos del año 2022 en forma de línea
    plt.plot(months, monthly_delays_2022,
             marker='o', linestyle='-', label='2022')
    # Establecer etiquetas para el eje x (meses) y
    #  el eje y (cantidad de vuelos atrasados)
    plt.xlabel('Months')
    plt.ylabel('Number of Delayed Flights')
    # Establecer un título para el gráfico
    plt.title("Number of Delayed Flights per"
              " year from 2018 to 2022 in the USA")
    # Agregar una grilla al gráfico
    ax.grid(True)
    # Calcular los valores máximos de cada año
    max_month_2018 = months[monthly_delays_2018.idxmax()]
    max_delay_2018 = monthly_delays_2018.max()
    max_month_2019 = months[monthly_delays_2019.idxmax()]
    max_delay_2019 = monthly_delays_2019.max()
    max_month_2020 = months[monthly_delays_2020.idxmax()]
    max_delay_2020 = monthly_delays_2020.max()
    '''
    max_month_2021 = months[monthly_delays_2021.idxmax()]
    max_delay_2021 = monthly_delays_2021.max()
    '''
    monthly_delays_2022.index = monthly_delays_2022.index - 1
    max_month_2022 = months[monthly_delays_2022.index[-1]]
    max_delay_2022 = monthly_delays_2022.iloc[-1]
    # Agregar etiquetas sobre cada punto del mes
    plt.text(max_month_2018, max_delay_2018,
             f'Max: {max_delay_2018}', ha='center', va='bottom')
    plt.text(max_month_2019, max_delay_2019,
             f'Max: {max_delay_2019}', ha='center', va='bottom')
    plt.text(max_month_2020, max_delay_2020,
             f'Max: {max_delay_2020}', ha='center', va='bottom')
    '''
    plt.text(max_month_2021, max_delay_2021,
             f'Max: {max_delay_2021}', ha='center', va='bottom')
    '''
    plt.text(max_month_2022, max_delay_2022,
             f'Max: {max_delay_2022}', ha='center', va='bottom')

    # Mostrar una leyenda con las etiquetas de cada línea
    plt.legend()
    # Mostrar el gráfico
    plt.show()


# Segunda función para generar el gráfico 2
def generar_grafica2(arr_del15_sum, carrier_delay_sum, weather_delay_sum,
                     nas_delay_sum, security_delay_sum,
                     late_aircraft_delay_sum):
    # Crear una lista de años
    years = carrier_delay_sum.index

    # Crear una lista de posiciones en el eje x para cada año
    x_pos = np.arange(len(years))

    # Definir el ancho de las barras
    bar_width = 0.1

    # Crear la figura y los ejes del gráfico con tamaño definido
    fig, ax = plt.subplots(figsize=(11, 6))

    # Ajustar el tamaño del subplot derecho
    fig.subplots_adjust(right=0.777)

    # Crear las barras para cada variable
    ax.bar(x_pos - bar_width*2, carrier_delay_sum,
           width=bar_width, align='center', label='Carrier Delay')
    ax.bar(x_pos - bar_width, weather_delay_sum, width=bar_width,
           align='center', label='Weather Delay')
    ax.bar(x_pos, nas_delay_sum, width=bar_width,
           align='center', label='NAS Delay')
    ax.bar(x_pos + bar_width, security_delay_sum, width=bar_width,
           align='center', label='Security Delay')
    ax.bar(x_pos + bar_width*2, late_aircraft_delay_sum,
           width=bar_width, align='center', label='Late Aircraft Delay')
    ax.bar(x_pos + bar_width*3, arr_del15_sum, width=bar_width,
           align='center', label='Arrival Delay')

    # Establecer las etiquetas del eje x como los años
    ax.set_xticks(x_pos)
    ax.set_xticklabels(years)

    # Agregar título al eje y
    ax.set_ylabel('Number of Delayed Flights')

    # Agregar título al eje x
    ax.set_xlabel('Years')

    # Utilizar escala logarítmica en el eje y
    ax.set_yscale('log')

    # Ajustar el límite del eje y para evitar valores negativos o cero
    ax.set_ylim(bottom=1)

    # Rotar las etiquetas del eje x para mayor legibilidad si es necesario
    plt.xticks(rotation=45)

    # Agregar una grilla en el gráfico
    ax.grid(True, axis='y', linestyle='--', alpha=0.5)

    # Agregar título al gráfico
    plt.title('Causes of Delays by Category for Flights in the USA, by Year')

    # Agregar una leyenda fuera del gráfico
    ax.legend(bbox_to_anchor=(1.02, 1), loc='upper left')

    # Mostrar el gráfico de barras
    plt.show()


# Tercera función para generar el gráfico 3
def generar_grafica3(total_operations, cancelled_flights, diverted_flights,
                     delayed_flights, on_time_sum):
    years = total_operations.keys()

    # Definir la paleta de colores personalizada
    colors = ['#FF0000', '#0000FF', '#FFA500', '#008000']
    # Rojo, Azul, Naranja, Verde

    # Crear una figura y un conjunto de ejes usando 'subplots'
    # El primer argumento '1' indica que se creará 1 fila de ejes
    # El segundo argumento 'len(years)' indica que se creará una
    #  cantidad de ejes igual a la longitud de la lista 'years'
    # El parámetro 'figsize=(12, 5)' establece el tamaño
    # de la figura en pulgadas
    fig, axs = plt.subplots(1, len(years), figsize=(12, 5))

    # Establecer el título principal de la figura usando 'suptitle'
    # El texto del título se especifica como una cadena entre comillas
    # El parámetro 'fontsize=16' establece el tamaño de fuente
    # del título en puntos
    fig.suptitle("On-Time Arrival Performance for US "
                 "Flights (2018 - 2022)", fontsize=16)

    # calculo de fraciones por año
    for i, year in enumerate(years):
        total = total_operations[year]
        sizes = [cancelled_flights[year] / total,
                 delayed_flights[year] / total,
                 diverted_flights[year] / total,
                 on_time_sum[year] / total]

        # Asignar colores personalizados a cada fracción
        pie_colors = [colors[0], colors[2], colors[1], colors[3]]

        # Crear un gráfico de pastel en el i-ésimo conjunto de ejes
        # 'sizes' es una lista con los tamaños de las porciones
        #  del gráfico de pastel 'colors' es una lista con los colores
        #  de las porciones del gráfico de pastel 'autopct' especifica
        #  el formato de las etiquetas de porcentaje en el gráfico de pastel
        # 'startangle' especifica el ángulo inicial para la primera porción
        #  del gráfico de pastel
        axs[i].pie(sizes, colors=pie_colors, autopct='%1.1f%%', startangle=90)

        # Establecer el aspecto igual en el i-ésimo conjunto de ejes
        axs[i].axis('equal')

        # Establecer el título del i-ésimo conjunto de ejes
        # 'f'Año {year}' es una cadena formateada que muestra
        #  el año correspondiente
        axs[i].set_title(f'Año {year}')

    # Configuración de ploteo
    plt.subplots_adjust(left=0.021, bottom=0.14, right=0.926,
                        top=0.779, wspace=0.012, hspace=0.2)

    # Crear una leyenda personalizada
    custom_legend = [plt.Rectangle((0, 0), 1, 1, color=color)
                     for color in colors]
    labels = ['Cancelled', 'Diverted', 'Delayed', 'On Time']
    plt.legend(custom_legend, labels, loc='lower right',
               bbox_to_anchor=(0.0, -0.15), ncol=4)
    plt.show()
