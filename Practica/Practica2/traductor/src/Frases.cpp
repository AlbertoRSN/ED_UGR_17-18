#include<iostream>
#include<fstream>
#include "Frases.h"

using namespace std;


//****************************************************************************
ifstream& operator>> (ifstream& i, Frase& f){
    
   int found=-1, found_anterior = -1;
   string linea;

   getline(i, linea);
   found = linea.find(";", found + 1);
   f.SetOrigen(linea.substr(found_anterior + 1, found - found_anterior - 1));

   found_anterior = found;
   found = linea.find(";", found + 1);

   while(found != -1){
      f.AniadirDestino(linea.substr(found_anterior + 1, found - found_anterior - 1));
      found_anterior = found;
      found = linea.find(";", found + 1);
   }

   f.AniadirDestino(linea.substr(found_anterior + 1, found - found_anterior - 1));
   
   return i;

 /*
    string linea;
    //Cargamos la linea
    getline(inputs,linea); //Esto mete en linea lo que venga de inputs
    
    //Buscamos la frase origen
    int i_ant=0;
    int i_sig=linea.find(";",i_ant);
 
    //Extraemos la frase origen
    f.SetOrigen(linea.substr(i_ant,i_sig));
    i_ant=i_sig+1;
    i_sig=linea.find(";",i_ant);

    return inputs;
*/
}


//****************************************************************************
string Frase::GetFraseOrigen(){
    return origen;
}


//****************************************************************************
vector<string> Frase::GetDestino(){
    return destino;
}


//****************************************************************************
void Frase::SetOrigen(string orig){
	this->origen=orig;
}

//****************************************************************************
void Frase::SetDestino(vector <string> traducciones){
	this->destino=traducciones;
}


//****************************************************************************
void Frase::AniadirDestino(string c){
	this->destino.push_back(c);
}


//****************************************************************************
void Frase::Borrar(){
	this->destino.clear();
}
