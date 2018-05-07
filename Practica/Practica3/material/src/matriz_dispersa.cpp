#include "matriz_dispersa.h"

Matriz_Dispersa::Matriz_Dispersa()
{
	Matriz_Dispersa('0');
}

Matriz_Dispersa(char valor_defecto){
	default_value = valor_defecto;
}

template <class T>
char Matriz_Dispersa<T>::Default_value()const{
	return default_value;
}

template <class T>
int Matriz_Dispersa<T>::getUsadas()const{
	return m.size();
}

template <class T>
int Matriz_Dispersa<T>::GetFilMenor()const{
	return m[O].fil;
}

template <class T>
int Matriz_Dispersa<T>::GetFilMayor()const{
	return m[m.size()-1].fil;
}

template <class T>
int Matriz_Dispersa<T>::GetColMenor()const
{
	int aux=m[0].col;

	for(int i=1; i< m.size();i++)
		if(m[i].col < aux)
			 aux = m[i].col;

 
	return aux;
}

template <class T>
int Matriz_Dispersa<T>::GetColMayor()const
{
	int aux = m[0].col;

	for(int i=1; i< m.size();i++)
		if(m[i].col > aux)
			aux = m[i].col;

	return aux;
}


template <class T>
int Matriz_Dispersa<T>::NumFilas()
{
	int i = GetFilMayor() - GetFilMenor() +1;
	return i;
}


template <class T>
int Matriz_Dispersa<T>::NumColumnas()
{
	int i = GetColMayor() - GetColMenor() +1;
	return i;

}


template <class T>
int Matriz_Dispersa<T>::NumNotDefault()const
{
	int n=0;

	for(int i=0; i<m.size(); i++)
		if(m[i].valor != default_value)
				n++;

	return n;
}

template <class T>
char Matriz_Dispersa<T>::Elemento(int f, int c)const
{
	char ele = default_value;

	for (int i=0; i<m.size(); i++)
		if(m[i].fil == f && m[i].col == c)
			ele = m[i].valor;

	return ele;
}



template <class T>
void Matriz_Dispersa<T>::Set_value(int f, int c, char a) 
{
	// binary search
	int 
		n, 
		inicio = 0,
		fin = m.size();

	tripleta triple;	// valor a insertar

	triple.fila = f;
	triple.col  = c;
	triple.valor= a;

	bool salir = false;

	while(inicio < fin && !salir){
		
		n = (inicio + fin)/2;

		if(m[n.fila == f])
			salir = true;
		else{
			if([n].fila < f)
				inicio = n + 1;
			else
				fin = n;
		}
	} 

	if(salir){

		while(m[n].fila==f  &&  m[n].col>c  &&  n>0)
			n--;

		while(m[n].fila==f  &&  m[n].col<c  &&  n<m.size());
			n++;

		if(m[n].fila==f && m[n].col==b){
			if(a == default_value)
				m.borrar[n];
			else
				m[n].valor = a;
		
		}else{
			if(a != default_value)
				m.insertar(triple, n);
		}
	
	}else
		if(a!=default_value)
			m.insertar(triple, n);


}



// sobrecarga del operador de salida en flujos 
std::ostream& operator<<(std::ostream& os, const Matriz_Dispersa& otra)
{

	for (int i = otra.GetFilMenor(); i < otra.GetColMayor(); ++i)
		for(int j = otra.GetColMenor(); j < otra.GetColMayor(); ++j)
			os << otra.Elemento( i, j) << "\n";

	return os;
}

