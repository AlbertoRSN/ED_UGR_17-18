#include <iostream>
#include "ConjuntoFrases.h"

#include <fstream>
#include <cstdlib>
using namespace std;


int main(int argc, char * argv[]){
  if (argc!=2){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.Dime el nombre del fichero con las frases "<<endl;
      return 0;
  }    
  
  ifstream fin(argv[1]);
  if (!fin){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }
  
  ConjuntoFrases CF;
  
  fin>>CF;	//Leemos las frases en CF. En ese momento empezamos a leer el origen y vamos añadiendole sus traducciones
  cout<<"Leidas las frases. Numero Total : "<<CF.Size()<<endl; 	//Una vez hecho lo anterior ya tenemos cuantas frases hay
  
  cout<<"************************************";
  //Escribimos las frases ordenadas
  cout<<"Frases leidas "<<endl; 	
  cout<<CF<<endl;	//Imprimimos las frases de forma ordenada, junto con sus traducciones
  
  cout<<"Dime una frase en el idioma origen:"<<endl;
  string ff;
  getline(cin,ff);	//Igual que poner cin >> ff, asi que esto lo hace el usuario
  
  //no distingue entre mayusculas y minusculas
  if (CF.Esta(ff)){	//Esta(ff) recorre toda la lista de conjunto de frases, y compara el origen de cada frase para ver si esta o no
	 Frase f =CF.GetTraducciones(ff);  //muestra/devuelve la traduccion o traducciones de la frase introducida(origen)
	 for (unsigned int i=0;i<f.GetDestino().size();++i) //f.GetDestino().size() devuelve el tamaño del vector de traducciones
	    cout<<f.GetDestino()[i]<<endl;	//Devuelve la traduccion de la posicion i para esa frase origen
  }
  else{
      cout<<"Esa frase no esta ";
  }
  
  //Construimos un conjunto de frases que contenga una subcadena
  cout<<endl;
  cout<<"Dime una subcadena  que quieras buscar en la frase origen con sus traducciones:";
  string c;
  getline(cin,c);	//Es igual que cin >> c
  ConjuntoFrases CF_consub=CF.Contenga(c);	//Muestra las frases origen que contengan esa subcadena, junto con sus traducciones
  
  //Visualizamos todas las frases con sus traducciones que contienen
  //la subcadena de entrada
  cout<<CF_consub;
}  
