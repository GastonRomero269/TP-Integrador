#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "Lista.h"
#include "Pila.h"
#include "TDACentroLogistico.h"
#include "TDACuil.h"
#include "TDADomicilio.h"
#include "TDAFechaYHora.h"
#include "TDANodo.h"
#include "TDAPaquetes.h"
#include "TDAPersona.h"
#include "TDARepartos.h"
#include "TDAVehiculo.h"
#include "test.h"
#include "util.h"

VehiculoPtr crearVehiculoPorDefecto() ///Crea un vehículo de forma rápida con datos predeterminados.
{
    VehiculoPtr vehiculo=crearVehiculo(3,"Mercedes-Benz","Actros","ZZ 999 ZZ");
    return vehiculo;
}
VehiculoPtr crearVehiculoGenerico() ///Crea un vehículo de forma rápida con datos aleatorios.
{
/*
NOTA: En esta version, simplifiqué el funcionamiento para que sea más facil de entender.

Qué quiero que pase?
    1. Se elige un tipo y una marca de vehiculo al azar.
    2. Según la marca y el tipo, se elige un modelo.
    3. Para la patente, se eligen letras y numeros al azar y se ponen en un string con sprintf().

Tips:
    -Solo saldrán marcas y modelos de vehiculos que tengan el tipo que tocó.
    -Solo saldrán modelos de vehiculos que sean de una determinada marca.

Fórmula para calcular un numero aleatorio entre dos límites determinados:
    int res=(rand()% (superior-inferior+1)) + inferior);
*/

    VehiculoPtr vehiculo=(VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));

    char **marca=(char**)obtenerMemoria((sizeof(char)*14)*10); //14 para el string + largo, 10 por la cantidad de strings.
    marca[0]="Toyota"; //tiene todos los tipos.
    marca[1]="Mercedes-Benz"; //no tiene moto.
    marca[2]="Kia"; //no tiene moto.
    marca[3]="Ford"; //no tiene moto.
    marca[4]="Chevrolet"; //no tiene moto.
    marca[5]="Fiat"; //solo autos.
    marca[6]="Yamaha"; //solo motos.
    marca[7]="Ducati"; //solo motos.
    marca[8]="Volkswagen"; //no tiene moto.
    marca[9]="Citroen"; //solo autos.

    char **modelo=(char**)obtenerMemoria((sizeof(char)*29)*30); //29 para el string + largo, 30 por la cantidad de modelos.
//Toyota
    modelo[0]="Profia FR1AWHG"; //camion
    modelo[1]="Corolla"; //auto
    modelo[2]="TZF 450"; //moto
//Mercedes-Benz
    modelo[3]="Actros"; //camion
    modelo[4]="S600"; //auto
    modelo[5]="EQC"; //auto
//Kia
    modelo[6]="K3000"; //camion
    modelo[7]="Rio"; //auto
    modelo[8]="Sportage 2018 Facelift"; //auto
//Ford
    modelo[9]="FMax"; //camion
    modelo[10]="Fiesta"; //auto
    modelo[11]="EcoSport"; //auto
//Chevrolet
    modelo[12]="Corsa"; //auto
    modelo[13]="FVZ 34T"; //camion
    modelo[14]="Colorado"; //camion
//Fiat
    modelo[15]="Cronos"; //auto
    modelo[16]="Toro"; //auto
    modelo[17]="500"; //auto
//Yamaha
    modelo[18]="R125"; //moto
    modelo[19]="FZ6R"; //moto
    modelo[20]="Niken"; //moto
//Ducati
    modelo[21]="Monster 1200R"; //moto
    modelo[22]="1198S"; //moto
    modelo[23]="Streetfighter V4 2020"; //moto
//Volkswagen
    modelo[24]="Golf"; //auto
    modelo[25]="Amarok"; //auto
    modelo[26]="Constellation 26420 V-Tronic"; //camion
//Citroen
    modelo[27]="C4 Cactus"; //auto
    modelo[28]="C3 Aircross"; //auto
    modelo[29]="Berlingo"; //auto

    //char *patente; //para esta, tenemos que generar letras y numeros aleatorios
    int limInf=1;
    int limSup=3; //empezamos del 1 al 3 para el tipo
    int resTipo=0;
    int resMarca=0;
    int resModelo=0;

    srand(time(NULL));
    resTipo=(rand()%(limSup-limInf+1))+limInf; //definimos el tipo
    vehiculo->tipo=resTipo; ///lo asignamos a la estructura.

    limSup=10;
    resMarca=rand()%(limSup+1); //definimos la marca
    vehiculo->marca=crearStringDinamico(marca[resMarca]);

    limSup=30;
    resModelo=rand()%(limSup+1); //definimos la marca
    vehiculo->modelo=crearStringDinamico(modelo[resModelo]);

///Ahora, generamos la patente aleatoria.

    limInf=65;
    limSup=90;
    int resLetra;
    char letra;
    char *patente=(char*)obtenerMemoria(sizeof(char)*10); //primero pasa acá, luego a la estructura.

    for(int i=0;i<2;i++) //asignamos las 2 primeras letras
    {
        resLetra=(rand()%(limSup-limInf+1))+limInf;
        letra=(char)resLetra;
        patente[i]=letra;
        printf("%s\n",patente); //imprimimos para ver como va progresando.
    }

    strcat(patente,"-"); //para añadir legibilidad, concatenamos un espacio al final de las 2 1ras letras.

    for(int i=0;i<3;i++) //asignamos los 3 numeros del medio
    {
        limInf=0;
        limSup=9;
        resLetra=(rand()%(limSup-limInf+1))+limInf;
        patente[i+3]=resLetra;
    } //i+3 porque queremos que se inserten luego de lo que ya pusimos: las letras y el espacio.

    strcat(patente,"-"); //concatenamos otro espacio al final de los 3 numeros.

    for(int i=0;i<2;i++) //asignamos las 2 ultimas letras
    {
        resLetra=(rand()%(limSup-limInf+1))+limInf;
        letra=(char)resLetra;
        patente[i+7]=letra;
        printf("%s\n",patente); //imprimimos para ver como va progresando.
    } //i+7 porque queremos que se inserten luego de lo que ya pusimos: las letras, los numeros y los 2 espacios entre medio de ellos.

    patente[10]='\0'; //terminamos el string.
    vehiculo->patente=crearStringDinamico(patente); ///asignamos a la estructura.

//destruimos los elementos que ya no utilizaremos.
    for(int i=0;i<10;i++)
    {
        marca[i]=NULL;
    }
    free(marca);
    for(int i=0;i<10;i++)
    {
        modelo[i]=NULL;
    }
    free(modelo);

    destruirStringDinamico(patente);
//Retornamos un puntero a la estructura generada.
    return vehiculo;
}

