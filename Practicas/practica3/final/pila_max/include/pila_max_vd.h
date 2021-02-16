#ifndef _PILA_MAX_VD
#define _PILA_MAX_VD
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

struct elemento{
    int ele;
    int maximo;
};

/**
*@param &e El struct elemento 
*@param &os ostream que se encarga del flujo de salida
*@brief SObrecarga del operador << para poder mostrar el struct elemento
*@return Devuelve el flujo de salida
*/
ostream & operator<<(ostream & os,const elemento &e);

class Pila_max{
    private:
        vector<elemento> datos;
    public:
    
    	/**
	*@brief Se encarga de devolver el elemento que se encuentra en el tope de la pila
	@return Devuelve el struct elemento
	*/
        elemento tope()const;
        
        /**
	* @brief Elimina el elemento que se encuentra en el tope de la pila
	* @return Nada
	*/

        void quitar();
        
        /**
	* @param x Es el entero que se quiere añadir a la pila
	* @brief Se crea un struct elemento con el entero y se comprueba si el elemento es mayor que el maximo de la pila. EL elemento se añade en el tope
	* @return Nada
	*/
        void poner(int x);
        
        /**
	* @brief Comprueba si la pila se encuentra vacia
	* @return Booleano 
	*/
        bool vacia()const;
        

	
	/**
	* @brief Calcula el tamaño de la pila
	* @return entero con el valor del tamaño de la pila
	*/

        int size()const;
};



#endif 
