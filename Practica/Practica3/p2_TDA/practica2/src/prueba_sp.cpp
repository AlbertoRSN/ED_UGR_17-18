#include "matriz_dispersa.h"
#include <fstream>
#include "sopa_letras.h"


#define YELLOW   "\033[33m"
#define BLUE     "\033[34m"
#define WHITE    "\033[37m"


using namespace std;


int main(int argc, char * argv[]){
 
    if (argc!=2){
      cout<<"Dime el nombre del fichero con las palabras de la sopa de letras"<<endl;
      return 0;
    }
    ifstream f(argv[1]);

    if (!f){
	   cout<<"No puedo abrir "<<argv[1]<<endl;
	   return 0;
    }
    Sopa_letras Sl;
    f>>Sl;
    //Leemos las palabras y construimos la sopa de letras
    //El usuario ahora tiene que ir descubriendo las palabras
    //en la sopa de letras
    while (Sl.GetNumNoDescubiertas()>0){
       cout<<Sl<<endl;
       cout<<"Dime una palabra: ";
       string word;
       cin>>word;
       cout<<"Dime la fila :";
       int row;
       cin>>row;
       cout<<"Dime la columna :";
       int col;
       cin>>col;
       
       cout<<"Direccion Arriba (vu), Abajo (vd), Izquierda (hi) , Derecha (hd), Diagonal abajo derecha (dd),Diagonal abajo izquierda (di) :";
       string direccion;
       cin>>direccion;

       if (!Sl.Comprobar_Palabra(word,row,col,direccion)){//Esta?
	       cout<<"La palabra "<<word << " no esta"<<endl;
       }
       else{
	     //La pone en negrita. Ademas la pone dentro de la lista de palabras descubiertas.
       cout<< YELLOW << "¡Genial! Ha encontrado la palabra: " << BLUE << word << WHITE << endl;
	     Sl.Poner_Acertada(word);

       }
    }
    cout<<Sl<<endl;
       
}     