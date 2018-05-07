ED - 31/10/2017


STL: Standar template library

EDL
	·Vector -> #inclucde <vector>
	·list -> #include <list>
	·queue
	·priority_queue -> #include <queue>
	·stack -> #include <stack>

	----O----

	LIST

	#include <iostream>
	#include <list>

	using namespace std;
	int main(){
		int mienteros[] = {13,12,10,20}
		list <int> miLista;
 
		miLista.assign(mienteros, mienteros+4); //los parametros son direcciones de memoria
		miLista.assign(7,100); //Crea lista con 7 enteros inicializados con valor 100


		list <int> otraLista;
		otraLista.assign(miLista.begin(), milista.end()); //13,12,10,20
		otraLista.assign(miLista.begin(), miLista.begin()+2);


		//Lista con iteradores (Clase list tiene dentro un iterator)
		list <int> l3;
		list <int>::iterator it;

		for(it=otraLista.begin(); it != otraLista.end(); ++it){
			l3.push.back(*it); //al final de l3 mete *it (elemento al que apunta)
		}

		void Imprimir(const list<int> &l){
			list<int>::const_iterator it;
			for(it = l.begin(); it != l.end(); ++it)
				cout<<*it;
		}

		//Eliminar -> erase
		l3.erase(l3.begin() + 1, l3.begin() + 3);
		l3.erase(l3.begin());

		Aspectos a tener en cuenta con erase:
			iterator erase(iterator posicion);
			iterator erase (iterator first, iterator end);		
	}


SPLICE -> Mueve los elementos de una lista a otra.

	list <int> l1, l2;
	list <int>::iterator it;

	for(int i=1; i<= 4; i++){
		l1.push_back(i);
	}//L1 -> 1,2,3,4

	for(int i=1; i<=3; i++){
		l2.push_back(i*10);
	}//L2 -> 10, 20, 30

	it = l1.begin(); 
	++it;
	l1.splice(it, l1); 

---------------------------------------------

REMOVE -> Elimina todos los elementos de la lista con un valor

	int mienteros[] = {3,4,74,15}
	list<int> l(mienteros, mienteros+4);
	l.remove(79);


Remove_if -> Eliminar los elementos de la lista que cumplan una condicion

	//Crear funcino booleana que tenga como parametro un parametros igual tipo que tipo base de la lista

	bool Par(int v){
		return v%2;
	}

	int main(){
		list<int> l;
		for(int i=1; i<10; i++){
			l.push_back(i);
		}
		l.Remove_if(Par);
	}


UNIQUE -> Elimina valores duplicados que se encuentran consecutivamente, dejando una unica ocurrencia

{1,1,1,2,2,3,4,4,4} -> {1,2,3,4}

unique() -> elimina cuando establece la igualdad de dos elementos consecutivos usando ==
unique(funcion) -> establece la igualdad segun la funcion


#include <list>
using namespace std;

bool iguales_enteros(double v1, double v2){
	return (int) v == (int) v2;
}

int main(){
	double m[] = {12.15, 2.75, 73.0, 12.77, 3.14, 12.77, 73.55, 72.25, 15.3, 72.25};
	list<double> l1(m, m+10);
	l1.sort(); // ordena la lista de menor a mayor.
	l1.unique(); //Elimina elementos repetidos tal cual (iguales desde el punto de vista de dos doubles)
	l1.unique(iguales_enteros); //Elimina los que sean iguales desde el punto de vista de int
}

_____________________________________________________________

bool compare_nocase(const string &first, const string &second){
	unsigned int i = =;

	while(i<firs.length() && i<second.size()){
		if(tolower(first[i]) < tolower(second[i]))
			return true
		else
			if(tolower(first[i]) > tolower(second[i]))
				return false
		++i;
	}

	return (first.length()<=second.length());
}


