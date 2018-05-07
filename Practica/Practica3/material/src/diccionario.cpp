
#include <iostream>
#include <string>
#include <array>
#include <map>

using namespace std;


Template <typename T> 
	class Diccionario{
	private:
		multimap<string,string> datos;
	public:
		class iterator{
		private:
			multimap<string, string>::iterator it;
		public:
			bool operator==(const iterator &i){
				return it == i.it;
			}

			bool operator!=(const iterator &i){
				return it != i.it;
			}
			
			pair <string, string> &operator*(){
				return *it;
			}

			iterator & operator++(){
				++it;
				while()
					++it;
				return *this;
			}

			iterator & operator--(){
				--it;
				while()
					--it;
				return *this;
			}
		}

		friend class Diccionario;


	iterator begin(){
		iterator i;

		i.it = datos.begin();
		i.final = datos.end();
		++i;

		return i;
	}

	iterator end(){
		iterator i;
		i.it = datos.begin();
		i.final = datos.end();
	}
}; 