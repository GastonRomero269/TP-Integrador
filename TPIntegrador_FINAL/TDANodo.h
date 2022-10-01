#ifndef TDANODO_H_INCLUDED
#define TDANODO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef void* PtrDato;

typedef struct Nodo
{
    PtrDato dato;
    struct Nodo* sgte;
} Nodo;
typedef Nodo* PtrNodo;

const void* SinNodoSgte;

// Operación de construccion (constructor)
// Precondición: El nodo no debe haberse creado
// Postcondición: Se crea el nodo con null en PtrDato y SinNodoSgte en sgte
// Parámetros:
//  Ninguno
// Devuelve puntero al nodo creado
PtrNodo crearNodo(PtrDato dato);

// Operación de destruccion (destructor)
// Precondición: El nodo debe haberse creado
// Postcondición: Se Libera la memoria del nodo eliminado
// Parámetros:
//  puntero al nodo a eliminar
// Devuelve NULL
PtrNodo destruirNodo(PtrNodo nodo);

// Operación de establecimiento de datos
// Precondición: nodo creado con crearNodo()
// Postcondición: almacena el dato proporcionado en el nodo apuntado por ptrNodo.
// Parámetros:
//  ptrNodo: puntero al nodo
//  PtrDato: Puntero al dato a almacenar
// No devuelve valor
void setDato(PtrNodo nodo,PtrDato dato);

// Operación de obtención de datos
// Precondición: nodo creado con crearNodo()
// Postcondición: obtiene el dato almacenado en el nodo apuntado por ptrNodo.
// Parámetros:
//  ptrNodo: puntero al nodo
// Devuelve puntero al dato almacenado
PtrDato getDato(PtrNodo nodo);

// Operación de establecimiento del siguiente nodo
// Precondición: esteNodo creado con crearNodo()
// Postcondición: se establece el nodo siguiente al actual
// Parámetros:
//  esteNodo: puntero al nodo
// No devuelve valor
void setSiguiente(PtrNodo esteNodo,PtrNodo siguienteNodo);

// Operación de obtención del siguiente nodo
// Precondición: esteNodo creado con crearNodo()
// Postcondición: se obtiene el nodo siguiente al actual
// Parámetros:
//  nodo: puntero al nodo
// No devuelve valor
PtrNodo getSiguiente(PtrNodo nodo);

#endif // TDANODO_H_INCLUDED
