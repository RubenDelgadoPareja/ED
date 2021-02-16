#ifndef _ALMACEN_RUTAS_H
#define _ALMACEN_RUTAS_H
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include "Ruta.h"

using namespace std;
/**
 * @class Almacen de Rutas
 * @brief Esta clase representa un diccionario de rutas donde el String 
 * indica el código identificativo de cada ruta.
 */

class Almacen_Rutas{
    private:
        map<string, Ruta> rutas;


    public:
    /**
     * @brief Constructor de Almacen_Rutas por defecto
     */
    Almacen_Rutas(){};

    /**
     * @brief Inserta una Ruta en el almacén 
     * @param R: Ruta que vamos a insertar
     */
    void Insertar(const Ruta &R){
        pair<string, Ruta> aux;
        aux.first = R.GetCode();
        aux.second = R;
        rutas.insert(aux);
    };

    /**
     * @brief Borramos una Ruta del nuestro map
     *  @param R: Ruta que queremos borrar
     */
    void Borrar(const Ruta &R){
        rutas.erase(R.GetCode());
    };

    /**
     * @brief Getter de la Ruta
     * @param clave: String el cual es el codigo que utilizas para encontrar la ruta asociada
     * @return Ruta
     */
    Ruta GetRuta(const string &clave){
        return (rutas.find(clave)).operator*().second;
    };

    /**
     * @brief Getter del tamaño 
     * @return Devuelve el tamaño del map
     */
    int size()const{
        return rutas.size();
    }

    /**
     * @brief Borra el contenido de nuestro almacen
     */
    void clear(){
        rutas.clear();
    }

    /**
     * @brief sobrecarga del operador []
     * @param clave: string asociado a una ruta del map
     * @return Devuelve la ruta asociada a la clave
     */
    Ruta & operator[](const string &clave) {
        return rutas[clave];
    }

    /**
     * @brief Sobrecarga del operador =
     * @param A: Almacen_Rutas el cual quieres asignar
     * @return Devuelves un Almacen de Rutas igual que el que has pasado por parámetro
     */
    Almacen_Rutas & operator=(const Almacen_Rutas &A){
        if(this != &A)
            rutas = A.rutas;
        return *this;
    }

    /**
     * @brief Sobrecarga del operador ==
     * @param A: Almacen de rutas el cual quieres comparar
     * @return Devuelve true si son el mismo almacen, en caso contrario devuelve false
     */
    bool operator==(const Almacen_Rutas &A)const{
        map<string, Ruta>::const_iterator it_A;
        map<string, Ruta>::const_iterator it = rutas.begin();

        for(it_A = A.rutas.begin(); it_A != A.rutas.end(); ++it_A ){
            if( (*it).first != (*it_A).first && (*it).second != (*it_A).second )
                return false;
            else{
                ++it;
            }
        }

        return true;
    }

    /**
     * @brief Sobrecarga del operador ==
     * @param A: Almacen de rutas el cual quieres comparar
     * @return Devuelve false si son el mismo almacen, en caso contrario devuelve true
     */
    bool operator!=(const Almacen_Rutas &A)const{
        map<string, Ruta>::const_iterator it_A;
        map<string, Ruta>::const_iterator it = rutas.begin();

        for(it_A = A.rutas.begin(); it_A != A.rutas.end(); ++it_A ){
            if( (*it).first != (*it_A).first && (*it).second != (*it_A).second )
                return true;
            else{
                ++it;
            }
        }

        return false;
    }

    class iterator{
        private:
            map<string,Ruta>::iterator it;
        public:
        iterator(){}
        iterator & operator++(){
            ++it;
            return *this;
        }

        iterator & operator--(){
            --it;
            return *this;
        }

        pair<const string, Ruta> & operator*(){
            return *it;
        }

        bool operator==(const iterator &i){
            return it == i.it;
        }

        bool operator!=(const iterator &i){
            return it != i.it;
        }

        friend class Almacen_Rutas;
    };

    class const_iterator{
        private: 
            map<string,Ruta>::const_iterator it;
        public:
            const_iterator(){} 
            const_iterator & operator++(){
                ++it;
                return *this;
            }

            const_iterator & operator--(){
                --it;
                return *this;
            }

            const pair<string, Ruta> & operator*(){
                return *it;
            }

            bool operator==(const const_iterator &i)const{
                return it == i.it;
            }

            bool operator!=(const const_iterator &i)const{
                return it != i.it;
            }

            friend class Almacen_Rutas;
    };


    iterator begin(){
	    iterator i;
	    i.it = rutas.begin();
	    return i;
    }
	iterator end(){
	    iterator i;
	    i.it = rutas.end();
	    return i;
	}
	const_iterator begin()const{
	    const_iterator i;
	    i.it = rutas.cbegin();
	    return i;
    }
	const_iterator end()const{
	    const_iterator i;
	    i.it = rutas.cend();
	    return i;
	}

    /**
     * @brief Sobrecarga del operador >> 
     * @param is: Flujo de entrada
     * @param AR: Almacen de Rutas donde vamos a almacenar
     * @return Flujo de entrada
     */
    friend istream & operator>>(istream & is, Almacen_Rutas &AR);

    /**
     * @brief SObrecarga del operador <<
     * @param os: Flujo de salida
     * @param R: Almacen de Rutas que queremos imprimir
     * @return Flujo de salida
     */
    friend ostream & operator<<(ostream & os, const Almacen_Rutas &R);

    //constructores, operadores de asignacion...
    //funciones de consulta y cambio de los miembros
    //insertar, borrar y consultar rutas
    //Devolver las rutas que contengan un det punto
    //iteradores 
    //funciones de lectura y escritura de puntos


};

istream & operator>>(istream &is,Almacen_Rutas &A){
    
    string basura;
    is>>basura;
    QuitaSeparadores(is);

    while(!is.eof()){
        Ruta aux;
        is>>aux;
        A.Insertar(aux);
        QuitaSeparadores(is);
    }

    return is;

}

ostream & operator<<(ostream &os,const Almacen_Rutas &A){
    os<<"#Rutas"<<endl;
    for(auto it=A.rutas.begin(); it!=A.rutas.end(); ++it){
        os<<(*it).second<<endl;
    }

    return os;
}

#endif