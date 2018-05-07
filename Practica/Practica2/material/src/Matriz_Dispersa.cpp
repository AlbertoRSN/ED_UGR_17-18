#include<iostream>
#include "Matriz_Dispersa.h"
#include <cstring>


using namespace std;

//Constructor por defecto
Matriz_Dispersa::Matriz_Dispersa(){
  VD<Tripleta> m;
  valor_defecto = '0';
} 

//Constructor parametros se le pasa valor por defecto
Matriz_Dispersa::Matriz_Dispersa(char valor='0'){ //Poner elementos a 0
  this->valor_defecto = valor;
} 

//Devolver elemento de la posicion i,j
template <class T>
T Matriz_Dispersa<T>::Get(int i, int j) const{
  
	for(int k=0; k<m.size(); k++){ //Este recorre filas
		if(m[k].fil == i && m[k].col == j)
			return m[k].dato;
		else
			if((m[k].fil == i && m[k].col > j) || m[k].fil > i )
				return valor_defecto;
	}

	return valor_defecto;
}

//Modificar elemento de la posicion (i,j)
template <class T>
void Matriz_Dispersa<T>::Set(int i, int j, const T &nuevo){
	if(nuevo == valor_defecto){
		bool salir=false;

		for(int k=0; k<m.size(); && !salir; k++){
			if(m[k].fil == i && m[k].col == j)//Es igual a defecto
				m.Borrar(k); //se borra 
			else if((m[k].fil == i && m[k].col > j) || m[k].fil>i){
				salir=true; //no está el elemento
			}
			else
				k++;
		}
	}
		else{
			if(nuevo != valor_defecto){
				bool mod = false;
				for(int k = 0; k<m.size() && !mod; k++){
					if(m[k].fil == i && m[k].col == j){
						m[k].dato = nuevo;
						mod = true;
					}
					else if((m[k].fil == i && m[k].col > j) || m[k].fil > i){
						Tripleta<T> a = {i,j,nuevo};
						m.Insertar(a,k);
						mod = true;
					}
				}

				if(!mod){
					Tripleta<T> a = {i,j,nuevo};
					m.Insertar(a,0);
				}
			}
		}
}

template <class T>
int Matriz_Dispersa<T>::menorFila()const{
	int menorFil = 0;

	for(int i=0; i<m.size(); i++){
		if(m[i].fil < menorFil){
			menorFil = m[i].fil;
		}
	}

	return menorFil;
}

template <class T>
int Matriz_Dispersa<T>::mayorFila()const{
	int mayorFil = 0;

	for(int i=0; i<m.size(); i++){
		if(m[i].fil > mayorFil){
			mayorFil = m[i].fil;
		}
	}

	return mayorFil;
}

template <class T>
int Matriz_Dispersa<T>::menorColumna()const{
	int menorCol = 0;

	for(int i=0; i<m.size(); i++){
		if(m[i].col < menorCol{
			menorCol = m[i].col;
		}
	}

	return menorCol;
}


template <class T>
int Matriz_Dispersa<T>::mayorFila()const{
	int mayorCol = 0;

	for(int i=0; i<m.size(); i++){
		if(m[i].fil > mayorCol){
			mayorCol = m[i].fil;
		}
	}

	return mayorCol;
}

template<class T>
char  Matriz_Dispersa<T>::getValorDefecto()const{
	return valor_defecto;
}

template<class T>
int Matriz_Dispersa<T>::numCasillasNoDefecto() const{
	int cont = 0;

	for(int i=0; i<m.size(); i++){
		if(m[i].dato != valor_defecto)
			cont++;
	}

	return cont;
}


//Operador <<
ostream& operator<< (ostream & os, const Matriz_Dispersa & m){
  	return os << '[' << m.fil << ',' << m.col << ',' << m.dato<< ']';
}

//Operador >>
istream& operator>> (istream& is, Matriz_Dispersa& m){
  char car, dat;
  int fila, columna;
  is >> caracter >> fila >> caracter >> columna >> caracter >> dat;
  m = Matriz_Dispersa();
  m.Set(fila,columna,dat);
  return is;
}






