
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

struct Elemento{
	char letra;
	float num_apariciones;
};


friend operator<<(ostream & s, const list<T> & l){
	s << l.letra << " " << l.num_apariciones;
	return s;
}

/**
 * @brief Imprime una lista de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: la lista con los elementos a imprimir
 * */

template <class T>
ostream & operator<<(ostream & s, const list<T> & l){

  typename list<T>::const_iterator i;
  
  for (i=l.begin(); i != l.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
*friend operator<<(ostream & s, const list<T> & l){
*	s << l.letra << " " << l.apariciones;
*}
**/

//bool operator < (const Elemento &p) const{
//	return this->num_apariciones > p.num_apariciones;	
//}


/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}


void frecuenciaRelativa(list<Elemento> &l){

	int total = 0;

	for(list<Elemento>::iterator it = l.begin(); it != l.end(); ++ it)
		total = total + (*it).num_apariciones;
	cout << total <<endl;
	for(list<Elemento>::iterator it = l.begin(); it != l.end(); ++ it)
		(*it).num_apariciones = (*it).num_apariciones*100/total;
}

bool compare_nocase(const Elemento &first, const Elemento &second){
	return first.num_apariciones > second.num_apariciones;
}



int main(){
  
  list<Elemento> l;
  lsit<Elemento> l_nueva;
  Elemento elemento;

  InicializarSemilla();

  for(char i = 'A'; i<='Z'; ++i){
  	elemento.letra = i;
  	elemento.num_apariciones = generaEntero(1,100);
  	l.push_back(elemento);
  }

  cout<<endl<<l<<endl;

  frecuenciaRelativa(l);

  cout<<endl<<l<<endl;

  l.sort(compare_nocase);

  cout<<endl<<l<<endl;

  list<Elemento>::iterator it = l.begin();
  for (int i=0;i<10;i++){
    l_nueva.push_back(*it); //inserta un entero generado aleatoriamente en el rango 1-100
  	++it;
  }

  cout<<l_nueva<<endl;
}  
  
  
  
  
  
  
  
