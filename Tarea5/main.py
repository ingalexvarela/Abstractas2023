# Importar el módulo 'pandas' y asignarlo a 'pd'
# para el manejo de datos estructurados
import pandas as pd

# Importar la función 'descargar_datos'
# desde el módulo 'descargar_datos'
from descargar_datos import descargar_datos


# URL base del sitio web
base_url = 'https://www.transtats.bts.gov/OT_Delay/'

# Obtener el enlace de descarga de datos
download_link = (
    'ot_delaycause1_DL.aspx?8n4=9ur4r Brn4z106u '
    'or69rr0 FHFEK NaQ FHFKJ'
)

# Construir la URL de descarga completa
download_url = base_url + download_link

# Llamar a la función de descarga de datos para traer al entorno el csv
csv_filename = descargar_datos(download_url)

# Imprimir mensaje de éxito y nombre del archivo descargado
if csv_filename:
    print("La descarga se completó con éxito.")
    print(f"Se descargó el archivo llamado: {csv_filename}")

    # Cargar el archivo CSV en un DataFrame de pandas
    df = pd.read_csv(csv_filename)

    # Limpieza y preparación de datos
    # condiciones al conjunto de datos
    columnas_numericas = ['arr_flights', 'arr_del15', 'carrier_ct',
                          'weather_ct', 'nas_ct', 'security_ct',
                          'late_aircraft_ct', 'arr_cancelled', 'arr_diverted',
                          'arr_delay', 'carrier_delay', 'weather_delay',
                          'nas_delay', 'security_delay', 'late_aircraft_delay']

    df[columnas_numericas] = df[columnas_numericas].fillna(0)

    df_filtrado = df[
        (df['year'].between(2018, 2023)) &
        (df['month'].between(1, 12)) &
        (df['carrier'].notnull()) &
        (df['carrier_name'].notnull()) &
        (df['airport'].str.len() > 1) &
        (df['airport_name'].notnull()) &
        df[columnas_numericas].notnull().all(axis=1) &
        df[columnas_numericas].apply(lambda x: x.apply(
            lambda y: isinstance(y, int) or isinstance(y, float))).all(axis=1)
    ]
    # Para verificar las lineas descartadas
    print("Filas descartadas:")
    df_descartado = df[~df.index.isin(df_filtrado.index)]
    for index, row in df_descartado.iterrows():
        print(row)

    # Filtrar los datos para los años 2020, 2021 y 2022
    df_2018_2022 = df[(df['year'] >= 2018) & (df['year'] <= 2022)]

    # INICIO DE CALCULOS GRÁFICA 1
    # Calcular la suma de vuelos atrasados (arr_del15)
    #  para cada mes del año 2020, 2021 y 2022
    monthly_delays_2018 = df_2018_2022[
        df_2018_2022['year'] == 2018].groupby('month')[
        'arr_del15'].sum()
    monthly_delays_2019 = df_2018_2022[
        df_2018_2022['year'] == 2019].groupby('month')[
        'arr_del15'].sum()
    monthly_delays_2020 = df_2018_2022[
        df_2018_2022['year'] == 2020].groupby('month')[
        'arr_del15'].sum()
    monthly_delays_2021 = df_2018_2022[
        df_2018_2022['year'] == 2021].groupby('month')[
        'arr_del15'].sum()
    monthly_delays_2022 = df_2018_2022[
        df_2018_2022['year'] == 2022].groupby('month')[
        'arr_del15'].sum()

    # Importar el archivo grafica.py y
    #  llamar a la función para generar la gráfica
    from graficos import generar_grafica

    generar_grafica(monthly_delays_2018, monthly_delays_2019,
                    monthly_delays_2020, monthly_delays_2021,
                    monthly_delays_2022)

    # INICIO DE CALCULOS GRÁFICA 2
    # Calcular la suma de las variables para cada año por categoría
    carrier_delay_sum = df_2018_2022.groupby('year')['carrier_ct'].sum()
    weather_delay_sum = df_2018_2022.groupby('year')['weather_ct'].sum()
    nas_delay_sum = df_2018_2022.groupby('year')['nas_ct'].sum()
    security_delay_sum = df_2018_2022.groupby('year')['security_ct'].sum()
    late_aircraft_delay_sum = df_2018_2022.groupby(
        'year')['late_aircraft_ct'].sum()
    arr_del15_sum = df_2018_2022.groupby('year')['arr_del15'].sum()

    from graficos import generar_grafica2
    # Llamar a la función para generar la gráfica 2
    generar_grafica2(arr_del15_sum, carrier_delay_sum, weather_delay_sum,
                     nas_delay_sum, security_delay_sum,
                     late_aircraft_delay_sum)

    # INICIO DE CALCULOS GRÁFICA 3
    # Calcular la variable para gráfica circular
    # Extraer la lista de años de una columna específica
    years = df['year'].unique().tolist()
    # Cantidad de vuelos llegados (operaciones) por año
    total_operations = {}
    for year in years:
        total_ops = df[df['year'] == year]['arr_flights'].sum()
        total_operations[year] = total_ops

    # Cantidad de vuelos cancelados por año
    cancelled_flights = {}
    for year in years:
        cancelled = df[df['year'] == year]['arr_cancelled'].sum()
        cancelled_flights[year] = cancelled

    # Cantidad de vuelos desviados por año
    diverted_flights = {}
    for year in years:
        diverted = df[df['year'] == year]['arr_diverted'].sum()
        diverted_flights[year] = diverted

    # Cantidad de vuelos demorados por año
    delayed_flights = {}
    for year in years:
        delayed = df[df['year'] == year]['arr_del15'].sum()
        delayed_flights[year] = delayed

    # Calcular la variable On_Time para cada año
    on_time_sum = {}
    for year in years:
        on_time = (df[df['year'] == year]['arr_flights'] - df[
            df['year'] == year]['arr_cancelled'] - df[
                df['year'] == year]['arr_diverted'] - df[
                    df['year'] == year]['arr_del15']).sum()
        on_time_sum[year] = on_time

    from graficos import generar_grafica3
    # Llamar a la función para generar la gráfica 3
    generar_grafica3(total_operations, cancelled_flights, diverted_flights,
                     delayed_flights, on_time_sum)
    print("Fin del Programa, revisar el README para la interpretación")

else:
    print("No se encontró ningún archivo CSV en la descarga."
          "Saliendo del programa...")
    exit()  # Salir del programa
