#include <iostream>
#include <string>
#include <map>

using namespace std;

multimap <string,string>:: iterator it;

if(argc != 2){
	cout<< "Dime el nombre del fichero del diccionario: "<<endl;
	return 0;
}

ifstream f(argv[1]){
	if(!f){
		cout<< "No puedo abrir el fichero "<<endl;
		return 0;
	}
}

while(!f.eof()){
	getline(f,linea_diccionario,'\n');
	//Busco un texto dentro de la cadena y obtengo la posicion
	int pos = linea_diccionario.find(";");

	//Obtengo una subcadena a partir del texto
	palabra = linea_diccionario.substr(0,pos);
	significado = linea_diccionario.substr(pos+1);

	diccionario.insert(Componente(palabra,significado));

}

for(it = diccionario.begin(); it != diccionario.end(); ++it){
	cout << it->first << "---->" << it->second << endl;
}