#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/**
****************************************************************************************************************
                                                INTERFAZ DE ARCHIVOS
****************************************************************************************************************/

//                                                  OperaciónES


//Escritura
//Precondición: La variable estructura / lista que se pase deberá haber sido creada previamente.
//Postcondición: se guarda los contenidos de la estructura / lista en un archivo dedicado al tipo de estructura / lista.
//Devuelve true si se pudo guardar, false de lo contrario (if archivo != NULL)
//  datos / estructuras individuales
bool guardarCuil(CuilPtr cuil);
bool guardarDomicilio(DomicilioPtr domicilio);
bool guardarFecha(FechaPtr fecha);
bool guardarPersona(PersonaPtr persona);
bool guardarPaquete(PaquetePtr paquete);
bool guardarVehiculo(VehiculoPtr vehiculo);
bool guardarReparto(RepartoPtr reparto);
//  conjuntos de datos / estructuras    -   Para guardar bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
//Postcondición: LA CANTIDAD QUE ELEMENTOS QUE DEVUELVE DEBE TENERSE EN CUENTA AL USAR LAS CONTRAPARTES DE APERTURA
//Parámetros
//     cantidad: de elementos a guardar.
//DEVUELVE CANTIDAD DE ELEMENTOS GUARDADOS
bool guardarCuils(CuilPtr *cuils,int cantidad);
bool guardarDomicilios(DomicilioPtr *domicilios,int cantidad);
bool guardarFechas(FechaPtr *fechas,int cantidad);
bool guardarPersonas(PersonaPtr *personas,int cantidad);
bool guardarPaquetes(PaquetePtr *paquetes,int cantidad);
bool guardarVehiculos(VehiculoPtr *vehiculos,int cantidad);
bool guardarRepartos(RepartoPtr *repartos,int cantidad);
//  listas de datos / estructuras
bool guardarListaPersonas(CentroLogisticoPtr centroLogistico);
bool guardarListaPaquetes(CentroLogisticoPtr centroLogistico);
bool guardarListaVehiculos(CentroLogisticoPtr centroLogistico);
bool guardarListaRepartos(CentroLogisticoPtr centroLogistico);
//  general
bool guardarTodo(CentroLogisticoPtr centroLogistico); //implementacion: llamará a las otras funciones de guardado



//Lectura - Se reutilizan las estructuras creadas en main.c
//Precondición: La variable estructura / lista que se pase deberá haber sido creada previamente,
//              y debe haberse vaciado con su funcion destructora.
//Postcondición: se llena la estructura / lista con los contenidos del archivo
//Devuelve true si se pudo abrir, false de lo contrario (if archivo != NULL)
//  datos / estructuras individuales

bool abrirCuil(CuilPtr cuil);
bool abrirDomicilio(DomicilioPtr domicilio);
bool abrirFecha(FechaPtr fecha);
bool abrirPersona(PersonaPtr persona);
bool abrirPaquete(PaquetePtr paquete);
bool abrirVehiculo(VehiculoPtr vehiculo);
bool abrirReparto(RepartoPtr reparto);
//  conjuntos de datos / estructuras    -   Para abrir bases de datos de structs por defecto. Nos servirá para las funciones de creacion de datos por defecto.
bool abrirCuils(CuilPtr *cuils);
bool abrirDomicilios(DomicilioPtr *domicilios);
bool abrirFechas(FechaPtr *fechas);
bool abrirPersonas(PersonaPtr *personas);
bool abrirPaquetes(PaquetePtr *paquetes);
bool abrirVehiculos(VehiculoPtr *vehiculos);
bool abrirRepartos(RepartoPtr *repartos);
//  conjuntos de datos / estructuras
bool abrirListaPersonas(CentroLogisticoPtr centroLogistico);
bool abrirListaPaquetes(CentroLogisticoPtr centroLogistico);
bool abrirListaVehiculos(CentroLogisticoPtr centroLogistico);
bool abrirListaRepartos(CentroLogisticoPtr centroLogistico);
//  general
///Crea un centro logistico y lo llena de datos de los distintos archivos del proyecto.
//Llama a las funciones de abrirLista
///RETORNA CENTROLOGISTICO O NULL SI HUBO ALGUN ERROR
CentroLogisticoPtr abrirTodo();



///*************************************************************************************************************


///                                         Especiales - Ayudantes

// Función para leer líneas de texto terminadas con un
// caracter determinado
int LeerString(FILE *archivo,char *buffer, int longitudMax, char terminador);


#endif // FILES_H_INCLUDED
