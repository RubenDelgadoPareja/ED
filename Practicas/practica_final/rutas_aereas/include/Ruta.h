#ifndef _RUTA__H
#define _RUTA__H
#include <list>
#include "Punto.h"
#include <string>
using namespace std;
/**
 * @class Ruta 
 * @brief Esta clase representa una Ruta de la siguiente forma:
 * -Un codigo que identifica la ruta
 * -Lista de puntos que forma la ruta
 */
class Ruta{
    private:
        list<Punto> puntos;
        string code;
    public:
    /**
     * @brief Constructor por defecto 
     */
    Ruta(){}
    /**
     * @brief Inserta un Punto en la lista de puntos de la ruta 
     * @param n: Punto que vamos a insertar
     */
    void Insertar(const Punto &n){
        this->puntos.push_back(n);
    }
    /**
     * @brief Borramos un Punto de la lista de puntos de la Ruta
     * @param n: Punto que vamos a eliminar
     */
    void Borrar(const Punto &n){
        this->puntos.remove(n);
    }
    /**
     * @brief Getter del codigo
     * @return Devuelve el codigo de la ruta 
     */
    string GetCode()const{
        return this->code;
    }
    /**
     * @brief Setter del codigo
     * @param code: codigo que vamos a establecer en la ruta
     */
    void SetCode(const string &code){
        this->code = code;
    }
    
    /**
     * @brief Operador menor
     * @param r: Ruta que vamos a comparar
     * @return Verdadero si el codigo de R1 es < al codigo de R2
     */
    bool operator<(const Ruta &r)const{
        bool res = false;
        if (this->code < r.code){ 
            res = true;
        }

        return res;
    }
    /**
     * @brief Operador de comparador
     * @param r: Ruta que vamos a comparar
     * @return Devuelve true si son la misma Ruta y false si no
     */ 
    bool operator==(const Ruta &r)const{
        bool res = true;
        if (this->GetCode() == r.GetCode() && this->puntos.size() == r.puntos.size()){
        
            auto it_r = r.puntos.begin();
            for(auto it = this->puntos.begin(); res && it!=this->puntos.end(); ++it ){
                if( *it != *it_r){
                    res = false;
                }
                ++it_r;
            }
        }
        else 
            res = false;
    
        return res;
    }
    /**
     * @brief Operador distinto  
     * @param r: Ruta que vamos a comparar
     * @return Devuelve Verdadero si son distintos y Falso si son iguales
     */
    bool operator!=(const Ruta &r)const{
        bool res = false;
        if (this->GetCode() == r.GetCode() && this->puntos.size() == r.puntos.size()){
        
            auto it_r = r.puntos.begin();
            for(auto it = this->puntos.begin(); !res && it!=this->puntos.end(); ++it ){
                if( *it != *it_r){
                    res = true;
                }
                ++it_r;
            }
        }
        else 
            res = true;
    
        return res;
    }
    
    /**
     * @brief Operador de asignacion
     * @param r: Ruta que vamos a copiar
     * @return La nueva ruta copiada
     */
    Ruta operator=(const Ruta &r){
        if(this != &r){
            this->SetCode(r.GetCode());
    
            this->puntos.resize(0);
            for(auto it=r.puntos.begin(); it!=r.puntos.end(); ++it){
                this->puntos.push_back(*it);
            }
            
        }
        return *this;
    
    }
    
        class iterator{
            private:
                list<Punto>::iterator it;
            public:
                iterator(){};
                iterator & operator++(){
                    ++it;
                    return *this;
                }
                iterator & operator--(){
                    --it;
                    return *this;
                }
    
                Punto& operator*(){
                    return *it;
                }
    
                bool operator==(const iterator &i){
    					return it == i.it;
    				}
    			bool operator!=(const iterator &i){
    					return it != i.it;
    				}
    
                friend class Ruta;
        };
        
        class const_iterator{
            private:
                list<Punto>::const_iterator it;
    
            public:
    
            const_iterator(){};
            const_iterator & operator++(){
                ++it;
                return *this;
            }
            const_iterator & operator--(){
                --it;
                return *this;
            }
            const Punto& operator*(){
                return *it;
            }
            bool operator==(const const_iterator &i)const{
    				return it == i.it;
    			}
    		bool operator!=(const const_iterator &i)const{
    				return it != i.it;
    			}
            friend class Ruta;
    
        };
        iterator begin(){
    	    iterator i;
    	    i.it = puntos.begin();
    	    return i;
        }
    	iterator end(){
    	    iterator i;
    	    i.it = puntos.end();
    	    return i;
    	}
    	const_iterator begin()const{
    	    const_iterator i;
    	    i.it = puntos.cbegin();
    	    return i;
        }
    	const_iterator end()const{
    	    const_iterator i;
    	    i.it = puntos.cend();
    	    return i;
    	}
    
        iterator find(const Punto &p);
    
        friend istream & operator>>(istream & is, Ruta  &R);
        friend ostream & operator<<(ostream & os, const Ruta &R);
    };
    
/**
 * @brief Sobrecargar del operador de entrada
 * @param is: Flujo de entrada
 * @param R: Ruta que vamos a almacenar
 * @return Flujo de entrada
 */
istream & operator>>(istream & is, Ruta &R){
    string codigo;
    int tam;
    Punto aux;
    is >> codigo;
    QuitaSeparadores(is);
    is >> tam;
    QuitaSeparadores(is);
    while(tam > 0){
        QuitaSeparadores(is);
        is>>aux;
        R.Insertar(aux);
        tam--;
    }
    QuitaSeparadores(is);
    R.SetCode(codigo);
    return is;

}
/**
 * @brief Sobrecargar del operador de salida
 * @param os: Flujo de salida
 * @param R: Ruta que vamos a imprimir
 * @return Flujo de salida
 */ 
ostream & operator<<(ostream & os, const Ruta &R){

    os <<R.GetCode()<<" "<<R.puntos.size()<<" ";
    for(auto it= R.puntos.begin(); it!=R.puntos.end(); ++it){
        os<<*it<<" ";
    }

    return os;
}



#endif