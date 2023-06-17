import requests
import zipfile
from io import BytesIO
import urllib3

# Deshabilitar advertencias de certificado SSL
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)


def descargar_datos(url):
    # Descargar el archivo ZIP
    zip_response = requests.get(url, verify=False)
    zip_data = BytesIO(zip_response.content)

    # Crear un objeto ZipFile a partir de los datos descargados
    zip_file = zipfile.ZipFile(zip_data)

    # Extraer el archivo CSV del ZIP
    csv_filename = None
    for file in zip_file.namelist():
        if file.endswith('.csv'):
            csv_filename = file
            zip_file.extract(file)

    return csv_filename
