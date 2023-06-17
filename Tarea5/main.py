import pandas as pd
from descargar_datos import descargar_datos

# URL base del sitio web
base_url = 'https://www.transtats.bts.gov/OT_Delay/'

# Obtener el enlace de descarga de datos
download_link = (
    'ot_delaycause1_DL.aspx?8n4=9ur4r Brn4z106u '
    'or69rr0 FHFHL NaQ FHFKM'
)

# Construir la URL de descarga completa
download_url = base_url + download_link

# Llamar a la función de descarga de datos
csv_filename = descargar_datos(download_url)

# Imprimir mensaje de éxito y nombre del archivo descargado
if csv_filename:
    print("La descarga se completó con éxito.")
    print(f"Se descargó el archivo llamado: {csv_filename}")
    # Cargar el archivo CSV en un DataFrame de pandas
    df = pd.read_csv(csv_filename)

    # Limpieza y preparación de datos
    # Análisis de datos
    # Visualización de datos
    # Agregar excepciones
    # Interpretación de resultados sobre README.md
    # Documentación y presentación: código

else:
    print("No se encontró ningún archivo CSV en la descarga."
          "Saliendo del programa...")
    exit()  # Salir del programa
