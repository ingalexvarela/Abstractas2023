import matplotlib.pyplot as plt
import numpy as np


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
    fig, ax = plt.subplots(figsize=(12, 6))

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
