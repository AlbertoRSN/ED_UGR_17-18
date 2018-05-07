12/12/2017

Tablas HASH

Objetivo
	Dados un conjunto de datos identificadors por una clave K se quiere obtener una funcion h (funcion hash), tal que h(k) nos da la posicion en una tabla (tabla hash) en la que almacenamos un par formado por clave k y la direccion en un fichero donde se encuentra toda la informacion del dato con clave k.

Colision
	Cuando dos claves k1 y k2 tienen el mismo valor hash -> h(k1) = h(k2)

Funciones Hash se caracterizan por:
	1. Tienen que ser rapidas de calcular.
	2. Que no produzcan muchas colisiones.

Estrategia a seguir
	1. Resolver la colision no genere mucho tiempo
	2. El tamaño de la tabla hash no sea muy grande 

	