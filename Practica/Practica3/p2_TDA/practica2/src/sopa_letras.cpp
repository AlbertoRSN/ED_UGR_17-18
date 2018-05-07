#include "sopa_letras.h"
#include <stdlib.h>     /* srand, rand */

using namespace std;

Sopa_letras::Sopa_letras(){}


bool Sopa_letras::EstaDescubierta(const string palabra)
{
	bool k = false;

	for(int i = 0; i < descubiertas.size() && !k; i++)
		if(no_descubiertas[i] == palabra)
			 k = true;

	return k;
}



int Sopa_letras::GetNumDescubiertas()const{
  return descubiertas.size();
}
		
int Sopa_letras::GetNumNoDescubiertas()const{
  return no_escubiertas.size();
}




bool Sopa_letras::Comprobar_Palabra(const string palabra, int fil, int col, const string dir)
const{

   bool esta = true; 


   switch(dir){
   
   case "hd"://horizontal derecha
    for(int i=0;i< palabra.length() && esta;i++)
     if(m.GetEle(fil,col+i) != palabra[i])
      esta=false;
  	break;
     
    
  
   case "hi"://horizontal izquierda
    for(int i=0;i< palabra.length() && esta;i++)
     if(m.GetEle(fil,col-i) != palabra[i])
      esta=false;
     break;
    
   
   case "vu"://vertical arriba
    for(int i=0;i< palabra.length() && esta;i++)
     if(m.GetEle(fil-i,col) != palabra[i])
      esta=false;
     break;
    
   
   case "vd"://vertical abajo
    for(int i=0;i< palabra.length() && esta;i++)
     if(m.GetEle(fil+i,col) != palabra[i])
      esta=false;
     break;
    
   case "di"://diagonal izquierda
    for(int i=0;i< palabra.length() && esta;i++)
     if(m.GetEle(fil-i,col+i) != palabra[i])
      esta=false;
     break;

   case "dd"://diagonal derecha
    for(int i=0;i< palabra.length() && esta;i++)
     if(m.GetEle(fil+i,col+i) != palabra[i])
      esta=false;
     break;
    
   

    default:
    	esta=false;
    	break;
   }
   

   return esta;


}









void Sopa_letras::SetPalabra(string palabra, int fil, int col, const string dir)
{

 
  if(PuedeInsertar(fil,col,dir,palabra))
  {

   switch(dir){
   
   case "hd"://horizontal derecha
    for(int i=0;i< palabra.length();i++)
     m.Set_value(fil,col+i, palabra[i]);
  	break;
     
  
   case "hi"://horizontal izquierda
    for(int i=0;i< palabra.length();i++)
     m.Set_value(fil, col-i, palabra[i]);
     break;
    
   
   case "vu"://vertical arriba
    for(int i=0;i< palabra.length();i++)
     m.Set_value(fil-i, col, palabra[i]);
     break;
    
   
   case "vd"://vertical abajo
    for(int i=0;i< palabra.length();i++)
     m.Set_value(fil+i, col, palabra[i]);
     break;
    
   case "di"://diagonal izquierda
    for(int i=0;i< palabra.length();i++)
     m.Set_value(fil-i,col+i, palabra[i]);
     break;

   case "dd"://diagonal derecha
    for(int i=0;i< palabra.length();i++)
	 m.Set_value(fil+i,col+i, palabra[i]);
     break;

   }
   

  }

}	




/*Una palabra puede colocarse si en cada casilla que ocupa tiene el valor por defecto,
o si no es así el carácter en la matriz debe coincidir con el carácter que corresponda de la palabra*/
bool Sopa_letras::PuedeInsertar(int fil, int col, const string dir, const string palabra)
const{

   bool puede = true; 


   switch(dir){
   
   case "hd"://horizontal derecha
    for(int i=0;i< palabra.length() && puede;i++)
     if( m.GetEle(fil,col+i) != palabra[i] || m.GetEle(fil, col+i) != m.Default_value() )
         puede=false;
  	break;
  
   case "hi"://horizontal izquierda
    for(int i=0;i< palabra.length() && puede;i++)
     if( m.GetEle(fil,col-i) != palabra[i] || m.GetEle(fil, col-i) != m.Default_value() )
         puede=false;
     break;
    
   
   case "vu"://vertical arriba
    for(int i=0;i< palabra.length() && puede;i++)
     if( m.GetEle(fil-i,col) != palabra[i] || m.GetEle(fil-i, col) != m.Default_value() )
         puede=false;
     break;
    
   
   case "vd"://vertical abajo
    for(int i=0;i< palabra.length() && puede;i++)
     if( m.GetEle(fil+i,col+i) != palabra[i] || m.GetEle(fil+i, col) != m.Default_value() )
         puede=false;
     break;
    
   case "di"://diagonal izquierda
    for(int i=0;i< palabra.length() && puede;i++)
     if( m.GetEle(fil-i,col+i) != palabra[i] || m.GetEle(fil-i, col+i) != m.Default_value() )
     	puede=false;
     break;

   case "dd"://diagonal derecha
    for(int i=0;i< palabra.length() && puede;i++)
     if( m.GetEle(fil+i,col+i) != palabra[i] || m.GetEle(fil+i, col+i) != m.Default_value() )
     puede=false;
     break;
    
   

    default:
    	puede=false;
    	break;
   }
   

   return puede;
}



//Modificar una palabra en la matriz dispersa como acertada. Quitarla de
//palabras no descubiertas y moverla a palabras descubiertas.
void Sopa_letras::Poner_Acertada(const string palabra)
{

   if(EstaDescubierta(palabra))
   {
    
    bool k = false;
    
    for(int i=0;i< no_descubiertas.size() && !k;i++){
     if(no_descubiertas[i] == palabra){
      no_descubiertas.borrar(i);
      descubiertas.insertar(palabra, descubiertas.size());    
      k = true;
  	 }
    }

   }


}

void Sopa_letras::EliminarPalabra(string palabra, int fil, int col, const string dir)
{
   string borrado = "";


   if(Comprobar_Palabra(fil, col, direccion, palabra))
   {
    bool aux=false;

    for(int i=0;i< no_descubiertas.size() && !aux;i++)
     if(palabra ==  no_descubiertas[i]){
      no_descubiertas.borrar(i);
      aux=true;
     }
    
    for(int i=0;i< descubiertas.size() &&!aux;i++)
     if(palabra == descubiertas[i]){
      descubiertas.borrar(i);
      aux=true;
     }
    
    //poner valor por defecto
    for(int i=0;i< palabra.length();i++)
     borrado = borrado + m.Default_value();

    

    SetPalabra(borrado,f,c,dir);    
   }

}


// Generar caracter aleatorio

char Sopa_letras::CaracterAleatorio()
{
	int r = rand() % 26;
	char c = 'A' + r;
	return c;
}






friend ostream& operator<< (ostream& os, const Sopa_letras& s)
{
   os << "Titulo: " << TITULO << endl;

   os << endl << "Numero de palabras ocultas: " << s.GetNumNoDescubiertas();

   os << endl << "Numero de palabras descubiertas: " << s.GetNumDescubiertas();
   
   for(int j=s.m.GetColMenor();j<s.m.GetColMayor();j++)
    os << "\t" << j << " " << endl;

   for(int i=s.m.GetFilMenor();i<s.m.GetFilMayor();i++){
    os << i << "\t";
    
    	for(int j=s.m.GetColMenor();j<s.m.GetColMayor();j++)
   		  os << s.m.GetEle(i, j) " "; 
    
    os << endl;
   }

   os << s.m
   return os;
}

friend istream& operator>> (istream& is, Sopa_letras& s)
{
   is >> TITULO;
   while(isspace(is.peek())){	//Returns the next character in the input sequence, 
   								//without extracting it: The character is left as the 
   								//next character to be extracted from the stream.
    is.ignore();
   }


   return is;
}



/*************************************************************************/
ostream& bold_on(ostream& os)
{
return os << "\e[1m";
}
/*************************************************************************/
ostream& bold_off(ostream& os)
{
return os << "\e[0m";
}
//Estas funciones para escribir en negrita podemos hacer
//cout<<bold_on<<”HOLA”<<bold_off<<endl;
/*************************************************************************/
