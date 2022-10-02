#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/**
****************************************************************************************************************
                                                INTERFAZ DE ARCHIVOS
****************************************************************************************************************/

//                                                  OPERACIONES


///                                                  Escritura


/// Para datos individuales
//  Se pueden pensar como un portapapeles.

//OPERACIÓN: Guarda un AAA en un archivo dedicado
//PRECONDICIÓN: La variable AAAPtr que se pase deberá haber sido creada previamente con crearA.
//POSTCONDICIÓN: se copian los contenidos de la estructura AAAPtr en una estructura estática interna "fAAA",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS:
//  Puntero a la estructura AAA dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarCuil(CuilPtr cuil);
//OPERACIÓN: Guarda un BBB en un archivo dedicado
//PRECONDICIÓN: La variable BBBPtr que se pase deberá haber sido creada previamente con crearB.
//POSTCONDICIÓN: se copian los contenidos de la estructura BBBPtr en una estructura estática interna "fBBB",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS:
//  Puntero a la estructura BBB dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarDomicilio(DomicilioPtr domicilio);
//OPERACIÓN: Guarda una CCC en un archivo dedicado
//PRECONDICIÓN: La variable CCCPtr que se pase deberá haber sido creada previamente con crearCCC.
//POSTCONDICIÓN: se copian los contenidos de la estructura CCCPtr en una estructura estática interna "fCCC",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS:
//  Puntero a la estructura CCC dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarFecha(FechaPtr fecha);
//OPERACIÓN: Guarda una DDD en un archivo dedicado
//PRECONDICIÓN: La variable DDDPtr que se pase deberá haber sido creada previamente con crearDDD.
//POSTCONDICIÓN: se copian los contenidos de la estructura DDDPtr en una estructura estática interna "fDDD",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS:
//  Puntero a la estructura DDD dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarPersona(PersonaPtr persona);
//OPERACIÓN: Guarda una EEE en un archivo dedicado
//PRECONDICIÓN: La variable EEEPtr que se pase deberá haber sido creada previamente con crearEEE.
//POSTCONDICIÓN: se copian los contenidos de la estructura EEEPtr en una estructura estática interna "fEEE",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS:
//  Puntero a la estructura EEE dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarPaquete(PaquetePtr paquete);
//OPERACIÓN: Guarda una FFF en un archivo dedicado
//PRECONDICIÓN: La variable FFFPtr que se pase deberá haber sido creada previamente con crearFFF.
//POSTCONDICIÓN: se copian los contenidos de la estructura FFFPtr en una estructura estática interna "fFFF",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS:
//  Puntero a la estructura FFF dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarVehiculo(VehiculoPtr vehiculo);
//OPERACIÓN: Guarda una GGG en un archivo dedicado
//PRECONDICIÓN: La variable GGGPtr que se pase deberá haber sido creada previamente con crearGGG.
//POSTCONDICIÓN: se copian los contenidos de la estructura GGGPtr en una estructura estática interna "fGGG",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS:
//  Puntero a la estructura GGG dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarReparto(RepartoPtr reparto);


///---------------------------------------------------------------------------------------------------------------

/// Para conjuntos de datos - Para guardar bases de datos de structs por defecto.
//  Dedicadas a las funciones de creación de datos por defecto de test.h.

//OPERACIÓN: Guarda un conjunto de AAAs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS:
//  cuils: PUNTERO A PUNTERO A la estructura AAA (Doble puntero). Se puede pensar como un vector de AAAs
//  cantidad: entero representando la cantidad de AAAs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrio un error
bool guardarCuils(CuilPtr *cuils,int cantidad);
//OPERACIÓN: Guarda un conjunto de BBBs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS:
//  cuils: PUNTERO A PUNTERO A la estructura BBB (Doble puntero). Se puede pensar como un vector de BBBs
//  cantidad: entero representando la cantidad de BBBs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrio un error
bool guardarDomicilios(DomicilioPtr *domicilios,int cantidad);
//OPERACIÓN: Guarda un conjunto de CCCs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS:
//  cuils: PUNTERO A PUNTERO A la estructura CCC (Doble puntero). Se puede pensar como un vector de CCCs
//  cantidad: entero representando la cantidad de CCCs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrio un error
bool guardarFechas(FechaPtr *fechas,int cantidad);
//OPERACIÓN: Guarda un conjunto de DDDs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS:
//  cuils: PUNTERO A PUNTERO A la estructura DDD (Doble puntero). Se puede pensar como un vector de DDDs
//  cantidad: entero representando la cantidad de DDDs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrio un error
bool guardarPersonas(PersonaPtr *personas,int cantidad);
//OPERACIÓN: Guarda un conjunto de EEEs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS:
//  cuils: PUNTERO A PUNTERO A la estructura EEE (Doble puntero). Se puede pensar como un vector de EEEs
//  cantidad: entero representando la cantidad de EEEs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrio un error
bool guardarPaquetes(PaquetePtr *paquetes,int cantidad);
//OPERACIÓN: Guarda un conjunto de FFFs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS:
//  cuils: PUNTERO A PUNTERO A la estructura FFF (Doble puntero). Se puede pensar como un vector de FFFs
//  cantidad: entero representando la cantidad de FFFs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrio un error
bool guardarVehiculos(VehiculoPtr *vehiculos,int cantidad);
//OPERACIÓN: Guarda un conjunto de GGGs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS:
//  cuils: PUNTERO A PUNTERO A la estructura GGG (Doble puntero). Se puede pensar como un vector de GGGs
//  cantidad: entero representando la cantidad de GGGs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrio un error
bool guardarRepartos(RepartoPtr *repartos,int cantidad);


///---------------------------------------------------------------------------------------------------------------

/// Para listas de datos - Centro Logístico

//  conjuntos de datos / estructuras    -   Para guardar bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  String representando el nombre de la persona(Cliente o chofer)
//  String representando el apellido de la persona(Cliente o chofer)
//  Estructura DomicilioPtr representando el destino
//                  String representando la calle del domicilio
//                  Entero representando la altura del domicilio
//                  String representando la localidad del domicilio
//  Estructura CuilPtr
//                  String representando el cuil/cuit(TIPO DNI VERIFICACION)
//  Entero representando la cantidad a guardar en el archivo correspondiente (Listas de personas.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos procedentes del centroLogisticoPtr de la lista de personas
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool guardarListaPersonas(CentroLogisticoPtr centroLogistico);
//  conjuntos de datos / estructuras    -   Para guardar bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Entero representando el id representativo del paquete
//  Entero representando el ancho del paquete en metros
//  Entero representando el alto del paquete en metros
//  Entero representando el largo del paquete en metros
//  Entero representando el peso del paquete en kilos
//  Estructura DomicilioPtr representando el destino
//                  String representando la calle del domicilio
//                  Entero representando la altura del domicilio
//                  String representando la localidad del domicilio
//  Estructura FechaPtr
//          Entero representando un dia juliano convertido anteriormente con dia, mes, anio
//          Entero representando la hora de la fecha correspondiente
//          Entero representando los minutos de la fecha correspondiente
//  Entero representando 0=Deposito 1=En curso 2=Retirado 3=Entregado 4=Demorado 5=suspendido
//  Entero representando la cantidad a guardar en el archivo correspondiente (Listas de paquetes.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos procedentes del centroLogisticoPtr de la lista de paquetes
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool guardarListaPaquetes(CentroLogisticoPtr centroLogistico);
//  conjuntos de datos / estructuras    -   Para guardar bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Entero representando el tipo del vehiculo 1=Moto 2=Auto 3=Camion
//  String representando la marca del vehiculo
//  String representando el modelo del vehiculo
//  String representando la patente del vehiculo
//  Entero representando la cantidad a guardar en el archivo correspondiente (Listas de vehiculos.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos procedentes del centroLogisticoPtr de la lista de vehiculos
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool guardarListaVehiculos(CentroLogisticoPtr centroLogistico);
//  conjuntos de datos / estructuras    -   Para guardar bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Estructura PersonaPtr representando al chofer
//  Estructura VehiculoPtr representando el transporte que se utilizara
//  Estructura FechaPtr representando la fecha de salida
//  Estructura FechaPtr representando la fecha de retorno
//  Estructura de pila representando la cantidad de paquetes que tiene el reparto asignado
//  Entero representando la cantidad a guardar en el archivo correspondiente (Listas de repartos.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos procedentes del centroLogisticoPtr de la lista de repartos
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool guardarListaRepartos(CentroLogisticoPtr centroLogistico);
//  conjuntos de datos / estructuras    -   Para guardar bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  String representando el nombre del centroLogistico
//  Estructura ListaClientes representando a las clientes totales
//  Estructura ListaRepartos representando a los repartos totales
//  Estructura ListaChoferes representando a los choferes totales
//  Estructura ListaPaquetes representando a los paquetes totales
//  Estructura de pila representando la cantidad de paquetes que tiene el reparto asignado
//  Entero representando la cantidad a guardar en el archivo correspondiente (Listas de repartos.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos procedentes del centroLogisticoPtr
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool guardarTodo(CentroLogisticoPtr centroLogistico); //implementacion: llamará a las otras funciones de guardado



//Lectura - Se reutilizan las estructuras creadas en main.c
//PRECONDICIÓN: La variable estructura / lista que se pase deberá haber sido creada previamente,
//              y debe haberse vaciado con su funcion destructora.
//POSTCONDICIÓN: se llena la estructura / lista con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  datos / estructuras individuales

//Lectura - Se reutilizan las estructuras CuilPtr creadas en main.c
//PRECONDICIÓN: La variable CuilPtr que se pase deberá haber sido creada previamente con crearCuil,
//              y debe haberse vaciado con su funcion destructora destruirCuil.
//POSTCONDICIÓN: se llena el CuilPtr con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  String representando el cuil/cuit correspondiente
bool abrirCuil(CuilPtr cuil);
//Lectura - Se reutilizan las estructuras DomicilioPtr creadas en main.c
//PRECONDICIÓN: La variable CuilPtr que se pase deberá haber sido creada previamente con crearDomicilio,
//              y debe haberse vaciado con su funcion destructora destruirDomciilio.
//POSTCONDICIÓN: se llena el DomicilioPtr con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  String representando la calle del domicilio
//  Entero representando la altura de la calle
//  String representando la localidad de la dirección
bool abrirDomicilio(DomicilioPtr domicilio);
//Lectura - Se reutilizan las estructuras DomicilioPtr creadas en main.c
//PRECONDICIÓN: La variable FechaPtr que se pase deberá haber sido creada previamente con crearFecha,
//              y debe haberse vaciado con su funcion destructora destruirFecha.
//POSTCONDICIÓN: se llena el FechaPtr con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  Entero representando un dia juliano convertido anteriormente con dia, mes, anio
//  Entero representando la hora de la fecha correspondiente
//  Entero representando los minutos de la fecha correspondiente
bool abrirFecha(FechaPtr fecha);
//Lectura - Se reutilizan las estructuras PersonaPtr creadas en main.c
//PRECONDICIÓN: La variable FechaPtr que se pase deberá haber sido creada previamente con crearPersona,
//              y debe haberse vaciado con su funcion destructora destruirPersona.
//POSTCONDICIÓN: se llena el PersonaPtr con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  String representando el nombre de la persona(Cliente o chofer)
//  String representando el apellido de la persona(Cliente o chofer)
//  Estructura DomicilioPtr representando el destino
//                  String representando la calle del domicilio
//                  Entero representando la altura del domicilio
//                  String representando la localidad del domicilio
//  Estructura CuilPtr
//                  String representando el cuil/cuit(TIPO DNI VERIFICACION)
bool abrirPersona(PersonaPtr persona);
//Lectura - Se reutilizan las estructuras PersonaPtr creadas en main.c
//PRECONDICIÓN: La variable PaquetePtr que se pase deberá haber sido creada previamente con crearPaquete,
//              y debe haberse vaciado con su funcion destructora destruirPaquete.
//POSTCONDICIÓN: se llena el PaquetePtr con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  Entero representando el id representativo del paquete
//  Entero representando el ancho del paquete en metros
//  Entero representando el alto del paquete en metros
//  Entero representando el largo del paquete en metros
//  Entero representando el peso del paquete en kilos
//  Estructura DomicilioPtr representando el destino
//                  String representando la calle del domicilio
//                  Entero representando la altura del domicilio
//                  String representando la localidad del domicilio
//  Estructura FechaPtr
//          Entero representando un dia juliano convertido anteriormente con dia, mes, anio
//          Entero representando la hora de la fecha correspondiente
//          Entero representando los minutos de la fecha correspondiente
//  Entero representando 0=Deposito 1=En curso 2=Retirado 3=Entregado 4=Demorado 5=suspendido
bool abrirPaquete(PaquetePtr paquete);
//Lectura - Se reutilizan las estructuras VehiculoPtr creadas en main.c
//PRECONDICIÓN: La variable FechaPtr que se pase deberá haber sido creada previamente con crearVehiculo,
//              y debe haberse vaciado con su funcion destructora destruirVehiculo.
//POSTCONDICIÓN: se llena el VehiculoPtr con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  Entero representando el tipo del vehiculo 1=Moto 2=Auto 3=Camion
//  String representando la marca del vehiculo
//  String representando el modelo del vehiculo
//  String representando la patente del vehiculo
bool abrirVehiculo(VehiculoPtr vehiculo);
//Lectura - Se reutilizan las estructuras RepartoPtr creadas en main.c
//PRECONDICIÓN: La variable FechaPtr que se pase deberá haber sido creada previamente con crearReparto,
//              y debe haberse vaciado con su funcion destructora destruirReparto.
//POSTCONDICIÓN: se llena el RepartoPtr con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  Estructura PersonaPtr representando al chofer
//  Estructura VehiculoPtr representando el transporte que se utilizara
//  Estructura FechaPtr representando la fecha de salida
//  Estructura FechaPtr representando la fecha de retorno
//  Estructura de pila representando la cantidad de paquetes que tiene el reparto asignado
bool abrirReparto(RepartoPtr reparto);


///Función de lectura
//  conjuntos de datos / estructuras    -   Para abrir bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  String representando el cuil/cuit correspondiente
//  Puntero a la estructura puntero CuilPtr
//  Entero representando la cantidad a leer en el archivo correspondiente (Cuils por Defecto.txt)
//PRECONDICIÓN: CuilPtr *cuils debe haber sido creado con memoria dinamica y la funcion crearCuil previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//     cantidad: de elementos a leer.
//      Puntero a la estructura puntero cuilPtr
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirCuils(CuilPtr *cuils);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  String representando la calle del domicilio
//  Entero representando la altura de la calle
//  String representando la localidad de la dirección
//  Entero representando la cantidad a leer en el archivo correspondiente (Domicilios por Defecto.txt)
//PRECONDICIÓN: DomciilioPtr *domicilios debe haber sido creado con memoria dinamica y la funcion crearDomicilio previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//     cantidad: de elementos a leer.
//      Puntero a la estructura puntero cuilPtr
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirDomicilios(DomicilioPtr *domicilios);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Entero representando un dia juliano convertido anteriormente con dia, mes, anio
//  Entero representando la hora de la fecha correspondiente
//  Entero representando los minutos de la fecha correspondiente
//  Entero representando la cantidad a leer en el archivo correspondiente (Fechas por Defecto.txt)
//PRECONDICIÓN: FechaPtr *fechas debe haber sido creado con memoria dinamica y la funcion crearFecha previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//     cantidad: de elementos a leer.
//      Puntero a la estructura puntero FechaPtr
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirFechas(FechaPtr *fechas);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  String representando el nombre de la persona(Cliente o chofer)
//  String representando el apellido de la persona(Cliente o chofer)
//  Estructura DomicilioPtr representando el destino
//                  String representando la calle del domicilio
//                  Entero representando la altura del domicilio
//                  String representando la localidad del domicilio
//  Estructura CuilPtr
//                  String representando el cuil/cuit(TIPO DNI VERIFICACION)
//  Entero representando la cantidad a leer en el archivo correspondiente (Personas por Defecto.txt)
//PRECONDICIÓN: PersonaPtr *fechas debe haber sido creado con memoria dinamica y la funcion crearPersona previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//     cantidad: de elementos a leer.
//      Puntero a la estructura puntero PersonaPtr
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirPersonas(PersonaPtr *personas);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Entero representando el id representativo del paquete
//  Entero representando el ancho del paquete en metros
//  Entero representando el alto del paquete en metros
//  Entero representando el largo del paquete en metros
//  Entero representando el peso del paquete en kilos
//  Estructura DomicilioPtr representando el destino
//                  String representando la calle del domicilio
//                  Entero representando la altura del domicilio
//                  String representando la localidad del domicilio
//  Estructura FechaPtr
//          Entero representando un dia juliano convertido anteriormente con dia, mes, anio
//          Entero representando la hora de la fecha correspondiente
//          Entero representando los minutos de la fecha correspondiente
//  Entero representando 0=Deposito 1=En curso 2=Retirado 3=Entregado 4=Demorado 5=suspendido
//  Entero representando la cantidad a leer en el archivo correspondiente (Paquetes por Defecto.txt)
//PRECONDICIÓN: PersonaPtr *fechas debe haber sido creado con memoria dinamica y la funcion crearPaquete previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//     cantidad: de elementos a leer.
//      Puntero a la estructura puntero PaquetePtr
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirPaquetes(PaquetePtr *paquetes);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Entero representando el tipo del vehiculo 1=Moto 2=Auto 3=Camion
//  String representando la marca del vehiculo
//  String representando el modelo del vehiculo
//  String representando la patente del vehiculo
//  Entero representando la cantidad a leer en el archivo correspondiente (Vehiculos por Defecto.txt)
//PRECONDICIÓN: VehiculoPtr *vehiculos debe haber sido creado con memoria dinamica y la funcion crearVehiculo previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//     cantidad: de elementos a leer.
//      Puntero a la estructura puntero VehiculoPtr
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirVehiculos(VehiculoPtr *vehiculos);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Estructura PersonaPtr representando al chofer
//  Estructura VehiculoPtr representando el transporte que se utilizara
//  Estructura FechaPtr representando la fecha de salida
//  Estructura FechaPtr representando la fecha de retorno
//  Estructura de pila representando la cantidad de paquetes que tiene el reparto asignado
//  Entero representando la cantidad a leer en el archivo correspondiente (Repartos por Defecto.txt)
//PRECONDICIÓN: RepartoPtr *vehiculos debe haber sido creado con memoria dinamica y la funcion crearReparto previamente
//POSTCONDICIÓN: Registra dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//     cantidad: de elementos a leer.
//      Puntero a la estructura puntero RepartoPtr
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirRepartos(RepartoPtr *repartos);


///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  String representando el nombre de la persona(Cliente o chofer)
//  String representando el apellido de la persona(Cliente o chofer)
//  Estructura DomicilioPtr representando el destino
//                  String representando la calle del domicilio
//                  Entero representando la altura del domicilio
//                  String representando la localidad del domicilio
//  Estructura CuilPtr
//                  String representando el cuil/cuit(TIPO DNI VERIFICACION)
//  Entero representando la cantidad a leer en el archivo correspondiente (Listas de personas.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Lee dentro del archivo los datos procedentes del centroLogisticoPtr de la lista de personas
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirListaPersonas(CentroLogisticoPtr centroLogistico);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Entero representando el id representativo del paquete
//  Entero representando el ancho del paquete en metros
//  Entero representando el alto del paquete en metros
//  Entero representando el largo del paquete en metros
//  Entero representando el peso del paquete en kilos
//  Estructura DomicilioPtr representando el destino
//                  String representando la calle del domicilio
//                  Entero representando la altura del domicilio
//                  String representando la localidad del domicilio
//  Estructura FechaPtr
//          Entero representando un dia juliano convertido anteriormente con dia, mes, anio
//          Entero representando la hora de la fecha correspondiente
//          Entero representando los minutos de la fecha correspondiente
//  Entero representando 0=Deposito 1=En curso 2=Retirado 3=Entregado 4=Demorado 5=suspendido
//  Entero representando la cantidad a leer en el archivo correspondiente (Listas de paquetes.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Lee dentro del archivo los datos procedentes del centroLogisticoPtr de la lista de paquetes
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirListaPaquetes(CentroLogisticoPtr centroLogistico);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Entero representando el tipo del vehiculo 1=Moto 2=Auto 3=Camion
//  String representando la marca del vehiculo
//  String representando el modelo del vehiculo
//  String representando la patente del vehiculo
//  Entero representando la cantidad a leer en el archivo correspondiente (Listas de vehiculos.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Lee dentro del archivo los datos procedentes del centroLogisticoPtr de la lista de vehiculos
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirListaVehiculos(CentroLogisticoPtr centroLogistico);
///Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  Estructura PersonaPtr representando al chofer
//  Estructura VehiculoPtr representando el transporte que se utilizara
//  Estructura FechaPtr representando la fecha de salida
//  Estructura FechaPtr representando la fecha de retorno
//  Estructura de pila representando la cantidad de paquetes que tiene el reparto asignado
//  Entero representando la cantidad a leer en el archivo correspondiente (Listas de repartos.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Lee dentro del archivo los datos procedentes del centroLogisticoPtr de la lista de repartos
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
bool abrirListaRepartos(CentroLogisticoPtr centroLogistico);


///  General
///Crea un centro logistico y lo llena de datos de los distintos archivos del proyecto.
//abrirListaPersonas
//abrirListaPaquetes
//abrirListaVehiculos
//abrirListaRepartos
///RETORNA CENTROLOGISTICO O NULL SI HUBO ALGUN ERROR

//Función de lectura
//  conjuntos de datos / estructuras    -   Para leer bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//  String representando el nombre del centroLogistico
//  Estructura ListaClientes representando a las clientes totales
//  Estructura ListaRepartos representando a los repartos totales
//  Estructura ListaChoferes representando a los choferes totales
//  Estructura ListaPaquetes representando a los paquetes totales
//  Estructura de pila representando la cantidad de paquetes que tiene el reparto asignado
//  Entero representando la cantidad a leer en el archivo correspondiente (Listas de repartos.txt)
//PRECONDICIÓN: CentroLogisticoPtr centroLogistico debe haber sido creado con memoria dinamica y la funcion crearCentroLogistico previamente
//POSTCONDICIÓN: Lee dentro del archivo los datos procedentes del centroLogisticoPtr
//PARÁMETROS
//      Puntero a la estructura centroLogistico
//DEVUELVE verdadero si se guardo correctamente, falso si ocurrio un error
CentroLogisticoPtr abrirTodo();



///*************************************************************************************************************


///                                         Especiales - Ayudantes

// Función para leer líneas de texto terminadas con un
// caracter determinado
//abrirListaPaquetes
int LeerString(FILE *archivo,char *buffer, int longitudMax, char terminador);


#endif // FILES_H_INCLUDED
