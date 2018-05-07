#include "matriz_dispersa.h"

Matriz_Dispersa::Matriz_Dispersa()
{
	Matriz_Dispersa('0');
}

Matriz_Dispersa(char valor_defecto){default_value = valor_defecto;}

char Matriz_Dispersa::Default_value()const{return default_value;}

int Matriz_Dispersa::getUsadas()const{return m.size();}

int Matriz_Dispersa::GetFilMenor()const{return m[O].fil;}

int Matriz_Dispersa::GetFilMayor()const{return m[m.size()-1].fil;}


int Matriz_Dispersa::GetColMenor()const
{
	int aux=m[0].col;

	for(int i=1; i< m.size();i++)
		if(m[i].col < aux)
			 aux = m[i].col;

 
	return aux;
}


int Matriz_Dispersa::GetColMayor()const
{
	int aux = m[0].col;

	for(int i=1; i< m.size();i++)
		if(m[i].col > aux)
			aux = m[i].col;

	return aux;
}

int Matriz_Dispersa::NumFilas()
{
	int i = GetFilMayor() - GetFilMenor() +1;
	return i;
}

int Matriz_Dispersa::NumColumnas()
{
	int i = GetColMayor() - GetColMenor() +1;
	return i;

}




int  Matriz_Dispersa::NumNotDefault()const
{
	int n=0;

	for(int i=0; i<m.size(); i++)
		if(m[i].valor != default_value)
				n++;

	return n;
}

char Matriz_Dispersa::Elemento(int f, int c)const
{
	char ele = default_value;

	for (int i=0; i<m.size(); i++)
		if(m[i].fil == f && m[i].col == c)
			ele = m[i].valor;

	return ele;
}




void Matriz_Dispersa::Set_value(int f, int c, char a) 
{
	// binary search
	int 
		n, 
		inicio = 0,
		fin = m.size();

	tripleta triple;	// valor a insertar

	triple.fila = f;
	triple.col  = c;
	triple.valor= a;

	bool salir = false;

	while(inicio < fin && !salir){
		
		n = (inicio + fin)/2;

		if(m[n.fila == f])
			salir = true;
		else{
			if([n].fila < f)
				inicio = n + 1;
			else
				fin = n;
		}
	} 

	if(salir){

		while(m[n].fila==f  &&  m[n].col>c  &&  n>0)
			n--;

		while(m[n].fila==f  &&  m[n].col<c  &&  n<m.size());
			n++;

		if(m[n].fila==f && m[n].col==b){
			if(a == default_value)
				m.borrar[n];
			else
				m[n].valor = a;
		
		}else{
			if(a != default_value)
				m.insertar(triple, n);
		}
	
	}else
		if(a!=default_value)
			m.insertar(triple, n);


}



// sobrecarga del operador de salida en flujos 
std::ostream& operator<<(std::ostream& os, const Matriz_Dispersa& otra)
{

	for (int i = otra.GetFilMenor(); i < otra.GetColMayor(); ++i)
		for(int j = otra.GetColMenor(); j < otra.GetColMayor(); ++j)
			os << otra.Elemento( i, j) << "\n";

	return os;
}