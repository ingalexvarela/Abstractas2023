/**
 * @file campus_facio.hpp
 *
 * @brief Este código define varias clases que representan diferentes elementos de un campus universitario, como aulas, edificios de aulas, edificios de parqueo, facultades y fincas.
 *
 Las clases definidas en el código son las siguientes:
 Aula: representa un aula en un campus universitario.
EdificioAulas: Clase que representa un edificio de aulas en un campus universitario.
EdificioParqueo: Clase que representa un edificio de parqueo en un campus universitario.
Facultad: Clase que representa una facultad en un campus universitario.
Finca: Clase que representa una finca en un campus universitario.
Campus: Clase que representa un campus universitario.
 *
 * Este archivo encabezado que forma parte del proyecto "Campus" utiliza la licencia Creative Commons Legal Code CC0 1.0 Universal.
 *
 * @license
 * Creative Commons Legal Code CC0 1.0 Universal
 * Consulta la licencia para más detalles: https://creativecommons.org/publicdomain/zero/1.0/
 *
 * @author Alex Varela
 * @date 17 de abril de 2023
 */

#ifndef CAMPUS_FACIO_H
#define CAMPUS_FACIO_H

#include <string>
#include <vector>
/**
 * @class Aula
 * @brief Clase que representa un aula en un campus universitario.
 */
class Aula
{
public:
    /**
     * @brief Constructor de la clase Aula.
     * @param nombre Nombre del aula.
     * @param cantidadPupitres Cantidad de pupitres en el aula.
     * @param tieneProyector Indica si el aula tiene proyector o no.
     * @param aulaenPiso Ubicacion del aula en un piso.
     */
    Aula(const std::string &nombre, int cantidadPupitres, bool tieneProyector, int aulaenPiso);
    /**
     * @brief Imprime la información del aula en la consola.
     */
    void imprimirInformacion() const;

private:
    std::string nombre_;
    int cantidad_pupitres_;
    bool tieneProyector_;
    int aula_id_;
    int piso_;

    /**
     * @brief Genera un ID único para el aula.
     * @return ID generado.
     */
    int generarID();
};
/**
 * @class EdificioAulas
 * @brief Clase que representa un edificio de aulas en un campus universitario.
 */
class EdificioAulas
{
public:
    /**
     * @brief Constructor de la clase EdificioAulas.
     * @param nombre Nombre del edificio de aulas.
     * @param tieneAscensor Indica si el edificio tiene ascensor o no.
     * @param tieneSoda Indica si el edificio tiene soda o no.
     * @param numeroPiso Indica el número de pisos del edificio de aulas.
     */
    EdificioAulas(const std::string &nombre, bool tieneAscensor, bool tieneSoda, int numeroPiso);
    /**
     * @brief Agrega un aula al edificio.
     * @param aula Aula a agregar.
     */
    void agregarAula(const Aula &aula);
    /**
     * @brief Imprime la información del edificio de aulas en la consola.
     */
    void imprimirInformacion() const;

private:
    std::string nombre_;
    std::vector<Aula> aulas_;
    bool tiene_ascensor_;
    bool tiene_soda_;
    int numero_piso_;
};

/**
 * @class EdificioParqueo
 * @brief Clase que representa un edificio de parqueo en un campus universitario.
 */
class EdificioParqueo
{
public:
    /**
     * @brief Constructor de la clase EdificioParqueo.
     * @param nombre Nombre del edificio de parqueo.
     * @param capacidad Capacidad de estacionamiento del edificio de parqueo.
     * @param tieneAscensor Indica si el edificio de parqueo tiene ascensor o no.
     * @param numeroPisoParqueo Indica el número de pisos del edificio de parqueo.
     */
    EdificioParqueo(const std::string &nombre, int capacidad, bool tieneAscensor, int numeroPisoParqueo)
        : nombre_(nombre), capacidad_(capacidad), tiene_ascensor_(tieneAscensor), numero_piso_parqueo(numeroPisoParqueo)
    {
    }
    /**
     * @brief Imprime la información del edificio de parqueo en la consola.
     */
    void imprimirInformacion() const;

private:
    std::string nombre_;
    int capacidad_;
    bool tiene_ascensor_;
    int numero_piso_parqueo;
};
/**
 * @class Facultad
 * @brief Clase que representa una facultad en un campus universitario.
 */
class Facultad
{
public:
    /**
     * @brief Constructor de la clase Facultad.
     * @param nombre El nombre de la facultad.
     */
    Facultad(const std::string &nombre) : nombre_(nombre) {}
    /**
     * @brief Agrega un edificio de aulas a la facultad.
     * @param edificio El edificio de aulas a agregar.
     */
    void agregarEdificioAulas(const EdificioAulas &edificio);
    /**
     * @brief Agrega un edificio de parqueo a la facultad.
     * @param edificio El edificio de parqueo a agregar.
     */
    void agregarEdificioParqueo(const EdificioParqueo &edificio);
    /**
     * @brief Imprime la información de la facultad.
     */
    void imprimirInformacion() const;

private:
    std::string nombre_;
    std::vector<EdificioAulas> edificiosAulas_;
    std::vector<EdificioParqueo> edificiosParqueo_;
};
/**
 * @class Finca
 * @brief Clase que representa una finca en un campus universitario.
 */
class Finca
{
public:
    /**
     * @brief Constructor de la clase Finca.
     * @param nombre El nombre de la finca.
     * @param pasaBus Indica si la finca está en una ruta de transporte público.
     */
    Finca(const std::string &nombre, bool pasaBus) : nombre_(nombre), pasa_bus_(pasaBus) {}
    /**
     * @brief Agrega una facultad a la finca.
     * @param facultad La facultad a agregar.
     */
    void agregarFacultad(const Facultad &facultad);
    /**
     * @brief Obtiene el nombre de la finca.
     * @return El nombre de la finca.
     */
    std::string getNombre() const;
    /**
     * @brief Imprime la información de la finca.
     */
    void imprimirInformacion() const;

private:
    std::string nombre_;
    std::vector<Facultad> facultades_;
    bool pasa_bus_;
};
/**
 * @class Campus
 * @brief Clase que representa un campus universitario.
 */
class Campus
{
public:
    /**
     * @brief Constructor de la clase Campus.
     * @param nombre El nombre del campus.
     */
    Campus(const std::string &nombre) : nombre_(nombre) {}
    /**
     * @brief Agrega una finca al campus.
     * @param finca La finca a agregar.
     */
    void agregarFinca(const Finca &finca);
    /**
     * @brief Imprime la información del campus.
     */
    void imprimirInformacion() const;

private:
    std::string nombre_;
    std::vector<Finca> fincas_;
};
/**
 * @brief Imprime la información de un campus.
 * @param campus El campus del cual se desea imprimir la información.
 *
 * Esta función imprime la información de un campus, utilizando el método
 * `imprimirInformacion` de la clase Campus.
 */
void imprimirInfoCampus(Campus campus);

#endif