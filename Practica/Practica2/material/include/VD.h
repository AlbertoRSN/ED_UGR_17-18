template <class T> //En VD.h
class VD{
private:
	T* datos;//zona de memoria para almacenar los datos de tipo T 6 
 	int n; //numero de datos almacenados
 	int reservado; //espacio asignado a datos
 	void resize (int nuevotam);
 	void Copiar (const VD<T> &v);
 	void Liberar ();
public:
 	/**
 	* @brief Contructor por defecto y con parametro
 	* @param tam: elementos a reservar para el vector dinamico
 	* @note si no se proporciona un valor para tam se tomara como 10 */
 VD (int tam=10);
 
 /**
 * @brief Constructor de copia
 * @param original: vector dinamico origen
 */
 VD (const VD<T> &original);

 /**
 * @brief Destructor. Elimina la memoria asociada al vector dinamico
 */
 ~VD ();

 /**
 * @brief Operador de asignacion
 * @param v: vector dinamico fuente
 * @return una referencia al objeto al que apunta this
 */
 VD<T> &operator= (const VD<T> &v);

 /**
 * @brief Obtiene el numero de elementos almacenados en el vector dinamico 
 */
 int size() const {return n;}

 /**
 * @brief Consulta y modifica el elemento i-esimo
 * @param i: posicion del elemento
 * @return una referencia al elemento i-esimo del vector dinamico
 */
 T &operator[] (int i) {return datos[i];}//version no constante
 const T &operator[] (int i) const {return datos[i];} //version constate
 
 /**
 * @brief Inserta un objeto en la posicion pos del vector dinamico
 * @param d: obejto a insertar 
 * @param pos: posicion donde insertar.
 * @pre pos debe estar comprendido entre 0 y size()
 * @post aumenta en uno el vector dinamico
 */
 void Insertar (const T &d, int pos);
 
 /**
 * @brief Elimina el elemento en la posicion pos
 * @param pos: posicion del elemento a borrar.
 */
 void Borrar (int pos);
 };
 #include "VD.cpp"