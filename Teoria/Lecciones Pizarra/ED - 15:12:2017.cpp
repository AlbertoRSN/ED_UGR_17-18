ED - 15/12/2017

T.HASH

unordered_set y unordered_multiset -> #include unordered_set
unordered_map y unordered_multimap -> #include unordered_map

unordered_Set <int> miunor.set;
unordered_multiset <int> miunor.set;

Ejemplo:

	#include <iostream>
	#include <string>
	#include <array>
	#include <unordered_set>

	using namespace std;

	int main(){
		unordered_set<string> myset = {"yellow", "green", "blue"};
		string mystring = "red";
		myset.insert(mystring);
		myset.insert(mystring"dash");
		array <string,2> myarray = {"black", "white"};
		myset.insert(myarray.begin(), myarray.end());
		myset.insert({"purple", "orange"});

		unordered_set<string>::iterator it;

		for(it=myset.begin(); it!=myset.end(); ++it){
			cout<<*it<<' ' ;
		}

		myset.clear();

		cout<<myset.size(); //devolvera 0

		myset.rehash(12); //Reserva para mi tabla hash 13 cubetas
		myset.insert({"USA", "FRANCE", "UK", "JAPA", "GERMANY", "ITALY"});
		myset.erase(myset.begin());
		myset.erase("FRANCE");
		myset.erase(myset.find("JAPAN"), myset.end());

		cout<< myset.bucket_count(); //n cubetas.
		cout<< myset.load_factor(); //factor de carg
		cout<< myset.max_load_factor();
		stringset::haser fn = myset.hash_function();

		cout<< fn("purple");
		cout<< fn("orange");
	}


	Ejemplo examen 15/16

	template <typename T> //poner typename o class es lo mismo.
	class Contenedor{
	private:
		unordered_map<T,vector<int>> datos;
		....
	public:
		class iterator{
		private:
			unordered_map<T,vector<int>>::iterator it, final;
		public:
			bool operator==(const iterator &i){
				return it == i.it;
			}

			bool operator!=(const iterator &i){
				return it != i.it;
			}
			
			pair <const T, vector<int>> &operator*(){
				return *it;
			}

			iterator & operator++(){
				++it;
				while(suma((*it).second)%2 == 0 && it != final)
					++it;
				return *this;
			}

			iterator & operator++(){
				--it;
				while(suma((*it).second)%2 == 0 && it != final)
					--it;
				return *this;
			}
		}

		friend class contenedor


	iterator begin(){
		iterator i;

		i.it = datos.begin();
		i.final = datos.end();

		if(suma(*(i.it).second % 2 == 0)
			++i;
		return i;
	}

	iterator end(){
		iterator i;
		i.it = datos.begin();
		i.final = datos.end();
	}
}; //CONTENEDORA


int suma(vector <int> &v){
	int s = 0;

	for(int i = 0; i<v.size(); i++)
		st = v[i];
	return s;
}

Contenedor<String> C;

contenedor::iterator i;

for(i = C.begin(); i != i.end())
	++i;
cout<<*i;

