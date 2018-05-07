
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;


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



struct Elemento{
	char letra;
	int apariciones;
};


int main(){
  
  list<int> l;

  list<Elemento> lista;
  Elemento ele;

  list<Elemento>::iterator iterator;


  int total_apariciones = 0;

  for(char i = 'A'; i<='Z'; ++i){
  	ele.letra = i;
  	ele.apariciones = generaEntero(1,100);
  	total_apariciones += ele.apariciones;
  	lista.push_back(ele);
  }

	for (iterator = lista.begin(); iterator != lista.end(); ++iterator) {
    	cout << *iterator;


  InicializarSemilla();
  
  for (int i=0;i<10;i++)
    l.push_back(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  cout<<endl<<l;
}  
  
  
  
  
  
  
  
  