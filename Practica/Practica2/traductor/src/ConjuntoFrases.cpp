#include<iostream>
#include <fstream>
#include "ConjuntoFrases.h"
using namespace std;


//****************************************************************************
int ConjuntoFrases::Size(){
	return this->CF.size();
}


//****************************************************************************
bool ConjuntoFrases::Esta(string orig_a_buscar){
  bool encontrada=false;

  //Recorro el conjunto de frases hasta encontrar la frase origen
  for(int i=0;i<this->Size() && !encontrada;i++){
	if(CF[i].GetFraseOrigen()==orig_a_buscar)
		encontrada=true;
  }
  return encontrada;
}


//****************************************************************************
Frase ConjuntoFrases::GetTraducciones(string orig_a_buscar){
  Frase f;
  vector <string> traducciones;
  bool parar=false;

  //Recorro el conjunto de frases hasta encontrar la frase origen
  for(int i=0;i<this->Size() && !parar;i++){
	if(CF[i].GetFraseOrigen()==orig_a_buscar){
		parar=true;
  		traducciones=CF[i].GetDestino();
  	}
  }
  f.SetOrigen(orig_a_buscar);
  f.SetDestino(traducciones);

  return f;
}


vector <Frase> ConjuntoFrases::GetCF(){
	return this->CF;
}

//****************************************************************************
void ConjuntoFrases::Aniadir(Frase& i){
	this->CF.push_back(i);
}

//****************************************************************************
ConjuntoFrases ConjuntoFrases::Contenga(string subcadena_a_buscar){
	ConjuntoFrases nuevo_cf;
	int cont;
	for(int i=0; i<this->Size();i++){
		cont=this->CF[i].GetFraseOrigen().find(subcadena_a_buscar,0);	//Si no lo encuentra devuelve -1
		if(cont!=-1)
			nuevo_cf.Aniadir(this->CF[i]);
	}
	
	return nuevo_cf;
}


//****************************************************************************	
//Sobrecarga de operador >>
ifstream& operator>> (ifstream& inputs, ConjuntoFrases& cf){
  //Creamos una frase
  Frase f; 
  //Leemos todas las frases, esto se va haciendo en la clase Frases
  while(inputs >> f){
	
	//Añadimos la frase al conjunto de frases
	cf.Aniadir(f);
	f.Borrar();
  }
  return inputs;
}


//****************************************************************************
//Operador <<
ostream& operator<< (ostream & os, ConjuntoFrases & cf){
   for(int i=0;i<cf.Size() ;i++){
  	os <<cf.GetCF()[i].GetFraseOrigen() << endl;
	for (unsigned int j = 0; j < cf.GetCF()[i].GetDestino().size(); j++)
		os << "\t" << cf.GetCF()[i].GetDestino()[j] << endl ;
	os << endl;
   }
   return os;
}
