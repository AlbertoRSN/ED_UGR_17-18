ED - 03/11/2017

MERGE

Mezcla dos listas ordenadas

#include <iostream>
#include <list>
#include <string>
#indluce <ctype>
#include <algorithm>

bool compare_nocase(const string &first, const string &second){
	unsigned int i=0;

	while(i < first.size() && i < second.size()){
		if(tolower(first[i]) < tolower(second[i]))
			return true;
		else
			if(tolower(first[i] > tolower(second[i])))
				return false;
		++i;
	}
	return (first.size() < second.size());
}

int main(){
	list<string> milista1, milista2;
	list<string>::iterator it;

	milista1.push_back("manzana");
	milista1.push_back("banana");

	milista2.push_back("Pera");
	milista2.push_back("Sandia");
	milista2.push_back("Melon");

	milista1.sort(); //milista1 -> banana manzana
	milista2.sort(); //milista2 -> Melon Pera Sandia

	milista1.merge(milista2);

	//milista1 = Melon Pera Sandia banana manzana
	//milista2 es vacia

	milista2.push_back("apple");
	milista1.merge(milista2, compare_nocase);

	milista1.sort(compare_nocase);

	//milista1 = apple banana manzana Melon Pera 

	for(it = milista1.begin(); it != milista1.end(); ++it)
		cout<<*it<<' ';

}

__________________________________________________________


REVERSE

	Invierte una listas

	#include <list>
	#include <iostream>

	using namespace std;

	int main(){
		list<char> milista;

		for(char a='a'; a<z; ++a){
			milista.push_back(a);
			milista.reverse();
		}
	}

__________________________________________________________

T.D.A Diccionarios (map)

	Es una coleccion de pares (clase, definicion). No hay clases repetidas.

	//Diccionario.h
	#include <string>
	#include <list>
	#include <iostream>

	using namespace std;

	//Podria usar un pair de la STL pero vamos a usar un struct con dos campos
	//Los pares estan ordenados por clave

	template <class T, class U>
	struct data
	{
		T clave;
		U info_asoci;
	};

	template <class T, class U>
	bool operator<(const data<T,U> &d1, const data<T,U> &d2){
		return (d1.clave<d2.clave);
	}
	
	template <class T, class U>
	class Diccionario{
	private:
		list <data<T,U>> datos;
	public:
		bool Esta_clave(const T &c1, typename list<data<T,U>>::iterator &it_out);
		void Insertar(const T &c1, const U &info);
	}


	//Diccionario.cpp
	template <class T, class U>
	bool Diccionario<T,U>::Esta_clave(const T &c1, typename list<data<T,U>>::iterator &it_out){
		if(datos.size()>0){
			typename list<data<T,U>>::iterator it;
			for(it=datos.begin(); it != datos.end(); ++it)
				if((*it).clave == c1){
					it_out = it;
					return true;
				}
				else{
					if((*it).clave > c1){
						it_out = it;
						return false;
					}
				}
			}

			it_out = datos.end();
			return false;
		}
	}

	void Diccionario<T,U>::Insertar(const T &c1, const U &info){

		typename list <data<T,U>>::iterator it;
		if(!Esta_clave(c1,it)){
			data<T,U> p = {cl, info};
			datos.insert(it, p);
		}
	}


















