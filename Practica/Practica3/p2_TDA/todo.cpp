/**
  * @file VD.h
  * @brief Fichero cabecera del TDA Vector Dinamico
  * @brief Fichero cabecera para representar un vector dinamico de plantillas
  * @warning Este fichero no se puede modificar
  */
#ifndef _VD_H
#define _VD_H
using namespace std;
/**
  * @brief T.D.A. Vector Racional
  *
  * Una instancia @e v del tipo de datos abstracto @c Vector Dinamico es un objeto
  * de tipo vector dinamico, compuestos por un puntero a template, dos enteros
  * que representan, respectivamente, el vector que contendrá los datos, el numero
  * de elementos almacenados y el numero de elementos reservados. 
  *
  * 
  *
  * Un ejemplo de su uso:
  * No se puede probar, es de tipo plantilla
  *
  * @author Pablo Merino Ávila
  * @date Nov 2017
  */

template <class T>
class VD{
 private:
 /**
   * @page repVD Rep del TDA VD
   *
   * @section invVector Invariante de la representación
   *
   * El invariante es \e rep.reservados<rep.n, que n>=0 y reservados>=0
   *
   * @section faVD Función de abstracción
   *
   * Un objeto válido @e rep del TDA VD representa a un puntero a template 
   *
   * (rep.datos, rep.n,rep.reservados)
   *
   */
  T *datos; //vector dinamico

  int n; //número de elementos almacenados
  int reservados; //La memora reservada en datos
  
  void resize(int nuevotam);

 public:
 /**
    * @brief Constructor por defecto de la clase. 
    * @param Crea un puntero a plantilla de tamaño 10
    */
  VD(int tam=10);
 /**
   * @brief Constructor de copias de la clase
   * @param original.n es el num de elementos a almacenar
   * @param original.reservados es la memoria a reservar 
   */
  VD(const VD<T> &original);
  /**
  * @brief Destructor de la clase
  * @return Libera memoria en el puntero datos
  */ 
  ~VD();
  /**
  * @brief size
  * @return Devuelve el tamaño del vector
  */ 
  int size() const;
  /**
  * @brief Sobrecarga del operador []
  * @param devuelve el elemento datos[i] permitiendo su modificacion
  */ 
  T& operator[](int i);
   /**
  * @brief Sobrecarga del operador [] constante
  * @param devuelve el elemento datos[i] sin modificarlo
  */ 
  const T& operator[](int i) const;
  /**
  * @brief introduce un nuevo elemento en el vector
  */
  void insertar(const T &dato, int pos);
   /**
  * @brief elimina un elemento en el vector que se encuentra
  * @brief en la posicion pos
  */
  void borrar(int pos);
  /**
  * @brief Sobrecarga del operador =
  * @param copia el vector original en el vector de la clase
  */
  VD<T> &operator=(const VD<T> &original);

};

#include "VD.cpp"
#endif
 /**
  * @file VD.h
  * @brief Fichero cabecera del TDA Matriz_Dispersa 
  * @brief Fichero cabecera para representar una matriz dispersa de char
  * @warning Este fichero no se puede modificar
  */
#ifndef _MD_H
#define _MD_H


#include "VD.h"
#include <iostream>
using namespace std;
/**
  * @brief Struct tripleta
  *
  * Una instancia @e t del tipo del tipo struct @c tripleta es un objeto
  * compuesto por 2 enteros indicando fila y columna en una matriz y un char  
  * para indicar el valor asociado
  * 
  *
  *
  * @author Pablo Merino Ávila
  * @date Nov 2017
  */
struct tripleta{
 int fila,columna;
 char d;
};
/**
  * @brief T.D.A. Matriz Dispersa
  *
  * Una instancia @e m del tipo de datos abstracto @c Matrizdispersa es un objeto
  * de tipo vector dinamico (VD), y un valor por defecto de tipo char. 
  *
  * 
  *
  * Un ejemplo de su uso:
  * @include prueba.cpp
  * @author Pablo Merino Ávila
  * @date Nov 2017
  */

class Matriz_Dispersa{
private:
/**
   * @page repVD Rep del TDA Matriz_Dispersa
   *
   * @section invMatriz Invariante de la representación
   *
   * El invariante es \e rep.v.reservados<rep.v.n, que rep.v.n>=0 y rep.v.reservados>=0
   *
   * @section faMatriz_Dispersa Función de abstracción
   *
   * Un objeto válido @e rep del TDA Matriz_Dispersa representa a una matriz infinita
   * en la cual solo se almacenan en memoria los datos que son distintos al valor por defecto.
   * (rep.v, rep.valor_defecto)
   *
   */
 VD<tripleta> v; //vector dinamico
 char valor_defecto; // valor predeterminado
public:
 /**
    * @brief Constructor por defecto de la clase. 
    * @param Pone el valor por defecto a 0
    */
 Matriz_Dispersa();
/**
    * @brief Constructor por parametros de la clase. 
    * @param Asigna un nuevo valor por defecto.
    */
 Matriz_Dispersa(char a);
/**
  * @brief Elemento
  * @return Devuelve el char asociado a una fila y a una columna
  */ 
 char getele(int i, int j)const;
/**
  * @brief Menor fila
  * @return Devuelve la fila mas pequeña de la matriz
  */ 
 int getmenorf()const;
/**
  * @brief Mayor fila
  * @return Devuelve a fila mas grande de la matriz
  */ 
 int getmayorf()const;
/**
  * @brief Menor columna
  * @return Devuelve la columna mas pequeña de la matriz
  */ 
 int getmenorc()const;
/**
  * @brief Mayor columna
  * @return Devuelve a columna mas grande de la matriz
  */
 int getmayorc()const;
/**
  * @brief Valor por defecto
  * @return Devuelve el el valor por defecto de la matriz
  */ 
 char get_default() const;
/**
  * @brief Usadas
  * @return Devuelve el numero de elementos de la matriz que son distintos al valor por defecto.
  */ 
 int getusadas()const;
/**
  * @brief Filas
  * @return Devuelve el numero de filas de la matriz
  */ 
 int getfilas()const; //restar la mayor fila a la menor +1
/**
  * @brief Columnas
  * @return Devuelve el numero de columnas de la matriz
  */ 
 int getcolumnas()const;
/**
  * @brief Modifica los objetos de la matriz dispersa;
  */
 void Set(int i, int j, char v);
/**
  * @brief Sobrecarga del operador salida;
  */
  friend ostream& operator<<(ostream& os, const Matriz_Dispersa& otra);
 //sobrecarga de escritura y lectura en flujos
 
  
};

#endif
 /**
  * @file sopa_letras.h
  * @brief Fichero cabecera del TDA Sopa de Letras
  * @brief Fichero cabecera para representar una sopa de letras 
  * @warning Este fichero no se puede modificar
  */
#ifndef _SL_H
#define _SL_H
#include <string>
#include "matriz_dispersa.h"
#include "VD.h"
using namespace std;
/**
  * @brief T.D.A. Sopa de Letras
  *
  * Una instancia @e s del tipo de datos abstracto @c Sopa_Letras es un objeto
  * de tipo Matriz_Dispersa, dos vectores dinamicos (VD) de tipo string y un string. 
  *
  * 
  *
  * Un ejemplo de su uso:
  * @include prueba_sp.cpp
  *
  * @author Pablo Merino Ávila
  * @date Nov 2017
  */
class Sopa_Letras{
 private:
/**
   * @page repSopa_Letras Rep del TDA Sopa_Letras
   *
   * @section invSopa_Letras Invariante de la representación
   *
   * El invariante es \e rep.m.v[i].f != rep.m.valor_defecto y que rep.Nodescubiertas[i] != rep.descubiertas[i] 
   *
   * @section faSopa_Letras Función de abstracción
   *
   * Un objeto válido @e rep del TDA Sopa_Letras representa a una matriz infinita
   * en la cual solo se almacenan en memoria los datos que son distintos al valor por defecto.
   * (rep.m, rep.Nodescubiertas, rep.descubiertas. rep.nombre)
   *
   */  
  Matriz_Dispersa m;
  VD<string> Nodescubiertas;
  VD<string> descubiertas;
  string nombre;

 public:
 /**
    * @brief Constructor por defecto de la clase. 
    */
  Sopa_Letras();
/**
  * @brief Esta
  * @return Comprueba si una palabra se encuentra en la sopa de letras
  */ 
  bool esta(int f, int c, const string &direccion, const string &palabra) const;
/**
  * @brief No esta descubierta
  * @return Comprueba si una palabra de la sopa de letras ha sido descubierta por el jugador
  */ 
  bool NOestadescubierta(const string &c) const;
/**
  * @brief Puedo Poner
  * @return Comprueba si una palabra se puede poner en la sopa de letras
  */
  bool puedoPoner(int f, int c, const string &direccion,const string &palabra)const;
/**
  * @brief No Descubiertas
  * @return Devuelve cuantas palabras quedan por descubrir.
  */
  int noDescubiertas()const;
/**
  * @brief Descubiertas
  * @return Devuelve cuantas palabras ya han sido descubiertas.
  */
  int Descubiertas()const;
/**
  * @brief Modifica una palabra de la sopa de letras
  */
  void setPalabra(int f, int c,const string &direccion, string &palabra);
 /**
  * @brief Modifica una palabra poniendola como acertada
  */
  void palabraAcertada(const string &palabra);
 /**
  * @brief Elimina una palabra de la sopa de letras.
  */
  void eliminarPalabra(int f, int c,const string &direccion,  string &palabra);
 /**
  * @brief Sobrecarga del operador Salida.
  */ 
  friend ostream& operator<<(ostream& os, const Sopa_Letras &otra);
  /**
  * @brief Sobrecarga del operador Entrada.
  */
  friend istream& operator>>(istream& is, Sopa_Letras &otra);
};
#endif
 #include "sopa_letras.h"
  using namespace std;
  Sopa_Letras::Sopa_Letras(){

  }

  bool Sopa_Letras::esta(int f, int c, const string &direccion, const string &palabra) const{
   bool rta = true; 
   if(direccion == "hd"){//horizontal derecha
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f,c+i) != palabra[i]){
      rta=false;
     }
    }
   }
   else if(direccion == "hi"){//horizontal izquierda
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f,c-i) != palabra[i]){
      rta=false;
     }
    }
   }
   else if(direccion == "vu"){ //vertical arriba
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f-i,c) != palabra[i]){
      rta=false;
     }
    }
   }
   else if(direccion == "vd"){ //vertical abajo
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f+i,c) != palabra[i]){
      rta=false;
     }
    }
   }
   else if(direccion == "dd"){//diagonal derecha
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f+i,c+i) != palabra[i]){
      rta=false;
     }
    }
   }
   else if(direccion == "di"){//diagonal izquierda
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f-i,c+i) != palabra[i]){
      rta=false;
     }
    }
   }
   else{
    rta = false;
   }
   return rta;
  }

  bool Sopa_Letras::NOestadescubierta(const string &c) const{
   //comprobamos si una palabra esta en la lista de palabras no descubiertas
   bool encontrado=false;
   for(int i=0;i<Nodescubiertas.size() && !encontrado;i++){
    if(Nodescubiertas[i] ==  c){
     encontrado=true;
    }
   }
   return encontrado;
  }

  bool Sopa_Letras::puedoPoner(int f, int c, const string &direccion,const string &palabra)const{
   bool rta = true; 
   if(direccion == "hd"){//horizontal derecha
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f,c+i) != palabra[i] || m.getele(f, c+i) != m.get_default() ){
      rta=false;
     }
    }
   }
   else if(direccion == "hi"){//horizontal izquierda
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f,c-i) != palabra[i]|| m.getele(f, c-i) != m.get_default() ){
      rta=false;
     }
    }
   }
   else if(direccion == "vu"){ //vertical arriba
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f-i,c) != palabra[i]|| m.getele(f-i, c) != m.get_default()){
      rta=false;
     }
    }
   }
   else if(direccion == "vd"){ //vertical abajo
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f+i,c) != palabra[i]|| m.getele(f+i, c) != m.get_default()){
      rta=false;
     }
    }
   }
   else if(direccion == "dd"){//diagonal derecha
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f+i,c+i) != palabra[i]|| m.getele(f+i, c+i) != m.get_default()){
      rta=false;
     }
    }
   }
   else if(direccion == "di"){//diagonal izquierda
    for(int i=0;i<palabra.length() && rta;i++){
     if(m.getele(f-i,c+i) != palabra[i]|| m.getele(f-i, c+i) != m.get_default()){
      rta=false;
     }
    }
   }
   else{
    rta = false;
   }
   return rta;
  }

  int Sopa_Letras::noDescubiertas()const{
   return Nodescubiertas.size();
  }

  int Sopa_Letras::Descubiertas()const{
   return descubiertas.size();
  }

  void Sopa_Letras::setPalabra(int f, int c,const string &direccion,  string &palabra){
   
   bool podemos = puedoPoner(f,c,direccion,palabra);
   if(podemos){ 
    if(direccion == "hd"){//horizontal derecha
     for(int i=0;i<palabra.length();i++){
      m.Set(f,c+i, palabra[i]);
     }
    }
    else if(direccion == "hi"){//horizontal izquierda
     for(int i=0;i<palabra.length();i++){
      m.Set(f,c-i, palabra[i]);
     }
    }
    else if(direccion == "vu"){ //vertical arriba
     for(int i=0;i<palabra.length();i++){
      m.Set(f-i,c, palabra[i]);
     }
    }
    else if(direccion == "vd"){ //vertical abajo
     for(int i=0;i<palabra.length();i++){
      m.Set(f+i,c, palabra[i]);
     }
    }
    else if(direccion == "dd"){//diagonal derecha
     for(int i=0;i<palabra.length();i++){
      m.Set(f+i,c+i, palabra[i]);
     }
    }
    else if(direccion == "di"){//diagona
 l izquierda
     for(int i=0;i<palabra.length();i++){
      m.Set(f-i,c+i, palabra[i]);
     }
    }
   }   
  }

  void Sopa_Letras::palabraAcertada(const string &palabra){
   if(NOestadescubierta(palabra)){
    bool encontrada  =false;
    for(int i=0;i<Nodescubiertas.size() && !encontrada;i++){
     if(Nodescubiertas[i] == palabra){
      Nodescubiertas.borrar(i);
      descubiertas.insertar(palabra, descubiertas.size());    
      encontrada = true;
     }
    }

   }
  }
  void Sopa_Letras::eliminarPalabra(int f, int c,const string &direccion,  string &palabra){
   string aux = "";
   if(esta(f, c, direccion, palabra)){
    bool encontrada=false;

    for(int i=0;i<Nodescubiertas.size() && !encontrada;i++){
     if(palabra == Nodescubiertas[i]){
      Nodescubiertas.borrar(i);
      encontrada=true;
     }
    }
    for(int i=0;i<descubiertas.size()&&!encontrada;i++){
     if(palabra == descubiertas[i]){
      descubiertas.borrar(i);
      encontrada=true;
     }
    }
    
    for(int i=0;i<palabra.length();i++){
     aux += m.get_default();

    }

    setPalabra(f,c,direccion, aux);    
   }
  }

  friend ostream& operator<<(ostream& os, const Sopa_Letras &otra){
   os << nombre << endl;
   os << m.ost 
   return os;
  }
  friend istream& operator>>(istream& is, Sopa_Letras &otra){

   while(isspace(is.peek)){
    is.ignore;
   }
   os >> nombre;

   setPalabra()
   return is;
  }

 Elegir archivos Elegir archivos
