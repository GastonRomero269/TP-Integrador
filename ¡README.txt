NOVEDADES

	V1.9 (Franco)
		- Arreglo de Errores y cambio a funciones de menus:
			- Se arreglaron varios errores menores con el debugger y se cambiaron los menues de actualizacion de datos con las nuevas funciones y cambios al TDA Cuil.

			- Menus.c: se unificaron las funciones "menuModificarCliente" y "menuModificarChofer" en una sola única funcion "menuModificarPersona", que pide un booleano para saber de que tipo de persona se trata, y desplegar distinta informacion de acuerdo a ello, lo cual reduce la carga de ejecución.

			- También se agregó un nuevo menú de creacion de centro logistico de forma rápida, utilizada en el START MENU de main.c


////////////////////////////////////////////////////////////////////////////////////////////////////

	Versiones anteriores (1.7, 1.8 y 1.8 (Gastón))

- Agregados archivos "Files.c","Files.h".
  Contienen funciones de lectura(***) y escritura de archivos y
  variantes especiales de las estructuras utilizadas en dichas funciones.
	

- Funciones de menues y submenues ahora se encuentran en archivos separados: "Menus.c" y "Menus.h".

- Main.c:
	- Se creo un "Start Menu", que crea un centro logistico vacio con un nuevo nombre si el usuario es nuevo, o carga datos en uno de lo contrario.
		(***) PRECAUCION: la funcion "abrirTodo" crea un centro logistico y devuelve un puntero al mismo, por lo que crearlo externamente y luego invocar a la funcion provocara un memory leak.
	- Se movio el Menu Principal a una funcion separada (en el mismo archivo main.c).
	- Agregadas llamadas a funciones en varios menues y submenues.

- TDA CUIL:
	- Se cambio la estructura interna del TDA. Ahora el cuil se guarda en un string.
	- Se cambiaron los getters y setters para tipo, dni y numero verificador, asi como las funciones de creacion y destruccion.
	- Se agregaron un setter y un getter para la nueva implementacion.
	- Se eliminaron las funciones traerCuil y traerCuilDinamico.
	- Se cambio la funcion mostrarCuil.
	- Se refino la apariencia de la interfaz en CUIL.h.

- TDA Personas:
	- Con los cambios al TDA CUIL, getCuil y setCuil debieron renombrarse a getCuilPersona y setCuilPersona, para prevenir confusiones o bugs.
	- Se cambio la funcion mostrarPersona.
	- Se agrego la funcion crearPersonaDirect, la cual construye en base a puramente datos primitivos (strings, ints y bool).
	- Se corrigio la funion crearPersona: se creaba un cuil y un domicilio llamando a sus respectivas constructoras, lo cual no era necesario y generaba trabajo extra en la ejecucion del programa (no percibido, pero existente). Ahora se asignan directamente a la estructura persona.

---------------------------------------------------------------------------------------------------------------------

BUG FIXES

- Se arregló el error de las funciones de mostrar listas, que hacían que el programa crasheara luego
  de mostrar los datos.

---------------------------------------------------------------------------------------------------------------------


BUGS

- En START MENU, opcion 1 - Soy nuevo (empezar de cero), el programa crashea luego de pedir el nombre para el nuevo centro logistico.

---------------------------------------------------------------------------------------------------------------------

MEJORAS

- Se quitaron los varios system("pause") porque aletargaban el proceso de navegar por el menu.

---------------------------------------------------------------------------------------------------------------------

PENDIENTES

- Crear funciones de menu de guardado usando las funciones nuevas de los archivos Files. Agregarlas a los menues de main.c.

- IMPORTANTE: MOTIVO POR EL QUE NO SE PUDO ENTREGAR. Una de dos:
  1. O bien nos quedamos con lo que tenemos, la variable int estado del paquete,
  2. O bien agregamos un string aparte. Tip: hay un motivo de entrega solo si hay un problema con dicha entrega, lo que quiere decir que sería un dato circunstancial. Entonces, es posible que no haga falta meterlo en una estructura, sino que los tengamos aparte.

Creamos el paquete con el campo "motivo de entrega" vacío. Luego, tendríamos que tener una funcion "agregarMotivo", recibe el string del motivo por el cual no se pudo entregar, y en el campo de la estrctura paquete, crea el string dinamicamente y le copia el contenido.





- Agregar llamado a las funciones de repartos.
- Ver como hacer para el resultado de la entrega. (llamar a la funcion "filtrarPaquetesPorEstado")

- IMPORTANTE: agregar lo que decia en las consignas del TP "El sistema debe/no debe permitir...". Tip: es posible que necesitemos hacer más funciones de búsqueda.
	FALTAN: debe permitir: 5 Y 6
		    no debe permitir: 1, 2, 4 y 5

- Menus: agregar un submenu donde puedas elegir si queres tomar accion sobre un solo dato o un grupo de datos a la vez, para evitar tener que entrar al menu varias veces (sería tedioso). Dentro de la segunda opcion (habria una 3ra, volver), podemos elegir si queremos tomar accion de un rango de indices, o bien si queremos tomar accion sobre varios indices especificos.

- Agregar getters y setters adicionales para las subestructuras de cada estructura (domicilio, cuil o fecha, por ejemplo, agregar getters y setters a sus campos específicos) (opcional).

- Agregar funciones de ordenamiento.
	FALTAN: 
		Ordenar paquetes por ID (opcional)
		Ordenar Vehiculos alfabeticamente por marca

- ARREGLAR POSIBLES BUGS :(