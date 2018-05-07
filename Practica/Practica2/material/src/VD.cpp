template <class T>
void VD<T> :: resize(int nuevotam){
	T *aux = new T [nuevotam];
 	int minimo = (n<nuevotam)?n:nuevotam;
 	
 	for (int i=0; i<minimo; i++)
 		aux[i] = datos[i];

 	reservados = nuevotam;
 	n = minimo;
 	delete [] datos;
 	datos = aux;
}

 template <class T>
 void VD<T> :: Copiar (const VD<T> &v){
 	reservados = v.reservados;
 	n=v.n;
 	datos = new T [reservados];
 	
 	for (int i=0; i<n; i++)
 		datos[i] = v.datos[i];
 }

 template <class T>
 void VD<T> :: Liberar(){
 	delete [] datos;
 }

 template <class T> //en otros sitios el class se sustituye por typename
 VD<T> :: VD (int tam){
 	reservados = tam;
 	datos = new T [reservados];
 	n=0;

 }

 template <class T>
 VD<T> :: VD(const VD<T> &original){
 	Copiar(original);
 }

 template <class T>
 VD<T> :: ~VD(){
 	Liberar();
 }

VD<T> & VD<T> :: operator=(const VD<T> & v){
	if (this != &v){
      Liberar();
      Copiar(v);
	}
	return *this;
}

template <class T>
void VD<T> :: Insertar (const T &d, int pos){
/*segun estudios estadisticos, la mejor forma de usar un vector dinamico es
que n < reservados/2, y cuando se supere esa cifra hacer un resize de 2*reservados*/
      if (n >= (reservados/2))
            resize(2*reservados);
      for (int i=n; i > pos; i--)
            datos[i] = datos[i-1];
      
      datos[pos] = d;
      n++;
}

template <class T>
void VD<T> :: Borrar (int pos){
    for (int i=pos; i<n-1; i++)
        datos[i] = datos[i+1];
    n--;
    if (n < (reservados/4))
        resize (reservados/2);
}
