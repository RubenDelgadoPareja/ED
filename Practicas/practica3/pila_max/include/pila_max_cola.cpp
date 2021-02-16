
#include <iostream>
#include "pila_max_cola.h"

using namespace std;

ostream & operator<<(ostream & os,const elemento &e){
    os <<"cola : ("<<e.ele<<","<<e.maximo<<")";
    return os;
}

elemento Pila_max::tope()const{
    Pila_max aux;
    aux.datos = this->datos;

    elemento ele_aux;

    while(!aux.vacia()){
        ele_aux = aux.datos.frente();
        aux.datos.quitar();
    }

    return ele_aux;

}

void Pila_max::quitar(){
    Cola<elemento> aux;
    int tam = this->datos.num_elementos();

    for(int i=0; i < tam-1; i++){
        aux.poner(this->datos.frente());
        this->datos.quitar();
    }

    this->datos = aux;
}

void Pila_max::poner(int x){
    elemento aux; 
    aux.ele = x;
    
    if( x > this->tope().maximo || datos.vacia() )
        aux.maximo = x;
    else
        aux.maximo = this->tope().maximo;

    this->datos.poner(aux);
}

bool Pila_max::vacia()const {
    return this->datos.vacia();
}

int Pila_max::size()const {
    return this->datos.num_elementos();
}