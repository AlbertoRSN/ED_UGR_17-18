ED - 27/10/2017 

VECTOR DISPERSO

Es un array 1-d de tipo T con indices enteros positivos sin limitacion de rango. Este vector se usa para almacenar valores donde la mayoria tiene un valor predeterminado.

{(i[0], v[0]), (i[1], v[1]),. . . , (i[n-1],v[n-1]), (*,d)}
En la matriz dispersa tendremos tripletas.

{(5, "patata"), (2, "melon"),. . . , (10,"Boniato"), (*,"")} //El ultimo que es (*,"") significa que en el resto, se rellena vacio


#include <vector>
using namespace std;

template <class T>

class Vector_Disperso{
	private:
		vector<pair<int, T>> datos;
		T valor_por_defecto;
		pair<bool, typename vector <pair<int,T>::iterator> posicion_indice(int i);

	public:
		Vector_Disperso(T defecto = T()): valor_por_defecto(defecto){} 
		
		T get_default()const{
			return valor_por_defecto;
		}

		T get(int i)const;

		void set(int i, T f);

}



//VECTOR DISPERSON.CPP

template <class T>
pair <bool, typename vector<pair<int, T>>::iterator> Vector_Dispersor<T>::posicion_indice(int i){
	int izq = 0;
	int der = catos.size() - 1;
	int centro;

	while(der - izq >= 0){
		centro = izq+der)/2;
		if(i<datos[centro].first)
			der = centro - 1;
		else
			if(i>datos[centro].first)
				izq = centro + 1;
			else
				return (pair<bool, typename vector<pair<int,T>>::iterator>(true, datos.begin()+centro);

	return pair <bool, vector<pair<int,T>>::iterator>(false, datos.begin()+izq);
	}
}

template<class T>
T Vector_Disperso<T>:: get(int i) const{
	pair <bool, typename vector<pair<int,T>>::iterator ret;
	ret = posicion_indice(i);
	if(ret.first){
		return (*(ret.second)).second;
	}

	else
		return valor_por_defecto;
}

template<class T>
T Vector_Disperso<T>::void set(int i, T f){
	pair<bool, typename vector<pair<int,T>>::iterator ret;

	ret = posicion_indice(i);

	if(ret.first){
		if(f != valor_por_defecto){	
			(*(ret.second)).second = f;
		}

		else
			datos.erase(ret.second);
	}

	else{//ret.first!=false
		datos.insert(ret.second, pair<int,T>(i,f));
	}
}

















