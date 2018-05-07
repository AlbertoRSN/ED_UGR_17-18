ED - 14/11/2017

Arboles Binarios (AB)

	1) Son arboles tal que cada nodo puede tener 0, 1 o 2 hijos
	2)El arbol vacío es un AB

Representacion:

template <class T>

//struct se diferencia de un class en que si no dices nada, todo es publico.

struct info_nodo{
	T et; //Etiqueta
	info_nodo *padre, *hizq, *hder;

	info_nodo(){padre = hizq = hder = 0;}
	info_nodo(const T&e){
		et = e;
		padre = hizq = hder = 0;
	}
}

template <class T>
T &etiqueta(infonodo<T> *n){
	return n->et;
}

template <class T>
info_nodo<T> * GetPadre(info_nodo<T> *n){
	return n->padre;
}

template <class T>
info_nodo<T> *GetHi(info_nodo<T> *n){
	return n->hizq;
}

template <class T>
info_nodo<T> * GetHid(info_nodo<T> *n){
	return n->hder;
}

template<class T>
void BorrarInfo(info_nodo<T> *&n){
	if(n!=0){ //Solamente puedo borrar si el puntero n es distinto de 0
		BorrarInfo(n->hizq);
		BorrarInfo(n->hder);
		delete n;
		n=0; //Al poner n=0 hay que pasar a la funcion *&n porque si no cuando vuelva puede tener cualquier valor.
	}
}

template <class T>
void Copiar(info_nodo <T> *s, info_nodo<T> * [] d){
	if(s!=0){
		d = new info_nodo<T>(s->et);
		Copiar(s->hizq, d->hizq);
		Copiar(s->hder, d->hder);

		if(d->hizq != 0)
			d->hizq->padre = d;
		if(d->hder != 0)
			d->hder->padre = d;
	}
	else{
		d=0;
	}
}


template <class T>
void insertarHijoIzquierda(info_nodo<T> *n, info_nodo<T> *sub){
	info_nodo<T> * aux = n->hizq;

	if(sub != 0){
		n->hizq = sub;
		BorrarInfo(aux);
		sub->padre = n;
	}
	else{
		n->hizq = 0;
		BorrarInfo(aux);
	}
}

template <class T>
void insertarHijoIzquierda(info_nodo<T> *n, const T&v){
	info_nodo<T> * nuevo = new info_nodo<T>(v);
	insertarHijoIzquierda(n,nuevo);
}

_____Sentencia crear______

info_nodo<int>*raiz;
1) raiz = new info_nodo<int>(5);
2) insertarHijoIzquierda(raiz, 7);



template <class T>
void PodarHijoIzquierda(info_nodo<T> * n){
	if(n->hizq != 0){
		BorrarInfo(n->hizq);
		n->hizq = 0;
	}
}

template <class T>
info_nodo<T>* Podar_HijoIzq_GetSubtree(info_nodo<T>* n){
	info_nodo<T>* sub = n->hizq;
	n->hizq = 0;
	if(sub != 0)
		sub->padre = 0;

	return sub;
}














