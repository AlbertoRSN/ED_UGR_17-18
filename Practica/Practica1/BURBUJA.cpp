//Metodo BUSQEUDA BURBUJA

void ordenar(int *v, int n){
	if(n==1)
      return;
	for(int i=0; i<n; i++){
		if(v[i] > v[i+1]){
			int aux=v[i];
			v[i]=v[i+1];
			v[i+1]=aux;
		}
	}
}
