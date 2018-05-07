#include "VD.h"

template <class T>

void VD<T>::resize(int nuevo_tam)
{

 T *aux = new T[nuevo_tam];
 int minimo = (n < nuevo_tam) ? n:nuevo_tam;

 for(int i=0; i<minimo;i++)
  aux[i] = datos[i];
 
 reservados = nuevo_tam;
 n=minimo;
 delete[] datos;
 datos = aux;

}

template <class T>
VD<T>::VD(int tam)
{

 datos = new T[tam];
 reservados = tam;
 n = 0;

}

template <class T>
VD<T>::VD(const VD<T> &original)
{

 reservados = original.reservados;
 n=original.n;
 datos = new T[reservados];

 for(int i=0;i<n;i++)
  datos[i] = original.datos[i];
 
}

template <class T>
VD<T>::~VD()
{

 if(n!=0){
  n=0;
  reservados=0;
  delete[] datos;
 }

}

template <class T>
VD<T> & VD<T>::operator=(const VD<T> &original)
{

 if(this != &original){
  if(datos!=0)
   delete[] datos;

  reservados = original.reservados;
  n=original.n;
  datos = new T[reservados];

  for(int i=0;i<n;i++)
   datos[i] = original.datos[i];
  
 }
 return *this;

}

template <class T> 
void VD<T>::insertar(const T &datos, int pos)
{

 if(n>=reservados){
  resize(2*reservados);
 }
 for(int i=n;i>pos;i++){
  datos[i] = datos[i-1];
 }
 datos[pos] = datos;
 n++;

}

template<class T>
void VD<T>::borrar(int pos)
{

 for(int i=pos;i<n-1;i++){ 
  datos[i] = datos[i+1];
 }
 n--;
 if(n<reservados/4){
    resize(reservados/2);
 }

}

template <class T>
T & operator[]( const int i){ return datos[i]; }


template <class T>
int VD<T>::size()const{ return n; }

