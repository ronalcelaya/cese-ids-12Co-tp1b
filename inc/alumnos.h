/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdbool.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/**
 * @brief Estructura que contiene los campos para guardar los datos del alumno.
 *        Ejemplo
 * @code
 * static const struct alumno_s ALUMNO = {
 *     .apellidos = "VOLENTINI",
 *     .nombres = "Esteban Daniel",
 *     .documento = "23.517.968",
 * };
 * @endcode
 */

typedef struct alumno_s {
    char apellidos[30];   /**< Campo donde se guarda el apellido. El tamaño
                               máximo es de 30 bytes */
    char nombres[30];     /**< Campo donde se guarda el nombre. l tamaño
                               máximo es de 30 bytes */
    char documento[11];   /**< Campo donde se guarda el número de documento. 
                               El tamaño máximo es de 11 bytes */
} const * alumno_t;

/*=====[Definitions of public global variables]==============================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

/**
 * @brief Función que serializa los datos del alumno
 * 
 * @param[in,out]    cadena  Puntero donde se pasa el buffer para guardar los 
 *                           datos de salida serializados.
 * @param[in]        espacio Es el máximo número de bytes que se van a escribir 
 *                           al buffer de salida 
 * @param[in]        alumno  Estructura que contiene los datos a serializar 
 * @see alumno_s
 * @return                   Regresa true si la serializaión fue exitosa. 
 * @return                   Regresa false si hubo problemas con la serialización
 * 
 * @code 
 * bool resultado;
 * 
 * static const struct alumno_s ALUMNO = {
 *     .apellidos = "VOLENTINI",
 *     .nombres = "Esteban Daniel",
 *     .documento = "23.517.968",
 * };
 * resultado = SerializarAlumno(cadena, espacio, &ALUMNO);
 * @endcode
 */

bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno);

/**
 * @brief Función que serializa los datos de un conjunto de alumnos.
 * 
 * @param[in,out] cadena  Puntero donde se pasa el buffer para guardar los 
 *                        datos de salida serializados.
 * @param[in]     espacio Tamaño máximo del buffer para serializar los datos.
 *                        El tamaño máximo es sizeof(cadena) 
 * @return                Regresa true si la serialización fue exitosa 
 * @return                Regresa false si hubo problemas con la serialización
 * 
 * @code
 * char cadena[2048];
 * 
 * SerializarAlumnos(cadena, sizeof(cadena));
 * @endcode
 */

bool SerializarAlumnos(char * cadena, size_t espacio);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _ALUMNOS_H_ */
