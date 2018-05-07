7/11/17 - ED

Pilas

clas stack
	top
	pop
	push
	empty
	size

_________clase cola implementada con una pila___________

#inlcude <stack>
using namespace std;

template <class T>
class Cola{
private:
	stack<T> datos;
public:
	T front{
		stack <T> aux;
		T v;
		while(!datos.empty()){
			v = datos.top();
			aux.push(v);
			datos.pop();
		}

		while(!aux.empty()){
			datos.push(aux.top());
			aux.pop();
		}
		return v;
	}

	bool empty() const{
		return datos.empty;
	}

	int size()const{
		return datos.size();
	}

	void push(const T &v){
		datos.push(v);
	}

	void pop(){
		stack<T> aux;
		T v;
		while(!datos.empty){
			v=datos.top();
			aux.push(v);
			datos.pop();
		}
		aux.pop();

		while(!aux.empty()){
			datos.push(aux.top());
			aux.pop();
		}
	}
}



____________________________________________-


Clase Queue

hay que hacer #include <queue>


- funcion que nos diga si una frase es un palíndromo o no-

#include <queue>
#include <stack>
#include<iostream>
#include<string>

using namespace std;

bool palindromo(const String & frase){
	queue<char> q;
	stack<char> p;

	for(int i =0; i<frase.size(); i++){
		if(frase[i]!=''){
			q.push(frase[i]);
			p.push(frase[i]);
		}
	}
	while(!q.empty()){
		if(p.top() != q.front()){
			return false;
		}

		p.pop();
		q.pop();
	}

	return true;


___________________________________________

Priority queue


#include <queue>
#include <iostream>

int main(){
	piority_queue<int> mypq;

	mypq.push(30);
	mypq.push(100);
	mypq.push(25);
	mypq.push(40);

	while(!mypq.empty){
		cout<<mypq.pop()<<' ';
		mypq.pop();
	}
}



___________________________________________


DOBLE COLA 	

#include <deque>

template <class T>
class PilaOCola{
private:
	deque<T> datos;
	bool is_cola; //True se comporta como una cola, false se comporta como pila

public:
	PilaOCola(bool tipo):is_cola(tipo){	}

	T & operator()(){
		if(is_cola){
			return datos.front();
		}
		else{
			return datos.back();
		}
	}

	const T &operator () () const{
		if(is_cola){
			return datos.front();
		}
		else{
			return datos.back();
		}
	}

	int size()const{
		return datos.size();
	}

	void pop(){
		if(is_cola){
			 datos.pop_front();
		}
		else{
			 datos.pop_back();
		}
	}

	void push(const T &v){
		datos.push_back(v);
	}

	bool empty() const{
		return datos.size()==0;
	}
}


//Principal.cpp

#include "PilaOCola.h"
#include <iostream>

using namespace std;

int main(){

	PilaOCola<int> pila (false);
	PilaOCola<int> cola(true);

	for(int i=10; i<100; i+=10){
		pila.push(i);
		cola.push(i);
	}

	cout<<"Los elementos de la pila: ";
	
	while(!pila.empty()){
		cout<<pila()<<' ';
		pila.pop();
	}

	cout<<"Los elementos de la cola: ";

	while(!cola.empty()){
		cout<<cola()<<' ';
		cola.pop();
	}


}















