#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void *obtenerMemoria(size_t tamanio);
char *crearStringDinamico(char* literal);
void destruirStringDinamico(char *buffer);
void limpiarBufferTeclado();
void presionarEnterYLimpiarPantalla();

///Esto es una prueba

#endif // UTIL_H_INCLUDED
