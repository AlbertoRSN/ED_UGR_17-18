ED - 24/11/2017	

Arboles binarios de busqueda (ABB)

	Un ABB es un arbol binario con las etiquetas de los nodos ordenados de forma que el eleemento situado en un nodo es mayor que todos lods qie se encuentran en el subarbol izquierdo y menor de los que se encuentran en el subarbol derecho.


	{10,5,14,7,12,3,9,8,6} 


Posible pregunta examen: Nos dan la cabecera y comprobar si un arbol binario es de busqueda:

	template <class T>
	bool esABB(ArbolBinario<T> &a){
		return esABB_N(a.getRaiz());
	}

	template <class T>
	bool esABB_N(typename ArbolBinario<T>::nodo n){
		if(n.nulo())
			return true;
		else{
			if(n.hi.nulo())
				if(*n < *(n.hi()))
					return false;
			if(n.hd.nulo())
				if(*n > *(n.hd()))
					return false
			return ABB_N(n.hi()) && ABB_N(n.hd());
		}			
	}