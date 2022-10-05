#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lista.h"
#include "TDAPaquetes.h"
#include "TDAPersona.h"
#include "TDAVehiculo.h"
#include "TDARepartos.h"
#include "TDACentroLogistico.h"
#include "util.h"


CentroLogisticoPtr crearCentroLogistico(char *nombre,ListaPtr listaPaquetes,ListaPtr listaPersonas,ListaPtr listaVehiculos,ListaPtr listaRepartosAbiertos,ListaPtr listaRepartosCerrados)
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));
    centroLogistico->nombre=crearStringDinamico(nombre);

    centroLogistico->listaPaquetes=listaPaquetes;
    centroLogistico->listaPersonas=listaPersonas;
    centroLogistico->listaVehiculos=listaVehiculos;
    centroLogistico->listaRepartosAbiertos=listaRepartosAbiertos;
    centroLogistico->listaRepartosCerrados=listaRepartosCerrados;

    return centroLogistico;
}
CentroLogisticoPtr crearCentroLogisticoRapido(char *nombre) ///Crea un centro logístico con un nombre y listas vacías.
{
    CentroLogisticoPtr centroLogistico=(CentroLogisticoPtr)obtenerMemoria(sizeof(CentroLogistico));

    centroLogistico->nombre=crearStringDinamico(nombre);

    centroLogistico->listaPaquetes=crearLista();
    centroLogistico->listaPersonas=crearLista();
    centroLogistico->listaVehiculos=crearLista();
    centroLogistico->listaRepartosAbiertos=crearLista();
    centroLogistico->listaRepartosCerrados=crearLista();

    return centroLogistico;
}
CentroLogisticoPtr destruirCentroLogistico(CentroLogisticoPtr centroLogistico)
{
    destruirStringDinamico(centroLogistico->nombre);

    centroLogistico->listaPaquetes=destruirLista(centroLogistico->listaPaquetes,true);
    centroLogistico->listaPersonas=destruirLista(centroLogistico->listaPersonas,true);
    centroLogistico->listaVehiculos=destruirLista(centroLogistico->listaVehiculos,true);
    centroLogistico->listaRepartosAbiertos=destruirLista(centroLogistico->listaRepartosAbiertos,true);
    centroLogistico->listaRepartosCerrados=destruirLista(centroLogistico->listaRepartosCerrados,true);

    free(centroLogistico);

    return NULL;
}

char *getNombreCentroLogistico(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->nombre;
}
ListaPtr getPaquetes(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaPaquetes;
}
ListaPtr getPersonas(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaPersonas;
}
ListaPtr getVehiculos(CentroLogisticoPtr centroLogistico)
{
    return centroLogistico->listaVehiculos;
}
ListaPtr getRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
	if(esRepartoAbierto)
		return centroLogistico->repartosAbiertos;
	else
		return centroLogistico->repartosCerrados;
}

void setNombreCentroLogistico(CentroLogisticoPtr centroLogistico,char *nombre)
{
    strcpy(centroLogistico->nombre,nombre);
}
void setPaquetes(CentroLogisticoPtr centroLogistico,ListaPtr listaPaquetes)
{
    centroLogistico->listaPaquetes=listaPaquetes;
}
void setPersonas(CentroLogisticoPtr centroLogistico,ListaPtr listaPersonas)
{
    centroLogistico->listaPersonas=listaPersonas;
}
void setVehiculos(CentroLogisticoPtr centroLogistico,ListaPtr listaVehiculos)
{
    centroLogistico->listaVehiculos=listaVehiculos;
}
void setRepartos(CentroLogisticoPtr centroLogistico, ListaPtr repartos, bool esRepartoAbierto)
{
	if(esRepartoAbierto)
		centroLogistico->listaRepartosAbiertos = repartos;
	else
		centroLogistico->listaRepartosCerrados = repartos;
}

void mostrarPaquetes(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));

    int i=0;

    printf("\nLISTA DE PAQUETES: \n\n");
    while(!listaVacia(listaAux)) //getPaquetes(centroLogistico)
    {
        printf("%d. ",i+1);
        mostrarPaquete((PaquetePtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

void mostrarPersonas(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));

    int i=0;

    printf("\nLISTA DE PERSONAS: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);
        mostrarPersona((PersonaPtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
void mostrarClientes(CentroLogisticoPtr centroLogistico) //busca y muestra solo las personas cuyo esChofer==false.
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));

    int i=0;

    printf("\nLISTA DE CLIENTES: \n\n");
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(getEsChofer(personaAux)==false)
        {
            printf("%d. ",i+1);

            mostrarPersona(personaAux);
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
void mostrarChoferes(CentroLogisticoPtr centroLogistico) //busca y muestra solo las personas cuyo esChofer==true.
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));

    int i=0;

    printf("\nLISTA DE CHOFERES: \n\n");
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(getEsChofer(personaAux))
        {
            printf("%d. ",i+1);

            mostrarPersona(personaAux);
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}

void mostrarVehiculos(CentroLogisticoPtr centroLogistico)
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));

    int i=0;

    printf("\nLISTA DE VEHICULOS: \n\n");
    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);

        mostrarVehiculo((VehiculoPtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
void mostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    ListaPtr listaAux=crearLista();
	if(esRepartoAbierto)
    {
		listaAux = getRepartos(centroLogistico,true);
        printf("\nLISTA DE REPARTOS ABIERTOS: \n\n");
    }
	else
    {
		listaAux = getRepartos(centroLogistico,false);
        printf("\nLISTA DE REPARTOS CERRADOS: \n\n");
    }

    int i=0;

    while(!listaVacia(listaAux))
    {
        printf("%d. ",i+1);

        mostrarReparto((RepartoPtr)getCabecera(listaAux));
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

        i++;
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
void filtrarPaquetes(CentroLogisticoPtr centroLogistico,int estado) //filtra los paquetes que se muestran por el estado indicado. Ver: TDAPaquete.h>>>Funcion helpEstadoPaquete().
{
    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));
    switch(estado)
    {
    case 0:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'EN DEPOSITO': \n\n");
        break;
    case 1:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'EN CURSO': \n\n");
        break;
    case 2:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'RETIRADO': \n\n");
        break;
    case 3:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'ENTREGADO': \n\n");
        break;
    case 4:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'DEMORADO': \n\n");
        break;
    case 5:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'SUSPENDIDO': \n\n");
        break;
    default:
        printf("\nLISTA DE PAQUETES FILTRADOS POR ESTADO 'ERROR': \n\n");
        break;
    }

    while(!listaVacia(listaAux))
    {
        PaquetePtr paqueteAux=(PaquetePtr)getCabecera(listaAux);
        if(paqueteAux->estado==estado)
            mostrarPaquete(paqueteAux);
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
    }
    listaAux=destruirLista(listaAux,false);
    printf("\n");
}
///NUEVO: Funciones de búsqueda de datos en la lista
bool buscarPaquete(CentroLogisticoPtr centroLogistico,int ID)
{
    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPaquetes(centroLogistico));
    while(!listaVacia(listaAux))
    {
        PaquetePtr paqueteAux=(PaquetePtr)getCabecera(listaAux);

        if(getID(paqueteAux)==ID)
        {
            match=true;
            mostrarPaquete(paqueteAux);
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);

    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}
bool buscarPersona(CentroLogisticoPtr centroLogistico,CuilPtr cuil,bool esChofer)
{
    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        PersonaPtr personaAux=(PersonaPtr)getCabecera(listaAux);
        if(strcmp(getCuil(getCuilPersona(personaAux)),getCuil(cuil))==0 && getEsChofer(personaAux)==esChofer)
        {
            match=true;
            mostrarPersona(personaAux); //mostramos solo si el cuil y esChofer coinciden
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}
bool buscarVehiculo(CentroLogisticoPtr centroLogistico,char *patente)
{
    bool match=false;

    ListaPtr listaAux=crearLista();
    agregarLista(listaAux,getVehiculos(centroLogistico));
    while(!listaVacia(listaAux))
    {
        VehiculoPtr vehiculoAux=(VehiculoPtr)getCabecera(listaAux);
        if(strcmp(getPatente(vehiculoAux),patente)==0)
        {
            match=true;
            mostrarVehiculo(vehiculoAux); //mostramos si las patentes coinciden, es decir, si strcmp da cero.
        }
        ListaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        listaADestruir=destruirLista(listaADestruir,false);
    }
    listaAux=destruirLista(listaAux,false);

    if(match)
        printf("\n"); //esto lo pongo acá para que no pase si no hay un match.

    return match;
}
//Funciones de agregado a la lista
void agregarPaquete(CentroLogisticoPtr centroLogistico,PaquetePtr paquete)
{
    agregarDatoLista(centroLogistico->listaPaquetes,(PaquetePtr)paquete);
}
void agregarPersona(CentroLogisticoPtr centroLogistico,PersonaPtr persona)
{
    agregarDatoLista(centroLogistico->listaPersonas,(PersonaPtr)persona);
}
void agregarVehiculo(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo)
{
    agregarDatoLista(centroLogistico->listaVehiculos,(VehiculoPtr)vehiculo);
}
void agregarReparto(CentroLogisticoPtr centroLogistico,RepartoPtr reparto, bool esRepartoAbierto)
{
	if(esRepartoAbierto)
		agregarDatoLista(getRepartos(centroLogistico,true), reparto);
	else
		agregarDatoLista(getRepartos(centroLogistico,false), reparto);
}
//Funciones de inserción a la lista
bool insertarPaqueteLista(CentroLogisticoPtr centroLogistico,PaquetePtr paquete,int posicion)
{
    return insertarDatoLista(centroLogistico->listaPaquetes,(PaquetePtr)paquete,posicion);
}
bool insertarPersonaLista(CentroLogisticoPtr centroLogistico,PersonaPtr persona,int posicion)
{
    return insertarDatoLista(centroLogistico->listaPersonas,(PersonaPtr)persona,posicion);
}
bool insertarVehiculoLista(CentroLogisticoPtr centroLogistico,VehiculoPtr vehiculo,int posicion)
{
    return insertarDatoLista(centroLogistico->listaVehiculos,(VehiculoPtr)vehiculo,posicion);
}
bool insertarRepartoLista(CentroLogisticoPtr centroLogistico,RepartoPtr reparto,int posicion) ///SOLO PARA REPARTOS ABIERTOS
{
    return insertarDatoLista(centroLogistico->listaRepartosAbiertos,(RepartoPtr)reparto,posicion);
}
//Funciones para eliminar de la lista
PaquetePtr removerPaquete(CentroLogisticoPtr centroLogistico,int posicion)
{
    return (PaquetePtr)removerDeLista(centroLogistico->listaPaquetes,posicion);
}
PersonaPtr removerPersona(CentroLogisticoPtr centroLogistico,int posicion)
{
    return (PersonaPtr)removerDeLista(centroLogistico->listaPersonas,posicion);
}
VehiculoPtr removerVehiculo(CentroLogisticoPtr centroLogistico,int posicion)
{
    return (VehiculoPtr)removerDeLista(centroLogistico->listaVehiculos,posicion);
}
RepartoPtr removerReparto(CentroLogisticoPtr centroLogistico,int posicion,bool esRepartoAbierto)
{
    if(esRepartoAbierto)
        return (RepartoPtr)removerDeLista(centroLogistico->listaRepartosAbiertos,posicion);
    else
        return (RepartoPtr)removerDeLista(centroLogistico->listaRepartosCerrados,posicion);
}
///NUEVA
void cerrarRepartoCtroLogistico(CentroLogisticoPtr centroLogistico, int posicion)
{ ///extraemos el reparto de la lista de abiertos
    RepartoPtr repartoACerrar = removerReparto(centroLogistico,posicion,true);
///Obtenemos cada paquete de la pila y le cambiamos el estado a 3: "entregado"
    PaquetePtr paqueteAux;
    int n=cantidadPaquetes(repartoACerrar);
    for(int i=0;i<n;i++)
    {
        paqueteAux = descargarPaquete(repartoACerrar);
        setEstado(paqueteAux,3);
    }
    for(int i=0;i<n;i++)
        cargarPaquete(repartoACerrar,paqueteAux);
///Agregamos el reparto a la lista de cerrados
    agregarReparto(centroLogistico,repartoACerrar,false);
}

//Funciones para resetear listas
///Precondición: debe existir una funcion de destruccion para cada tipo de dato.
void resetearPaquetes(CentroLogisticoPtr centroLogistico)
{
    while(!listaVacia(centroLogistico->listaPaquetes))
    {
        PaquetePtr paqueteEliminar=(PaquetePtr)removerDeLista(centroLogistico->listaPaquetes,0);
        paqueteEliminar=destruirPaquete(paqueteEliminar);
    }
}
void resetearPersonas(CentroLogisticoPtr centroLogistico)
{
    while(!listaVacia(centroLogistico->listaPersonas))
    {
        PersonaPtr personaEliminar=(PersonaPtr)removerDeLista(centroLogistico->listaPersonas,0);
        personaEliminar=destruirPersona(personaEliminar);
    }
}
void resetearVehiculos(CentroLogisticoPtr centroLogistico)
{
    while(!listaVacia(centroLogistico->listaVehiculos))
    {
        VehiculoPtr vehiculoEliminar=(VehiculoPtr)removerDeLista(centroLogistico->listaVehiculos,0);
        vehiculoEliminar=destruirVehiculo(vehiculoEliminar);
    }
}
void resetearRepartos(CentroLogisticoPtr centroLogistico)
{
    while(!listaVacia(centroLogistico->listaRepartos))
    {
        RepartoPtr repartoEliminar=(RepartoPtr)removerDeLista(centroLogistico->listaRepartos,0);
        repartoEliminar=cerrarReparto(repartoEliminar); //usamos cerrar reparto porque la destructora es una funcion privada.
    }
}

///FUNCIONES DE ORDENAMIENTO
void ordenarPorMarca(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaVehiculos=crearLista();
    listaVehiculos = getVehiculos(centroLogistico);
    ListaPtr listaAux = crearLista();
    int n = longitudLista(listaVehiculos);
    VehiculoPtr vehiculos[n];
    VehiculoPtr vehiculoAux;

    while(!listaVacia(listaVehiculos))
    {
        vehiculos[i] = getCabecera(listaVehiculos);
        PtrLista listaADestruir = listaVehiculos;
        listaVehiculos = getResto(listaVehiculos);
        i++;
    }
    destruirLista(listaVehiculos, false);

    for(int i=0; i<n-1 ; i++){
        for(int j=i; j<longitudlistaVehiculos-1; j++){
            if(strcmp(getMarca(getDatoLista(listaVehiculos,j)), getMarca(getDatoLista(listaVehiculos,j+1))) == 0){
                vehiculoAux = vehiculos[j];
                vehiculos[j] = vehiculos[j+1];
                vehiculos[j+1] = vehiculoAux;
            }
        }
    }

    ListaPtr listaNuevaVehiculos = crearLista();
    for(int i=0; i<n ; i++){
        agregarDatoLista(listaNuevaVehiculos, vehiculos[i]);
    }

    setVehiculos(centroLogistico, listaNuevaVehiculos);
    listaAux = destruirLista(listaAux,true);
    listaVehiculos = destruirLista(listaVehiculos, true);
}
void ordenarPorID(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaPaquetes = crearLista();
    listaPaquetes = getPaquetes(centroLogistico);
    ListaPtr listaAux = crearLista();
    int n = longitudLista(listaPaquetes);
    PaquetePtr paquetes[n];
    PaquetePtr paqueteAux;

    while(!listaVacia(listaPaquetes))
    {
        paquetes[i] = getCabecera(listaPaquetes);
        PtrLista listaADestruir = listaPaquetes;
        listaPaquetes = getResto(listaPaquetes);
        i++;
    }
    destruirLista(listaPaquetes, false);

    for(int i=0; i<n-1 ; i++){
        for(int j=i; j<n-1; j++){
            if(getID(getDatoLista(listaPaquetes,j)) > getID(getDatoLista(listaPaquetes,j+1))){
                paqueteAux = paquetes[j];
                paquetes[j] = paquetes[j+1];
                paquetes[j+1] = paqueteAux;
            }
        }
    }

    ListaPtr listaNuevaPaquetes = crearLista();
    for(int i=0; i<n ; i++){
        agregarDatoLista(listaNuevaPaquetes, paquetes[i]);
    }

    setPaquetes(centroLogistico, listaNuevaPaquetes);
    listaAux = destruirLista(listaAux,true);
    listaPaquetes = destruirLista(listaPaquetes, true);
}

void ordenarPorFechaSalida(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaRepartos=crearLista();
    listaRepartos=getRepartos(centroLogistico);
    ListaPtr listaAux=crearLista();
    int n=longitudLista(listaRepartos);
    RepartoPtr repartos[n];
    RepartoPtr repartoAux;
    while(!listaVacia(listaRepartos))
    {
        repartos[i]=getCabecera(listaRepartos);
        ListaPtr listaADestruir = listaRepartos;
        listaRepartos = getResto(listaRepartos);
        i++;
    }
    destruirLista(listaRepartos, false);
    for(int i=0; i<n-1 ; i++){
        for(int j=i; j<n-1; j++){
            if(repartos[j]->fechaSalida > repartos[j+1]->fechaSalida){
                repartoAux=repartos[j];
                repartos[j]=repartos[j+1];
                repartos[j+1]=repartoAux;
            }
        }
    }
    ListaPtr listaNuevaRepartos=crearLista();
    for(int i=0; i<n; i++){
        agregarDatoLista(listaNuevaRepartos, repartos[i]);
    }
    setRepartos(centroLogistico,listaNuevaRepartos);
    listaAux=destruirLista(listaAux,true);
    listaRepartos=destruirLista(listaRepartos,true);
}
void ordenarPorFechaRetorno(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaRepartos=crearLista();
    listaRepartos=getRepartos(centroLogistico);
    ListaPtr listaAux=crearLista();
    int n=n;
    RepartoPtr repartos[n];
    RepartoPtr repartoAux;
    while(!listaVacia(listaRepartos))
    {
        repartos[i]=getCabecera(listaRepartos);
        ListaPtr listaADestruir = listaRepartos;
        listaRepartos = getResto(listaRepartos);
        i++;
    }
    destruirLista(listaRepartos, false);
    for(int i=0; i<n-1 ; i++){
        for(int j=i; j<n-1; j++){
            if(repartos[j]->fechaRetorno > repartos[j+1]->fechaRetorno){
                repartoAux=repartos[j];
                repartos[j]=repartos[j+1];
                repartos[j+1]=repartoAux;
            }
        }
    }
    ListaPtr listaNuevaRepartos=crearLista();
    for(int i=0; i<n; i++){
        agregarDatoLista(listaNuevaRepartos, repartos[i]);
    }
    setRepartos(centroLogistico,listaNuevaRepartos);
    listaAux=destruirLista(listaAux,true);
    listaRepartos=destruirLista(listaRepartos,true);
}
void ordenarPorFechaRepartos(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaRepartos=crearLista();
    listaRepartos=getRepartos(centroLogistico);
    ListaPtr listaAux=crearLista();
    int n=n;
    RepartoPtr repartos[n];
    RepartoPtr repartoAux;
    while(!listaVacia(listaRepartos))
    {
        repartos[i]=getCabecera(listaRepartos);
        ListaPtr listaADestruir = listaRepartos;
        listaRepartos = getResto(listaRepartos);
        i++;
    }
    destruirLista(listaRepartos, false);
    for(int i=0; i<n-1 ; i++){
        for(int j=i; j<n-1; j++){
            if(repartos[j]->fechaSalida > repartos[j+1]->fechaSalida && repartos[j]->fechaRetorno > repartos[j+1]->fechaRetorno){
                repartoAux=repartos[j];
                repartos[j]=repartos[j+1];
                repartos[j+1]=repartoAux;
            }
        }
    }
    ListaPtr listaNuevaRepartos=crearLista();
    for(int i=0; i<n; i++){
        agregarDatoLista(listaNuevaRepartos, repartos[i]);
    }
    setRepartos(centroLogistico,listaNuevaRepartos);
    listaAux=destruirLista(listaAux,true);
    listaRepartos=destruirLista(listaRepartos,true);
}
void ordenarPorNombreChofer(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaChoferes=crearLista();
    listaChoferes=getPersonas(centroLogistico);

    int longitudPersonas=longitudLista(listaChoferes);
    PersonaPtr personas[longitudPersonas];
    PersonaPtr personaAux;
    while(!listaVacia(listaChoferes))
    {
        personas[i]=getCabecera(listaChoferes);
        ListaPtr listaADestruir = listaChoferes;
        listaChoferes = getResto(listaChoferes);
        i++;
    }
    destruirLista(listaChoferes, false);
    for(int i=0;i<longitudPersonas;i++){
        for(int j=i;j<longitudPersonas;j++){
            if(strcmp(getNombre(personas[j]), getNombre(personas[j+1]))==0){
                personaAux=personas[j];
                personas[j]=personas[j+1];
                personas[j+1]=personaAux;
            }
        }
    }
    ListaPtr listaNuevaPersonas=crearLista();
    for(int i=0;i<longitudPersonas;i++){
        agregarDatoLista(listaNuevaPersonas,personas[i]);
    }
    setPersonas(centroLogistico,listaNuevaPersonas);
    listaChoferes=destruirLista(listaChoferes,true);
}
void ordenarPorApellidoChofer(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaChoferes=crearLista();
    listaChoferes=getPersonas(centroLogistico);

    int longitudPersonas=longitudLista(listaChoferes);
    PersonaPtr personas[longitudPersonas];
    PersonaPtr personaAux;
    while(!listaVacia(listaChoferes))
    {
        personas[i]=getCabecera(listaChoferes);
        ListaPtr listaADestruir = listaChoferes;
        listaChoferes = getResto(listaChoferes);
        i++;
    }
    destruirLista(listaChoferes, false);
    for(int i=0;i<longitudPersonas;i++){
        for(int j=i;j<longitudPersonas;j++){
            if(strcmp(getApellido(personas[j]), getApellido(personas[j+1]))==0){
                personaAux=personas[j];
                personas[j]=personas[j+1];
                personas[j+1]=personaAux;
            }
        }
    }
    ListaPtr listaNuevaPersonas=crearLista();
    for(int i=0;i<longitudPersonas;i++){
        agregarDatoLista(listaNuevaPersonas,personas[i]);
    }
    setPersonas(centroLogistico,listaNuevaPersonas);
    listaChoferes=destruirLista(listaChoferes,true);
}
void ordenarPorChoferRepartos(CentroLogisticoPtr centroLogistico)
{
    int i=0;
    ListaPtr listaChoferes=crearLista();
    listaChoferes=getPersonas(centroLogistico);

    int longitudPersonas=longitudLista(listaChoferes);
    PersonaPtr personas[longitudPersonas];
    PersonaPtr personaAux;
    while(!listaVacia(listaChoferes))
    {
        personas[i]=getCabecera(listaChoferes);
        ListaPtr listaADestruir = listaChoferes;
        listaChoferes = getResto(listaChoferes);
        i++;
    }
    destruirLista(listaChoferes, false);
    for(int i=0;i<longitudPersonas;i++){
        for(int j=i;j<longitudPersonas;j++){
           if(strcmp(getNombre(personas[j]), getNombre(personas[j+1]))==0){
               if(strcmp(getApellido(personas[j]), getApellido(personas[j+1]))==0){
                    personaAux=personas[j];
                    personas[j]=personas[j+1];
                    personas[j+1]=personaAux;
                }
            }
        }
    }
    ListaPtr listaNuevaPersonas=crearLista();
    for(int i=0;i<longitudPersonas;i++){
        agregarDatoLista(listaNuevaPersonas,personas[i]);
    }
    setPersonas(centroLogistico,listaNuevaPersonas);
    listaChoferes=destruirLista(listaChoferes,true);
}
